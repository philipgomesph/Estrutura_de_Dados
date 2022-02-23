#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int dado;
    struct no *esq;
    struct no *dir;
}no;


no  *raiz;
no  *atual;
no  *ant;
int tam,i;
int *v;


void cria_arvore(){

   raiz=NULL;
   atual=NULL;
   ant=NULL;
   //return raiz;

}
int arvore_vazia(no *raiz){

  if(raiz == NULL){
    return 1;

  }else{

    return 0;
  }
}
int insere_arvore(int valor){

   //cria um novo no
   no *novo =(no*)malloc(sizeof(no));

   novo->dado=valor;
   novo->dir =NULL;
   novo->esq =NULL;


    if(raiz == NULL){ //se for a primeira vez entra no caso especial

      raiz=novo;
      return 1;

    }else{

        atual=raiz;
        ant=atual;

        //enquanto não chegar no nó folha
        while(atual!=NULL){

                //valor maior que a raiz
                if(valor>atual->dado){
                    ant=atual;
                    atual=atual->dir;

                //valor menor que a raiz
                }else{
                    ant=atual;
                    atual=atual->esq;
                }
         }


            //insere como filho desse no folha
            if(valor > ant->dado){
                ant->dir = novo;
            }else{
                ant->esq = novo;
            }
            return 1;
       }
     }

//raiz esquerda direita
void pre_ordem(no *raiz){

    int valor;

    if(raiz == NULL){

        //printf("\n NULL");
        //"return" sem valor, simplesmente retorna o controle
        //para a função que chamou a função corrente.
        //Nenhum valor de retorno é passado, ou seja,
        //o valor de retorno é indefinido.
        return;

    }else if(raiz != NULL){

     //printf("%d \n ", raiz->dado);
     insere_arvore_Vetor(valor);
     pre_ordem(raiz->esq);
     pre_ordem(raiz->dir);

    }
}

void insere_arvore_Vetor(int valor)
{
    v[i]= valor;
    i++;
}




int main()
{
    cria_arvore();

    printf("Hello world!\n");
    return 0;
}
