#include <stdio.h>

int CheckZenkaku(unsigned char);

/* 1==�����ł͂Ȃ�
 * 0==����*/
int CheckKanzi(char *s) {

	/*CheckZenkaku(s[0]);*/

	if (*s < 0xffffff88) {
		/*TRUE �Ђ炪�� ���[�}�� ���p*/
		return 1;
	}

	/* FALSE ���� */
	return 0;
}

int CheckZenkaku(unsigned char c) {

	printf("%c ", c);
	if (c & 0x80) {
		printf("�S�p\n");
		/*TRUE �S�p*/
		return 1;
	}
	/*FALSE ���p*/
	printf("���p\n");
	return 0;
}

/*int main(void) {
	char *kanji = "����";
	char *hiragana = "�Ђ炪��";
	char *roma = "���[�}";
	char *english = "english";

	CheckKanzi(kanji);
	CheckKanzi(hiragana);
	CheckKanzi(roma);
	CheckKanzi(english);

	return 0;
}*/
