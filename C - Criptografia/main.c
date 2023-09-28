#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void fCrypto(FILE* entrada, FILE* saida);

int main(void) {
	char espaco;
	FILE* arqIn;
	char* nomeArqin[20];
	FILE* arqOut;
	char* nomeArqout = "saida.txt";
	char escolha;


	//printf("Insira o nome do primeiro arquivo:\n");
	//scanf("%s", nomeArqin);
	//scanf("%c", &espaco);

	arqIn = fopen("textoLinhas.txt", "r");
	if (arqIn == NULL) {
		fprintf(stderr, "Falha em abrir o arquivo ");
		exit(230);
	}
	arqOut = fopen(nomeArqout, "w");
	fCrypto(arqIn, arqOut);
	return 0;
}

void fCrypto(FILE* entrada, FILE* saida)
{
	char linha[150];
	char linhanova[150];
	while (!feof(entrada))
	{
		fscanf(entrada, "%[^\n]\n", linha);
		printf("%s\n", linha);

		for (int i = 0; i < strlen(linha); i++)
		{
			linhanova[i] = linha[i] + 1;
			fprintf(saida, "%c", &linhanova[i]);
			//putc('\n', saida);
			printf("%c", linhanova[i]);
			/*
			putchar('\n');
		]*/	
		}
	}
	return;
}
