/* * mainsource.c
 *
 *  Created on: 2014/01/08
 *      Author: cs051
 */

#include "mainhedder.h"

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(void) {
	char inputtext[MAXcharsize];
	char decidetext[MAXcharsize];
	int status;

	head = NULL;
	tail = NULL;

	system("cls");
	/*辞書ファイルの読み込み*/
	ReadDictionary();
	while (1) {/*enter2回まで繰り返す*/
		/*入力*/
		status = UserInput(inputtext);
		if (status == END)
			break;
		switch (status) {
		case KANA:
			/*DPマッチング*/
			DPmatching(inputtext);
			/*ユーザ選択*/
			Choose(inputtext, decidetext);
			break;
		case DEL:
			Centensdelete();/*でりーと関数*/
			*decidetext = '\0';
			system("cls");
			break;
		case TWEET:
			system("cls");
			*decidetext = '\0';
			FileTweetWrite();
			break;
		case CANCEL:
			*decidetext = '\0';
			system("cls");
			break;
		default:
			strcpy(decidetext, inputtext);
			system("cls");
			break;
		}
		/*表示と一時ファイルへの書き込み*/
		PrintScreen(decidetext);
	}
	system("cls");
	*decidetext = '\0';
	PrintScreen(decidetext);

	/*ファイル出力*/
	FileWrite();
	FileTweetWrite();
	return 0;
}
