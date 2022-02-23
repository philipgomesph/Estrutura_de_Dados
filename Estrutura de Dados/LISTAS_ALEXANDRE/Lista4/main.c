#include <stdio.h>
#include <stdlib.h>
#define MAX 4
///ALUNO:  Philipe M Gomes


int atribuirValor(int *valores, int num)
{
    int i;
   for(i = 0; i<num; i++)
   {
       printf("\nInsira valor %d:\n",i+1);
       scanf("%d",&valores[i]);
   }
   return valores;
}
int mostrarValores(int *vet,int num)
{
    int i;
    int min,max;
    min = 9999999;
    max = -99999;
    for(i = 0; i<num; i++)
    {
        if(min>vet[i])
        {
            min = vet[i];
        }
        if(vet[i]>max)
        {
            max = vet[i];
        }
    }
    printf("\nMaior valor do vetor %d",max);
    printf("\nMenor valor do vetor %d\n\n",min);


}

int inverterVetor(int *vet,int num)
{
    int vet2[num];
    int j;
    int i;
    int k;
    j = MAX-1;

    for(i=0; i<num ; i++)
    {
       vet2[j] = vet[i];
       j--;

    }
    k=0;
    for(k = 0; k<num; k++)
    {
        printf("\nVetor 2 posicao %d:", k+1);
        printf("\n%d",vet2[k]);
    }
}


int main()
{
    ///variaveis gerais
    int vet[MAX];
    int min,max;

    atribuirValor(vet,MAX);
    mostrarValores(vet,MAX);
    inverterVetor(vet,MAX);

    printf("\n\n\t  Obrigado por utilizar nosso sistema, ate a proxima! \n\n\n");
    return 0;
}
