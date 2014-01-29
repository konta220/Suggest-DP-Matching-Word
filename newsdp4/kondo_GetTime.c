#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

time_t time(time_t *timer);

struct tm *localtime(const time_t *timer);

static char rtntime[50];

void SystemLine() {
	printf("\n----------------------------------\n\n");
}

char *GetTime() {
	*rtntime = '\0';

	char *lotime;

	time_t timer;
	struct tm *local;

	timer = time(NULL);

// rtntime = (char *) malloc(sizeof(char) * 50);
	lotime = (char *) malloc(sizeof(char) * 10);

	local = localtime(&timer);

	sprintf(lotime, "%4d-", local->tm_year + 1900);
	strcat(rtntime, lotime);

	sprintf(lotime, "%2d-", local->tm_mon + 1);
	strcat(rtntime, lotime);

	sprintf(lotime, "%2d-", local->tm_mday);
	strcat(rtntime, lotime);

	sprintf(lotime, "%2d-", local->tm_hour);
	strcat(rtntime, lotime);

	sprintf(lotime, "%2d-", local->tm_min);
	strcat(rtntime, lotime);

	sprintf(lotime, "%2d", local->tm_sec);
	strcat(rtntime, lotime);

	return rtntime;
}

/*int main(void) {
 char *txt;
 txt = GetTime();
 printf("%s", txt);
 return 0;
 }*/
