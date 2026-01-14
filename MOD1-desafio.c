#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int qtdItens = 0;

void inserirItem() {
    if (qtdItens >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    Item novo;
    printf("Nome: ");
    scanf(" %29[^\n]", novo.nome);
    printf("Tipo: ");
    scanf(" %19s", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    
    mochila[qtdItens] = novo;
    qtdItens++;
    printf("Item adicionado.\n");
}

void removerItem() {
    char nome[30];
    printf("Nome do item a remover: ");
    scanf(" %29[^\n]", nome);

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < qtdItens-1; j++)
                mochila[j] = mochila[j+1];
            qtdItens--;
            printf("Item removido.\n");
            return;
        }
    }
    printf("Item nao encontrado.\n");
}

void listarItens() {
    if (qtdItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- MOCHILA (%d/%d) ---\n", qtdItens, MAX_ITENS);
    for (int i = 0; i < qtdItens; i++) {
        printf("%d. %s (%s) x%d\n", 
               i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("---------------------\n");
}

void buscarItem() {
    char nome[30];
    printf("Nome do item: ");
    scanf(" %29[^\n]", nome);

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\nEncontrado:\n");
            printf("%s (%s) x%d\n", 
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }
    printf("Item nao encontrado.\n");
}

int main() {
    int op;

    do {
        printf("\n1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar mochila\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}