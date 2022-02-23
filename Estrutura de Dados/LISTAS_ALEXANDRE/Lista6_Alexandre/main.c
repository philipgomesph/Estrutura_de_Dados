#include <stdio.h>
#include <stdlib.h>

///Aluno: Philipe M. Gomes.



int menu()
{
    system("CLS");
    int opc;
    printf("\n\n    ~~~~   MENU   ~~~~");
    printf("\n1 - Inverter vetor");                     ///COMPLETO
    printf("\n2 - Multiplica vetor");                   ///COMPLETO
    printf("\n3 - Recebe e Imprimi aluno pela media");
    printf("\n0 - Sair.\n->");
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\n\nOpc invalida, digite novamente\n->");
        scanf("%d",&opc);
    }
    return opc;
}

void inverte(int *v1,int tam)
{
    int i,j;
    int *v2;
    system("CLS");
    printf("\nInverter vetor");
    printf("\nDigite o tamanho do vetor\n->");
    scanf("%d",&tam);
    v1=(int*)calloc(sizeof(int),tam);
    v2=(int*)calloc(sizeof(int),tam);
    printf("\nDigite os valores do vetor");
    for(i=0;i<tam;i++)
    {
        printf("\nValor da posicao %d : \n->",i);
        scanf("%d",&v1[i]);

    }
    j = tam-1;
    for(i=0;i<tam;i++)
    {

        v2[j]=v1[i];
        j--;
    }
    printf("\n\nO vetor invertido");
    for(i=0;i<tam;i++)
    {
        printf("\nVetor invertido na posicao %d\n",i);
        printf("%d",v2[i]);
    }
    printf("\n\n");
    system("pause");
}

void multiplica(int *v1,int tam)
{
    int i;
    int *v2;
    v2 = (int*)calloc(sizeof(int),tam);
    system("CLS");
    printf("\nMultiplica vetor.");
    printf("\nDigite o tamanho do vetor\n->");
    scanf("%d",&tam);
    v1=(int*)calloc(sizeof(int),tam);
    v2=(int*)calloc(sizeof(int),tam);
    printf("\nDigite os valores do vetor");
    for(i=0;i<tam;i++)
    {
        printf("\nValor da posicao %d : \n->",i);
        scanf("%d",&v1[i]);

    }
    printf("\nDigite o vetor multiplicador");
    for(i=0;i<tam;i++)
    {
        printf("\nDigite o valor do vetor na posicao %d:\n->",i);
        scanf("%d",&v2[i]);
    }
    printf("\nO vetor resultante\n");
    for(i=0;i<tam;i++)
    {
        v2[i] = v2[i]*v1[i];
        printf("\nPosicao %d :",i);
        printf("%d",v2[i]);
    }
    printf("\n\n");
    system("pause");
}

typedef struct
{
    char nome[30];
    float medias;
    int faltas;
}aluno;

void mostraAluno(aluno *novo,int tam)
{

    system("CLS");
    int i, j, min;
    float aux;
    aux= -1;
    float *v1;
    printf("\n\tAlunos");
    printf("\nDigite o numero de alunos:\n");
    scanf("%d",&tam);
    novo = (aluno*)calloc(sizeof(aluno),tam);
    for(i=0;i<tam;i++)
    {
        printf("\nDigite os dados do aluno: %d  ",i);
        printf("\nNome:\n-> ");
        fflush(stdin);
        gets(novo[i].nome);
        printf("\nNota do aluno %d: \n->",i);
        scanf("%f",&novo[i].medias);
        printf("\nFaltas do aluno %d  \n->",i);
        scanf("%d",&novo[i].faltas);
    }
    system("CLS");
/*
    for(i=0;i<tam;i++)
    {
        v1[i]= novo[i].medias;
    }
    for(i=0; i<(tam-1);i++)
    {
        min = i;
        for(j=(i+1);j<tam;j++)
        {
            if(v1[j]<v1[min])
                min = j;
        }
        if(v1[i] != v1[min])
        {
            aux = v1[i];
            v1[i] = v1[min];
            v1[min]=aux;
        }
    }





    printf("\nAs Notas ordenadas sao: \n");
    for(i=0;i<tam;i++)
    {
        printf("\nNota %d: ", i );
        printf("%f",v1[i]);

    }
    */
    printf("\n\n");
    system("pause");
}
int main()
{
    ///VARIAVEIS GLOBAIS
    int opc,tam;
    int *v1;
    aluno *novo;
    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            inverte(v1, tam);
            opc = menu();
            break;
        case 2:
            multiplica(v1,tam);
            opc=menu();
            break;
        case 3:
            mostraAluno(novo,tam);
            opc=menu();
            break;

        }
    }

    printf("\n\n\t AINDA FUNFANDO \n\n");
    return 0;
}
