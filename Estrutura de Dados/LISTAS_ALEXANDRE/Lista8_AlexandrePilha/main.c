#include <stdio.h>
#include <stdlib.h>
///ALuno: Philipe M. Gomes.





int menu()
{
    int opc;

    system("CLS");
    printf("\n\t~~~~  MENU  ~~~~");
    printf("\n1 - Inserir na pilha");
    printf("\n2 - Mostrar Pilha.");
    printf("\n3 - Remover topo da Pilha.");
    printf("\n4 - Inverter Pilha.");
    printf("\n5 - Qual Pilha tem mais elementos.");
    printf("\n6 - Ver se as duas pilhas sao iguais.");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc<0 || opc>6)
    {
        printf("\nOPC invalida, digite novamente...\n->");
        scanf("%d",&opc);
    }
    return opc;
}

void inserir_topo(int topo)
{

}
int main()
{
    ///VARIAVEIS GLOBAIS
    int opc;
    int *p;

    p = (int*)malloc(sizeof(int));
    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:

            break;
        }
    }
    printf("\n\n\t  AINDA FUNFANDO \n");
    return 0;
}
