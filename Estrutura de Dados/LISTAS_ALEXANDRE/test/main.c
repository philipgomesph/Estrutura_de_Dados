#include <stdio.h>
#include <stdlib.h>



///          ARVORE

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
  if(atual->esq==NULL){ //se não existir filho a esquerda

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

        //busca o nó a ser removido e trata o lado da remoção
        if( valor == atual->dado){

            if(atual == raiz){ //se o valor está na raiz

               raiz = remove_atual(atual); //chama a função e remove a raiz

            }else{

                    if(ant->dir == atual){ //verifica se o no a ser retirado está a direita

                      ant->dir = remove_atual(atual);

                    }else{

                      ant->esq = remove_atual(atual);

                    }
            }

           return 1;
         }



    //continua andando na arvore a procura do nó a ser removido
         ant=atual;
         if(valor>atual->dado){

            atual=atual->dir;
         }else{

            atual=atual->esq;
         }

      }//fim while


}









void menu(){
 int op;  //opção recursiva

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



///    LISTA INICIO FIM

typedef struct
{
    int cpf;
    struct lista *prox;
}lista;
lista *inicio;
lista *fim;

void inicializaFila()
{
    inicio= NULL;
    fim = NULL;
}
int listaVazia()
{
    if(inicio==NULL)
    {
        return 1;

    }else
    {
        return 0;
    }
}


void inserirFim_lista(int cpf)
{
   lista *novo;
   novo = (lista*)malloc(sizeof(lista));
   novo->cpf=cpf;
   novo->prox=NULL;

   if(inicio==NULL)
   {
       inicio=novo;
       fim=novo;
   }else
   {
       fim->prox=novo;
   }
   fim=novo;
}
void inserirInicio_lista(int cpf)
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->cpf=cpf;
    novo->prox=NULL;
    if(inicio==NULL)
    {
        inicio = novo;
        fim=novo;
    }else
    {
        novo->prox=inicio;
    }
    inicio=novo;
}



int removeInicio_lista()
{
    if(listaVazia()==1)
    {
        printf("\nNao eh possivel remover\n");
        printf("\nFila vazia...\n");
        system("pause");
        return 0;
    }else
    {
       lista *aux;
       aux = inicio;
        int y;
        y=aux->cpf;
        inicio=inicio->prox;
        free(aux);
        return(y);
    }
}

void removerFim_lista()
{
    lista *aux;
    lista *auxFim;
    aux=inicio;
    auxFim=inicio;

    if(listaVazia()==1)
    {
        printf("\nLista vazia, impossivel remover...\n");
        system("pause");
        return 0;
    }else
    {
        while(aux->prox!=NULL)
        {
            auxFim=aux;
            aux=aux->prox;
        }
        fim=auxFim;
    }
    fim->prox=NULL;
}



void mostraLista()
{
    lista *aux;
    aux = inicio;
    printf("\nClientes na Fila: ");
    while(aux!=NULL)
    {
        printf("\n | %d", aux->cpf);
        aux = aux->prox;
    }
}

int menu()
{
    system("CLS");
    int opc;
    printf("\n  ~~~~  MENU  ~~~~");
    printf("\n1 - Inserir inicio da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Remover no inicio da lista");
    printf("\n4 - Remover no fim da lista");
    printf("\n5 - Mostrar lista");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);
    while(opc<0 || opc>5)
    {
        printf("\nOPC invalida, digite novamente....\n->");
        scanf("%d",&opc);
    }
    return opc;
}
int main()
{
    int opc,valor,qtd;
    inicializaFila();
    qtd=0;
    opc=menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            system("CLS");
            printf("\nInforme o cpf: ");
            scanf("%d",&valor);
            inserirInicio_lista(valor);
            //enfileira(valor);
            opc = menu();
            break;
        case 2:
            system("CLS");
            printf("\nInforme o cpf: ");
            scanf("%d",&valor);
            inserirFim_lista(valor);
            opc = menu();
            break;
        case 3:
            removeInicio_lista();
            opc = menu();

            break;
        case 4:
            removerFim_lista();
            opc = menu();
            break;
        case 5:
            mostraLista();

            printf("\n\n");
            system("pause");
            opc=menu();
            break;
        }
    }
    printf("AINDA FUNFANDO....");
    return 0;
}



