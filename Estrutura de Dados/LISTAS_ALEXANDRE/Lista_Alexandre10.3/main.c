#include <stdio.h>
#include <stdlib.h>
#define tam 5

int i;

typedef struct
{
    int numero;
}vetor;

typedef struct
{
    int valor[tam];
    int topo;
}pilha;


void inicia(pilha *p)
{
    p->topo=-1;
}

int pilha_vazia(pilha *p){
    if(p->topo == -1){
        return 1; //pilha vazia
    }else{
        return 0; //pilha não está vazia
    }
}

int pilha_cheia(pilha *p){

    if(p->topo == tam -1){ //vetor começa com 0

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
     p->valor[p->topo]= x;

   }
}

int retira(pilha *p){
    int aux;

    if(pilha_vazia(p)== 1){
        printf("Erro: pilha vazia");
    }else{
        aux = p->valor[p->topo];
        p->topo--;
        return aux;

    }
}



int TPilha(vetor *v)
{
    pilha *p;
    int x,y;
    p = (pilha*)malloc(sizeof(pilha));

    for(i=0;i<tam;i++)
    {
        x = v[i].numero;

        if(x%2==0)
        {
            insere(p,x);

        }
        else
        {
            y=retira(p);
            printf("\nNumeros removidos: %d\n",y);
        }
    }

    ///PAROU AQUI !!!!!!!!!!!!!!!!
return 0;
}
int main()
{

    vetor *v;

    v= (vetor*)calloc(sizeof(vetor),tam);
    for(i=0;i<tam;i++)
    {
        printf("\nDigite os valores do vetor: \n");
        scanf("%d",&v[i].numero);
    }
    TPilha(v);


    printf("\n\n\t  AINDA FUNFANDO \n\n");
    return 0;
}
