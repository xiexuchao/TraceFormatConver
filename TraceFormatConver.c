#include <stdio.h>
#include <string.h>

//#define __TRACE_MSR__
//#define __TRACE_SPC__
//#define __TRACE_NETAPP__

#define BUFSIZE 300
#define READ	0
#define WRITE	1

#define TIMESLOT 5 //MIN

void msr2ascii(char *source,char *target);
void netapp2ascii(char *source,char *target);

void main()
{
#ifdef __TRACE_MSR__
	char path_i[100]="F:\\MSR Trace\\";
#else
	char path_i[100]="F:\\Netapp Trace\\";
#endif
	char path_o[100]="results\\";
	char path_source[100];
	char path_target[100];

#ifdef __TRACE_MSR__
	msr2ascii(strcat(strcpy(path_source,path_i),"prxy_1.csv"),strcat(strcpy(path_target,path_o),"prxy_1.ascii"));
#else
	netapp2ascii(strcat(strcpy(path_source,path_i),"UMNtrace2_5.csv"),strcat(strcpy(path_target,path_o),"UMNtrace2_5.ascii"));
#endif

}

void msr2ascii(char *source,char *target)
{
	char buf[BUFSIZE];
	FILE *file_source=fopen(source,"r");
	FILE *file_target=fopen(target,"w");

	//ASCII Format
	double time;		//milliseconds
	unsigned int dev;
	long long lba;		//LBA
	unsigned int size;	//Blocks
	unsigned int type;	//R<->0;W<->1

	//MSR Format
	long long timeStamp;	//windows filetime (100ns)
	char hostName[10];		
	unsigned int diskNumber;
	char operation[10];		//"Read" or "Write"
	long long offset;	//bytes
	unsigned int length;	//bytes
	long long responseTime;	//windows filetime

	//for preprocess
	int i,count=0;
	long long initTime;

	printf("Format Coverting %s ...\n",source);
	while(fgets(buf,sizeof(buf),file_source))
	{
		for(i=0;i<sizeof(buf);i++)
		{
			if(buf[i]==',')
			{
				buf[i]=' ';
			}
		}
		sscanf(buf,"%lld %s %d %s %lld %d %lld",&timeStamp,hostName,
			&diskNumber,operation,&offset,&length,&responseTime);
		
		//Preprocess 
		/*A file time is a 64-bit value that represents the number of 
		 *100-nanosecond intervals that have elapsed since 12:00 A.M. 
		 *January 1, 1601 Coordinated Universal Time (UTC).*/
		count++;
		if(count==1)
		{
			initTime=timeStamp;
		}
		if(count%1000000==0)
		{
			printf("processing %d ...\n",count);
		}
		timeStamp=timeStamp-initTime;
		
		//Format Covert
		time=(double)((long double)timeStamp/10000); //10ns-->ms
		dev=diskNumber;
		lba=offset/512;
		size=length/512;
		if(strcmp(operation,"Read")==0)
		{
			type=READ;
		}else
		{
			type=WRITE;
		}
		fprintf(file_target,"%-15lf %d %-8lld %-4d %d\n",time,dev,lba,size,type);
		fflush(file_target);
	}//while
	fclose(file_source);
	fclose(file_target);
}


void netapp2ascii(char *source,char *target)
{
	char buf[BUFSIZE];
	FILE *file_source=fopen(source,"r");
	FILE *file_target=fopen(target,"w");

	//ASCII Format
	double time;		//milliseconds
	unsigned int dev;
	long long lba;		//LBA
	unsigned int size;	//Blocks
	unsigned int type;	//R<->0;W<->1

	//NetApp Format
	long double elapsedTime;//us
	char cmd[10];
	unsigned int lunssid;
	unsigned int op;		//0<->Read,1<->Write
	unsigned int phase;
	long long offset;		//blocks
	unsigned int nblks;		//blocks
	unsigned int hostid;

	//for preprocess
	int i,count=0;
	long double initTime;

	printf("Format Coverting %s ...\n",source);
	while(fgets(buf,sizeof(buf),file_source))
	{
		for(i=0;i<sizeof(buf);i++)
		{
			if(buf[i]==',')
			{
				buf[i]=' ';
			}
		}
		sscanf(buf,"%Lf %s %d %d %d %lld %d %d",&elapsedTime,cmd,
			&lunssid,&op,&phase,&offset,&nblks,&hostid);
		
		//Preprocess 
		count++;
		if(count==1)
		{
			initTime=elapsedTime;
		}
		if(count%1000000==0)
		{
			printf("processing %d ...\n",count);
		}
		elapsedTime=elapsedTime-initTime;
		
		//Format Covert
		time=(double)(elapsedTime/1000); //us-->ms
		dev=lunssid;
		lba=offset;
		size=nblks;
		type=op;

		fprintf(file_target,"%-15lf %d %-12lld %-4d %d\n",time,dev,lba,size,type);
		fflush(file_target);
	}//while
	fclose(file_source);
	fclose(file_target);
}