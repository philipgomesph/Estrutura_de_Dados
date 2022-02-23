#ifndef TRAB_H_INCLUDED
#define TRAB_H_INCLUDED
typedef struct funcionario
{
    char nome[30];
    int matricula;
    float salario;
}Func;

typedef struct Lista
{
    Func func;
    struct Lista *prox;
}lista;

lista* inserir(lista *inicio,Func novo);
void imprimir(lista *inicio);

#endif // TRAB_H_INCLUDED
