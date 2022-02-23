#include "pacienteH.h"


struct paciente *inserir(struct paciente *lista)
{
    char nomeTemp[30];
    int telTemp;

    struct paciente *aux;
    struct paciente *novo;

    system("CLS");
    printf("\n\t Dados do Paciente");
    printf("\nNOME: ");
    fflush(stdin);
    gets(nomeTemp);
    printf("\nTELEFONE: ");
    scanf("%d",&telTemp);

    //VERIFICANDO CONDIÇOES
    while(telTemp<0)
    {
        printf("\n\nTelefone invalido, digite novamente\n");
        scanf("%d",telTemp);
    }
    novo = (struct paciente*)malloc(sizeof(struct paciente));
    strcpy(novo->nome,nomeTemp);
    novo->tel= telTemp;
    novo->prox = NULL;


    //DECIDINDO ONDE COLOCAR

    aux = lista;

    if( aux == NULL)
    {
        lista = novo;
    }
    else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return(lista);
};


void mostrar(struct paciente *lista)
{
    struct paciente *aux;

    aux = lista;
    system("CLS");
    if(aux == NULL)
    {
        printf("\n\tLista vazia\n\n");
    }
    else
    {
        printf("\n\tDADOS DA FILA");
        while( aux!=NULL)
        {
            printf("\nNOME: %s",aux->nome);
            printf("\nTELEFONE: %d\n", aux->tel);
            aux= aux->prox;
        }
    }

    system("pause");
}
struct paciente *remover(struct paciente *lista)
{
    struct paciente *aux;

    aux = lista;
    if(aux == NULL)
    {
        printf("Lista Vazia, impossivel remover\n\n");
        system("pause");
    }
    else
    {
        lista = lista->prox;
        free(aux);
    }
    return lista;
};

struct paciente *removerRecursao(struct paciente *lista)
{
    if(lista == NULL)
    {
        printf("Lista Vazia\n\n");
        system("pause");
    }
    else
    {
        return removerRecursao(remover(lista));

    }

};


/*struct paciente *removerRecursao(struct paciente *lista)
{
    if(lista == NULL)
    {
        printf("Lista Vazia\n\n");
        system("pause");
    }
    else
    {

        lista = remover(removerRecursao(lista->prox));
    }
};
*/

