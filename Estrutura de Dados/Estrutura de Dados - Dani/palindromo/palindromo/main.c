#include "pilha.h"

int main()
{
    Pilha p = Cria_pilha();
    char palavra[MAX], invertida[MAX];
    int i=0;

    printf("informe uma frase: ");
    fflush(stdin);
    gets(palavra);

    for (i=0; i < strlen(palavra);i++)//funcao length retorna o tamanho da string
    {
        if (Push(p,palavra[i]) == 0)
        {
         printf("Pilha cheia!");
         i = MAX;//força a saida do laço
        }
    }
    printf("%i\n", p->topo);

    for (i=0; i<strlen(palavra);i++)
    {
        invertida[i]=Pop(p);
    }
    invertida[i]='\0';

    printf("%i\n", p->topo);

    if (strcmp(palavra,invertida)==0)
        printf("é um palindromo\n");
    else
        printf("nao eh um palindromo\n");

    return 0;
}
