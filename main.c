#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

void filestat1(void)//get file info
{
	stat("./text1",&stat1);
}
void filestat2(void)
{
	stat("./text2",&stat2);
}
void filetime1(void)//get file time
{
	time1 = localtime(&stat1.st_mtime);
}
void filetime2(void)
{
	time2 = localtime(&stat2.st_mtime);
}
void sizecmp(void)//compare file size
{
  printf("size compare\n");
  if(stat1.st_size > stat2.st_size){
    printf("text1 is bigger\n");
  }
  else if(stat1.st_size < stat2.st_size){
    printf("text2 is bigger\n");
  }
  else{
    printf("sizes are equal\n");
  }
  printf("\n");
}
void blockcmp(void)//compare file block count
{
  printf("block compare\n");
  if(stat1.st_blocks > stat2.st_blocks){
    printf("text1 is bigger\n");
  }
  else if(stat1.st_blocks < stat2.st_blocks){
    printf("text2 is bigger\n");
  }
  else{
    printf("sizes are equal\n");
  }
  printf("\n");
}
void datecmp(void)//compare file change time
{
  int t1_mon,t2_mon,t1_day,t2_day;
	printf("date compare\n");
  filetime1();
  t1_mon = time1->tm_mon;
  t1_day = time1->tm_mday;
  filetime2();
  t2_mon = time2->tm_mon;
  t2_day = time2->tm_mday;
	if (t1_mon == t2_mon) {
		if (t1_day == t2_day)
			printf("same time. \n");
		else if (t1_day < t2_day)
			printf("text1 is early. \n");
		else
			printf("text2 is early. \n");
	}
	else if (t1_mon < t2_mon) {
		printf("text1 is early. \n");
	}
	else {
		printf("text2 is early. \n");
	}
	printf("\n");
}
void timecmp(void)
{
  int t1_hour,t2_hour,t1_min,t2_min;
  filetime1();
  t1_hour = time1->tm_hour;
  t1_min = time1->tm_min;
  filetime2();
  t2_hour = time2->tm_hour;
  t2_min = time2->tm_min;
	printf("time compare\n");
	if (t1_hour == t2_hour) {
		if (t1_min == t2_min)
			printf("same date. \n");
		else if (t1_min < t2_min)
			printf("text1 is early. \n");
		else
			printf("text2 is early. \n");
	}
	else if (t1_hour < t2_hour)	{
		printf("text1 is early. \n");
	}
	else {
		printf("text2 is early. \n");
	}
	printf("\n");
}
