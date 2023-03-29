#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Tno{

	int num;
	struct Tno *dir;
	struct Tno *esq;
}Tno;


typedef struct NumNo{

	int num;
	struct NumNo *prox;

}NumNo;


Tno *Inserir(int k){

    Tno *novo = malloc(sizeof(Tno));

    novo->num = k;
    novo->dir = NULL;
    novo->esq = NULL;


}


Tno *insereTNo(Tno **p, int k){

    if (k < 0) return NULL;

    if(*p == NULL){

        *p = Inserir(k);
        return *p;
    }

    if((*p)->num < k)   return insereTNo( &((*p)->esq), k);

    return insereTNo( &((*p)->dir), k);


}


void ImprimeTno(Tno *p, NumNo **a){

    if(p == NULL) return;

    ImprimeTno(p->esq, a);

    if(p->dir != NULL && p->esq != NULL){

		if(*a != NULL) a = &((*a)->prox);

		*a = malloc(sizeof(NumNo));
		(*a)->num = p->num;
		(*a)->prox = NULL;

	}
    ImprimeTno(p->dir, a);


}



void main(int argc, char *argv[]){

    Tno *raiz = NULL;
    NumNo *aux, *duplos = NULL; //usado pra guardar os numeros dos nos com nos direito e esquerdo.

    raiz = insereTNo(&raiz, 7);

    int n[9], i = 0;

    while( i < (sizeof(n)/sizeof(int))){

        insereTNo(&raiz, n[i]);
        i++;

    }


    ImprimeTno(raiz, &duplos);

    if(duplos != NULL){
    	printf("os  numeros dos nos com nos na esquerda e direita são: %d", duplos->num);
    	aux = duplos->prox;

    	while(aux != NULL){

			printf(", %d", aux->num);
    		aux = aux->prox;

		}


	}


}
