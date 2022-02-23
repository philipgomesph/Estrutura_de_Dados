#include <stdio.h>
#include <stdlib.h>

///ALUNO: Philipe M Gomes.
typedef struct
{
    int info;
    struct lista *prox;
}lista;

lista *inicio;
lista *fim;

void inicializaFila()
{
    inicio=NULL;
    fim=NULL;
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


void inserirFim_lista(int info)
{
   lista *novo;
   novo = (lista*)malloc(sizeof(lista));
   novo->info=info;
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
void inserirInicio_lista(int info)
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->info=info;
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

void mostraLista()
{
    lista *aux;
    aux = inicio;
    printf("\nClientes na Fila: ");
    while(aux!=NULL)
    {
        printf("\n | %d", aux->info);
        aux = aux->prox;
    }
    printf("\n\n");
    system("pause");
}

int menu()
{
    int opc;
    system("CLS");
    printf("\n\t~~~~  MENU  ~~~~");
    printf("\n1 - Inserir valores no vetor.");
    printf("\n2 - Inserir vetor na lista.");
    printf("\n3 - Mostrar lista.");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc>3 || opc<0)
    {
        printf("\nOpc invalida, digite novamente...\n->");
        scanf("%d",&opc);
    }
}

void receberVetor(int *v,int max)
{
    int i;
    system("CLS");
    v = (int*)calloc(sizeof(int),max);
    for(i=0;i<max;i++)
    {
        printf("\nDigite o valor do vetor na posicao %d:\n->",i);
        scanf("%d",&v[i]);
    }


    for(i=0 ; i<max;i++)
    {
        printf("\n Valor do vetor na posicao %d\n",i);
        printf("%d",v[i]);
    }

   // return *v;
}

int confirmaEntrada(int confirm)
{
    system("CLS");
    printf("\nDeseja inserir os valore do vetor na lista:");
    printf("\n1 - Sim");
    printf("\n0 - Nao\n->");
    scanf("%d",&confirm);
    while(confirm<0 || confirm>1)
    {
        printf("Opc invalida, digite novamente...\n->");
        scanf("%d",&confirm);
    }
    return confirm;
}
int main()
{
    int opc,max,confirm,valor;
    int *v;
    valor=0;
    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            system("CLS");
            printf("\nQuantas posicoes o vetor devera ter:\n->");
            scanf("%d",&max);
            if(max==0)
            {
                if(listaVazia()==1)
                {
                    printf("\n\tlista vazia....\n\n");
                    system("pause");
                }
            }else
            {
               /// receberVetor(v,max);
            int i;
            system("CLS");
            v = (int*)calloc(sizeof(int),max);
            for(i=0;i<max;i++)
            {
                printf("\nDigite o valor do vetor na posicao %d:\n->",i);
                scanf("%d",&v[i]);
            }


            for(i=0 ; i<max;i++)
            {
                printf("\n Valor do vetor na posicao %d\n",i);
                printf("%d",v[i]);
            }

                    }
            opc = menu();
            break;
        case 2:
            confirm = confirmaEntrada(confirm);
            if(confirm==1)
            {
                for(int i=0;i<max;i++)
                {
                    valor=v[i];
                    inserirInicio_lista(valor);
                }
                system("pause");
                opc = menu();
            }else
            {

                opc = menu();
            }
            break;
        case 3:

            if(listaVazia()==1)
            {
                printf("\n\tlista vazia....\n\n");
                system("pause");
            }else
            {
                mostraLista();
            }
            opc = menu();
            break;
        }
    }
    printf("\n\n\tObrigado por usar nosso sistema, ate a proxima !!!\n");
    return 0;
}
