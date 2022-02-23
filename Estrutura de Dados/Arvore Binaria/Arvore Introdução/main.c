#include <stdio.h>
#include <stdlib.h>

//arvore binaria de busca
typedef struct {
    int dado;
    struct no *esq;
    struct no *dir;
}no;


no  *raiz;
no  *atual;
no  *ant; //anterior



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

        //enquanto n�o chegar no n� folha
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

    if(raiz == NULL){

        //printf("\n NULL");
        //"return" sem valor, simplesmente retorna o controle
        //para a fun��o que chamou a fun��o corrente.
        //Nenhum valor de retorno � passado, ou seja,
        //o valor de retorno � indefinido.
        return;

    }else if(raiz != NULL){

     printf("%d \n ", raiz->dado);
     pre_ordem(raiz->esq);
     pre_ordem(raiz->dir);

    }
}

//esquerda raiz direita
void em_ordem(no *raiz){

    if(raiz ==NULL){
        return;
    }else if(raiz != NULL){

      em_ordem(raiz->esq);
      printf("%d \n", raiz->dado);
      em_ordem(raiz->dir);
    }
}

//esquerda direita raiz
void pos_ordem(no *raiz){

    if(raiz ==NULL){
        return;
    }else if(raiz != NULL){

     pos_ordem(raiz->esq);
     pos_ordem(raiz->dir);
     printf("%d \n", raiz->dado);

    }

}



no* remove_atual(no *atual){


  no *no1, *no2;

  //nos folhas com 1 filho
  if(atual->esq==NULL){ //se n�o existir filho a esquerda

     no2=atual->dir; //aponta para o filho da direita
     free(atual);
     return no2;

  }

//---------no com dois filhos ----------------------------
//-----procura filho mais a direita da sub-arvore a esquerda
  no1=atual;
  no2=atual->esq;

  while(no2->dir != NULL){

    no1=no2;
    no2=no2->dir;
  }



//---------------copia mais a direita da subarvore da esquerda para o lugar do no removido

  if(no1 != atual){

    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }

  no2->dir = atual ->dir;
  free(atual);
  return no2;


}




//------------------------------------busca no a ser removido na arvore--------------------

int remove_no(no *raiz, int valor){

  if(raiz==NULL) return 0;

  ant = NULL;
  atual = raiz;

      while(atual != NULL){

        //busca o n� a ser removido e trata o lado da remo��o
        if( valor == atual->dado){

            if(atual == raiz){ //se o valor est� na raiz

               raiz = remove_atual(atual); //chama a fun��o e remove a raiz

            }else{

                    if(ant->dir == atual){ //verifica se o no a ser retirado est� a direita

                      ant->dir = remove_atual(atual);

                    }else{

                      ant->esq = remove_atual(atual);

                    }
            }

           return 1;
         }



    //continua andando na arvore a procura do n� a ser removido
         ant=atual;
         if(valor>atual->dado){

            atual=atual->dir;
         }else{

            atual=atual->esq;
         }

      }//fim while


}









void menu(){
 int op;  //op��o recursiva

 do{
     printf("\n\n");
     printf("1 - Inserir Arvore \n");
     printf("2 - Remover Arvore \n");
     printf("3 - Mostrar Arvore pre_order \n");
     printf("4 - Mostrar Arvore in_order  \n");
     printf("5 - Mostrar Arvore pos_order \n");
     printf("6 - Remover No \n ");
     printf("7 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{

       int x;
       printf("\n Informe o valor: >_");
       scanf("%d",&x);

       insere_arvore(x);
       break;

     }

     case 2:

     case 3:

      pre_ordem(raiz);
      menu();
      break;

     case 4:
        em_ordem(raiz);
        menu();
        break;

     case 5:
        pos_ordem(raiz);
        menu();
        break;


     case 6:{

       int x;
       printf("\n Informe o valor a ser removido: >_");
       scanf("%d",&x);

       int y = remove_no(raiz,x);

        if(y==1){
         printf("\n Valor removido com sucesso!!!");

        }else{
          printf("\n Deu ruim!!!");

        }

       break;

     }


     case 7:
        op=7;
        exit(1);

    }

  }while(op != 7);
}



int main()
{

     cria_arvore();
     menu();

    printf("\n\n");
    return 0;
}
