#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto_h.h"


struct Lista *cria_pilha(lista *pilha)
{
    lista *novo;
    lista *aux;
    int numero_temp;


    novo = (lista*)malloc(sizeof(lista));


    printf("\nDigite um Numero para a lista");
    scanf("%d",&numero_temp);

    novo->numero = numero_temp;
    novo->prox = NULL;

    aux = pilha;

    if(aux == NULL)
    {
        pilha = novo;
    }
    else
    {
        while(aux->prox !=NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }


    return(pilha);
};
