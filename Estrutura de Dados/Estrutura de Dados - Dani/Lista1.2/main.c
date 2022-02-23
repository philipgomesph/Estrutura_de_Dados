#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct aluno{
    char nome[20];
    int matri;
    int p1,p2,p3;

};

int main()
{
    printf("============================ MENU ============================");

    struct aluno p[1];
    int i;




    for(i=0;i<2;i++)
    {
        printf("\n\nDigite o nome do aluno...\n");
        fflush(stdin);
        gets(p[i].nome);
        printf("\nDigite a matricula...\n");
        scanf("%d",&p[i].matri);
        fflush(stdin);
        printf("\nDigite a nota da p1...\n");
        scanf("%d",&p[i].p1);
        printf("\nDigite a nota da p2...\n");
        scanf("%d",&p[i].p2);
        printf("\nDigite a nota da p3...\n");
        scanf("%d",&p[i].p3);
        system("cls");
        fflush(stdin);

    }



    return 0;
}
