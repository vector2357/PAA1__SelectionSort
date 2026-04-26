#include <stdio.h>
#include <stdlib.h>

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
    newNode->next = (*head_ref)->next;
    (*head_ref)->next = newNode;
}

// Função para remover valor da lista
int removeNode(Node** head_ref, int value) {
    if (*head_ref == NULL) {
        printf("Nao e possivel remover, a lista esta vazia!");
        return 0;
    }
    Node* last = *head_ref;
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
        Node* minPrev = sortedTail;
        Node* minNode = sortedTail->next;
        
        Node* currPrev = sortedTail->next;
        Node* curr = currPrev->next;

        // Varre o restante da lista para encontrar o menor elemento
        while (curr != NULL) {
            if (curr->data < minNode->data) {
                minNode = curr;
                minPrev = currPrev;
            }
            currPrev = curr;
            curr = curr->next;
        }

        // Se o menor nó não for o primeiro da parte não ordenada, precisamos movê-lo
        if (minNode != sortedTail->next) {
            // 1. Desconecta o menor nó de sua posição atual
            minPrev->next = minNode->next;
            
            // 2. Reconecta o menor nó logo após o final da parte ordenada
            minNode->next = sortedTail->next;
            sortedTail->next = minNode;
        }
        
        // Avança o limite da parte ordenada
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

    // Populando a lista com valores desordenados
    insertBack(&head, 64);
    insertBack(&head, 25);
    insertBack(&head, 12);
    insertBack(&head, 22);
    insertBack(&head, 11);

    printf("--- Selecao Direta em Lista Encadeada ---\n\n");

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