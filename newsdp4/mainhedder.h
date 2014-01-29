/*
 * mainhedder.h
 *
 *  Created on: 2014/01/17
 *      Author: cs12033
 */

#ifndef MAINHEDDER_H_
#define MAINHEDDER_H_

#define MAXcharsize 1024
#define patterns 15
# define RANKSIZE 4
#define MAX_DATA 400

#define KANA 1
#define DEL 2
#define TWEET 5
#define CANCEL 7
#define END -1
#define ZEN 1
#define HAN 0

typedef struct data {        // ç\ë¢ëÃÇÃêÈåæ
	char word[MAXcharsize];
	char read[MAXcharsize];
} PATTERN;

PATTERN pattern[MAX_DATA];

typedef struct result {
	struct result *before;
	struct result *after;
	char content[MAXcharsize];
} RESULT;

RESULT *head;
RESULT *tail;

int line_count;

void ReadDictionary();
char * GetTime();
int UserInput(char *);
void DPmatching(char *);
void Choose(char *, char *);
void PrintScreen(char *);
void FileWrite();
int CheckKanzi(char *);
void Centensdelete();
int CheckZenkaku(unsigned char);
void Printscreen_Print();
void SystemLine();

void FileTweetWrite();

#endif /* MAINHEDDER_H_ */
