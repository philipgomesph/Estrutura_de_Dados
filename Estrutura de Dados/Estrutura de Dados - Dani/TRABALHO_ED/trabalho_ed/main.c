#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "trab.h"
int menu()
{
    printf("\t\t\tMENU.\n");
    printf("1 para inserir funcionario.\n");
    printf("2 para mostrar funcionario.\n");
    printf("3 para encontrar o maior nome.\n");
    printf("0 para fechar o programa.\n");
    int opc;
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("Valor invalido informe outro.\n");
        scanf("%d",&opc);
    }
    return opc;
}
//========================================================
Func novofuncionario(Func novo)
{
    printf("Informe o nome do funcionario.\n");
    fflush(stdin);
    gets(novo.nome);
    printf("Informe a matricula.\n");
    scanf("%d",&novo.matricula);
    printf("Informe o salario.\n");
    scanf("%f",& novo.salario);
    while(novo.salario<=0)
    {
        printf("Salario invalido, informe outro.\n");
        scanf("%f",& novo.salario);
    }
    return novo;
}
//=========================================================
void maiorNome(lista *inicio)
{
    int maior;
    lista *aux = inicio;
    maior = strlen(aux->func.nome);

    char maiorn[30];
    strcpy(maiorn,aux->func.nome);
    while (aux != NULL)
    {
        if (maior < strlen(aux->func.nome))
        {
            maior = strlen(aux->func.nome);
            strcpy(maiorn,aux->func.nome);
        }
        aux = aux->prox;
    }

    printf("O maior nome e do: %s", maiorn);
    char *sobrenome=NULL;
    sobrenome = strrchr(maiorn,' ');
    if(sobrenome!= NULL)
        printf("\n O Sobre nome e: %s.",sobrenome+1);

}
//========================================================
int main()
{
    Func novo;
    lista *inicio=NULL;
    int opc;
    lista *aux=inicio;
    opc=menu();
    while(opc!=0)
    {
        system("cls");
        if(opc==1)
        {
            system("cls");
            novo=novofuncionario( novo);
            if(inicio!=NULL)
            {
                while(aux!= NULL)
                {
                    if(novo.matricula==aux->func.matricula)
                    {
                        printf("Essa matricula ja existe, informe outra.\n");
                        scanf("%d",&novo.matricula);
                        aux=inicio;
                    }
                    aux=aux->prox;
                }
            }
            inicio = inserir(inicio, novo);

        }
        else
            {
                if(opc==2)
                {
                    system("cls");
                    imprimir( inicio);

                }
                else
                {
                    maiorNome(inicio);
                }
            }
            opc=menu();
    }


}
