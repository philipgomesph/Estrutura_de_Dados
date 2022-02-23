#include <stdio.h>
#include <stdlib.h>



struct aluno {
    char nome[40];
    char matri[40];
};


int main()
{

    struct aluno p[1];
    int i;

    for(i=0;i<2; i++){
    printf("\nDigite o nome do aluno\n");
    gets(p[i].nome);
    fflush(stdin);


    printf("\n\nDigite a matricula do aluno\n");
    gets(p[i].matri);
    fflush(stdin);

    system("cls");
    };






    return 0;
}
