#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  // para toupper()

// Struct para representar um item no inventario
typedef struct {
    char nome[30];    // Nome do item
    char tipo[20];    // Tipo do item (ex: arma, municao, cura)
    int quantidade;   // Quantidade do item
} Item;

// Vetor para armazenar ate 10 itens
Item mochila[10];
int numItens = 0;     // Contador de itens atuais

// Funcao para inserir um item na mochila
void inserirItem() {
    if (numItens >= 10) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }
    Item novo;
    printf("Digite o nome do item: ");
    scanf("%29s", novo.nome);  // Le nome sem espacos
    for (int i = 0; novo.nome[i] != '\0'; i++) {
        novo.nome[i] = toupper(novo.nome[i]);
    } // Converte nome para maiúsculas
    printf("Digite o tipo do item (ex: arma, municao, cura): ");
    scanf("%19s", novo.tipo);  // Le tipo sem espacos
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    mochila[numItens] = novo;
    numItens++;
    printf("\nItem adicionado com sucesso!\n");
}

// Funcao para remover um item pelo nome
void removerItem() {
    char nome[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%29s", nome);
    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = toupper(nome[i]);
    }
    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];  // Desloca itens para preencher espaco
            }
            numItens--;
            printf("Item removido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nItem nao encontrado!\n");
    }
}

// Funcao para listar todos os itens
void listarItens() {
    if (numItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }
    printf("\nItens na mochila:\n");
    for (int i = 0; i < numItens; i++) {
        printf("\nItem: %s, Tipo: %s, Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Funcao para buscar um item pelo nome (busca sequencial)
void buscarItem() {
    char nome[30];
    printf("Digite o nome do item a buscar: ");
    scanf("%29s", nome);
    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s, Tipo: %s, Qtd: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nItem nao encontrado!\n");
    }
}

int main() {
    int opcao;
    while (1) {
        printf("\n==============\n   Mochila:\n==============\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

               
        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 5:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}