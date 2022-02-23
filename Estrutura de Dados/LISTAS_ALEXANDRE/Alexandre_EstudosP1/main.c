#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opc;
    system("CLS");
    printf("\n\n   ~~~~  MENU  ~~~~\n");
    printf("\n1 - Lista 4");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc<0 || opc>1)
    {
        printf("\n\nOPC invalida digite novamente\n->");
        scanf("%d",&opc);
    }
    return opc;
}

int lista6()
{
    system("CLS");

    printf("\n\n Lista 6");
    printf("\n
}
int main()
{
    int opc,retorno;

    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            retorno = lista6();
            opc = menu();
            break;
        }
    }
    printf("\n\n\t  AINDA FUNFANDO\n");
    return 0;
}
