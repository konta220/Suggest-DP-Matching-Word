/*
 * watanabe.c
 *
 *  Created on: 2014/01/17
 *      Author: cs12100
 */

#include "mainhedder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadDictionary() {
	FILE *fp;
	char fname[256] = "worddata.csv";
	int i;

	if ((fp = fopen(fname, "r")) == NULL) {
		printf("ファイルが見つかりません。--- %s\n", fname);
		exit(EXIT_FAILURE);
	}
	printf("ファイルをオープンしました。--- %s\n", fname);

	/*CSVファイルからのデータの入力*/
	for (i = 0;
			fscanf(fp, "%[^,],%s\n", pattern[i].word, pattern[i].read) != EOF;
			i++) {
		line_count++;
	};

	fclose(fp);

	/*入力したCSVファイルの内容を表示*/
	/*for(n = 0; n < line_count; n++)
	 printf("%s %s\n", pattern[i].word, pattern[i].read);
	 */

	/*printf("%d", line_count);*/
}
void Centensdelete() {
	if (head == tail) {
		free(head);
		head = NULL;
		tail = NULL;
	} else {
		tail = tail->before;
		free(tail->after);
		tail->after = NULL;
	}
}
