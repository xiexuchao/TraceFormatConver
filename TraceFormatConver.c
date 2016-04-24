#include <stdio.h>
#include <string.h>

#define __TRACE_MSR__
//#define __TRACE_SPC__
//#define __TRACE_NETAPP__

#define BUFSIZE 300
#define READ	0
#define WRITE	1

#define SLOT_BEG 55 //MIN
#define SLOT_END 65

void msr2ascii(char *source,char *target);
void netapp2ascii(char *source,char *target);

void main()
{
#ifdef __TRACE_MSR__
	char path_i[100]="F:\\MSR Trace\\";
	char path_o[100]="F:\\MSR Trace\\";
#else
	char path_i[100]="F:\\Netapp Trace\\";
	char path_o[100]="F:\\Netapp Trace\\";
#endif
	char path_source[100];
	char path_target[100];

#ifdef __TRACE_MSR__
	msr2ascii(strcat(strcpy(path_source,path_i),"hm_0.csv"),strcat(strcpy(path_target,path_o),"hm_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"hm_1.csv"),strcat(strcpy(path_target,path_o),"hm_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"mds_0.csv"),strcat(strcpy(path_target,path_o),"mds_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"mds_1.csv"),strcat(strcpy(path_target,path_o),"mds_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"prn_0.csv"),strcat(strcpy(path_target,path_o),"prn_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"prn_1.csv"),strcat(strcpy(path_target,path_o),"prn_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"proj_0.csv"),strcat(strcpy(path_target,path_o),"proj_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"proj_1.csv"),strcat(strcpy(path_target,path_o),"proj_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"proj_2.csv"),strcat(strcpy(path_target,path_o),"proj_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"proj_3.csv"),strcat(strcpy(path_target,path_o),"proj_3.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"proj_4.csv"),strcat(strcpy(path_target,path_o),"proj_4.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"prxy_0.csv"),strcat(strcpy(path_target,path_o),"prxy_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"prxy_1.csv"),strcat(strcpy(path_target,path_o),"prxy_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"rsrch_0.csv"),strcat(strcpy(path_target,path_o),"rsrch_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"rsrch_1.csv"),strcat(strcpy(path_target,path_o),"rsrch_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"rsrch_2.csv"),strcat(strcpy(path_target,path_o),"rsrch_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"src1_0.csv"),strcat(strcpy(path_target,path_o),"src1_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"src1_1.csv"),strcat(strcpy(path_target,path_o),"src1_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"src1_2.csv"),strcat(strcpy(path_target,path_o),"src1_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"src2_0.csv"),strcat(strcpy(path_target,path_o),"src2_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"src2_1.csv"),strcat(strcpy(path_target,path_o),"src2_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"src2_2.csv"),strcat(strcpy(path_target,path_o),"src2_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"stg_0.csv"),strcat(strcpy(path_target,path_o),"stg_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"stg_1.csv"),strcat(strcpy(path_target,path_o),"stg_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"ts_0.csv"),strcat(strcpy(path_target,path_o),"ts_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"usr_0.csv"),strcat(strcpy(path_target,path_o),"usr_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"usr_1.csv"),strcat(strcpy(path_target,path_o),"usr_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"usr_2.csv"),strcat(strcpy(path_target,path_o),"usr_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"wdev_0.csv"),strcat(strcpy(path_target,path_o),"wdev_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"wdev_1.csv"),strcat(strcpy(path_target,path_o),"wdev_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"wdev_2.csv"),strcat(strcpy(path_target,path_o),"wdev_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"wdev_3.csv"),strcat(strcpy(path_target,path_o),"wdev_3.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"web_0.csv"),strcat(strcpy(path_target,path_o),"web_0.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"web_1.csv"),strcat(strcpy(path_target,path_o),"web_1.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"web_2.csv"),strcat(strcpy(path_target,path_o),"web_2.ascii"));
	msr2ascii(strcat(strcpy(path_source,path_i),"web_3.csv"),strcat(strcpy(path_target,path_o),"web_3.ascii"));
#else
	netapp2ascii(strcat(strcpy(path_source,path_i),"hadoop10.csv"),strcat(strcpy(path_target,path_o),"hadoop10.ascii"));
	netapp2ascii(strcat(strcpy(path_source,path_i),"hadoop13.csv"),strcat(strcpy(path_target,path_o),"hadoop13.ascii"));
	netapp2ascii(strcat(strcpy(path_source,path_i),"backup1.csv"),strcat(strcpy(path_target,path_o),"backup1.ascii"));
	netapp2ascii(strcat(strcpy(path_source,path_i),"backup5.csv"),strcat(strcpy(path_target,path_o),"backup5.ascii"));
	netapp2ascii(strcat(strcpy(path_source,path_i),"backup14.csv"),strcat(strcpy(path_target,path_o),"backup14.ascii"));
	netapp2ascii(strcat(strcpy(path_source,path_i),"backup15.csv"),strcat(strcpy(path_target,path_o),"backup15.ascii"));
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