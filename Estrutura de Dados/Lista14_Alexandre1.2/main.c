#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dado;
    struct no *prox;
    struct nov *ant;
}no;
no *inicio;
no *fim;

void incializaLista()
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
        return 0 ;
    }
}

void inserir_inicio_listaVazia(int valor)
{
    no *novo=(no*)malloc(sizeof(no));
    novo->dado=valor;
    novo->prox=NULL;
    novo->ant=NULL;

    if(inicio==NULL)
    {
        inicio=novo;
        fim=novo;
    }else
    {
        inicio->ant=novo;
        novo->prox=inicio;
        inicio=novo;

    }
}
void inserirFim(int valor)
{
    no *novo=(no*)malloc(sizeof(no));
    novo->dado=valor;
    novo->prox=NULL;
    novo->ant=NULL;

    fim->prox=novo;
    novo->ant=fim;
    fim=novo;
}

void inserirLista(int valor)
{
    no *aux;
    no *aux2;
    aux = inicio;
    if(listaVazia()==1) ///SE A LISTA é vazia
    {
        inserir_inicio_listaVazia(valor);

    }else /// ELA NAO É VAZIA
    {
        if(valor < aux->dado) /// SE O VALOR FOR MENOR Q O PRIMEIRO MEMBRO
        {
            inserir_inicio_listaVazia(valor);
        }
        else ///NAO É MENOR Q O PRIMEIRO MEMBRO
        {
            while(valor>aux->dado)///ENQUANTO VALOR MENOR Q A LISTA RODAR ELA
             {
                if(aux->prox==NULL)///SE FOR O ULTIMO MEMBRO
                {
                    inserirFim(valor);
                }
                    aux2 = aux;///ANTERIOR AO AUXILIAR
                    aux=aux->prox;/// AUXILIAR
             }
            if(valor<aux->dado)///APOS RODAR A LISTA, ACHAR O ESPAÇO E INSERIR ENTRE OS AUXILIARES
            {
                no *novo=(no*)malloc(sizeof(no));
                novo->dado=valor;
                novo->ant=aux2;
                novo->prox=aux;
                aux->ant=novo;
                aux2->prox=novo;
            }
        }
    }
}
void removerFim(int valor)
{
    no *aux;
    if(listaVazia()==1)
    {
        system("CLS");
        printf("\nLista vazia, impossivel remover...\n\n");
        system("pause");
    }else
    {
        aux=fim;
        fim=fim->ant;
        fim->prox=NULL;
        free(aux);
    }

}
void removerLista(int valor)
{
    int opc;
    no *aux;
    no *aux2;
    no *auxfree;
    aux=inicio;

    if(listaVazia()==1)
    {
        system("CLS");
        printf("\nImpossivel remover, lista vazia....\n\n");
        system("pause");
    }else
    {
        if(valor==aux->dado)///SE FOR O PRIMEIRO TERMO
        {
            inicio=aux->prox;
            free(aux);
        }else
        {
            while(valor != aux->dado) ///ENQUANTO O DADO FOR DIFERENTE
            {
                if(aux->prox==NULL)
                {
                    printf("\nValor nao encontrado....\n\n");
                    system("pause");
                    valor=aux->dado;
                }else
                {
                    aux2=aux;
                    aux=aux->prox;
                }

            }///QUANDO ACHAR O DADO IGUAL
            if(valor==aux->dado) ///REMOVE O DADO DA LISTA
            {
                if(aux->prox==NULL)
                {
                    removerFim(valor);
                }
                aux2->prox=aux->prox;
                aux=aux->prox;
                aux->ant=aux2;
            }
        }
    }
}

void mostra_lista()
{
    no *aux;
    aux =inicio;

  if(listaVazia()==1){
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

int pegaValor()
{
    int valor;
    system("CLS");
    printf("\nDigite o valor desejado");
    scanf("%d",&valor);
    return valor;
}
int menu()
{
    int opc;
    system("CLS");
    printf("\n  ~~~~  MENU  ~~~~");
    printf("\n1 - Inserir numero");
    printf("\n2 - Remover numero");
    printf("\n3 - Mostrar Lista");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\nOpc invalida, digite novamente....");
        scanf("%d",&opc);
    }
    return opc;
}

int main()
{
    int opc,valor;

    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            valor = pegaValor();
            inserirLista(valor);
            opc = menu();
            break;
        case 2:
            if(listaVazia()==1)
            {
                system("CLS");
                printf("\nImpossivel remover, lista vazia....\n\n");
                system("pause");
            }
            else{
                valor = pegaValor();
                removerLista(valor);
            }
            opc = menu();
            break;

        case 3:
            mostra_lista();
            printf("\n\n");
            system("pause");
            opc = menu();
            break;
        }
    }
    printf("\n\n\tAINDA FUNFANDO \n\n");
    return 0;
}
