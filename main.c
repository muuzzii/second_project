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
}
void filestat2(void)
{
}
void filetime1(void)//get file time
{
}
void filetime2(void)
{
}
void sizecmp(void)//compare file size
{
}
void blockcmp(void)//compare file block count
{
}
void datecmp(void)//compare file change time
{
}
void timecmp(void)
{
}
