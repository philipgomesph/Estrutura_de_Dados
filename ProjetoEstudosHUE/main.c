#include <stdio.h>
#include <stdlib.h>
#include "pontoHUE.h"

int main()
{
    //VARAIVEIS GERAIS
    int opc;
    int opcLista;
    int opcPilha;
    int opcFila;
    int opcRecursao;
    int numFat;
    //VARIAVEIS INTERNAS
    struct pessoa *lista;
    struct pilha *pilha;
    struct fila *alguem;
    pilha = NULL;
    lista = NULL;
    alguem  = NULL;  //Vou usar "alguem" em vez de Fila, para poder desprender do comum

    opc = menu();

    while(opc!=0)
    {
        switch(opc)
        {
        case 1:                                            ///LISTA
            opcLista = menuLista();
            switch(opcLista)
            {
            case 0:
                opc = menu();
                break;
            case 1:
                lista = inserir(lista);

                break;
            case 2:
                mostrar(lista);

                break;
            case 3:
                lista = removerInicio(lista);
                break;
            case 4:
                lista = removerFim(lista);
                break;
            }
            break;
        case 2:                                           ///PILHA
            opcPilha = menuPilha();
            switch(opcPilha)
            {
            case 0:
                opc = menu();
                break;
            case 1:
                pilha = inserirPilha(pilha);
                break;
            case 2:
                mostrarPilha(pilha);
                break;
            case 3:
                pilha = removerPilha(pilha);
                break;
            }
            break;
        case 3:                                           ///FILA
            opcFila = menuFila();
            switch(opcFila)
            {
            case 0:
                opc = menu();
                break;
            case 1:
                alguem = inserirFila(alguem);
                break;
            case 2:
                mostrar(alguem);
                break;
            case 3:
                alguem = removerFila(alguem);
                break;
            }
            break;
        case 4:
           opcRecursao = menuRecursao();                  ///RECURSAO
           switch(opcRecursao)
           {
           case 0:
               opc = menu();
                break;
           case 1:
                system("CLS");
                printf("Digite qual numero deseja saber o fatorial:\n");
                scanf("%d",&numFat);
                numFat = fatorial(numFat);
                printf("\n\nResultado: %d\n\n", numFat);
                printf("\n\n");
                system("pause");

                break;
           case 2:
               lista = removerRecursao(lista);
                break;
           case 3:
               mostrar(lista);
                break;
           }
            break;
        case 5:
            break;
        }
    }

    printf("\n\n\t AINDA FUNFANDO :B\n");
    return 0;
}

int menu()
{
    int opc;
    system("CLS");
    printf("\n\tEscolha uma opcao\n");
    printf("\n1 - Lista");                         ///COMPLETO
    printf("\n2 - Pilha");                         ///COMPLETO
    printf("\n3 - Fila");                          ///COMPLETO
    printf("\n4 - Recursao");                      ///FAZER + EXERCICIOS
    printf("\n5 - Lista com prioridade\n");        ///CONTEUDO EM FALTA.
    printf("\n0 - Sair.\n");
    scanf("%d", &opc);
    while(opc<0 || opc>5)
    {
        printf("\n\nOpc invalida, digite novamente ...");
        scanf("%d", &opc);
    }
    return (opc);
}
int menuLista()
{
    int opcLista;
    system("CLS");
    printf("\n\tSelecione uma opc da LISTA\n");
    printf("\n1 - Adicionar membro");
    printf("\n2 - Mostrar membros");
    printf("\n3 - Remover no Inicio");
    printf("\n4 - Remover no Fim");
    printf("\n0 - Retornar.\n");
    scanf("%d",&opcLista);

    while(opcLista<0 || opcLista>4)
    {
        printf("\n\nOpc invalida, digite novamente ...");
        scanf("%d", &opcLista);
    }

    return(opcLista);
}
int menuPilha()
{
    int opcPilha;
    system("CLS");
    printf("\n\tSelecione uma opc da PILHA\n");
    printf("\n1 - Adicionar membro");
    printf("\n2 - Mostrar membros");
    printf("\n3 - Remover membro");
    printf("\n0 - Retornar.\n");
    scanf("%d",&opcPilha);
    while(opcPilha<0 || opcPilha>3)
    {
        printf("\n\nOpc invalida, digite novamente ...");
        scanf("%d", &opcPilha);
    }
    return(opcPilha);
}
int menuFila()
{
    int opcFila;
    system("CLS");
    printf("\n\tSelecione uma opc da FILA\n");
    printf("\n1 - Adicionar membro");
    printf("\n2 - Mostrar membros");
    printf("\n3 - Remover membro");
    printf("\n0 - Retornar.\n");
    scanf("%d",&opcFila);
    while(opcFila<0 || opcFila>3)
    {
        printf("\n\nOpc invalida, digite novamente ...");
        scanf("%d", &opcFila);
    }
    return(opcFila);
}

int menuRecursao()
{
    int opc;
    system("CLS");
    printf("\n\tSelecione um exercicio\n");
    printf("\n1 - Fatorial");
    printf("\n2 - Limpar Lista c/ Recursao");
    printf("\n3 - Mostrar a Lista");
    printf("\n0 - Retornar.\n");
    scanf("%d",&opc);
    while(opc < 0 || opc>3)
    {
        printf("\n\nOPC invalida, digite novamente ...");
        scanf("%d",&opc);
    }
    return(opc);
}

int fatorial(int numFat)
{
    if(numFat==0)
    {
        return 1;
    }
    else
    {
        return numFat*fatorial(numFat-1);
    }
}
