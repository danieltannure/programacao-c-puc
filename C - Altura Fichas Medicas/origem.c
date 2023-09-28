//Nome: Daniel Acosta Brazil Ventura Tannure
//Matrícula: 2112182
//Turma:33A
#include <stdio.h>

typedef struct medidas Medidas;
typedef struct patient Patient;

int buscaBinaria(int tamanho, Patient* b, float altura);
int compara(float altura, float vetorAltura);

struct medidas {
    float altura;
    float peso;
};

struct patient {
    char nome[50];
    Medidas informacoes;
};
int main(void) {
    //Configuração Inicial

    Patient d[] =
    {
    {"Lucy",{1.70,40}}, {"Pedro",{1.70,75}}, {"Eduardo",{1.70,80}}, {"Tito",{1.80,50}}, {"Alga",{1.80,75}},
    {"Alice",{1.90,60}}, {"Marcos",{2.00,50}}, {"Nivia",{2.00,55}}
    };

    Patient* v[] = { d, d + 1, d + 2, d + 3, d + 4, d + 5, d + 6,d+7 };
    int n = sizeof(v) / sizeof(v[0]);
    for (int i = 0; i < n; i++) {
        printf("%-10s %.2f %.1f\n", v[i]->nome, v[i]->informacoes.altura,
            v[i]->informacoes.peso);
    }

    //Testes

    float altura1 = 1.70;
    int indice = buscaBinaria(8,*v, altura1);
    printf("Registro de menor peso com altura %.2f:\t%-10s %.2f %.1f\n", altura1, v[indice]->nome, v[indice]->informacoes.altura,
        v[indice]->informacoes.peso);

    float altura2 = 2.00;
    indice = buscaBinaria(8,*v, altura2);
    printf("Registro de menor peso com altura %.2f:\t%-10s %.2f %.1f\n", altura2, v[indice]->nome, v[indice]->informacoes.altura,
        v[indice]->informacoes.peso);
    putc('\n',stdout);
    printf("TESTES NEGATIVOS:\n");
    
    float altura3 = 2.50;
    indice = buscaBinaria(8, *v, altura3);
    if (indice == -1) {
        printf("Nao possivel encontrar um paciente com a altura de %.2f\n", altura3);
    }

    float altura4 = 1.20;
    indice = buscaBinaria(8, *v, altura4);
    if (indice == -1) {
        printf("Nao possivel encontrar um paciente com a altura de %.2f\n", altura4);
    }


    return 0;
}

int buscaBinaria(int tamanho, Patient* b, float altura) {
    int ini = 0;
    int meio;
    int fim = tamanho - 1;
    int num;
    while (ini <= fim) {
        meio = ini + fim / 2;
        num = compara(altura, b[meio].informacoes.altura);
        
        if (num == 0) {
            while (meio > 0 && compara(altura, b[meio - 1].informacoes.altura) == 0) {
                meio--;
            }
            return meio;
        }
        else if (num == -1) {
            fim = meio - 1;
        }
        else if (num == 1) {
            ini = meio + 1;
        }
        
    }
    return -1;
}

int compara(float altura, float vetorAltura) {
    if (altura < vetorAltura) {
        return -1;
    }
    else if (altura > vetorAltura) {
        return 1;
    } 
    else {
        return 0;
    }
};