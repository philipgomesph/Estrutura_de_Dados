#include <stdio.h>
#include <stdlib.h>


int menu()
{
    system("CLS");
    int opc;
    printf("\n1 - Inserir na primeira pilha");
    printf("\n2 - Inserir na segunda pilha");
    printf("\n3 - Comparar.");
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
    int opc;


    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }
    printf("\n\n\t  AINDA FUNFANDO \n\n");
    return 0;
}
