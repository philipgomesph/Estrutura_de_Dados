#include <stdio.h>
#include <stdlib.h>
#define max 2

int pilha[max];
int topo;
int aux;

int inicia_pilha(){
    topo=-1;
}

int pilha_vazia(){
    if(topo==-1){
        return 1; //pilha vazia
    }else{
        return 0; //pilha cheia
    }
}

int pilha_cheia(){
    if(topo==max-1){
        return 1; //pilha cheia
    }else{
        return 0; //pilha com espaço
    }

}

void insere_pilha(int valor){
    if(pilha_cheia()==1){
       printf("\n Erro:Pilha cheia!!! \n ");

    }else{
        topo++;
        pilha[topo]=valor;
        printf("\n Valor inserido [%d]: %d",topo,pilha[topo]);
    }
}

int remove_pilha( ){
    if(pilha_vazia()==1){
        printf("\n Erro: pilha vazia!!! \n");
    }else{
      aux=pilha[topo];
      topo--;
      return aux;


    }
}



int main()
{

        inicia_pilha();
        insere_pilha(2);
        insere_pilha(3);

        printf("\n \t valor removido = %d", remove_pilha());
        printf("\n \t valor removido = %d", remove_pilha());
        remove_pilha();

        insere_pilha(12);

//      insere_pilha(4);
//      insere_pilha(10);
//      insere_pilha(30);





        printf("\n\n\n");

    return 0;
}
