#include <stdio.h>
#include "header.h"

int main(void) {
	char s[100] = { 'p','@','r','@','l',';','l',';','p','i','p',';','d','o' };
	int contagemEspec;
	int contagemOcorrencia;
	char sAntes = ';';
	char sDepois = 'e';

	contagemEspec = contaChar(s);
	printf("A palavra escaneada foi %s e possui %d caracteres especiais\n", s, contagemEspec);
		
	contagemOcorrencia = mudaChar(s, sAntes, sDepois);
	printf("A string transformada sofreu %d modificações, resultando na nova string: %s\n", contagemOcorrencia, s);
	
	return 1;
}

