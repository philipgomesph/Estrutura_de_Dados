#include <stdio.h>
#include <stdlib.h>

struct produto
{
    char nome[30];
    double preco;
    int qtd;
    struct produto *prox;
};

int menu()
{
    int opc;
    system("CLS");
    printf("\n\t~~MENU~~");
    printf("\n1 - Inserir");
    printf("\n2 - Mostrar produto");
    printf("\n3 - Mostrar pelo preco");
    printf("\n4 - Mostrar pela quantidade");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);

    while(opc<0 || opc>4)
    {
        printf("\nOPC invalida, digite novamente...\n");
        scanf("%d",&opc);
    }


}

struct produto *inserir(struct produto *lista)
{
    //Variaveis da funcao
    struct produto *aux;
    struct produto *novo;

    //Variaveis Temporaria
    char nomeTemp[30];
    double precoTemp;
    int qtdTemp;

    system("CLS");
    printf("\nDigite o nome do produto:\n");
    fflush(stdin);
    gets(nomeTemp);

    printf("\nDigite o preco:\n");
    scanf("%d",&precoTemp);
    while(precoTemp<0)
    {
        printf("\nPreco invalido digite novamente:\n");
        scanf("%d",&precoTemp);
    }

    printf("\nDigite a quantidade do produto:\n");
    scanf("%d",&qtdTemp);
    while(qtdTemp<1)
    {
        printf("\nQuantidade informada invalida, digite novamente:\n");
        scanf("%d",&qtdTemp);
    }

    novo = (struct produto*) malloc(sizeof(struct produto));

    strcpy(novo->nome, nomeTemp);
    novo->preco = precoTemp;
    novo->qtd = qtdTemp;
    novo->prox = NULL;

    aux = lista;
    if(aux==NULL)
    {
        lista = novo;
    }
    else
    {
        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return(lista);
};
void mostrarProduto(lista)
{
    struct produto *aux;

    aux = lista;



    if(lista == NULL)
    {
        printf("\nLista vazia...\n\n");
    }


    while(aux !=NULL)
    {
        printf("\nNome do produto: %s", aux->nome);
        printf("\nPreco do produto: %d", aux->preco);
        printf("\nQuantidade do produto: %d\n\n",aux->qtd);
        aux=aux->prox;
    }



return 0;
}

void mostrarPreco(lista)
{

    struct produto *aux;

    aux = lista;
    if(lista == NULL)
    {
        printf("\nLista vazia...\n\n");

    }
    if(lista->preco > aux->preco)
    {

    }

}



int main()
{

    ///variaveis globais
    int opc;

    ///variaveis de estrutura
    struct produto *lista;
    lista = NULL;

    ///menu
    opc = menu();

    ///desenvolvimento
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            lista = inserir(lista);
            opc = menu();
            break;
        case 2:
            mostrarProduto(lista);
            system("pause");
            opc = menu();
            break;
        case 3:
            mostrarPreco(lista);
            system("pause");
            opc = menu();
            break;
        }
    }

    printf("\n\n\n\tAINDA FUNFANDO!!!!\n\n");
    return 0;
}
