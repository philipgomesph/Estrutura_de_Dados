#include <stdio.h>
#include <stdlib.h>
#define MAX 2




int menu()
{
    int opc;
    system("CLS");
    printf("\n1 - Inserir");
    printf("\n2 - Mostrar produtos pelo preco");
    printf("\n3 - Mostrar por quantidade");
    printf("\n0 - Sair\n");
    scanf("\n%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\n\nOPC invalida digite novamente...");
        scanf("\n%d",&opc);
    }
    return opc;
}


typedef struct
{
    char nome[30];
    double preco;
    int quantidade;
}produto[MAX];


void atribui(produto *vet)
{
    int i;
    system("CLS");
    //vet = (struct produto*)malloc(sizeof(struct produto)*MAX);
    vet = (produto*)malloc(MAX *sizeof(produto));
    for(i= 0; i<MAX ; i++)
    {
        printf("\n\nDigite o nome do produto %d",i);
        fflush(stdin);
        gets(&(*vet)[i].nome);



        printf("\nDigite o preco do produto");
        scanf("\n%d",&(*vet)[i].[i].preco);

    }

};
void mostraProduto(produto vet)
{
    int i;
    system("CLS");
    for(i=0; i<MAX;i++)
    {
        printf("\nNome do produto: %s",vet[i].nome);
        printf("\nPreco do produto: %d",vet[i].preco);
        //printf("\nQuantida do produto: %d",vet[i].quantidade);
    }
    system("pause");

}
int main()
{
    ///VARIAVEIS
    int opc;
    produto vet;

    while(opc !=0)
    {
        opc = menu();
        switch(opc)
        {
        case 1:
           atribui(&vet);
           opc = menu();
            break;
        case 2:
            mostraProduto(vet);
            break;
        case 3:
            break;
        }
    }
    printf("\n\n\t AINDA FUNFANDO \n\n");
    return 0;
}
