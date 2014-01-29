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
	/*�����t�@�C���̓ǂݍ���*/
	ReadDictionary();
	while (1) {/*enter2��܂ŌJ��Ԃ�*/
		/*����*/
		status = UserInput(inputtext);
		if (status == END)
			break;
		switch (status) {
		case KANA:
			/*DP�}�b�`���O*/
			DPmatching(inputtext);
			/*���[�U�I��*/
			Choose(inputtext, decidetext);
			break;
		case DEL:
			Centensdelete();/*�ł�[�Ɗ֐�*/
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
		/*�\���ƈꎞ�t�@�C���ւ̏�������*/
		PrintScreen(decidetext);
	}
	system("cls");
	*decidetext = '\0';
	PrintScreen(decidetext);

	/*�t�@�C���o��*/
	FileWrite();
	FileTweetWrite();
	return 0;
}
