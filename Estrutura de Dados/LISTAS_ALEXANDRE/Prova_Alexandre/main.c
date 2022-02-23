#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dado;
    struct lista *prox;
}lista;

lista *inicio;
lista *fim;

void inicializaLista()
{
    inicio = NULL;
    fim = NULL;
}
int listaVazia()
{
    if(inicio == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void inserirFim_lista(int dado)
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->dado=dado;
    novo->prox=NULL;
    if(inicio==NULL)///Lista vazia
    {
        inicio=novo;

    }
    else
    {
        fim->prox=novo;///PROXIMO DO FIM É O NOVO
    }
    fim=novo; ///O FIM AGORA É O NOVO
}
void inserirInicio_lista(int dado)
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));

    novo->dado=dado;
    novo->prox=NULL;

    if(fim==NULL)
    {
        fim=novo;
    }else
    {
        novo->prox=inicio;
    }
    inicio=novo;
}
void removerInicio_lista()
{
    if(listaVazia()==1)
    {
        printf("\nImpossivel remover\n");
        printf("\nFila vazia...\n\n");
        system("pause");
        return 0;
    }else
    {
        lista *aux;
        aux = inicio;
        inicio=inicio->prox;
        free(aux);
    }
}

void removerFim_lista()
{
    lista *aux;
    lista *auxFim;
    aux = inicio;
    auxFim = inicio;
    if(listaVazia()==1)
    {
        printf("\nImpossivel remover\n");
        printf("\nFila vazia...\n\n");
        system("pause");
    }
    else
    {
        while(aux->prox!= NULL)
        {
            auxFim = aux;
            aux=aux->prox;
        }
        fim =auxFim;

    }
    fim->prox=NULL;
}


void mostraLista()
{
    lista *aux;
    aux = inicio;
    while(aux!=NULL)
    {
        printf("\n| %d", aux->dado);
        aux = aux->prox;
    }

    printf("\n\n");
    system("pause");
}
int menuLista()
{
    int opc;
    system("CLS");
    printf("\n\t === MENU LISTA ===");
    printf("\n1 - Inserir inicio");
    printf("\n2 - Inserir fim");
    printf("\n3 - Remover inicio.");
    printf("\n4 - Remover fim.");
    printf("\n5 - Mostrar Lista.");
    printf("\n0 - Sair.\n->");

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
    int opc,opcLista,valor;
    inicializaLista();


    opcLista=menuLista();
    while(opcLista!=0)
    {
        switch(opcLista)
        {
        case 1:

            system("CLS");
            printf("\n\tDigite o valor a ser inserido no inicio da lista:\n");
            scanf("%d",&valor);
            inserirInicio_lista(valor);
            opcLista=menuLista();
            break;
        case 2:
            system("CLS");
            printf("\n\tDigite o valor a ser inserido no fim da lista:\n");
            scanf("%d",&valor);
            inserirFim_lista(valor);
            opcLista=menuLista();
            break;
        case 3:

            removerInicio_lista();
            opcLista=menuLista();

            break;
        case 4:
            removerFim_lista();
            opcLista=menuLista();

            break;
        case 5:
            mostraLista();
            opcLista=menuLista();

            break;
        }
    }

    printf("\n\n\t FILA, PILHA, E LISTA FIM/INICIO -> COMPLETA.... \n");
    return 0;
}
