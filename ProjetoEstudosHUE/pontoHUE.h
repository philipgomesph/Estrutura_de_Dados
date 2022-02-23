#ifndef PONTOHUE_H_INCLUDED
#define PONTOHUE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct pessoa
{
    char nome[30];
    int idade;
    struct pessoa *prox;
    struct pessoa *ant;

};

struct pilha
{
    char nome[30];
    int numero;
    struct pilha *prox;
};
struct fila
{
    char nome[30];
    int senha;
    struct fila *prox;
};


///LISTA
struct pessoa *inserir(struct pessoa *lista);
void mostrar(struct pessoa *lista);
struct pessoa *removerInicio(struct pessoa *lista);
struct pessoa *removerFim(struct pessoa *lista);

///PILHA
struct pilha *inserirPilha(struct pilha *pilha);
struct pilha *removerPilha(struct pilha *pilha);
void mostrarPilha(struct pilha *pilha);

///FILA
struct fila *inserirFila(struct fila *alguem);
struct fila *removerFila(struct fila *alguem);
///void mostraFila(struct fila *alguem);   //Vou utilizar a mesma funçao de mostrar a "lista", funciona do mesmo jeito.

///RECURSAO



#endif // PONTOHUE_H_INCLUDED
