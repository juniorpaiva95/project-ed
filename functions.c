#include "biblioteca.h"

boolean vazia(Lista lst){
    return lst == NULL;
}

void criar(Lista *lst){
    *lst = NULL;
}

boolean inserir(Lista *lst, char dado){
    No* aux = *lst;///Aux ir� receber o ponteiro pro come�o da lista
    No* novo;///Novo n�

    if(vazia(*lst)){///Se tiver vazia ir� entrar no bloco
        if((novo = (No*)malloc(sizeof(No)))==NULL)return false;///Validando se conseguiu criar o novo n�
        novo->dado = dado;///Guardando o dado no novo n�
        *lst = novo;///O ponteiro que guarda o inicio da lista ir� deixar de apontar pra NULL e guardar� o novo n�
        novo->prox = (*lst);///Campo pr�ximo do n� inserido ir� receber o pr�pio n�
        return true;
    }
    if((novo = (No*)malloc(sizeof(No)))==NULL)return false;///Validando se conseguiu criar o novo n�
    novo->dado = dado;///Guardando o dado no novo n�

    while(aux->prox != (*lst)){///Percorrendo a lista at� chegar ao final
        aux = aux->prox;///Percorrendo at� o final. Quando a condi��o do while falhar a variavel estar� guardando o ultimo n�.
    }
    aux->prox = novo;///Campo pr�ximo ir� receber o novo n�
    novo->prox = (*lst);///Ultimo n� ir� apontar pro come�o da lista ou seja o primeiro elemento.
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
