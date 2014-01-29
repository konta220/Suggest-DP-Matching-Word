#include <stdio.h>

int CheckZenkaku(unsigned char);

/* 1==Š¿Žš‚Å‚Í‚È‚¢
 * 0==Š¿Žš*/
int CheckKanzi(char *s) {

	/*CheckZenkaku(s[0]);*/

	if (*s < 0xffffff88) {
		/*TRUE ‚Ð‚ç‚ª‚È ƒ[ƒ}Žš ”¼Šp*/
		return 1;
	}

	/* FALSE Š¿Žš */
	return 0;
}

int CheckZenkaku(unsigned char c) {

	printf("%c ", c);
	if (c & 0x80) {
		printf("‘SŠp\n");
		/*TRUE ‘SŠp*/
		return 1;
	}
	/*FALSE ”¼Šp*/
	printf("”¼Šp\n");
	return 0;
}

/*int main(void) {
	char *kanji = "Š¿Žš";
	char *hiragana = "‚Ð‚ç‚ª‚È";
	char *roma = "ƒ[ƒ}";
	char *english = "english";

	CheckKanzi(kanji);
	CheckKanzi(hiragana);
	CheckKanzi(roma);
	CheckKanzi(english);

	return 0;
}*/
