#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct Tno{
	
	int chave;
	
	int bal;
	struct Tno *dir, *esq;
}Tno;


// função da questão 3 da prova
int Conta(Tno **p){ 
	
	if(*p == NULL) return 0;
	
	int assist = 0, n = 0;
	
	if((*p)->dir != NULL){
		
		n += Conta(&((*p)->dir));
		assist++;
	}
	
	if((*p)->esq != NULL){
		
		n += Conta(&((*p)->esq));
		if( assist == 1) n++;
	}

	
	return n;
}



// Função da questao 4 da prova:
int Remove(Tno **p){
	
	if(*p == NULL) return 0;
	
	int assist = 0, n = 0;
	if((*p)->dir == NULL && (*p)->esq == NULL) return 1;
	
	if(Remove(&((*p)->dir)) == 1){
		
		free((*p)->dir);
		(*p)->dir = NULL;
	}
	
	if(Remove(&((*p)->esq)) == 1){
		
		free((*p)->esq);
		(*p)->esq = NULL;
	}
	
	return 0;
}



Tno *Criar(int k){
	
	Tno *novo = malloc(sizeof(Tno));
	
	if(novo == NULL) return NULL;
	
	novo->dir = NULL;
	novo->esq = NULL;
	novo->chave = k;
	
	return novo;
}

int InserirABP(Tno **p, int k){
	
	if(*p == NULL) return 0;
	
	if((*p)->chave == k) return 0;
	
	if((*p)->chave > k){
		
		if((*p)->esq == NULL){
			
			(*p)->esq = Criar(k);
			return 1;
		}
		
		else return InserirABP(&((*p)->esq), k);
		
	}
	else{

		
		if((*p)->dir == NULL){

			
			(*p)->dir = Criar(k);
			return 1;
		}
		
		else InserirABP(&((*p)->dir), k);
	}
	
}


int printa(Tno *p){
	
	
	if(p == NULL) return 0;
	
	printf("o no atual e igual a %d\n\n", p->chave);
	
	printf("entrando a direita de %d\n", p->chave);
	printa(p->dir);
	printf("saindo da direita de %d\n", p->chave);
	printf("entrando na  esqquerda de %d\n", p->chave); 
	printa(p->esq);
	printf("saindo da esquerda de %d\n", p->chave);
	
	
}

int printaRemove(Tno *p){
	
	
	if(p == NULL) return 0;
	
	printf("%d\n", p->chave);
	
	printaRemove(p->dir);
	printaRemove(p->esq);
	
	
}



Tno *Finalizar(Tno **p){
	
	
	if(*p == NULL) return NULL;
	
	
	(*p)->dir = Finalizar(&((*p)->dir));
	(*p)->esq = Finalizar(&((*p)->esq));
	free(*p);
	*p = NULL;
	
	return NULL;
	
}

int main(int argc, char *argv[]) {


	Tno *raiz = Criar(100);
	
	InserirABP(&raiz, 20);
	InserirABP(&raiz, 200);
	InserirABP(&raiz, 10);
	InserirABP(&raiz, 300);
	InserirABP(&raiz, 150);
	InserirABP(&raiz, 250);
	InserirABP(&raiz, 400);
	InserirABP(&raiz, 50);
	InserirABP(&raiz, 75);
	InserirABP(&raiz, 40);
	
	printf("\n ===========a arvre possui a seguinte formação de chaves: ===================\n\n");
	printa(raiz);
	int a = Conta(&raiz);
	
	printf("\n ============================================================================\n");
	printf("\no numero de nos que possuem dois filhos é igual a %d\n", a);
		
	Remove(&raiz);
	
	printf("\a arvre depois de remover os nós folha tem os seguintes numeros:\n");
	
	printaRemove(raiz);
	
	if(Finalizar(&raiz) == NULL) printf("fim");
	
	
	return 0;






	return 0;
}



