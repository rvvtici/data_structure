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
    struct Celula *anterior; //ponteiro endereço de uma célula
} Celula;

typedef struct LDDE { //lista
    int qtde;
    Celula *primeiro;
} LDDE;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula)); //malloc = armazenar memoria e sempre retorna um ponteiro
    nova->valor = valor;
    nova->proximo = NULL;
    nova->anterior = NULL;
    return nova;
}

LDDE *criar_lista(){
    LDDE *nova = malloc(sizeof(LDDE)); // alloca um espaço e retorna o endereço dele. como *nova é um ponteiro, possui o endereço dele.
    nova->qtde = 0;                  // se baseando na struct do LDDE, armazena as variaveis "qtde" e "primeiro" nele.
    nova->primeiro = NULL;
    return nova;                     // quem chamou o criar_lista é retornado com o endereço dessa lista
}

void inserir(LDDE *lista, int valor){
    Celula *nova = criar_celula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while(atual != NULL && valor > atual->valor) { // lista nao vazia e valor inserido na celula percorre todos os valores menores doq ele.
        anterior = atual;
        atual = atual->proximo;
    } if(anterior == NULL){ //lista vazia
        // nova->proximo = lista->primeiro;
        lista->primeiro = nova;
    } else {
        nova->proximo = atual;
        nova->anterior = anterior;
        anterior->proximo = nova;
        if (atual != NULL) { // *nova n é o final da lista
            atual->anterior = nova;
        }
    }
    lista->qtde++;
}


//arrumar o remover caso seja ultimo/primeiro valor...
int remover (LDDE *lista, int valor){ //int p/ retornar o valor e printa-lo dps
    Celula *anterior = NULL;
    Celula*atual = lista->primeiro;
    if(lista->qtde == 0){
        return -1;
    }
    while(atual != NULL && valor > atual->valor) {
        anterior = atual;
        atual = atual->proximo;
    } 
    anterior->proximo = atual->proximo;
    atual->proximo->anterior = anterior;
    free(atual);

    lista->qtde--; 
    return valor;


}



void imprimir(LDDE *lista){ // lista já está na ordem correta, basta imprimir. 
    Celula *atual = lista->primeiro; // 1. endereço atual = primeiro valor
    while(atual != NULL){            // 3. quando não tiver mais ponteiro [ 12 | / ]
        printf("%d ", atual->valor);
        atual = atual->proximo;      // 2. ponteiro atual = ponteiro celula->proximo
    }
    printf("\n");
}

int main(){
    LDDE *lista = criar_lista();  // cria e pega o endereço da lista
    for(int i = 9; i >= 0; i--){  
        inserir(lista, i);
        imprimir(lista);
    }
    for(int i = 9; i >= 0; i--){  
        printf("valor removido: %d\n", remover(lista, i));
        imprimir(lista);
    }
    return 0;
}


//compilar: gcc data.c
//rodar:    ./a.out

//implementar o remover. a cada remover printa.
//lab: LDDE (ponteiro adicional - 3) [ponteiro p/ anterior | valor | ponteiro] (remocao e adicao mais complicados) 