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
		} while (current != NULL); /* ファイルに書く*/
		/*fprintf(reportfp, NewLineChar);*/
	}
}

static void HtmlCreate(FILE *fp) {
	char *hashtag = "ADII";
	/*char *tweettxt = "[ADII?] ツイートは大丈夫なはずです. #test";*/

	/*html header*/
	fprintf(fp, "<!DOCTYPE html>");
	fprintf(fp, "<html>");
	fprintf(fp, "<head>");
	fprintf(fp, "<title>DPマッチングを用いた予\測変換</title>");
	fprintf(fp, "\n");
	fprintf(fp, "</head>");
	fprintf(fp, "<body>");
	fprintf(fp, "<h1>");
	fprintf(fp, "DPマッチングを用いた予\測変換</h1>");

	fprintf(fp,
			"<a href=\"https://twitter.com/share\" class=\"twitter-share-button\"");
	fprintf(fp, "data-count=\"none\" data-text=\"");

	/*ツイートする文*/
	/*fprintf(fp, tweettxt);*/
	HtmlResult(fp);
	fprintf(fp, "\" data-hashtags=\"");

	/*ハッシュタグ*/
	fprintf(fp, hashtag);
	fprintf(fp, "\">tweet</a>");

	/*確認表示用*/
	fprintf(fp, "<h2>");
	/*fprintf(fp, tweettxt);*/
	HtmlResult(fp);
	fprintf(fp, "</h2>");
	fprintf(fp, "<p>");
	fprintf(fp, "さぁツイートしよう");
	fprintf(fp, "</p>");

	fprintf(fp, "\n");
	fprintf(fp, "<hr>");
	fprintf(fp, "<a class=\"twitter-timeline\" ");
	fprintf(fp, "href=\"https://twitter.com/search?q=");
	fprintf(fp, "%%");
	fprintf(fp, "23ADII\"");
	fprintf(fp, "data-widget-id=\"428200306678038529\">#ADII に関するツイート</a>");
	fprintf(fp, "\n");
	fprintf(fp,
			"<a class=\"twitter-timeline\" href=\"https://twitter.com/fukutax\"");
	fprintf(fp, "data-widget-id=\"428197803555184640\">@fukutax からのツイート</a>");
	fprintf(fp, "\n");
	fprintf(fp, "<a class=\"twitter-timeline\"");
	fprintf(fp, "href=\"https://twitter.com/suneo3476Pro/omdete-12\"");
	fprintf(fp,
			"data-widget-id=\"428211596519698432\">https://twitter.com/suneo3476Pro/omdete-12");
	fprintf(fp, "からのツイート</a>");
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

	/* ファイルのオープン */
	/*  ここで、ファイルポインタを取得する */
	if ((reportfp = fopen(filename, "w")) == NULL) {
		printf("ファイルを作成しました\n");
	}

	/* ファイルに書く*/
	HtmlCreate(reportfp);

	/*fprintf(reportfp, NewLineChar);*/
	fclose(reportfp); /* (5)ファイルのクローズ */
	printf("「%s」 ファイル\n", filename);
}

/*TODO  まとめてファイルに書き込む*/
void FileTweetWrite() {

	printf("\n ツイート用HTMLを作成しました.\n");
	FileTweetOpen(GetTime());

	SystemLine();
}
