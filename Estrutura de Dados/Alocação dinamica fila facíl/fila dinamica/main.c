#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
    struct no *prox;
}no;

no *inicio;
no *fim;

void inicializa_fila(){
 inicio=NULL;
 fim=NULL;
}


int fila_vazia(){

  if(inicio==NULL){

    return 1;
  }else {
   return 0;
  }

}


void enfileirar(int valor){
  //cria um novo no
  no *novo=(no*)malloc(sizeof(no));

  novo->dado =valor;
  novo->prox=NULL;

  if(inicio==NULL){ //primeira vez

    inicio=novo; //inicio aponta pro novo no

  }else{
    fim->prox=novo;// Novo nó será apontado pelo último nó da fila
  }

   fim=novo;    //Ajusta-se o fim
}




int remove_fila( )
{

  if(fila_vazia()==1){

    printf("Nao e possivel remover\n");
    printf("Fila Vazia!!\n");
    return 0;

  }else{


    no *aux;     //ponteiro auxiliar
	aux=inicio;  //aponta para o nó inicial


	//essa variável é necessário porque ao dar free no no esse valor será perdido
	int y;   //variável que recebe o valor de retorno
	y =aux->dado; //passa o valor da struc para a variável


	inicio=inicio->prox; //aponta para a proxima posição

	free(aux); //liberado.

    return(y);

  }

}


void mostra_fila()
{
    no *aux;
    aux =inicio;

	printf("\n Fila : ");
	while(aux != NULL)
	{
		printf(" | %d ", aux->dado);
		aux = aux->prox; //incrementa o ponteiro
	}
}


void menu(){
 int op;  //opção recursiva

 do{
     printf("\n\n");
     printf("1 - Enfileirar \n");
     printf("2 - Desenfileirar \n");
     printf("3 - Mostrar Fila \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);
      enfileirar(x);
      break;
     }


     case 2:{
        int x;
        x=remove_fila( );

        if(x!=0){
            printf("\n\tValor retirado: %d \n\n",x);

        }
        break;

     }

     case 3:

        mostra_fila();
        break;

     case 4:
        op=4;

    }


 }while(op != 4);


}




int main()
{

    inicializa_fila();

    menu();

    printf("\n\n");
    return 0;
}
