#include "analise.h"

float caracterPorlinha(int ncaracter, int nlinha) {
		if (ncaracter == 0 || nlinha == 0) {
			printf("O arquivo está vazio");
			exit(1);
		}
	return (float)(ncaracter / nlinha);

}