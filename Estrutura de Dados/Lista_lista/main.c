#include <stdio.h>
#include <stdlib.h>

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
