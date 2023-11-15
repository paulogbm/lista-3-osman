#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
struct Node {
    int data;
    struct Node *next;
};

// Função para criar um novo nó com um valor específico
struct Node *criarNovoNo(int valor) {
    struct Node *novoNo = (struct Node *)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novoNo->data = valor;
    novoNo->next = NULL;
    return novoNo;
}

// Função para inserir um elemento na lista de forma ordenada
void inserirListaOrdenada(struct Node **head, int valor) {
    struct Node *novoNo = criarNovoNo(valor);
    struct Node *atual = *head;
    struct Node *anterior = NULL;

    // Encontre a posição correta para inserir o novo nó
    while (atual != NULL && atual->data < valor) {
        anterior = atual;
        atual = atual->next;
    }

    // Caso especial: o novo nó será o primeiro da lista
    if (anterior == NULL) {
        novoNo->next = *head;
        *head = novoNo;
    } else {
        // Inserção entre dois nós existentes ou no final da lista
        anterior->next = novoNo;
        novoNo->next = atual;
    }
}

// Função para imprimir a lista
void imprimirLista(struct Node *head) {
    struct Node *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL\n");
}

// Função para liberar a memória alocada para a lista
void liberarLista(struct Node *head) {
    struct Node *atual = head;
    while (atual != NULL) {
        struct Node *temp = atual;
        atual = atual->next;
        free(temp);
    }
}

int main() {
    struct Node *lista = NULL;
    int tamanho;
    int i;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    for (i = 0; i < tamanho; i++) {
        int valor;
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        inserirListaOrdenada(&lista, valor);
    }

    printf("Lista ordenada: ");
    imprimirLista(lista);

    // Liberar a memória alocada para a lista
    liberarLista(lista);

    return 0;
}

