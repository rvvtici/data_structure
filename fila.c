// head começo da fila, tail final da fila. 
// first in first out (fifo). 
// pilha lifo (last in first out)
// dequeue = desenfileiramento

//alocacao dinamica de memoria. lab.

#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula da lista duplamente ligada
typedef struct Celula {
	int valor;					// Valor armazenado na célula
	struct Celula *proximo;		// Ponteiro para o próximo elemento
	struct Celula *anterior;	// Ponteiro para o elemento anterior
} Celula;

// Estrutura da fila com ponteiros para início e fim
typedef struct {
	Celula *head;	// Ponteiro para o primeiro elemento (início da fila)
	Celula *tail;	// Ponteiro para o último elemento (fim da fila)
	int qtde;		// Contador de elementos na fila
} Queue;

// Cria uma nova célula com o valor especificado
Celula *criar_celula(int valor){
	// Implementar
    Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->anterior = NULL;
    nova->valor = valor;
    return nova;
}

// Cria uma nova fila vazia
Queue *criar_queue(){
	// Implementar
    Queue *fila = malloc(sizeof(Queue));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
    return fila;
}

// Operação ENQUEUE: insere elemento no final da fila (FIFO)

// celula: anterior, proximo e valor;
// fila: head, tail e qtde;
void enqueue(Queue *fila, int valor){
	// novo valor sempre tem anterior nulo e aponta pra frente da fila 
    Celula *nova = criar_celula(valor);
    // Celula *anterior = NULL;
    // Celula *atual = fila->head; //aponta p/ primeiro da fila
    Celula*atual = NULL;

    if(fila->qtde == 0){
        fila->tail = nova;
        fila->head = nova;
    } else {
        atual = fila->tail;
        atual->proximo = nova;
        nova->anterior = atual;
        fila->tail = nova;
    }

    // while(atual != NULL) {//msm logica do lde. p percorrer o while pelo menos
    // // uma vez, a fila deve possuir 1+ elemento

    // // [/ | 5 | o ] ------------------ [o | 8 | / ]
    // // anterior: null, proximo: 8  --- anterior: 5, proximo: NULL
    // // começo->5,8<-final 
    // //atual = 5 (head)   
    //     anterior = atual;
    //     atual = atual->proximo;
    // }        
    
    // // fila vazia:
    // if(atual == NULL){
    //     atual = nova;
    //     if(fila->qtde==0){
    //         fila->head = atual;
    //     } else {
    //         anterior->proximo = nova;
    //         fila->tail = nova;
    //         nova->anterior = anterior;
    //     }
    // }
    fila->qtde++;
}

// // Operação DEQUEUE: remove elemento do início da fila (FIFO)
int dequeue(Queue *fila){
// 	// Implementar
    // Celula *atual = fila->tail; //pega o ultimo valor da fila
    // Celula *atual = NULL;
    Celula *proximo = NULL;
    // Celula *anterior = atual->anterior; //valor na frente do ultimo

    Celula *atual = fila->head;
    int valor = atual->valor;
    
    if(fila->qtde <= 1){
        atual = fila->head;        
        printf("Valor removido: %d, Fila restante: ", atual->valor);
        free(atual);
        fila->tail = NULL;
        fila->head = NULL;
    } else {
        atual = fila->head;
        proximo = atual->proximo;
        printf("Valor removido: %d, Fila restante: ", atual->valor);
        free(atual);
        fila->head = proximo;
        proximo->anterior = NULL;
    }




    // while (anterior != NULL) {
    //     atual = anterior;
    //     anterior = atual->anterior;
    // }
    // anterior = atual->proximo;
    // anterior->anterior = NULL;
    // fila->head = anterior;

    // atual->anterior = NULL;

    // printf("Valor removido: %d, Fila restante: ", atual->valor);
    // free(atual);
    // // ultimo(free);

    fila->qtde--;
    return valor;
}

// Exibe todos os elementos da fila (do início ao fim)
void show(Queue *fila){
    // if (fila->head == NULL) {
    //     printf(" ");
    //     return;
    // } 
    Celula *atual = fila->head;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(void) {
    printf("=== INSERINDO ELEMENTOS ===\n");
	Queue *fila = criar_queue();
    int numbers[] = {10,2,0,4,5,5,6,2,8,1,9};
    for(int i = 0; i <= 10; i++){
        printf("Inserido %d: ", numbers[i]);
        enqueue(fila, numbers[i]);
        show(fila);
    }
    printf("\n=== REMOVENDO ELEMENTOS ===\n");
    for(int i = 0; i <= 10; i++){
        // printf("Valor removendo, %d: ", i);
        dequeue(fila);
        show(fila);
    }
	
	return 0;
}