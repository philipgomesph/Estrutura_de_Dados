#include <stdio.h>
#include <stdlib.h>

//lista duplamente encadeada sem ordenação
typedef struct {
    int dado;
    struct no *prox;
    struct no *ant;
}no;


no *inicio;
no *fim;



void inicializa_lista(){
 inicio=NULL;
 fim=NULL;
}


int lista_vazia(){

  if(inicio==NULL){
    return 1;
  }else {
   return 0;
  }

}


void inserir_inicio_lista(int valor){

  //cria um novo no
  no *novo=(no*)malloc(sizeof(no));

  novo->dado =valor;
  novo->prox=NULL;
  novo->ant = NULL;

  if(inicio==NULL){ //primeira vez

    inicio=novo;
    fim=novo;

  }else{

     inicio->ant = novo;
     novo->prox= inicio;
     inicio=novo;    //Ajusta-se o inicio

  }

}


void inserir_fim_lista(int valor){

  //cria um novo no
  no *novo=(no*)malloc(sizeof(no));

  novo->dado =valor;
  novo->prox=NULL;
  novo->ant = NULL;

  if(inicio==NULL){ //primeira vez

    inicio=novo; //inicio aponta pro novo no
    fim=novo;

  }else{
    fim->prox=novo;// Novo nó será apontado pelo último nó da fila
    novo->ant= fim;
    fim=novo;    //Ajusta-se o fim
  }

}


int remove_inicio_lista( )
{
  no *aux;     //ponteiro auxiliar
  int y;   //variável que recebe o valor de retorno

  if(lista_vazia()==1){

    printf("Nao e possivel remover\n");
    printf("Lista Vazia!!\n");
    return 0;

  }else{

       if(inicio==fim){


        aux=inicio;  //aponta para o nó inicial
        y =inicio->dado; //passa o valor da struc para a variável

        inicializa_lista();


        free(aux);

        return(y);

      }else{

        aux=inicio;  //aponta para o nó inicial
        y =aux->dado; //passa o valor da struc para a variável

        inicio=inicio->prox; //aponta para a proxima posição
        free(aux); //liberado.

        return(y);

     }

  }
}


int remove_fim_lista( )
{
  no *aux;             //ponteiro auxiliar
  int y;   //variável que recebe o valor de retorno


  if(lista_vazia()==1){

    printf("Nao e possivel remover\n");
    printf("Lista Vazia!!\n");
    return 0;

  }else{

    if(inicio==fim){//se so tem um unico nó

        aux=fim;  //aponta para o nó inicial
        y =fim->dado; //passa o valor da struc para a variável
        inicializa_lista();
        free(aux);
        return(y);

     }else{
         aux=fim;            //aponta para o nó inicial
         y =aux->dado; //passa o valor da struc para a variável
         fim=fim->ant;
         fim->prox = NULL;

         free(aux); //liberado.
        return(y);
    }
  }

}


void mostra_lista()
{
    no *aux;
    aux =inicio;

  if(lista_vazia()==1){
    printf("\n Lista Vazia ");

  }else{

	printf("\n Lista : ");
	while(aux != NULL)
	{
		printf(" | %d ", aux->dado);
		aux = aux->prox; //incrementa o ponteiro
	}
  }
}


void menu(){
 int op;  //opção recursiva

 do{
     printf("\n\n");
     printf("1 - Inserir fim lista \n");
     printf("2 - Inserir inicio lista \n");
     printf("3 - Remover inicio Lista \n");
     printf("4 - Remover fim Lista \n");
     printf("5 - Mostrar lista \n");
     printf("6 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);
      inserir_fim_lista(x);
      break;
     }

     case 2:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);
      inserir_inicio_lista(x);
      break;
     }

     case 3:{
        int x;
        x=remove_inicio_lista( );

        if(x!=0){
            printf("\n\tValor retirado: %d \n\n",x);

        }
        break;

     }



     case 4:{
        int x;
        x=remove_fim_lista( );

        if(x!=0){
            printf("\n\tValor retirado: %d \n\n",x);

        }
        break;

     }


     case 5:

        mostra_lista();
        break;

     case 6:
       op=6;


    }
 }while(op != 6);


}


int main()
{

    inicializa_lista();

    menu();

    printf("\n\n");
    return 0;
}
