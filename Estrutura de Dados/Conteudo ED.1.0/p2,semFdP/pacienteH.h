#ifndef PACIENTEH_H_INCLUDED
#define PACIENTEH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct paciente
{
    char nome[30];
    int tel;
    struct paciente *prox;
};

struct paciente *inserir(struct paciente *lista);
void mostrar(struct paciente *lista);
struct paciente *remover(struct paciente *lista);
struct paciente *removerRecursao(struct paciente *lista);

#endif // PACIENTEH_H_INCLUDED
