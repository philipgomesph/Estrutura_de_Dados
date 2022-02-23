#include <stdio.h>
#include <stdlib.h>
#include "ponto_h.h"
int main()
{
    //variaveis comuns.
    int opc;
    int opc2;
    //variaveis padrao ED
    lista *pilha;





    opc = menu();

      while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            {


            system("cls");
//            novo = novo_funcionario(novo);

            }
            break;
        case 2:
            {
                system("cls");

            }
            break;
        case 3:
            {
                system("cls");

            }
            break;
        case 4:
            {
                pilha = cria_pilha(pilha);
            }


        }
        opc = menu();
    }




    printf("\n\n\t  AINDA FUNCIONANDO \n\n\n");
    return 0;
}



int menu()
{
    int opc;

    printf("\n\t~~~~  MENU  ~~~~\n\n");
    printf("\nDigite uma opçao.");
    printf("\n1 - Inverter ordem.");
    printf("\n2 - Inverter topo com base.");
    printf("\n3 - Separar impares e pares.");
    printf("\n4 - Inserir elemento na pilha");
    printf("\n0 - Sair.\n");
    scanf("\n%d",&opc);

    while(opc<0 || opc>4)
    {
        printf("Opçao invalida digite novamente.\n");
        scanf("\n%d",&opc);

    }
    return opc;
}
