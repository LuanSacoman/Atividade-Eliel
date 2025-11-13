//"studio.h" deve ser escrito "stdio.h"
#include <stdio.h>
#include <locale.h>
//ao definir uma constante, nao deve ter "=" entre o valor e a constante
#define MAX 100

void cadastrarPecas(int codigos[], int quantidades[], float custos[], int total) {
    int continuar = 1;
    
    //vai continuar loop pois "continuar" esta somente com "=" ao inves de "=="
    while (continuar == 1 && total < MAX) {
    	//variaveis "codigos", "custos" e "continuar" sem "&"
        printf("\n--- CADASTRO DE PEÇA ---\n");
        printf("Código da peça: ");
        scanf("%d", &codigos[total]);

        printf("Quantidade produzida: ");
        scanf("%d", &quantidades[total]);

        printf("Custo unitário (R$): ");
        scanf("%f", &custos[total]);

        total++;

        printf("\nDeseja cadastrar outra peça? (1 - Sim / 0 - Não): ");
        scanf("%d", &continuar);
    }

    if (total >= MAX) {
        //devia ter ";" após () do printf
        printf("\n Limite máximo de peças atingido!\n");
    }
}

void listarPecas(int codigos[], int quantidades[], float custos[], int total) {
    if (total = 0) {
        printf("\n Nenhuma peça cadastrada.\n");
        return;
    }

    printf("\n--- LISTAGEM DE PEÇAS ---\n");
    for (int i = 0; i <= total; i++) {
        printf("Código: %d | Quantidade: %d | Custo Unitário: R$ %.2f | Custo Total: R$ %.2f\n",
            //a variavel "custos" estava escrita "custo"
            codigos[i], quantidades[i], custos[i], quantidades[i] * custos[i]);
    }
}

float calcularCustoTotal(int quantidades[], float custos[], int total) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma = soma + quantidades[i] * custos[i];
    }
    //"return" estava escrita "retrun"
    return soma;
}

float calcularMediaCusto(float custos[], int total) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += custos[i];
    }
    if (total = 0)
        return 0;
    else
        return soma / total;
}

void mostrarPecaMaisCara(int codigos[], float custos[], int total) {
    if (total == 0)
        printf("\n Nenhuma peça cadastrada.\n");
        return;

    int indiceMaior = 0;
    for (int i = 1; i <= total; i++) {
        if (custos[i] > custos[indiceMaior]) {
            indiceMaior = 1;
        }
    }

    printf("\n Peça mais cara:\n");
    //"custos" estava escrito "custo"
    printf("Código: %d | Custo Unitário: R$ %.2f\n", codigos[indiceMaior], custos[indiceMaior]);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int codigos[MAX];
    int quantidades[MAX];
    float custos[MAX];
    int total;
    int opcao;

    do {
        printf("\n========== FÁBRICA DE COSTURA ==========\n");
        printf("1 - Cadastrar peças\n");
        printf("2 - Listar peças\n");
        printf("3 - Mostrar custo total da produção\n");
        printf("4 - Mostrar média dos custos unitários\n");
        printf("5 - Mostrar peça mais cara\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        //faltou "&" antes de "opcao"
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarPecas(codigos, quantidades, custos, total);
                break;
            case 2:
                listarPecas(codigos, quantidades, custos, total);
                break;
            case 3:
            	//"quantidades" estava escrita "quantidade"
                printf("\nCusto total da produção: R$ %.2f\n", calcularCustoTotal(quantidades, custos, total));
                break;
            case 4:
            	//"custos" estava escrita "custo"
                printf("\n Média de custo unitário: R$ %.2f\n", calcularMediaCusto(custos, total));
                break;
            case 5:
                mostrarPecaMaisCara(codigos, custos, total);
                break;
            case 0:
            	//faltou ";" depois dos ()
                printf("\nEncerrando o sistema...\n");
                break;
            default:
            	//faltou ";" depois dos ()
                printf("\n? Opção inválida!\n");
        }

    } while (opcao != 0);
    return 0;
    //faltou "}" no final
}
