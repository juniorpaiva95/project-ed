#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stlist{
    char dado;
    struct stlist *prox;
}No;
typedef enum {false, true}boolean;
typedef No* Lista;
boolean vazia(Lista lst);
void criar(Lista *lst);
void imprimir(Lista lst);
int tamanho(Lista lst);
boolean inserir(Lista *lst, char dado);
boolean povoar(Lista *lst, int qtde);
int buscar(Lista lst,char elemento);

