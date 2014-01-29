/*
 * tachibana_choose.c
 *
 *  Created on: 2014/01/22
 *      Author: cs12051
 */


#include "tachi_hedder.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>


void choose_print(int,char *);
void printallow(int, int);
void choose_userinput(int *, char);


/*変換選択 */

void Choose(char *intxt, char *outtxt) {
	int select = -1;
	char ucom;
	while (1) {
		system("cls");
		Printscreen_Print();
		printf("\n");
		choose_print(select,intxt);
		ucom = getch();
		if (ucom == 0xd){
			/*Enterキーが押されたらループを抜ける*/
			system("cls");
			break;
		}

		choose_userinput(&select, ucom);
	}
	if (select ==-1) {
		strcpy(outtxt, intxt);
	} else {
		strcpy(outtxt, pattern[costRank[select].patternnunber].word);
	}
}

void choose_print(int select, char *intxt) {
	int i;
	printallow(-1, select);
	printf("%s\n", intxt);
	for (i = 0; i < RANKSIZE; i++) {
		printallow(i, select);
		printf("%s\n", pattern[costRank[i].patternnunber].word);
	}
}

void printallow(int i, int select) {
	if (i == select) {
		printf("-> ");
	} else {
		printf("   ");
	}
}

void choose_userinput(int *sct, char ucom) {
	if (ucom == 0xffffffe0) {/*矢印キーが動いたらカーソルを動かす*/
		ucom = getch();
		switch (ucom) {
		case 0x48:
			if (*sct > -1)
				(*sct)--;
			break;
		case 0x50:
			if (*sct < RANKSIZE-1)
				(*sct)++;
			break;
		}
	}
}
