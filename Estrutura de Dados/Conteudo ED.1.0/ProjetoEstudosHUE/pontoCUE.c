#include "pontoHUE.h"


struct pessoa *inserir(struct pessoa *lista)
{
    //VARIAVEIS DA FUNÇAO
    struct pessoa *aux;  //NÓ AUXILIAR
    struct pessoa *novo; //NÓ NOVO


    //VARIAVEIS TEMPORARIARIS PARA VALIDAR ANTES DE INSERIR
    char nomeTemp[30];
    int idadeTemp;

    system("CLS");
    printf("\n\n\tDigite os dados");
    printf("\nNOME: ");
    fflush(stdin);
    gets(nomeTemp);
    printf("\nIdade: ");
    scanf("%d", &idadeTemp);
    //EXEMPLO DE VALIDAÇAO
    while(idadeTemp<0)
    {
        printf("\n\nIdade invalida, digite novamente...\n");
        scanf("%d",&idadeTemp);
    }

    //CRIANDO ESPAÇo PARA ADD DADOS EM UM "NO  NOVO"
    novo = (struct pessoa*)malloc(sizeof (struct pessoa));
    //ADICIONANDO DADOS NO "NÓ NOVO"
    strcpy(novo->nome, nomeTemp);
    novo->idade = idadeTemp;
    novo->prox = NULL;


    //ACHANDO UM LUGAR PARA ADICIONAR NA LISTA, NO CASO, NO INICIO.
    aux = lista;
    if(aux == NULL)  //SE A LISTA ESTA VAZIA, ADICIONA O NOVO NÓ
    {
        lista = novo;
    }
    else             //SE NAO, ELA ACHA O ULTIMO MEMBRO E ADICIONA DEPOIS DELE
    {
        while(aux->prox != NULL)
        {

            aux = aux->prox;    //RODANDO ATE ACHAR O ULTIMO NÓ
        }
        aux->prox = novo;       //ULTIMO MEMBRO AGR APONTA PRO NOVO NÓ
    }

    return (lista);
};

void mostrar(struct pessoa *lista)
{
    struct pessoa *aux;
    aux = lista;
    printf("\n\tMembros da lista\n");
    if(lista == NULL)
    {
        printf("\nLista vazia...\n\n");

    }

    while(aux != NULL)
    {
        printf("\nNome: %s",aux->nome);
        printf("\nIdade: %d\n\n",aux->idade);
        aux = aux->prox;

    }
    system("pause");
}


struct pessoa *removerInicio(struct pessoa *lista)  //REMOVE O PRIMEIRO DA LISTA, O PRIMEIRO QUE ENTROU.
{
    struct pessoa *aux;
    aux = lista;

    if(aux == NULL)
    {
        printf("\nLista vazia, impossivel remover membros\n");
        system("pause");

    }
    else
    {
       lista = lista->prox;
       free(aux);
    }
    return(lista);
};
struct pessoa *removerFim(struct pessoa *lista)   //REMOVE O ULTIMO Q ENTROU.
{
  struct pessoa *aux;
  aux = lista;
  struct pessoa *ultimo;
  struct pessoa *penultimo;
  ultimo = aux->prox;
    penultimo = aux;


  if(aux == NULL)
  {
        printf("\nLista vazia, impossivel remover membros\n");
        system("pause");
  }
  else
  {
      while(ultimo->prox != NULL)
      {
          penultimo = ultimo;
          ultimo = ultimo->prox;

      }

      penultimo->prox = NULL;

  }

  return(penultimo);
};


///PILHA
struct pilha *inserirPilha(struct pilha *pilha)
{
    struct pilha *aux;
    struct pilha *novo;

    char nomeTemp[30];
    int numeroTemp;

    system("CLS");
    printf("\n\tDIGITE OS DADOS");
    printf("\nNOME :");
    fflush(stdin);
    gets(nomeTemp);
    printf("\nNUMERO :");
    scanf("%d", &numeroTemp);

    while(numeroTemp<0)
    {
        printf("\nNumero invalido, digite novamente");
        scanf("%d", &numeroTemp);
    }

    novo = (struct pilha*)malloc(sizeof(struct pilha));

    strcpy(novo->nome, nomeTemp);
    novo->numero= numeroTemp;
    novo->prox= NULL;

    //DECIDINDO ONDE COLOCAR
    aux = pilha;

    if(aux == NULL)
    {
        pilha = novo;
    }
    else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return(pilha);
};
void mostrarPilha(struct pilha *pilha)  ///FUNÇAO MOSTRAR DE PILHA É A MESMA DE LISTA, VC CHAMAR MOSTRAR DE LISTA COM A PILHA E VAI RODAR DO MESMO JEITO
{
    struct pilha *aux;
    aux = pilha;
    system("CLS");
    printf("\n\tMembros da PILHA");
    if(aux == NULL)
    {
        printf("\nPilha vazia");

    }
    else
    {
        while(aux != NULL)
        {
            printf("\nNOME: %s", aux->nome);
            printf("\nNUMERO: %d\n\n", aux->numero);
            aux = aux->prox;
        }
    }
    system("pause");
}
struct pilha *removerPilha(struct pilha *pilha) //A PILHA É UMA LISTA, A DIFERNÇA FICA NA REMOÇAO, ELA SO REMOVE NO FINAL
{
    struct pilha *ultimo;
    struct pilha *penultimo;

    ultimo = pilha->prox;
    penultimo = pilha;

    if(penultimo == NULL)
    {
        printf("\nPILHA VAZIA");
        system("pause");
    }
    else
    {
        while(ultimo->prox !=NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
    }
    return(penultimo);
};



///FILA
struct fila *inserirFila(struct fila *alguem)
{
    struct fila *aux;
    struct fila *novo;
    char nomeTemp[30];
    int senhaTemp;

    system("CLS");
    printf("\n\tDIGITE OS DADOS DA FILA");
    printf("\nNome: ");
    fflush(stdin);
    gets(nomeTemp);
    printf("\nSenha: ");
    scanf("%d",&senhaTemp);
    while(senhaTemp<0  || senhaTemp>100)
    {
        printf("\nSenha invalida, digite novamente...");
        scanf("%d",&senhaTemp);
    }

    novo = (struct fila*)malloc(sizeof(struct fila));

    strcpy(novo->nome,nomeTemp);
    novo->senha = senhaTemp;
    novo->prox = NULL;

    aux = alguem;

    if(aux == NULL)
    {
        alguem = novo;
    }
    else
    {
        while(aux->prox != NULL)
        {

            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return(alguem);
};
struct fila *removerFila(struct fila *alguem)
{
    struct fila *aux;
    aux = alguem;
    if( aux == NULL)
    {
        printf("\n\nFila vazia, impossivel remover");
        system("pause");
    }
    else
    {
        alguem = alguem->prox;
        free(aux);
    }
    return(alguem);
};

///RECURSAO
struct pessoa *removerRecursao(struct pessoa *lista)
{

    if(lista == NULL)
    {
        printf("\n\nLista removida com sucesso atravez de recursao!\n\n");
        system("pause");
    }
    else
    {
        lista = lista->prox;
        return removerRecursao(lista);
    }

};

