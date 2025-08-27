//last in first out

#include<stdio.h>
#include<stdlib.h>

typedef struct Celula {
    int valor;
    struct Celula *proximo;
} Celula;


typedef struct {
    int qtde;
    Celula *topo;
} Pilha;


Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula)); // malloc vem do stdlib    
    nova -> proximo = NULL;
    nova -> valor = valor;
    return nova; //devolve o endereço dela p/ quem pediu
}


Pilha *criar_pilha(){
    Pilha *nova = malloc(sizeof(Pilha));
    nova->qtde = 0;
    nova->topo = NULL;
    return nova;
}

// celula: valor e proximo  
// pilha: qtde e topo
void push(Pilha *pilha, int valor){
    Celula *nova = criar_celula(valor);
    nova->proximo = pilha->topo; // salva o antigo topo como o próximo da nova celula [antigo: 9 | novo: 10 | anteriores <- 9 <- 10]
    pilha->topo = nova;          // nova celula se torna o topo da pilha
    pilha->qtde++;
}

int pop(Pilha *pilha){
    if(pilha->qtde == 0){
        return -1; // sem valor p/ ser retirado
    }
    int valor = pilha->topo->valor; //pilha aponta p/ endereço do topo que pega o valor da celula
    Celula *temp = pilha->topo;     // temporário aponta p/ endereço do topo
    pilha->topo = pilha->topo->proximo; // a celula anterior do topo se torna o novo topo
    free(temp);                         // libera a memoria do temp
    pilha->qtde--;
    return valor;
}

void imprimir(Pilha *pilha){
    Celula *atual = pilha->topo; // começa do topo
    printf("TOPO -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo; // aponta pro proximo ate não ter mais ponteiro (null) | anteriores <- 9 <- 10
    }
    printf(" <- BASE\n");
}

int main(){
    Pilha *pilha = criar_pilha();
    for(int i = 0; i < 10; i++){
        push(pilha, i);
        imprimir(pilha);
    }
    for(int i = 0;i<10;i++){
        printf("Valor do topo (valor removido): %d\n", pop(pilha));
        imprimir(pilha);
    }
    return 0;
}