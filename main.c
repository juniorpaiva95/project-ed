#include "biblioteca.h"
int main()
{
    int qtde,origem;
    Lista l1;

    criar(&l1);

    printf("Informe quantos soldados deseja inserir [ ]\b\b");
    scanf("%d",&qtde);
    if(povoar(&l1,qtde)){
      printf("\nSoldados armazenados com sucesso!\n");
    }else{printf("Dado inválido!"); return 0;}
    imprimir(l1);
    printf("%d",buscar(l1,'B'));

    printf("Informe a posicao de origem [ ]\b\b");
    scanf("%d",&origem);


}