///   FILA

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

/// PILHA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
 int item;
 struct pilha *ant;
}pilha;

int contador;
pilha *nova_celula;
pilha *topo;
pilha *valor;

void menu(){
 int op;  //opção recursiva


 do{
     printf("\n");
     printf("1 - Empilhar \n");
     printf("2 - Desempilhar \n");
     printf("3 - Mostrar tamanho \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){
     case 1:
      insere_pilha();
      break;

     case 2:
        printf("Valor retirado: %d",desempilha());
        break;
     case 3:

        printf("\n\t Tamanho pilha = %d",tamanho_pilha());
        break;

     case 4:
        op=4;

    }

 }while(op != 4);


}


void inicializa_pilha(){
    topo=NULL;
    contador =0;
}

bool pilha_vazia(){
    if(topo == NULL){
        return true;
    }else{
        return false;
    }
}

int tamanho_pilha(){
    return contador;
}

void insere_pilha(){

    int valor;

    system("cls");
    printf("Informe o valor: >_");
    scanf("%d",&valor);

    nova_celula =(pilha *)malloc(sizeof(pilha));

    if(nova_celula == NULL){
       printf("Erro: espaco insuficiente!!");

    }else{

        nova_celula->item = valor; //insere o valor na nova célula
        nova_celula->ant = topo;  //prox recebe o valor da célula de baixo

        topo= nova_celula;  //topo aponta para o endereço da nova célula

        contador++;

    }
}

int desempilha( ){

    int valor;

    pilha *temp; //variavel temporaria para não perder o topo

    if(pilha_vazia()){

       printf("\n Pilha vazia!!!\n");
       return 0;

    }else{

        valor =topo->item; //variavel recebe o valor do item
        temp = topo;       //variavel temporaria recebe o topo para não perder
        topo=topo->ant;   //topo aponta pra celula de baixo

        free(temp);

        contador--; //tira o valor do contador
        return valor; //diz que deu tudo certo

    }
}

int elemento_topo(){//obtem o elemento topo da pilha

    int valor;

    if(pilha_vazia()){

       printf("Pilha vazia!!!");
       return 0;

     }else{
        valor=topo->item;
        return valor;
     }


}

//finalia pilha por questão de segurança
bool finaliza_pilha(){

    pilha *temp;     //variavel temporaria

     if(pilha_vazia()){ //so limpa a pilha se tiver elementos para limpar

       printf("Pilha vazia!!!");
       return false;

     }else{

        while(topo !=NULL){
            temp=topo; //variavel temporaria recebe topo para não perder o topo
            temp->ant = NULL;  //Desconecta a célula de cima da de baixo //celula aponta pra null
            topo=topo->ant;

            free(temp);

        }

        contador=0;
        return true;

     }
}


int main()
{

    inicializa_pilha();

    menu();


    printf("\n\n");






    return 0;
}
/// FIM


int main()
{
    printf("Hello world!\n");
    return 0;
}#include <stdio.h>
#include <stdlib.h>



///          ARVORE

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
  if(atual->esq==NULL){ //se não existir filho a esquerda

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

        //busca o nó a ser removido e trata o lado da remoção
        if( valor == atual->dado){

            if(atual == raiz){ //se o valor está na raiz

               raiz = remove_atual(atual); //chama a função e remove a raiz

            }else{

                    if(ant->dir == atual){ //verifica se o no a ser retirado está a direita

                      ant->dir = remove_atual(atual);

                    }else{

                      ant->esq = remove_atual(atual);

                    }
            }

           return 1;
         }



    //continua andando na arvore a procura do nó a ser removido
         ant=atual;
         if(valor>atual->dado){

            atual=atual->dir;
         }else{

            atual=atual->esq;
         }

      }//fim while


}









void menu(){
 int op;  //opção recursiva

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



///    LISTA INICIO FIM

typedef struct
{
    int cpf;
    struct lista *prox;
}lista;
lista *inicio;
lista *fim;

void inicializaFila()
{
    inicio= NULL;
    fim = NULL;
}
int listaVazia()
{
    if(inicio==NULL)
    {
        return 1;

    }else
    {
        return 0;
    }
}


void inserirFim_lista(int cpf)
{
   lista *novo;
   novo = (lista*)malloc(sizeof(lista));
   novo->cpf=cpf;
   novo->prox=NULL;

   if(inicio==NULL)
   {
       inicio=novo;
       fim=novo;
   }else
   {
       fim->prox=novo;
   }
   fim=novo;
}
void inserirInicio_lista(int cpf)
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->cpf=cpf;
    novo->prox=NULL;
    if(inicio==NULL)
    {
        inicio = novo;
        fim=novo;
    }else
    {
        novo->prox=inicio;
    }
    inicio=novo;
}



