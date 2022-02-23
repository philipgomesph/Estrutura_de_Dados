#include <stdio.h>
#include <stdlib.h>
#define max 4

typedef struct{
    int item[max]; //itens da pilha
    int topo;          //posição do topo da pilha
}pilha;


void inicia(pilha *p){
 p->topo=-1; //inicializa a pilha como vazia
}

int pilha_vazia(pilha *p){
    if(p->topo == -1){
        return 1; //pilha vazia
    }else{
        return 0; //pilha não está vazia
    }
}

int pilha_cheia(pilha *p){

    if(p->topo == max -1){ //vetor começa com 0

        return 1; //pilha cheia

    }else{
        return 0; //pilha com espaço

    }

}

void insere(pilha *p, int x){

   if (pilha_cheia(p)== 1){
     printf("Erro: pilha cheia");

   }else{
     p->topo++;
     p->item[p->topo]= x;

   }
}

int retira(pilha *p){
    int aux;

    if(pilha_vazia(p)== 1){
        printf("Erro: pilha vazia");
    }else{
        aux = p->item[p->topo];
        p->topo--;
        return aux;

    }
}




int main()
{
    pilha *p =(pilha *)malloc(sizeof(pilha));
    inicia(p);

    insere(p,1);
    insere(p,2);
    insere(p,3);
    insere(p,4);



    int aux;
    aux=retira(p);

    printf("Item removido: %d",aux);

    printf("\n\n\n");
    return 0;
}
