#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "mainhedder.h"

static void HtmlCreate(FILE *);
static void HtmlResult(FILE *);
/* #ShizuokaUniv #TEST*/

/*int main(void) {
 system("cls");

 FileTweetWrite();
 return 0;
 }*/

static void HtmlResult(FILE *fp) {
	RESULT *current;
	current = head;
	if (head != NULL) {
		do {
			fprintf(fp, "%s", current->content);
			current = current->after;
		} while (current != NULL); /* �t�@�C���ɏ���*/
		/*fprintf(reportfp, NewLineChar);*/
	}
}

static void HtmlCreate(FILE *fp) {
	char *hashtag = "ADII";
	/*char *tweettxt = "[ADII?] �c�C�[�g�͑��v�Ȃ͂��ł�. #test";*/

	/*html header*/
	fprintf(fp, "<!DOCTYPE html>");
	fprintf(fp, "<html>");
	fprintf(fp, "<head>");
	fprintf(fp, "<title>DP�}�b�`���O��p�����\\���ϊ�</title>");
	fprintf(fp, "\n");
	fprintf(fp, "</head>");
	fprintf(fp, "<body>");
	fprintf(fp, "<h1>");
	fprintf(fp, "DP�}�b�`���O��p�����\\���ϊ�</h1>");

	fprintf(fp,
			"<a href=\"https://twitter.com/share\" class=\"twitter-share-button\"");
	fprintf(fp, "data-count=\"none\" data-text=\"");

	/*�c�C�[�g���镶*/
	/*fprintf(fp, tweettxt);*/
	HtmlResult(fp);
	fprintf(fp, "\" data-hashtags=\"");

	/*�n�b�V���^�O*/
	fprintf(fp, hashtag);
	fprintf(fp, "\">tweet</a>");

	/*�m�F�\���p*/
	fprintf(fp, "<h2>");
	/*fprintf(fp, tweettxt);*/
	HtmlResult(fp);
	fprintf(fp, "</h2>");
	fprintf(fp, "<p>");
	fprintf(fp, "�����c�C�[�g���悤");
	fprintf(fp, "</p>");

	fprintf(fp, "\n");
	fprintf(fp, "<hr>");
	fprintf(fp, "<a class=\"twitter-timeline\" ");
	fprintf(fp, "href=\"https://twitter.com/search?q=");
	fprintf(fp, "%%");
	fprintf(fp, "23ADII\"");
	fprintf(fp, "data-widget-id=\"428200306678038529\">#ADII �Ɋւ���c�C�[�g</a>");
	fprintf(fp, "\n");
	fprintf(fp,
			"<a class=\"twitter-timeline\" href=\"https://twitter.com/fukutax\"");
	fprintf(fp, "data-widget-id=\"428197803555184640\">@fukutax ����̃c�C�[�g</a>");
	fprintf(fp, "\n");
	fprintf(fp, "<a class=\"twitter-timeline\"");
	fprintf(fp, "href=\"https://twitter.com/suneo3476Pro/omdete-12\"");
	fprintf(fp,
			"data-widget-id=\"428211596519698432\">https://twitter.com/suneo3476Pro/omdete-12");
	fprintf(fp, "����̃c�C�[�g</a>");
	fprintf(fp, "\n");

	fprintf(fp, "<script>");
	fprintf(fp, "!function(d, s, id) {");
	fprintf(fp, "var js, fjs = d.getElementsByTagName(s)[0], p = /^http:/");
	fprintf(fp, ".test(d.location) ? 'http' : 'https';");
	fprintf(fp, "if (!d.getElementById(id)) {");
	fprintf(fp, "js = d.createElement(s);");
	fprintf(fp, "js.id = id;");
	fprintf(fp, "js.src = p + \"://platform.twitter.com/widgets.js\";");
	fprintf(fp, "fjs.parentNode.insertBefore(js, fjs);");
	fprintf(fp, "}");
	fprintf(fp, "}(document, \"script\", \"twitter-wjs\");");
	fprintf(fp, "</script>");
	fprintf(fp, "\n");
	fprintf(fp, "</body>");
	fprintf(fp, "</html>\n");
}

static void FileTweetOpen(char *savename) {
	FILE *reportfp;
	char *filename;

	strcat(savename, ".html");
	filename = savename;

	/* �t�@�C���̃I�[�v�� */
	/*  �����ŁA�t�@�C���|�C���^���擾���� */
	if ((reportfp = fopen(filename, "w")) == NULL) {
		printf("�t�@�C�����쐬���܂���\n");
	}

	/* �t�@�C���ɏ���*/
	HtmlCreate(reportfp);

	/*fprintf(reportfp, NewLineChar);*/
	fclose(reportfp); /* (5)�t�@�C���̃N���[�Y */
	printf("�u%s�v �t�@�C��\n", filename);
}

/*TODO  �܂Ƃ߂ăt�@�C���ɏ�������*/
void FileTweetWrite() {

	printf("\n �c�C�[�g�pHTML���쐬���܂���.\n");
	FileTweetOpen(GetTime());

	SystemLine();
}
