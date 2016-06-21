#include "biblioteca.h"

boolean vazia(Lista lst){
    return lst == NULL;
}

void criar(Lista *lst){
    *lst = NULL;
}

boolean inserir(Lista *lst, char dado){
    No* aux = *lst;///Aux irá receber o ponteiro pro começo da lista
    No* novo;///Novo nó

    if(vazia(*lst)){///Se tiver vazia irá entrar no bloco
        if((novo = (No*)malloc(sizeof(No)))==NULL)return false;///Validando se conseguiu criar o novo nó
        novo->dado = dado;///Guardando o dado no novo nó
        *lst = novo;///O ponteiro que guarda o inicio da lista irá deixar de apontar pra NULL e guardará o novo nó
        novo->prox = (*lst);///Campo próximo do nó inserido irá receber o própio nó
        return true;
    }
    if((novo = (No*)malloc(sizeof(No)))==NULL)return false;///Validando se conseguiu criar o novo nó
    novo->dado = dado;///Guardando o dado no novo nó

    while(aux->prox != (*lst)){///Percorrendo a lista até chegar ao final
        aux = aux->prox;///Percorrendo até o final. Quando a condição do while falhar a variavel estará guardando o ultimo nó.
    }
    aux->prox = novo;///Campo próximo irá receber o novo nó
    novo->prox = (*lst);///Ultimo nó irá apontar pro começo da lista ou seja o primeiro elemento.
}

void imprimir(Lista lst){
    No* aux = lst;
    int cont=1;

    while(cont <= tamanho(lst)){
        printf("(%c) ", aux->dado);
        aux = aux->prox;
        cont++;
    }
}

int tamanho(Lista lst){
    No* aux = lst;
    int cont = 1;
    while(aux->prox != lst){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

boolean povoar(Lista *lst, int qtde){
    char dado = 'A';
    int i;
    if(qtde < 1 || qtde > 26){
        return false;
    }
    for(i =0; i< qtde ;i++){
        inserir(lst,dado++);
    }
    return true;
}
int buscar(Lista lst, char elemento){
    int cont =1;
    No* aux = lst;
    if(vazia(lst))return 0;
    while(cont <= tamanho(lst)){
        if(aux->dado == elemento){
            return cont;
        }
        aux = aux->prox;
        cont++;
    }
    return 0;
}
void execute(Lista *lst){

}
