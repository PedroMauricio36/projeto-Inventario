#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct para Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Struct para No na lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Para vetor
Item mochilaVetor[10];
int numItensVetor = 0;

// Para lista encadeada
No* cabecaLista = NULL;

// Funcao para converter string para maiusculo
void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// --- Funcoes para Vetor ---

// Inserir item no vetor
void inserirItemVetor() {
    if (numItensVetor >= 10) {
        printf("Mochila cheia!\n");
        return;
    }
    Item novo;
    printf("\nNome: ");
    scanf("%29s", novo.nome);
    toUpperCase(novo.nome);  // Converte para maiusculo
    printf("Tipo: ");
    scanf("%19s", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    mochilaVetor[numItensVetor] = novo;
    numItensVetor++;
    printf("\nAdicionado!\n");
}

// Remover item por nome no vetor
void removerItemVetor() {
    char nome[30];
    printf("Nome a remover: ");
    scanf("%29s", nome);
    toUpperCase(nome);
    int encontrado = 0;
    for (int i = 0; i < numItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < numItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            numItensVetor--;
            printf("Removido!\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("Nao encontrado!\n");
}

// Listar itens no vetor
void listarItensVetor() {
    if (numItensVetor == 0) {
        printf("Vazia!\n");
        return;
    }
    printf("\n=================================\n  ITEM    |   TIPO    |   QTD\n=================================");
    printf("\nQuantidade de itens na mochila: %d/10\n", numItensVetor);
    for (int i = 0; i < numItensVetor; i++) {
        printf("\n%s | %s | %d", (mochilaVetor[i].nome), mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
    }
}

// Ordenar vetor por nome (Bubble Sort)
void ordenarVetor() {
    for (int i = 0; i < numItensVetor - 1; i++) {
        for (int j = 0; j < numItensVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                Item temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    printf("\nOrdenado!\n");
}

// Busca sequencial no vetor com contador
void buscarSequencialVetor(int* comparacoes) {
    char nome[30];
    printf("Nome a buscar: ");
    scanf("%29s", nome);
    toUpperCase(nome);
    *comparacoes = 0;
    for (int i = 0; i < numItensVetor; i++) {
        (*comparacoes)++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Encontrado: %s, %s, %d\n", mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
            return;
        }
    }
    printf("Nao encontrado!\n");
}

// Busca binaria no vetor (apos ordenacao) com contador
void buscarBinariaVetor(int* comparacoes) {
    char nome[30];
    printf("Nome a buscar: ");
    scanf("%29s", nome);
    toUpperCase(nome);
    *comparacoes = 0;
    int esq = 0, dir = numItensVetor - 1;
    while (esq <= dir) {
        (*comparacoes)++;
        int meio = esq + (dir - esq) / 2;
        int cmp = strcmp(mochilaVetor[meio].nome, nome);
        if (cmp == 0) {
            printf("Encontrado: %s, %s, %d\n", mochilaVetor[meio].nome, mochilaVetor[meio].tipo, mochilaVetor[meio].quantidade);
            return;
        } else if (cmp < 0) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    printf("Nao encontrado!\n");
}

// --- Funcoes para Lista Encadeada ---

// Inserir item na lista (fim)
void inserirItemLista() {
    No* novo = (No*)malloc(sizeof(No));
    printf("Nome: ");
    scanf("%29s", novo->dados.nome);
    toUpperCase(novo->dados.nome);
    printf("Tipo: ");
    scanf("%19s", novo->dados.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);
    novo->proximo = NULL;
    if (cabecaLista == NULL) {
        cabecaLista = novo;
    } else {
        No* temp = cabecaLista;
        while (temp->proximo != NULL) temp = temp->proximo;
        temp->proximo = novo;
    }
    printf("\nAdicionado!\n");
}

// Remover item por nome na lista
void removerItemLista() {
    char nome[30];
    printf("Nome a remover: ");
    scanf("%29s", nome);
    toUpperCase(nome);
    No* anterior = NULL;
    No* atual = cabecaLista;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) {
                cabecaLista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Removido!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Nao encontrado!\n");
}

// Listar itens na lista
void listarItensLista() {
    if (cabecaLista == NULL) {
        printf("Vazia!\n");
        return;
    }
    printf("Itens (lista):\n");
    No* temp = cabecaLista;
    while (temp != NULL) {
        printf("%s, %s, %d\n", temp->dados.nome, temp->dados.tipo, temp->dados.quantidade);
        temp = temp->proximo;
    }
}

// Busca sequencial na lista com contador
void buscarSequencialLista(int* comparacoes) {
    char nome[30];
    printf("Nome a buscar: ");
    scanf("%29s", nome);
    toUpperCase(nome);
    *comparacoes = 0;
    No* temp = cabecaLista;
    while (temp != NULL) {
        (*comparacoes)++;
        if (strcmp(temp->dados.nome, nome) == 0) {
            printf("Encontrado: %s, %s, %d\n", temp->dados.nome, temp->dados.tipo, temp->dados.quantidade);
            return;
        }
        temp = temp->proximo;
    }
    printf("Nao encontrado!\n");
}

// Main com menu
int main() {
    int estrutura, opcao, comparacoes;
    while (1) {
        printf("==================\n1-Lista Sequencial\n2-Lista Encadeada\n3-Sair\n==================\nSelecione uma opcao: ");
        if (scanf("%d", &estrutura) != 1) {
            while (getchar() != '\n');
            printf("Invalido!\n");
            continue;
        }
        if (estrutura == 3) break;
        if (estrutura != 1 && estrutura != 2) {
            printf("Invalido!\n");
            continue;

        }

        while (1) {
            printf("\n==================\n      Mochila\n==================\n1-Adicionar Itens\n2-Remover Itens\n3-Listar Itens\n4-Buscar Itens por Nome\n5-Ordenar(Sequencial Apenas)\n6-Busca Binaria(Sequencial Apenas)\n7-Voltar\n\nSelecione uma opcao: ");
            if (scanf("%d", &opcao) != 1) {
                while (getchar() != '\n');
                printf("Invalido!\n");
                continue;
            }
            if (opcao == 7) break;

            if (estrutura == 1) {  // Vetor===Lista Sequencial
                switch (opcao) {
                    case 1: inserirItemVetor(); listarItensVetor(); break;
                    case 2: removerItemVetor(); listarItensVetor(); break;
                    case 3: listarItensVetor(); break;
                    case 4: buscarSequencialVetor(&comparacoes); printf("Comparacoes: %d\n", comparacoes); break;
                    case 5: ordenarVetor(); listarItensVetor(); break;
                    case 6: buscarBinariaVetor(&comparacoes); printf("Comparacoes: %d\n", comparacoes); break;
                    default: printf("Invalido!\n");
                }
            } else {  // Lista Encadeada
                switch (opcao) {
                    case 1: inserirItemLista(); listarItensLista(); break;
                    case 2: removerItemLista(); listarItensLista(); break;
                    case 3: listarItensLista(); break;
                    case 4: buscarSequencialLista(&comparacoes); printf("Comparacoes: %d\n", comparacoes); break;
                    case 5: case 6: printf("Nao disponivel para lista encadeada!\n"); break;
                    default: printf("Invalido!\n");
                }
            }
        }
    }
    // Libera lista
    No* temp = cabecaLista;
    while (temp != NULL) {
        No* prox = temp->proximo;
        free(temp);
        temp = prox;
    }
    return 0;
}