#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define MAX_FILA 10

#include <stdio.h>
#include <stdlib.h>

struct queue {
                         int *fila;
                         int IF;
                         int FF;
                         int N; //numro de elementos na fila
                     };

typedef struct queue* Fila;


// Criar uma fila vazia
Fila Cria_fila();

// Inserir um nodo no final da fila
int enqueue(Fila, int); //retorna 1 se inseriu e 0 se n�o inseriu

 //Excluir o nodo do in�cio da fila
int dequeue(Fila f);

// Consultar  nodo no inicio da fila
int consulta(Fila f);

//Liberar �rea alocada para a fila
void libera_fila(Fila f);

//Verificar se fila est� cheia
int e_cheia(Fila f); //retorna 1 se estiver e 0 se n�o estiver

//Verificar se fila est� vazia
int e_vazia(Fila f); //retorna 1 se estiver vazia e 0 se n�o estiver

#endif // FILA_H_INCLUDED
