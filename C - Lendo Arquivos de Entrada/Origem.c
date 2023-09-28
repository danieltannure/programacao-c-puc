#include <stdio.h>

#include "analise.h"


int main(void) {

	int entrada;
	entrada = getc(stdin);

	int  ncaracter;
	ncaracter = 0;

	int  nnewline;
	nnewline = 0;

	int  nlinha;
	nlinha = 1;

	int quebralinha;
	quebralinha = 0;

	while (entrada != EOF) {
		ncaracter++;

		if (quebralinha == 1) {
			nlinha++;
			quebralinha = 0;
		}
		if (entrada == '\n') {
			nnewline++;
			quebralinha = 1;
		}
		putc(entrada, stdout);
		entrada = getc(stdin);
	}

	float media;
	media = caracterPorlinha(ncaracter, nlinha);
	
	printf("ARQUIVO LEITURA: caracteres= %d, caracteres tipo new line= %d e linhas= %d\nMedia caracteres por linha: %.1f", ncaracter,nnewline,nlinha,media);
	return 0;
}
