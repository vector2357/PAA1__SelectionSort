#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição das sequências ANSI para cores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"


// Definição da Estrutura da Lista Encadeada Simples
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir no final da lista
void insertBack(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Função para inserir no início da lista
void insertFront(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

// Função para remover valor da lista
int removeNode(Node** head_ref, int value) {
    if (*head_ref == NULL) {
        printf("Nao e possivel remover, a lista esta vazia!");
        return 0;
    }
    Node* last = *head_ref;

    if (last->data == value) {
        Node* aux = last;
        (*head_ref) = last->next;
        free(aux);
        return 1;
    }

    while (last->next != NULL) {
        if (last->next->data == value) {
            Node* aux = last->next;
            last->next = aux->next;
            free(aux);
            return 1;
        }
        last = last->next;
    }
    return 0;
}

int listSize(Node* node) {
    int size = 0;
    
    while (node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}

// Função para exibir a lista
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Função de Ordenação: Seleção Direta com reencadeamento de ponteiros
Node* selectionSortLinkedList(Node* head) {
    if (!head || !head->next) return head; // Lista vazia ou com 1 elemento

    // Nó auxiliar (dummy) para facilitar as manipulações de ponteiros no início
    Node* dummy = createNode(0);
    dummy->next = head;
    
    // Ponteiro que demarca o fim da porção ordenada da lista
    Node* sortedTail = dummy;

    int passo = 1;

    // Enquanto houver elementos na parte não ordenada
    while (sortedTail->next != NULL) {
        // Inicializa a busca pelo menor nó na parte não ordenada
        Node* minNode = sortedTail->next;

        Node* curr = minNode->next;

        // Varre o restante da lista para encontrar o menor elemento
        while (curr != NULL) {
            if (curr->data < minNode->data) {
                minNode = curr;
            }
            curr = curr->next;
        }

        // Se o menor nó não for o primeiro da parte não ordenada, precisamos movê-lo
        if (minNode != sortedTail->next) {
            // Swap dos valores dos nós sortedTail e minNode
            int aux = minNode->data;
            minNode->data = sortedTail->next->data;
            sortedTail->next->data = aux;
        }
        
        sortedTail = sortedTail->next;

        // Exibição durante o processo
        printf("Passo %d: ", passo++);
        printList(dummy->next);
    }

    Node* sortedHead = dummy->next;
    free(dummy);
    return sortedHead;
}

int main() {
    Node* head = NULL;

    printf("--- Selecao Direta em Lista Encadeada ---\n\n");

    // CASO ALEATÓRIO
    printf(ANSI_COLOR_YELLOW "> CASO 1: ALEATORIO\n\n" ANSI_COLOR_RESET);

    srand(time(NULL));

    // Populando a lista com valores aleatórios

    for (int i=0; i<8; i++) {
        int num = rand()%100;
        insertBack(&head, num);
    }

    // Exibição antes da ordenação
    printf("Lista ANTES da ordenacao:\n");
    printList(head);
    printf("\n");

    // Processo de Ordenação
    printf("Lista DURANTE o processo (Passos principais):\n");
    head = selectionSortLinkedList(head);
    printf("\n");

    // Exibição após a ordenação
    printf("Lista APOS a ordenacao:\n");
    printList(head);


    head = NULL;

    // CASO ORDENADO
    printf(ANSI_COLOR_GREEN "\n\n> CASO 2: ORDENADO\n\n" ANSI_COLOR_RESET);

    // Populando a lista com valores ordenados

    for (int i=0; i<8; i++) {
        insertBack(&head, i+1);
    }

    // Exibição antes da ordenação
    printf("Lista ANTES da ordenacao:\n");
    printList(head);
    printf("\n");

    // Processo de Ordenação
    printf("Lista DURANTE o processo (Passos principais):\n");
    head = selectionSortLinkedList(head);
    printf("\n");

    // Exibição após a ordenação
    printf("Lista APOS a ordenacao:\n");
    printList(head);


    head = NULL;

    // CASO DESORDENADO
    printf(ANSI_COLOR_RED "\n\n> CASO 3: DESORDENADO\n\n" ANSI_COLOR_RESET);

    // Populando a lista com valores ordenados

    for (int i=0; i<8; i++) {
        insertBack(&head, 8-i);
    }

    // Exibição antes da ordenação
    printf("Lista ANTES da ordenacao:\n");
    printList(head);
    printf("\n");

    // Processo de Ordenação
    printf("Lista DURANTE o processo (Passos principais):\n");
    head = selectionSortLinkedList(head);
    printf("\n");

    // Exibição após a ordenação
    printf("Lista APOS a ordenacao:\n");
    printList(head);

    return 0;
}