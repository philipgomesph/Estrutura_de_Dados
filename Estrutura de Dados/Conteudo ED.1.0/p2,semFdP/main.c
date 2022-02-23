#include <stdio.h>
#include <stdlib.h>
#include "pacienteH.h"
int main()
{
    //VARIAVEIS GERAIS
    int opc;
    int qtdP=0;
    //VARIAVEIS ESTRUTURA
    struct paciente *lista;
    lista = NULL;


    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            lista = inserir(lista);
            qtdP++;
            opc = menu();
            break;
        case 2:
            system("CLS");
            printf("\n\tNumero de pessoas na fila: \n");
            printf("\t%d\n\n",qtdP);
            system("pause");
            opc = menu();
            break;
        case 3:
            mostrar(lista);
            opc = menu();
            break;
        case 4:
            lista = remover(lista);
            qtdP--;
            opc = menu();
            break;
        case 5:
            lista = removerRecursao(lista);
            opc = menu();
            break;
        }

    }
    printf("\t\n  AINDA FUNCIONANDO \n");
    return 0;
}
int menu()
{
    int opc;
    system("CLS");
    printf("\t\n   MENU");
    printf("\n1 - Inserir paciente");
    printf("\n2 - Quantidade de pessoas na fila");
    printf("\n3 - Mostrar fila");
    printf("\n4 - Remover proximo da fila");
    printf("\n5 - Liberar toda fila");
    printf("\n0 - Sair.\n");
    scanf("%d", &opc);

    while(opc<0 || opc>5)
    {
        printf("\n\nOPC invalida, digite novamente...\n");
        scanf("%d",&opc);
    }

    return(opc);
}
