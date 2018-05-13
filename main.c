#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <iostream>

using namespace std;

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
	int a = stat("./text1",&stat1);
  int b = stat("./text2",&stat2);
  printf("%ld %ld\n",stat1.st_size,stat2.st_size);

  if(stat1.st_size > stat2.st_size){
    printf("text1 is bigger\n");
  }
  else if(stat1.st_size < stat2.st_size){
    printf("text2 is bigger\n");
  }
  else{
    printf("sizes are equal\n");
  }
}
void blockcmp(void)//compare file block count
{
  int a = stat("./text1",&stat1);
  int b = stat("./text2",&stat2);
  printf("%ld %ld\n",stat1.st_blocks,stat2.st_blocks);
  if(stat1.st_blocks > stat2.st_blocks){
    printf("text1 is bigger\n");
  }
  else if(stat1.st_blocks < stat2.st_blocks){
    printf("text2 is bigger\n");
  }
  else{
    printf("sizes are equal\n");
  }
}
void datecmp(void)//compare file change time
{
	printf("data compare\n");
	
	if (time1.tm_mon == time2.tm_mon) {
		if (time1.tm_mday == time2.tm_mday)
			printf("same time. \n");
		else if (time1.tm_mday < time2.tm_mday)
			printf("temp1.dat file is early. \n");
		else
			printf("temp2.dat file is early. \n");
	}
	else if (time1.tm_mon < time2.tm_mon) {
		printf("temp.dat file is early. \n");
	}
	else {
		printf("temp2.dat file is early. \n");
	}
	printf("\n");
}
void timecmp(void)
{
	printf("time compare\n");

	if (time1.tm_hour == time2.tm_hour) {
		if (time1.tm_min == time2.tm_min)
			printf("same time. \n");
		else if (time1.tm_min < time2.tm_min)
			printf("temp1.dat file is early. \n");
		else
			printf("temp2.dat file is early. \n");
	}
	else if (time1.tm_hour < time1.tm_hour)	{
		printf("temp.dat file is early. \n");
	}
	else {
		printf("temp2.dat file is early. \n");
	}
	printf("\n");
}
