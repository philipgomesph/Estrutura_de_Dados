#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opc;
    system("CLS");
    printf("\n1 - Inserir Pessoas");
    printf("\n2 - Mostrar Pessoas");
    printf("\n3 - Inseir novas pessoa");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\nOPC invalida, digite novamente: \n");
        scanf("%d",&opc);
    }

    return (opc);
}

void inserir(int *p,int tam)
{


    int i;
    for(i=0; i<tam;i++)
    {
        printf("\nDigite um numero desejado");
        scanf("\n%d", &p[i]);
    }
}
void mostrar(int*p,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\nValor na posicao %d:  ",i);
        printf("%d",p[i]);
    }
    printf("\n\n");
    system("pause");
}


int main()
{
    ///VARIAVEIS
    int opc,tam;
    int *p;


    printf("\n\n\tInforme o tamanho do cadastro\n->");
    scanf("\n%d",&tam);

    p = (int*)calloc(sizeof(int),tam);

    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:

            inserir(p,tam);
            opc=menu();

            break;
        case 2:
            mostrar(p,tam);
            printf("\n");


            opc=menu();

            break;
        case 3:
            system("CLS");

            int i,aumenta,novoTamanho;

            printf("\nDeseja aumentar quantas pessoas: \n\n");
            scanf("%d",&aumenta);
            novoTamanho = tam+aumenta;

            p = (int*)realloc(p,sizeof(int)*aumenta);
            if(p == NULL)
            {
                printf("\nERRO de memoria");
                system("pause");
            }

            for(i=tam;i<novoTamanho;i++)
            {
                printf("\nDigite o novo numero na posicao %d :\n", i);
                scanf("%d",&p[i]);
            }


            tam = novoTamanho;

            opc=menu();
            break;
        }
    }


    printf("\n\n\tAINDA FUNFANDO\n");
    return 0;
}
