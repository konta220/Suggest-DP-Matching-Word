#include <stdio.h>

int CheckZenkaku(unsigned char);

/* 1==漢字ではない
 * 0==漢字*/
int CheckKanzi(char *s) {

	/*CheckZenkaku(s[0]);*/

	if (*s < 0xffffff88) {
		/*TRUE ひらがな ローマ字 半角*/
		return 1;
	}

	/* FALSE 漢字 */
	return 0;
}

int CheckZenkaku(unsigned char c) {

	printf("%c ", c);
	if (c & 0x80) {
		printf("全角\n");
		/*TRUE 全角*/
		return 1;
	}
	/*FALSE 半角*/
	printf("半角\n");
	return 0;
}

/*int main(void) {
	char *kanji = "漢字";
	char *hiragana = "ひらがな";
	char *roma = "ローマ";
	char *english = "english";

	CheckKanzi(kanji);
	CheckKanzi(hiragana);
	CheckKanzi(roma);
	CheckKanzi(english);

	return 0;
}*/
