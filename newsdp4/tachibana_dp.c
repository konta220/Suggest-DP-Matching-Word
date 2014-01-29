/*
 * tachibana.c
 *
 *  Created on: 2014/01/17
 *      Author: cs12051
 *
 */
/*TODO
 * �E���͔��p���������񂪑Ή����Ă��Ȃ��̂ŁA�����I�ɑS�p�ɑΉ��ł���悤�Ɋ撣�邱�ƁB
 */
#include "tachi_hedder.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void maketable(char *, char *);
int calcMinCost();
void calclocalcost(int, int);
void initCostRank();
void insertsortbyRank(int, int);
int tablecalc(char *, char *);

int rsize;
int csize;

/*DP�}�b�`���O */
void DPmatching(char *intxt) {
	int i;
	int dpcost;
	initCostRank();
	for (i = 0; i < line_count; i++) {
		csize = strlen(intxt);
		rsize = strlen(pattern[i].read);
		maketable(intxt, pattern[i].read);

		dpcost = calcMinCost();
		insertsortbyRank(dpcost, i);
	}
}

void initCostRank() {
	int i;
	for (i = 0; i < RANKSIZE; i++) {
		costRank[i].patternnunber = -1;
		costRank[i].costs = 9999; /*�߂��Ⴍ����傫�Ȑ��ŏ�����*/
	}
}

/*DP�}�b�`���O�ɗp����\���쐬*/
void maketable(char *txt1, char *txt2) {
	char *txt1pointer;
	int i = 0, j = 0;
	txt1pointer = txt1;
	while (*txt2 != '\0') {
		while (*txt1pointer != '\0') {
			table[i][j] = tablecalc(txt1pointer, txt2);/*�e�[�u���̊e�}�X�̒l�����߂�*/
			j++;
			txt1pointer++;
		}
		i++;
		txt2++;
		txt1pointer = txt1;
		j = 0;
	}
#if defined(debug)

	printf("Tables:\n");
	for (i = 0; i < rsize; i++) {
		for (j = 0; j < csize; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
#endif

}
/*�e�[�u�����ł̍��ォ��E���܂ł̍ŏ��R�X�g�����߂�
 * ���ォ��E���܂�1�}�X���v�Z���Ă���
 * */
int calcMinCost() {
	int i, j;
	for (i = 0; i < rsize; i++) {
		for (j = 0; j < csize; j++) {
			if (i == 0 && j == 0) {
				cost[0][0].mincost = table[0][0];
				cost[0][0].leftdir = 0;
				cost[0][0].updir = 0;
			} else {
				calclocalcost(i, j);
			}
		}
	}
	if (csize > rsize) {
		return cost[rsize - 1][csize - 1].mincost;
	}
	return cost[csize - 1][csize - 1].mincost;
}

/*����1�}�X�܂ł̍ŏ��R�X�g�����߂�
 * ������A�ォ��A���΂ߏォ�炻�̃}�X�ɂ��ǂ蒅���܂ł̃R�X�g���v�Z��
 * �ǂ̃p�^�[��������ԏ������������߂�B
 * */
void calclocalcost(int i, int j) {
	cost[i][j].mincost = 9999999;
	if (i != 0) {
		int c = cost[i - 1][j].mincost + 1 + table[i][j];
		cost[i][j].mincost = c;
		cost[i][j].updir = 1;
		cost[i][j].leftdir = 0;
	}
	if (j != 0) {
		int c = cost[i][j - 1].mincost + 1 + table[i][j];
		if (cost[i][j].mincost > c) {
			cost[i][j].mincost = c;
			cost[i][j].updir = 0;
			cost[i][j].leftdir = 1;
		}
	}
	if (i != 0 && j != 0) {
		int c = cost[i - 1][j - 1].mincost + table[i][j];
		if (cost[i][j].mincost > c) {
			cost[i][j].mincost = c;
			cost[i][j].updir = 1;
			cost[i][j].leftdir = 1;
		}
	}
}

/*TODO
 * ���͕����R�[�h�̍�����DP�}�b�`���O�̃e�[�u��������Ă��邪�A�����I�ɂǂ����邩�l���邱��
 * (�L�[�{�[�h�̔z����l���������̂ɂ���́H�ق��̃A���S���Y���H)
 */
int tablecalc(char *c1, char *c2) {
	int answer;
	answer = *c1 - *c2;
	//printf("c1:%c c2:%c ans:%d\n",*c1,*c2,abs(answer));
	return abs(answer);
}

void insertsortbyRank(int rank, int patternnum) {
	int i, j;
	i = RANKSIZE - 1;
	while (i >= 0 && rank <= costRank[i].costs) {
		i--;
	}
	for (j = RANKSIZE - 2; j > i; j--) {
		costRank[j + 1] = costRank[j];
	}
	if (i >= j) {
		costRank[i + 1].costs = rank;
		costRank[i + 1].patternnunber = patternnum;
	}

	for (i = 0; i < RANKSIZE; i++) {
		//printf("%d��:%s cost=%d\n",i,pattern[costRank[i].patternnunber].word,costRank[i].costs);
	}
}
