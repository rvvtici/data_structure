#include<stdio.h>
#include<stdlib.h>

// possibilides:
// 1. lista vazia
// 2. lista não vazia, nova celula = primeiro valor
// 3. lista não-vazia, nova celula = valor no meio   
// 4. lista não-vazia, nova celula = valor no final/depois do final da lista antes




typedef struct Celula {
    int valor;
    struct Celula *proximo; // ponteiro p proximo numero
} Celula;

typedef struct LDE { //lista
    int qtde;
    Celula *primeiro;
} LDE;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula)); //malloc = armazenar memoria e sempre retorna um ponteiro
    nova->valor = valor;
    nova->proximo = NULL;
    return nova;
}

LDE *criar_lista(){
    LDE *nova = malloc(sizeof(LDE)); // alloca um espaço e retorna o endereço dele. como *nova é um ponteiro, possui o endereço dele.
    nova->qtde = 0;                  // se baseando na struct do LDE, armazena as variaveis "qtde" e "primeiro" nele.
    nova->primeiro = NULL;
    return nova;                     // quem chamou o criar_lista é retornado com o endereço dessa lista
}

void inserir(LDE *lista, int valor){
    Celula *nova = criar_celula(valor);             // 1. cria nova celula e o *nova >aponta< para ela
    Celula *anterior = NULL;                        // 2. ponteiro *anterior esvazia-se
    Celula *atual = lista->primeiro;                // 3. ponteiro *atual aponta para primeiro da lista (se ela já tiver algum valor)
    // em nenhum momento o while utiliza o endereço da nova celula, apenas o valor. quando o valor é menor (10) < (12),
    // a celula anterior (8) salva a (12) como atual
    while(atual != NULL && valor > atual->valor){   // 4. lista não-vazia & valor da nova celula (10) > valor atual da lista (8)
        anterior = atual;      // atual vira anterior  5. celula anterior pega todos os valores da celula atual (9 e endereço de memoria)
        atual = atual->proximo;// proximo vira atual   6. atual = ponteiro p/ celula. atual = atual->proximo, ponteiro deve apontar para o
    }                          //                         proximo endereço (que ja estava dentro dele por conta do nova->proximo
    if(anterior == NULL){                           // 7. inserir no começo/lista vazia
        nova->proximo = lista->primeiro;            // 8. ponteiro *próximo da célula nova salva em si o ponteiro *primeiro da lista
        lista->primeiro = nova;                     // 9. ponteiro primeiro aponta p/ celula nova [Celula *atual = lista->primeiro;]
    } else {                                        // 10. lista não-vazia/inserir depois do começo. quando celula (10) < atual da lista (12) 
        anterior->proximo = nova;                   // 11. depois do (8) vem a (10) 
        nova->proximo = atual;                      // 12. endereço do nova->proximo(12)
    }
    lista->qtde++;
}

void imprimir(LDE *lista){ // lista já está na ordem correta, basta imprimir. 
    Celula *atual = lista->primeiro; // 1. endereço atual = primeiro valor
    while(atual != NULL){            // 3. quando não tiver mais ponteiro [ 12 | / ]
        printf("%d ", atual->valor);
        atual = atual->proximo;      // 2. ponteiro atual = ponteiro celula->proximo
    }
    printf("\n");
}

int main(){
    LDE *lista = criar_lista();  // cria e pega o endereço da lista
    for(int i = 9; i >= 0; i--){  
        inserir(lista, i);
        imprimir(lista);
    }
    return 0;
}


//compilar: gcc data.c
//rodar:    ./a.out

//implementar o remover. a cada remover printa.
//lab: LDDE (ponteiro adicional - 3) [ponteiro p/ anterior | valor | ponteiro] (remocao e adicao mais complicados) 