/*
 * kondo.c
 *
 *  Created on: 2014/01/17
 *      Author: cs12033
 */

#include "mainhedder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define NewLineChar "\n"

/*TODO テキストファイルに書き出す文字を保持しておく*/

/* */

int UserInput(char *intxt) {
	/* TODO DPマッチングで改行コードを消す必要がある */
	char *c;
	char command;
	printf("\n>>");
	fgets(intxt, MAXcharsize, stdin);

	if (strlen(intxt) != 1) {
		/*
		 * 改行コード削除
		 */
		c = strchr(intxt, '\n');
		*c = '\0';
	}

	if (*intxt == '\n') {
		return 3;
	}

	if (*intxt == ':') {
		system("cls");
		printf("\nレポートファイル編集メニュー\n\n");
		printf("[ESC]:ファイルを保存して終了\n");
		printf("[BackSpace]:単語削除\n");
		printf("[T]:ツイート用HTMLファイル作成\n");
		printf("[:(コロン)]:コロン(:)を入力\n");
		printf("[その他のキー]:キャンセル\n");
		printf("----------コマンドを入力してください---------------\n");
		printf("\nCommand:");

		command = getch();
		switch (command) {
		case 0x8:/*BackSpace 削除*/
			return DEL;
		case 0x1b:/*ESC 終了*/
			return END;
		case 0x74:/*T Tweet*/
			return TWEET;
		case 0x3a:
			intxt = ":";
			return 0;
		default:
			intxt = ":";
			return CANCEL;
		}
	}

	return CheckKanzi(intxt);
}

/*出力する文字列は何がいいのか*/
void PrintScreen(char *outtxt) {
	RESULT *current;
	if (*outtxt != '\0') {
		current = (RESULT *) malloc(sizeof(RESULT));
		current->after = NULL;

		if (head == NULL) {
			head = current;
			tail = current;
		} else {
			tail->after = current;
			current->before = tail;
			tail = current;
		}

		strcpy(current->content, outtxt);

	}

	Printscreen_Print();

}

void Printscreen_Print() {
	RESULT *current;
	current = head;
	printf("OUT:");
	if (head != NULL) {
		do {
			printf("%s", current->content);
			current = current->after;
		} while (current != NULL);
	}
	printf("\n");
}

/*TODO
 * ファイルアクセスに関する参考情報
 * URL: http://www9.plala.or.jp/sgwr-t/c/sec17.html */
static void FileOpen(char *savename) {
	FILE *reportfp;
	char *filename;
	RESULT *current;
	strcat(savename, ".txt");

	filename = savename;
	/* ファイルのオープン */
	/*  ここで、ファイルポインタを取得する */
	if ((reportfp = fopen(filename, "w")) == NULL) {
		printf("ファイルを作成しました\n");
	}

	current = head;
	/* ファイルの書き*/
	if (head != NULL) {
		do {
			fprintf(reportfp, "%s", current->content);
			current = current->after;
		} while (current != NULL); /* ファイルに書く*/
		/*fprintf(reportfp, NewLineChar);*/
	}
	fclose(reportfp); /* (5)ファイルのクローズ */
	printf("「%s」 ファイルを作成しました\n", filename);
}

/*TODO  まとめてファイルに書き込む*/
void FileWrite() {
	SystemLine();
	FileOpen(GetTime());
}
