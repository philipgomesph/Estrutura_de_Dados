#ifndef PONTO_H_H_INCLUDED
#define PONTO_H_H_INCLUDED



struct Lista
{
    int numero;
    struct Lista *prox;
};typedef struct Lista lista;

struct Lista *cria_pilha(lista *pilha);


#endif // PONTO_H_H_INCLUDED
