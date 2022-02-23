#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opc;
    system("CLS");
    printf("\n\n\t~~MENU~~");
    printf("\n1 - Exercicio 1");
    printf("\n2 - Exercicio 2");
    printf("\n3 - Exercicio 3");
    printf("\n4 - Exercicio 4");
    printf("\n5 - Exercicio 5");
    printf("\n6 - Exercicio 6");
    printf("\n0 - Sair.\n");
    scanf("%d",&opc);
    while(opc<0 || opc>6)
    {
        printf("\n Opicao invalida, digite novamente: \n");
        scanf("%d",&opc);
    }
    return opc;
}

void trocaValor(int *p)
{
    *p = 10;
    return *p;
}

int exer2 ()
{
    float a;
    float b;
    float *p;


    printf("\nDigite um numero do tipo real para A: \n");
    scanf("%f",&a);
    printf("\nDigite um numero do tipo real para B: \n");
    scanf("%f",&b);
    p = &b;
    printf("\nConteudo de A: %f",a);
    printf("\nEndereco de A: %d",&a);
    printf("\nConteudo de B: %f",b);
    printf("\nEndereco de B: %d",&b);
    printf("\nConteudo de *P: %f",p);
    printf("\nEndereco de *P: %d\n\n",&p);
return 0;
}

int exer3()
{
   int x = 42;
   int* pt=&x;
   printf("x = %d\n",x);
   printf("&x = %d\n",&x);
   printf("pt = %d\n",pt);
   printf("%pt = %d\n",&pt);
   printf("*pt = %d\n\n\n",*pt);

   return 0;
}

int exer4(int x, int y)
{
    int soma;
    int produto;

    soma= x + y;
    produto = x*y;

    if(soma> 33767 || soma< - 33767){
        printf("\nEstorou a faixa dos reais");
        return -1;
    }
    if(produto>33767 || produto< -33767)
    {
        printf("\nEstorou a faixa dos reais");
    return -1;
    }
    else{
        if(x == y)
            return 1;
        if(x != y)
            return 0;
    }
}
int main()
{
    ///Variaveis globais
    int opc;
    ///variaveis ex1
    int x1;
    int x;
    int y;




    opc = menu();
while(opc!= 0){
    switch(opc)
    {
        case 1:
            trocaValor(&x1);
            printf("\n%d\n\n", x1);
            system("pause");
            opc = menu();
        break;

        case 2:
            x1 = exer2();
            system("pause");
            opc = menu();
        break;

        case 3:
            x1 = exer3();

            system("pause");
            opc = menu();

        break;

        case 4:
            printf("\nDigite dois numeros");
            printf("\nPrimeiro numero: ");
            scanf("\n %d", &x);
            printf("\nSegundo numero: ");
            scanf("\n %d", &y);
            x1 = exer4(x,y);

            printf("\n\nresultado: %d\n",x1);
            system("pause");
            opc = menu();
        break;

        case 5:

        break;

        case 6:
        break;
    }


}
    printf("\n\n\t  AINDA FUNFANDO \n");
    return 0;
}
