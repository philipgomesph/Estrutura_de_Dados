#include <stdio.h>
#include <stdlib.h>

int main()
{

    int XC,V;

    float f,Corre;
    printf("\n\n");

    f=200;
    for(int i= 0; i<10;i++)
    {
        V=100;
        XC = (1/(2*3.1415*f*0.5*0.000001));
        Corre = (V/XC);

        printf("XC para frequencia %f: ",f);
        printf("\n%d",XC);

        printf("\nCorrente: \n");
        printf("%f",Corre);
        printf("\n\n");
        f = f +200;
    }





    printf("\n\n");
    printf("Hello world!\n");
    return 0;
}
