#include <stdio.h>
#include <stdlib.h>

///Proxima etapa:
///FAZER A ORDENAÇAO

typedef struct
{
    int numero;
    struct No *prox;
    struct No *ant;
}No;

No *lista;

void inicializaFila()
{
    lista = NULL;
}
int listaVazia()
{
    if(lista==NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}
void inserirPrimeiraVez(int valor)
{
    No *novo;
    novo = (No*)malloc(sizeof(No));
    novo->numero=valor;
    novo->ant=NULL;
    novo->prox=NULL;
    lista =novo;
}
void inserirInicio(int valor)
{
    No *novo;
    No *aux;
    novo = (No*)malloc(sizeof(No));
    novo->numero=valor;
    novo->ant=NULL;
    novo->prox=NULL;
    aux = lista;
    novo->prox=lista;
    lista->ant=novo;
    lista=novo;

}

void inserirOrdenado(int valor)
{
    No *aux;
    No *aux2;
    aux = lista;
    if(valor<lista->numero)
    {
        inserirInicio(valor);
    }else
    {

        while(valor>aux->numero)
        {

            aux=aux->prox;
            aux2=aux->ant;
        }
        No *novo;
        No *aux;
        novo = (No*)malloc(sizeof(No));
        novo->numero=valor;
        novo->ant=NULL;
        novo->prox=NULL;

        novo->prox=aux;
        novo->ant=aux2;
        aux2->prox=novo;
        aux->ant=novo;
    }

}
void mostrarLista()
{
    No *aux;
    aux = lista;
    printf("\nElementos na Lista\n");
    while(aux!=NULL)
    {
        printf("\n | %d",aux->numero);
        aux = aux->prox;
    }
}
int pegaValor()
{
    int valor;
    system("CLS");
    printf("\n\tDigite o valor desejado\n->");
    scanf("%d",&valor);
    return valor;
}
int menu()
{
    int opc;
    system("CLS");
    printf("\n\t~~~~  MENU  ~~~~");
    printf("\n1 - Inserir numero");
    printf("\n2 - Remover numero");
    printf("\n3 - Mostrar Lista");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\nOPC invalida, digite novamente....\n->");
        scanf("%d",&opc);
    }
    return opc;
}

int main()
{
    int opc,valor;
    inicializaFila();
    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            valor = pegaValor();
            if(listaVazia() == 1)
            {
                inserirPrimeiraVez(valor);
            }else
            {
                inserirOrdenado(valor);
            }
            opc = menu();
            break;
        case 2:
            valor = pegaValor();

            opc = menu();
            break;
        case 3:
            mostrarLista();
            printf("\n\n");
            system("pause");
            opc = menu();
            break;

        }
    }
    printf("\n\n\tAINDA FUNFANDO\n\n");
    return 0;
}
