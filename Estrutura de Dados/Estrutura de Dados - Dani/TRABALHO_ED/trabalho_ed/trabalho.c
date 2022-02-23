#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab.h"
#include <locale.h>
lista* inserir(lista *inicio,Func novo)
{

    lista *n = (lista*)malloc(sizeof(lista));
    if (n != NULL)
    {
        n->func = novo;
        n->prox = inicio;
        inicio = n;
    }
    return inicio;
}
void imprimir(lista *inicio)
{
    lista *aux = inicio;
    while (aux != NULL)
    {
        printf("\n=======================================================================\n");
        printf("\nNOME :%s\n",aux->func.nome);
        printf("\nSALARIO: R$ %.2f\n", aux->func.salario);
        printf("\nMATRICULA: %d\n", aux->func.matricula);
        aux = aux->prox;
    }
}
