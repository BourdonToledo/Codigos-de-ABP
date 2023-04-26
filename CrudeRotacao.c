#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tno{
	
	int chave;
	
	int bal;
	struct Tno *dir, *esq;
}Tno;

Tno *Criar(int k){
	
	
	Tno *novo = malloc(sizeof(novo));
	
	if(novo == NULL) return NULL;
	
	novo->dir = NULL;
	novo->esq = NULL;
	novo->chave = k;
	novo->bal = 0;
	
	return novo;
}


Tno *RotacaoDir(Tno **p){
	
	Tno *aux;
	aux = (*p)->esq;
	(*p)->esq = aux->dir;
	aux->dir = (*p);
	
	return aux;
	
	
}

Tno *RotacaoEsq(Tno **p){
	
	Tno *aux;
	aux = (*p)->dir;
	(*p)->dir = aux->esq;
	aux->esq = (*p);
	
	return aux;
	
	
}


int Inserir(Tno **p, int k){
	
	if(*p == NULL){
	
		*p = Criar(k);
		return -1;
	
	}
	
	if((*p)->chave > k){
		if((*p)->esq != NULL)	if( Inserir(&((*p)->esq), k) == 0) return 0;
		
		else	(*p)->esq = Criar(k);
		
		
		
		
		(*p)->bal -= 1;
		if((*p)->bal < -1) {
			
			*p = RotacaoDir(p);
			(*p)->bal = 0;
		}
		
		return -(abs((*p)->bal));
	}
	
	if((*p)->dir != NULL)	if ( 0 == Inserir(&((*p)->dir), k)) return 0;
	
	
	else	(*p)->dir = Criar(k);
	
	
	(*p)->bal += 1;
	if((*p)->bal > 1) {
			
		*p = RotacaoEsq(p);
		(*p)->bal = 0;
	}
		
	return (abs((*p)->bal));
	
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	
	
	
	
	
	
	return 0;
	
}