int removeInicio_lista()
{
    if(listaVazia()==1)
    {
        printf("\nNao eh possivel remover\n");
        printf("\nFila vazia...\n");
        system("pause");
        return 0;
    }else
    {
       lista *aux;
       aux = inicio;
        int y;
        y=aux->cpf;
        inicio=inicio->prox;
        free(aux);
        return(y);
    }
}

void removerFim_lista()
{
    lista *aux;
    lista *auxFim;
    aux=inicio;
    auxFim=inicio;

    if(listaVazia()==1)
    {
        printf("\nLista vazia, impossivel remover...\n");
        system("pause");
        return 0;
    }else
    {
        while(aux->prox!=NULL)
        {
            auxFim=aux;
            aux=aux->prox;
        }
        fim=auxFim;
    }
    fim->prox=NULL;
}



void mostraLista()
{
    lista *aux;
    aux = inicio;
    printf("\nClientes na Fila: ");
    while(aux!=NULL)
    {
        printf("\n | %d", aux->cpf);
        aux = aux->prox;
    }
}

int menu()
{
    system("CLS");
    int opc;
    printf("\n  ~~~~  MENU  ~~~~");
    printf("\n1 - Inserir inicio da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Remover no inicio da lista");
    printf("\n4 - Remover no fim da lista");
    printf("\n5 - Mostrar lista");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);
    while(opc<0 || opc>5)
    {
        printf("\nOPC invalida, digite novamente....\n->");
        scanf("%d",&opc);
    }
    return opc;
}
int main()
{
    int opc,valor,qtd;
    inicializaFila();
    qtd=0;
    opc=menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            system("CLS");
            printf("\nInforme o cpf: ");
            scanf("%d",&valor);
            inserirInicio_lista(valor);
            //enfileira(valor);
            opc = menu();
            break;
        case 2:
            system("CLS");
            printf("\nInforme o cpf: ");
            scanf("%d",&valor);
            inserirFim_lista(valor);
            opc = menu();
            break;
        case 3:
            removeInicio_lista();
            opc = menu();

            break;
        case 4:
            removerFim_lista();
            opc = menu();
            break;
        case 5:
            mostraLista();

            printf("\n\n");
            system("pause");
            opc=menu();
            break;
        }
    }
    printf("AINDA FUNFANDO....");
    return 0;
}



///   FILA

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

/// PILHA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
 int item;
 struct pilha *ant;
}pilha;

int contador;
pilha *nova_celula;
pilha *topo;
pilha *valor;

void menu(){
 int op;  //opção recursiva


 do{
     printf("\n");
     printf("1 - Empilhar \n");
     printf("2 - Desempilhar \n");
     printf("3 - Mostrar tamanho \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){
     case 1:
      insere_pilha();
      break;

     case 2:
        printf("Valor retirado: %d",desempilha());
        break;
     case 3:

        printf("\n\t Tamanho pilha = %d",tamanho_pilha());
        break;

     case 4:
        op=4;

    }

 }while(op != 4);


}


void inicializa_pilha(){
    topo=NULL;
    contador =0;
}

bool pilha_vazia(){
    if(topo == NULL){
        return true;
    }else{
        return false;
    }
}

int tamanho_pilha(){
    return contador;
}

void insere_pilha(){

    int valor;

    system("cls");
    printf("Informe o valor: >_");
    scanf("%d",&valor);

    nova_celula =(pilha *)malloc(sizeof(pilha));

    if(nova_celula == NULL){
       printf("Erro: espaco insuficiente!!");

    }else{

        nova_celula->item = valor; //insere o valor na nova célula
        nova_celula->ant = topo;  //prox recebe o valor da célula de baixo

        topo= nova_celula;  //topo aponta para o endereço da nova célula

        contador++;

    }
}

