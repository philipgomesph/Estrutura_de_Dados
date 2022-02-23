#include "pilha.h"

Pilha Cria_pilha()
{
   Pilha Ptp;

    //Ptp = (Pilha)malloc(sizeof(struct pilha));

   Ptp = (struct pilha*)malloc(sizeof(struct pilha));

   Ptp->topo = -1;

   return Ptp;
}

int E_cheia(Pilha Ptp)
{
    if (Ptp->topo == MAX-1)
      return 1;
    else
      return 0;
}

int E_vazia(Pilha Ptp)
{
    if (Ptp->topo == -1)
      return 1;
    else
      return 0;
}

int Top(Pilha Ptp)
{
  if (Ptp->topo == -1)
     return -1;// -1 não é um valor que pode ser adicionado à pilha, ele o nulo
  else
    return Ptp->pilha[Ptp->topo];
}

int Push(Pilha Ptp, int elem)
{
   if (E_cheia(Ptp) == 1)
      return 0;
   else
   {
       (Ptp->topo)++;
       Ptp->pilha[Ptp->topo] = elem;
       return 1;
   }
}

int Pop(Pilha Ptp)
{
  int elem;
  if (E_vazia(Ptp) == 1)
     return -1;//indica o nulo
  else{
  elem = Ptp->pilha[Ptp->topo];
  (Ptp->topo)--;
  return elem;
  }
}


