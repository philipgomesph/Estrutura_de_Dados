#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int dado;
    struct no *esq;
    struct no *dir;
}no;

int tamA;
int tamB;
int i;
int *v;


no  *raiz;
no  *atual;
no  *ant; //anterior

no  *raizB;
no *atualB;
no *antB;

void cria_arvore(){


   raiz=NULL;
   atual=NULL;
   ant=NULL;

   raizB=NULL;
   atualB=NULL;
   antB = NULL;
   //return raiz;

}


int arvore_vazia(no *raiz){

  if(raiz == NULL){
    return 1;

  }else{

    return 0;
  }
}

///ARVORE PADRAO
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
///ARVORE B
int insere_arvoreB(int valor){

   //cria um novo no
   no *novo =(no*)malloc(sizeof(no));

   novo->dado=valor;
   novo->dir =NULL;
   novo->esq =NULL;


    if(raizB == NULL){ //se for a primeira vez entra no caso especial

      raizB=novo;
      return 1;

    }else{

        atualB=raizB;
        antB=atualB;

        //enquanto não chegar no nó folha
        while(atualB!=NULL){

                //valor maior que a raiz
                if(valor>atualB->dado){
                    antB=atualB;
                    atualB=atualB->dir;

                //valor menor que a raiz
                }else{
                    antB=atualB;
                    atualB=atualB->esq;
                }
         }


            //insere como filho desse no folha
            if(valor > antB->dado){
                antB->dir = novo;
            }else{
                antB->esq = novo;
            }
            return 1;
       }
     }

//raiz esquerda direita
void pre_ordem(no *raiz){

    if(raiz == NULL){

        //printf("\n NULL");
        //"return" sem valor, simplesmente retorna o controle
        //para a função que chamou a função corrente.
        //Nenhum valor de retorno é passado, ou seja,
        //o valor de retorno é indefinido.
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
void em_ordem_Duplo(no *raiz,no *raizB){

    if(raiz ==NULL || raizB == NULL){
        return;
    }else if(raiz != NULL && raizB != NULL){


    em_ordem_Duplo(raiz->esq, raizB->esq);
    if(raiz->dado != raizB->dado)
      {
          printf("\nArvores de valores diferentes...");
          printf("%d \n", raiz->dado);
          printf("%d \n", raizB->dado);


      }
      em_ordem_Duplo(raiz->dir,raizB->dir);
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




int altura(no *r)
{
    if(r == NULL)
    {
        return -1;
    }else
    {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if(he<hd) return 11;
        else return 10;
    }
}


int iguais(Arv* a,Arv* b){
    if(a==NULL && b==NULL)
    return 1;
    if(a==NULL || b==NULL)
    return 0;
    return ((a->info==b->info) && iguais(a->esq,b->esq) && iguais(a->dir,b->dir));
}
int menu()
{
    int opc;
    system("CLS");
    printf("\n\t  ~~~~ MENU ~~~~\n");
    printf("\n1 - Inserir na arvore A.");
    printf("\n2 - Inserir na arvore B.");
    printf("\n3 - Mostrar Arvores.");
    printf("\n4 - Lado c/ mais folhas, as folhas.");
    printf("\n5 - Compara A e B.");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc<0 || opc>5)
    {
        printf("\nOPC invalida, digite novamente...\n->");
        scanf("%d",&opc);
    }
    return opc;
}




///MAIN

int main()
{
    int opc,valor,valorA,valorB,Q3,primeiro,contE,contD;
    int h;
    cria_arvore();
    opc = menu();
    tamA=0;
    tamB=0;
    i=0;
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            system("CLS");
            printf("\nInforme o valor a ser inserido: \n->");
            scanf("%d",&valorA);
            tamA++;
            insere_arvore(valorA);
            opc = menu();
            break;
        case 2:
            system("CLS");
            printf("\nInforme o valor a ser inserido: \n->");
            scanf("%d",&valorB);
            tamB++;
            insere_arvoreB(valorB);
            opc = menu();
            break;
        case 3:
            system("CLS");
            printf("\nMostrar Arvore:");
            printf("\n1 - Arvore A.");
            printf("\n2 - Arvore B.");
            printf("\n0 - Sair.\n->");
            scanf("%d",&Q3);
            while(Q3<0 || Q3>2)
            {
                printf("\nOPC invalida, digite novamente..\n->");
                scanf("%d",&Q3);
            }
            if(Q3 ==1)
            {
                pre_ordem(raiz);
                printf("\n\n");
                system("pause");

            }
            if(Q3==2)
            {
                pre_ordem(raizB);
                printf("\n\n");
                system("pause");
            }
            opc = menu();
            break;
        case 4:

            h = altura(raiz);

            if(h==10)
            {
                printf("\nLado Esquerdo eh maior ...");
            }
            if(h==11)
            {
                printf("\nLado Direito eh maior...");
            }
            ///mostrar FOLHAS
            printf("\n\n");
            system("pause");
            opc = menu();
            break;
        case 5:
            em_ordem_Duplo(raiz,raizB);

            opc = menu();
            break;
        }
    }

    printf("\n\t Obrigado por usar nosso sistema, ate mais... \n");
    return 0;
}