int desempilha( ){

    int valor;

    pilha *temp; //variavel temporaria para não perder o topo

    if(pilha_vazia()){

       printf("\n Pilha vazia!!!\n");
       return 0;

    }else{

        valor =topo->item; //variavel recebe o valor do item
        temp = topo;       //variavel temporaria recebe o topo para não perder
        topo=topo->ant;   //topo aponta pra celula de baixo

        free(temp);

        contador--; //tira o valor do contador
        return valor; //diz que deu tudo certo

    }
}

int elemento_topo(){//obtem o elemento topo da pilha

    int valor;

    if(pilha_vazia()){

       printf("Pilha vazia!!!");
       return 0;

     }else{
        valor=topo->item;
        return valor;
     }


}

//finalia pilha por questão de segurança
bool finaliza_pilha(){

    pilha *temp;     //variavel temporaria

     if(pilha_vazia()){ //so limpa a pilha se tiver elementos para limpar

       printf("Pilha vazia!!!");
       return false;

     }else{

        while(topo !=NULL){
            temp=topo; //variavel temporaria recebe topo para não perder o topo
            temp->ant = NULL;  //Desconecta a célula de cima da de baixo //celula aponta pra null
            topo=topo->ant;

            free(temp);

        }

        contador=0;
        return true;

     }
}


int main()
{

    inicializa_pilha();

    menu();


    printf("\n\n");






    return 0;
}
/// FIM


int main()
{
    printf("Hello world!\n");
    return 0;
}#include <stdio.h>
#include <stdlib.h>



///          ARVORE

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
  if(atual->esq==NULL){ //se não existir filho a esquerda

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

        //busca o nó a ser removido e trata o lado da remoção
        if( valor == atual->dado){

            if(atual == raiz){ //se o valor está na raiz

               raiz = remove_atual(atual); //chama a função e remove a raiz

            }else{

                    if(ant->dir == atual){ //verifica se o no a ser retirado está a direita

                      ant->dir = remove_atual(atual);

                    }else{

                      ant->esq = remove_atual(atual);

                    }
            }

           return 1;
         }



    //continua andando na arvore a procura do nó a ser removido
         ant=atual;
         if(valor>atual->dado){

            atual=atual->dir;
         }else{

            atual=atual->esq;
         }

      }//fim while


}









void menu(){
 int op;  //opção recursiva

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



///    LISTA INICIO FIM

typedef struct
{
    int cpf;
    struct lista *prox;
}lista;
lista *inicio;
lista *fim;

void inicializaFila()
{
    inicio= NULL;
    fim = NULL;
}
int listaVazia()
{
    if(inicio==NULL)
    {
        return 1;

    }else
    {
        return 0;
    }
}


void inserirFim_lista(int cpf)
{
   lista *novo;
   novo = (lista*)malloc(sizeof(lista));
   novo->cpf=cpf;
   novo->prox=NULL;

   if(inicio==NULL)
   {
       inicio=novo;
       fim=novo;
   }else
   {
       fim->prox=novo;
   }
   fim=novo;
}
void inserirInicio_lista(int cpf)
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->cpf=cpf;
    novo->prox=NULL;
    if(inicio==NULL)
    {
        inicio = novo;
        fim=novo;
    }else
    {
        novo->prox=inicio;
    }
    inicio=novo;
}



int removeInicio_lista()
{
    if(listaVazia()==1)
    {
        printf("\nNao eh possivel remover\n");
        printf("\nFila vazia...\n");
        system("pause");
        return 0;
    }else
    {
       lista *aux;
       aux = inicio;
        int y;
        y=aux->cpf;
        inicio=inicio->prox;
        free(aux);
        return(y);
    }
}

void removerFim_lista()
{
    lista *aux;
    lista *auxFim;
    aux=inicio;
    auxFim=inicio;

    if(listaVazia()==1)
    {
        printf("\nLista vazia, impossivel remover...\n");
        system("pause");
        return 0;
    }else
    {
        while(aux->prox!=NULL)
        {
            auxFim=aux;
            aux=aux->prox;
        }
        fim=auxFim;
    }
    fim->prox=NULL;
}



void mostraLista()
{
    lista *aux;
    aux = inicio;
    printf("\nClientes na Fila: ");
    while(aux!=NULL)
    {
        printf("\n | %d", aux->cpf);
        aux = aux->prox;
    }
}

