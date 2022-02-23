#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *p;

    p = (int*)calloc(sizeof(int),3);


    for(i=0;i<3;i++)
    {
        printf("Digite o valor do vetor na posicao %d: \n",i);
        scanf("%d",&p[i]);
    }
    system("CLS");
     for(i=0;i<3;i++)
     {
         printf("\nOs valores do vetor na posicao %d:\n->",i);
         printf("%d",p[i]);
     }




    printf("\n\n\t  AINDA FUNFANDO\n");
    return 0;
}
