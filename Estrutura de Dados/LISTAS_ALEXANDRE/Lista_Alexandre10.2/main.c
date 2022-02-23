#include <stdio.h>
#include <stdlib.h>
///EXERCIOCIO 10-2.
///ALUNO: Philipe Matheus Gomes.
#define max 4
///VARIAVEIS
int topo;
int aux;

typedef struct
{
    int placa[max];
    int topo;
}pilha;

int menu()
{
    int opc;
    system("CLS");
    printf("\n1 - Estacionar carro.");
    printf("\n2 - Verificar carros estacionados.");
    printf("\n3 - Procurar por carro.");
    printf("\n0 - Sair.\n=>");
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\nOpc invalida, digite novamente....\n->");
        scanf("%d",&opc);
    }
    return opc;
}

void inicia_pilha(pilha *p)
{
    p->topo=-1;
}
int pilha_vazia(pilha *p)
{
    if(p->topo==-1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void inserir_pilha(pilha *p, int placa)
{

    p->topo++;
    p->placa[p->topo]=placa;
    printf("\n Placa [ %d ] inserida na vaga %d.\n\n", p->placa[p->topo], p->topo);
    system("pause");
}

void mostrar(pilha *p)
{
    pilha *aux;
    aux = p;
    while(aux->topo>-1)
    {
        printf("\n%d\n",aux->placa[aux->topo]);
        aux->topo--;
    }
    system("pause");
}

void retirar_carro(pilha *p,int compara)
{
    pilha *aux;
    aux =p;

    while(aux->topo>-1)
    {

        if(compara == p->placa[aux->topo])
        {
            aux->topo= -1;
        }else
        {
            printf("\Placa dos carros a frente: %d\n",aux->placa[aux->topo]);

        }
        aux->topo--;
    }

    system("pause");
}

int main()
{
    int opc,placa,compara;

    pilha *p;
    p = (pilha*)malloc(sizeof(pilha));
    inicia_pilha(p);
    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            system("CLS");
            printf("\nDigite o numero da placa: \n->");
            scanf("%d",&placa);
            while(placa>999 || placa<1)
            {
                printf("\nPlaca invalida, digite novamente...\n->");
                scanf("%d",&placa);
            }

            inserir_pilha(p,placa);
            opc= menu();
            break;
        case 2:
            mostrar(p);
            opc=menu();
            break;
        case 3:
            system("CLS");
            printf("\nDigite a placa do veiculo");
            scanf("%d",&compara);
              while(compara>999 || compara<1)
            {
                printf("\nPlaca invalida, digite novamente...\n->");
                scanf("%d",&compara);
            }
            retirar_carro(p,compara);
            opc=menu();
            break;
        }
    }

    printf("\n\n\t Obrigado por usar nosso sistema, ate a proxima....\n\n");
    return 0;
}
