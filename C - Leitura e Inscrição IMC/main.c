#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medidas Medida;
typedef struct clientes Cliente;

float bodyMassIndex(Cliente *c, int *status);
Cliente *formaCliente(char *nome, int id, char sexo, float peso, float altura);
float desvioPadrao(Cliente** vetorPonteiro,int tamanho,float mediaIMC);


struct medidas {
  float peso;
  float altura;
};

struct clientes {
  char nome[80];
  int identificacao;
  char genero;
  struct medidas Medidas;
};

int main(void) {
  FILE *arqIn;
  FILE *arqOut;
  int nClientes;
  Cliente *ficha;

  arqIn = fopen("registros.txt", "r");
  if (arqIn == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo");
    exit(29);
  }

  int scan = fscanf(arqIn, "%d", &nClientes);
  if (scan != 1) {
    fprintf(stderr, "Erro ao ler os clientes");
    exit(28);
  }

  arqOut = fopen("dados.dat", "w");
  fwrite(&nClientes, sizeof(int), 1, arqOut);

  ficha = (Cliente *)malloc(nClientes * sizeof(Cliente));

  for (int i = 0; i < nClientes; i++) {
    int n = fscanf(arqIn, "%[^:]: %d %c %f %f", ficha[i].nome,
                   &ficha[i].identificacao, &ficha[i].genero,
                   &ficha[i].Medidas.peso, &ficha[i].Medidas.altura);

    if (n != 5) {
      fprintf(stderr, "nao foi possivel ler todos os dados");
      exit(23);
    }
  }

  int m = fwrite(ficha, sizeof(Cliente), nClientes, arqOut);
  if (m != nClientes) {
    fprintf(stderr, "nao foi possivel inserir os dados no documento");
  }

  fclose(arqOut);
  arqOut = fopen("dados.dat", "r");

  fread(&nClientes, sizeof(int), 1, arqOut);
  fread(ficha, sizeof(Cliente *), nClientes, arqOut);

  int statusCliente = 0;
  int *vetorIMCclientes = (int *)malloc(nClientes * sizeof(int));
  Cliente **fichaDobin = (Cliente **)malloc(sizeof(Cliente *) * nClientes);
  float somaIMC = 0;
  float media=0;

  for (int i = 0; i < nClientes; i++) {
    fichaDobin[i] =
        formaCliente(ficha[i].nome, ficha[i].identificacao, ficha[i].genero,
                     ficha[i].Medidas.peso, ficha[i].Medidas.altura);

    vetorIMCclientes[i] = bodyMassIndex(fichaDobin[i], &statusCliente);
    printf("%s %d %c %.1f %.2f - Status do IMC: %d", ficha[i].nome,
           ficha[i].identificacao, ficha[i].genero, ficha[i].Medidas.peso,
           ficha[i].Medidas.altura, statusCliente);
    somaIMC+=vetorIMCclientes[i];
    }
  puts("\n");
  
  media=somaIMC/nClientes;
  printf("Media IMC: %.2f\n",media);
  printf("Desvio Padrao: %.4f\n",desvioPadrao(fichaDobin,nClientes,media));

  free(ficha);

  for (int i = 0; i < nClientes; i++){
    free(fichaDobin[i]);
  }
  
  fclose(arqIn);
  fclose(arqOut);
  return 0;
}

float bodyMassIndex(Cliente *c, int *status) {
  float imc = (c->Medidas.peso) / pow(c->Medidas.altura, 2);
  if (imc < 25) {
    *status = 0;
  } else {
    *status = 1;
  }
  return imc;
}

Cliente *formaCliente(char *nome, int id, char sexo, float peso, float altura) {
  Cliente *ponteiro = (Cliente *)malloc(sizeof(Cliente));
  for (int num = 0; num < strlen(nome); num++) {
    ponteiro->nome[num] = nome[num];
  }
  ponteiro->identificacao = id;
  ponteiro->genero = sexo;
  ponteiro->Medidas.peso = peso;
  ponteiro->Medidas.altura = altura;
  return ponteiro;
}

float desvioPadrao(Cliente** vetorPonteiro, int tamanho, float mediaIMC) {
    float somatorio = 0;
    int status = 0;
    for (int parte = 0; parte < tamanho; parte++) {
        float imc = bodyMassIndex(vetorPonteiro[parte], &status);
        somatorio += pow(imc - mediaIMC, 2);
    }
    return sqrt(somatorio / tamanho);
}