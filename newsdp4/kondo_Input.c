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

/*TODO �e�L�X�g�t�@�C���ɏ����o��������ێ����Ă���*/

/* */

int UserInput(char *intxt) {
	/* TODO DP�}�b�`���O�ŉ��s�R�[�h�������K�v������ */
	char *c;
	char command;
	printf("\n>>");
	fgets(intxt, MAXcharsize, stdin);

	if (strlen(intxt) != 1) {
		/*
		 * ���s�R�[�h�폜
		 */
		c = strchr(intxt, '\n');
		*c = '\0';
	}

	if (*intxt == '\n') {
		return 3;
	}

	if (*intxt == ':') {
		system("cls");
		printf("\n���|�[�g�t�@�C���ҏW���j���[\n\n");
		printf("[ESC]:�t�@�C����ۑ����ďI��\n");
		printf("[BackSpace]:�P��폜\n");
		printf("[T]:�c�C�[�g�pHTML�t�@�C���쐬\n");
		printf("[:(�R����)]:�R����(:)�����\n");
		printf("[���̑��̃L�[]:�L�����Z��\n");
		printf("----------�R�}���h����͂��Ă�������---------------\n");
		printf("\nCommand:");

		command = getch();
		switch (command) {
		case 0x8:/*BackSpace �폜*/
			return DEL;
		case 0x1b:/*ESC �I��*/
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

/*�o�͂��镶����͉��������̂�*/
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
 * �t�@�C���A�N�Z�X�Ɋւ���Q�l���
 * URL: http://www9.plala.or.jp/sgwr-t/c/sec17.html */
static void FileOpen(char *savename) {
	FILE *reportfp;
	char *filename;
	RESULT *current;
	strcat(savename, ".txt");

	filename = savename;
	/* �t�@�C���̃I�[�v�� */
	/*  �����ŁA�t�@�C���|�C���^���擾���� */
	if ((reportfp = fopen(filename, "w")) == NULL) {
		printf("�t�@�C�����쐬���܂���\n");
	}

	current = head;
	/* �t�@�C���̏���*/
	if (head != NULL) {
		do {
			fprintf(reportfp, "%s", current->content);
			current = current->after;
		} while (current != NULL); /* �t�@�C���ɏ���*/
		/*fprintf(reportfp, NewLineChar);*/
	}
	fclose(reportfp); /* (5)�t�@�C���̃N���[�Y */
	printf("�u%s�v �t�@�C�����쐬���܂���\n", filename);
}

/*TODO  �܂Ƃ߂ăt�@�C���ɏ�������*/
void FileWrite() {
	SystemLine();
	FileOpen(GetTime());
}
