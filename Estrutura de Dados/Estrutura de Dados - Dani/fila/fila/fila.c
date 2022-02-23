#include "fila.h"

Fila Cria_fila(int nro_elem)
{
    Fila f;

    f = (Fila)malloc(sizeof(struct queue));



    if (f != NULL) //se o malloc conseguiu alocar memoria
        {
            f->FF = f->IF = f->N = 0;

        }

    return f;

}

//Verificar se fila está cheia
int e_cheia(Fila f) //retorna 1 se estiver e 0 se não estiver
{
        if (f->N == MAX_FILA)
            return 1;
        else
            return 0;
}

//Verificar se fila está vazia
int e_vazia(Fila f) //retorna 1 se estiver vazia e 0 se não estiver
{
    if (f->N == 0)
        return 1;
    else
        return 0;
}


// Inserir um nodo no final da fila
int enqueue(Fila f, int elem) //retorna 1 se inseriu e 0 se não inseriu
{
    if (e_cheia(f) == 1)
    {
     return 0;
    }
    else
    {
            f->fila[f->FF] = elem;


            if (f->FF == MAX_FILA-1) // esse if equivale a f->FF = (f->FF+1)%MAX_FILA;
                f->FF = 0;
            else
                (f->FF)++;

            (f->N)++;

            return 1;
    }
}
 //Excluir o nodo do início da fila
int dequeue(Fila f)
{
int elem;
	if(e_vazia(f) == 1)
	return 0;
else
	{
	elem = f->fila[f->IF];
	f->IF = (f->IF-1)%MAX_FILA;
	(f->N)--;

	return elem;
	}
	
}

// Consultar  nodo no inicio da fila
int consulta(Fila f)
{

int elem;
	if(e_vazia(f) == 1)
	return 0;
else
	{
	elem = f->fila[f->IF];
	return elem;
	}
}

//Liberar área alocada para a fila
void libera_fila(Fila f){

    f->FF = f->IF = f->N = 0;
    free(f);

}


