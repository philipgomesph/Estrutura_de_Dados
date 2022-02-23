#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opc;

    system("CLS");
    printf("\n1 - Inserir alunos");
    printf("\n2 - Mostrar alunos");
    printf("\n3 - Inserir mais alunos");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);
    while(opc<0 || opc>3)
    {
        printf("\nOpc invalida, digite novamente\n");
        scanf("%d",&opc);
    }

    return opc;
}


typedef struct
{
    char nome[30];
    int id;
}pessoa;


void receber(pessoa *aluno,int tam)
{
    int i;
    system("CLS");
    for(i=0 ; i<tam;i++)
    {
        printf("\nDigite o nome do aluno: \n");
        fflush(stdin);
        gets(aluno[i].nome);

        printf("\nDigite o ID do aluno: \n ");
        scanf("%d",&aluno[i].id);
        printf("\n\n");
    }
}

void mostrar(pessoa *aluno, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\nNome do aluno: ");
        printf("%s",aluno[i].nome);
        printf("\nID do aluno: ");
        printf("\%d",aluno[i].id);
        printf("\n\n");
    }
    system("pause");
}
pessoa realocar(pessoa *aluno, int tam)
{



}

int boolean(int verifi)
{
    if(verifi==1)
    {
        return 1;
    }
}
int main()
{
    ///VARIAVEIS GLOBAIS
    int opc,tam;
    pessoa *aluno;

    printf("\nDIGITE A QUANTIDADE DE PESSOAS A SER CADASTRADAS....\n->");
    scanf("%d",&tam);
    //ALOCAÇAO GLOBAL
    aluno = (pessoa*)calloc(sizeof(pessoa),tam);
   int verifi;
    verifi=1;


    opc = menu();
    while(opc!=0)
    {
        switch(opc)
        {
        case 1:

            if(verifi==1)
            {
                receber(aluno,tam);
                verifi = 0;
            }
            else
            {
                system("CLS");
                printf("\nDados ja foram digitados, tente outra opc\n\n\n");
                system("pause");

            }
            opc= menu();
            break;
        case 2:
            mostrar(aluno,tam);

            opc = menu();
            break;
        case 3:
              system("CLS");

                int i,novoTamanho,aumenta;
                printf("\nDigite quantos alunos deseja realocar: \n\n");
                scanf("%d",&aumenta);
                novoTamanho = tam+aumenta;

                aluno = (pessoa*)realloc(aluno,sizeof(pessoa)*novoTamanho);
                if(aluno==NULL)
                {
                    printf("\nERRO DE MEMORIA..");
                    system("pause");
                }

                for(i=tam;i<novoTamanho;i++)
                {
                    printf("\nDigite o nome do novo aluno: ");
                    fflush(stdin);
                    gets(aluno[i].nome);

                    printf("\nDigite o ID do novo aluno: ");
                    scanf("%d",&aluno[i].id);
                 }

                tam = novoTamanho;
                opc=menu();
            break;
        }
    }


    printf("\n\n\n\tObrigado por usar nosso sistema, ate a proxima...\n\n\n");
    return 0;
}