int menu()
{
    system("CLS");
    int opc;
    printf("\n  ~~~~  MENU  ~~~~");
    printf("\n1 - Inserir inicio da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Remover no inicio da lista");
    printf("\n4 - Remover no fim da lista");
    printf("\n5 - Mostrar lista");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);
    while(opc<0 || opc>5)
    {
        printf("\nOPC invalida, digite novamente....\n->");
        scanf("%d",&opc);
    }
    return opc;
}
int main()
{
    int opc,valor,qtd;
    inicializaFila();
    qtd=0;
    opc=menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            system("CLS");
            printf("\nInforme o cpf: ");
            scanf("%d",&valor);
            inserirInicio_lista(valor);
            //enfileira(valor);
            opc = menu();
            break;
        case 2:
            system("CLS");
            printf("\nInforme o cpf: ");
            scanf("%d",&valor);
            inserirFim_lista(valor);
            opc = menu();
            break;
        case 3:
            removeInicio_lista();
            opc = menu();

            break;
        case 4:
            removerFim_lista();
            opc = menu();
            break;
        case 5:
            mostraLista();

            printf("\n\n");
            system("pause");
            opc=menu();
            break;
        }
    }
    printf("AINDA FUNFANDO....");
    return 0;
}



///   FILA

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

/// PILHA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
 int item;
 struct pilha *ant;
}pilha;

int contador;
pilha *nova_celula;
pilha *topo;
pilha *valor;

void menu(){
 int op;  //opção recursiva


 do{
     printf("\n");
     printf("1 - Empilhar \n");
     printf("2 - Desempilhar \n");
     printf("3 - Mostrar tamanho \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){
     case 1:
      insere_pilha();
      break;

     case 2:
        printf("Valor retirado: %d",desempilha());
        break;
     case 3:

        printf("\n\t Tamanho pilha = %d",tamanho_pilha());
        break;

     case 4:
        op=4;

    }

 }while(op != 4);


}


void inicializa_pilha(){
    topo=NULL;
    contador =0;
}

bool pilha_vazia(){
    if(topo == NULL){
        return true;
    }else{
        return false;
    }
}

int tamanho_pilha(){
    return contador;
}

void insere_pilha(){

    int valor;

    system("cls");
    printf("Informe o valor: >_");
    scanf("%d",&valor);

    nova_celula =(pilha *)malloc(sizeof(pilha));

    if(nova_celula == NULL){
       printf("Erro: espaco insuficiente!!");

    }else{

        nova_celula->item = valor; //insere o valor na nova célula
        nova_celula->ant = topo;  //prox recebe o valor da célula de baixo

        topo= nova_celula;  //topo aponta para o endereço da nova célula

        contador++;

    }
}

int desempilha( ){

    int valor;

    pilha *temp; //variavel temporaria para não perder o topo

    if(pilha_vazia()){

       printf("\n Pilha vazia!!!\n");
       return 0;

    }else{

        valor =topo->item; //variavel recebe o valor do item
        temp = topo;       //variavel temporaria recebe o topo para não perder
        topo=topo->ant;   //topo aponta pra celula de baixo

        free(temp);

        contador--; //tira o valor do contador
        return valor; //diz que deu tudo certo

    }
}

int elemento_topo(){//obtem o elemento topo da pilha

    int valor;

    if(pilha_vazia()){

       printf("Pilha vazia!!!");
       return 0;

     }else{
        valor=topo->item;
        return valor;
     }


}

//finalia pilha por questão de segurança
bool finaliza_pilha(){

    pilha *temp;     //variavel temporaria

     if(pilha_vazia()){ //so limpa a pilha se tiver elementos para limpar

       printf("Pilha vazia!!!");
       return false;

     }else{

        while(topo !=NULL){
            temp=topo; //variavel temporaria recebe topo para não perder o topo
            temp->ant = NULL;  //Desconecta a célula de cima da de baixo //celula aponta pra null
            topo=topo->ant;

            free(temp);

        }

        contador=0;
        return true;

     }
}


int main()
{

    inicializa_pilha();

    menu();


    printf("\n\n");






    return 0;
}
/// FIM


int main()
{
    printf("Hello world!\n");
    return 0;
}
