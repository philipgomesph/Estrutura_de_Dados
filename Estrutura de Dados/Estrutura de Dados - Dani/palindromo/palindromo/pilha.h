#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAX 100

#include  <stdio.h>
#include  <stdlib.h>

struct pilha {
               int pilha[MAX];
               int topo;
              };
typedef struct pilha* Pilha;


int E_cheia(Pilha Ptp);
int E_vazia(Pilha Ptp);
Pilha Cria_pilha();
int Push(Pilha Ptp, int elem);
int Pop(Pilha Ptp);
int Top(Pilha Ptp);
void Libera_pilha(Pilha Ptp);


#endif // PILHA_H_INCLUDED
