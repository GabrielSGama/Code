#include <stdio.h>
#include <stdlib.h>

struct matriz{
	int x;
	int y;
	float val;
};

int clear()
{
	int y = 1;
	char x;

	x = getchar();
	while(x != '\n'){
		x = getchar();
		y = 0;
	}
	if(!y) printf("Digite uma opcao valida\n\n");
	return y;
}

void clear_scren()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

char choose()
{
	int y = 0;
	char x;

	while(!y){
		printf("Escolha a opção que deseja realizar:\n");
		printf("Fechar programa                                     -> A\n");
		printf("Criar a matriz m por n                              -> B\n");
		printf("Adicionar elementos à matriz                        -> C\n");
		printf("Modificar elementos na matriz                       -> D\n");
		printf("Mostrar informacoes indiviuais da matriz:           -> E\n");
		printf("Mostrar informações gerais da matriz                -> F\n");
		printf("Consultar soma dos valores de cada linha da matriz  -> G\n");
		printf("Consultar soma dos valores de cada coluna da matriz -> H\n");
		printf("Excluir a matriz m por n                            -> I\n");
		x = getchar();
		clear_scren();
		y = clear();
	}
	return x;
}

void get_limits(int *col, int *lin, int *flag)
{
	int y;
	int check = 0;

	while(!check){
		printf("Digite o número de colunas que deseja ter em sua matriz:\n");
		scanf("%d", col);
		y = clear();
		if(!y){
		}else if(*col < 0) printf("Digite um numero valido\n\n");
		else check = 1;
	}
	check = 0;
	while(!check){
		printf("Digite o número de linhas que deseja ter em sua matriz:\n");
		scanf("%d", lin);
		y = clear();
		if(!y){
		}else if(*lin < 0) printf("Digite um numero valido\n\n");
		else check = 1;
	}
	*flag = 1;
}

int val_lin(int lin, struct matriz *p, int n)
{
	int check = 0;
	int y;
	int linha;
	int i;
	float sum = 0;

	while(!check){
		printf("Digite a linha que deseja ver a soma de seus elementos\n");
		scanf("%d", &linha);
		y = clear();
		if(!y){
		}else if(linha < 0 || linha > lin) printf("Digite um numero valido\n\n");
		else check = 1;
	}
	for(i = 0; i<n; i++){
		if(p[i].y == linha){
			sum += p[i].val;
		}
	}
	printf("Valor da soma dos elementos da linha %d: %f\n\n", linha, sum);
}

int val_col(int col,int *coluna, struct matriz *p, int n)
{
	int check = 0;
	int y;
	int i;
	float sum = 0;

	get_col(coluna, col);
	for(i = 0; i<n; i++){
		if(p[i].x == *coluna){
			sum += p[i].val;
		}
	}
	printf("Valor da soma dos elementos da coluna %d: %f\n\n", coluna, sum);
}

void add_n_numbers(int col, int lin,int *add, int n)
{
	int y;
	int check;

	clear_scren();
	check = 0;
	while(!check){
		printf("Digite o numero de elementos que deseja adicionar ou modificar na matriz:\n");
		scanf("%d", add);
		y = clear();
		if(!y){
		}else if(*add <= 0) printf("Digite um numero valido de elementos\n\n");
		else check = 1;
	}
}
void get_lin(int *linha, int lin){
	int y;
	int check = 0;

	while(!check){
		printf("Digite a linha que deseja selecionar:\n");
		scanf("%d", linha);
		y = clear();
		if(!y){
		}else if(*linha > lin || *linha < 0)printf("Digite um numero válido\n\n");
		else check = 1;
	}	
}
void get_col(int *coluna, int col){
	int y;
	int check = 0;
	while(!check){
		printf("Digite a coluna que deseja selecionar:\n");
		scanf("%d", coluna);
		y = clear();
		if(!y){
		}else if(*coluna > col || *coluna < 0)printf("Digite um numero válido\n\n");
		else check = 1;
	}
}

int find(int *linha ,int *coluna,int col, int lin, int n, struct matriz *p)
{
	int check = 0;
	int y;
	int i;

	
	get_lin(linha,lin);
	get_col(coluna, col);
	for(i = 0; i < n; i++){
		if(p[i].x == *coluna && p[i].y == *linha){
			return i;
		}
	}
	return -1;
}

void change_numbers(int col, int lin, struct matriz *p, int n, int i)
{
	int y;
	int check;
	int coluna;
	int linha;

	do{
		printf("Coluna: %d	Linha: %d\n", p[i].x, p[i].y);
		printf("Numero antigo: %f\n", p[i].val);
		check = 0;
		while(!check){
			printf("Digite o numero que ira substituir o antigo\n:");
			scanf("%f", &p[i].val);
			y = clear();
			if(y) return;
		}
		printf("Digite uma posicao ja ocupada na matriz\n\n");
	}while(1);
}



void get_numbers(int *coluna, int *linha,int col, int lin, int add, struct matriz *p,int *n)
{
	int i;
	int k;
	int y;
	int check;
	int check_all;

	for(i = 0; i<add; i++){
		check_all = 0;
		while(!check_all){
			printf("Numeros restantes a serem adicionados: %d\n", add - i);
			y = 0;
			while(!y){
				printf("Digite o número que deseja adicionar:\n");
				scanf("%f", &p[i+*n].val);
				y = clear();
			}
			get_lin(linha,lin);
			get_col(coluna, col);
			p[i+*n].x = *coluna;	p[i+*n].y = *linha;
			check_all = 1;
			for(k = 0; k < *n + i; k++){
				if(p[i+*n].x == p[k].x && p[i+*n].y == p[k].y && (i+*n)!=k){
					check_all = 1;
					break;
				}
			}
		}
		clear_scren();
	}
	*n = *n + add;
}

void show_info_all(int col, int lin, int n, struct matriz *p)
{
	int i;
	int k;

	printf("Informações da matriz:\n");
	printf("Numero de colunas: %d    Numero de linhas: %d\n",col,lin);
	printf("Numero de elementos adicionados: %d\n", n);
	for(k = 0; k <= lin; k++){
		for(i = 0; i<n; i++)
		if(p[i]. y == k)printf("Numero: %f	linha: %d	coluna: %d\n", p[i].val, p[i].y, p[i].x);
	}
	printf("Os outros elementos nao foram adicionados, ou seja, sao zeros\n\n");
}

int main(int argc, char const *argv[])
{
	int *nostack;
	int *flag;
	int *add;
	int *col;
	int *lin;
	int *n;
	int *coluna;
	int *linha;
	int i;
	int k;
	float val;
	char x;
	struct matriz *p;
	struct matriz *savep;

	nostack = (int*)malloc(10*sizeof(int));
	if(!nostack){
		printf("Não foi possível alocar memória sufuciente para dez inteiros\n");
		printf("Feche outros programas e retorne mais tarde\n\n");
		return 1;
	}
	flag = nostack;
	col = ++nostack;
	lin = ++nostack;
	add = ++nostack;
	n = ++nostack;
	coluna = ++nostack;
	linha = ++nostack;
	nostack--;	nostack--;	nostack--;	nostack--;	nostack--;	nostack--;
	*flag = 0;
	*n = 0;

	clear_scren();
	do{
		x = choose();
		if(x == 'A' || x == 'a'){
			printf("Programa encerrado...\n");
			free(nostack);
			if(*n){
				free(p);
			}
			return 0;
		}else if(x == 'B' || x == 'b'){
			clear_scren();
			if(!*flag){
			get_limits(col, lin, flag);
			clear_scren();
			}else printf("Já exite uma matriz\n\n");
		}else if(x == 'C' || x == 'c'){
			clear_scren();
			if(*flag){
				do{
					add_n_numbers(*col, *lin, add, *n);
					if(*add <= (*col)*(*lin) - *n)
						break;
					printf("Nao e possivel adicionar mais elementos do que espacos vazios(nao inseridos pelo usuario) na matriz\n\n");
				}while(1);
				if(*n){
					savep = p;
				}
				p = (struct matriz *) calloc(*n + *add, sizeof(struct matriz));
				if(!p){
					printf("Não foi possivel alocar memoria suficiente\n\n");
					return 1;
				}
				if(*n){
					for(i = 0; i<*n; i++)
						p[i] = savep[i];
					free(savep);
				}
				get_numbers(coluna, linha,*col, *lin, *add, p, n);
			}else printf("Crie uma matriz primeiro\n\n");
		}else if(x == 'D' || x == 'd'){
			clear_scren();
			if(*flag){
				do{
					add_n_numbers(*col, *lin, add, *n);
					clear_scren();
					if(*add <= *n)
						break;
					printf("Nao eh possivel modificar mais elementos do que existem inseridos na matriz\nCaso queira adicionar um elemento acesse a opcao 'C'\n\n");
				}while(1);
				for(k = 0; k < *add; k++){
					printf("Numeros restantes a serem modificados: %d\n", *add - k);
					i = find(linha, coluna, *col, *lin, *n, p);
					change_numbers(*col, *lin, p, *n, i);
					clear_scren();
				}
			}else printf("Crie uma matriz primeiro\n\n");
		}else if(x == 'E' || x == 'e'){
			clear_scren();
			if(*flag){
				i = find(linha, coluna,*col, *lin, *n, p);
				clear_scren();
				if(i < 0){
					val = 0;
				}else val = p[i].val;
				printf("Numero: %f	linha: %d	coluna: %d\n\n", val, *linha, *coluna);
			}else printf("Crie uma matriz primeiro\n\n");
		}else if(x == 'F' || x == 'f'){
			clear_scren();
			if(*flag){
				show_info_all(*col, *lin, *n, p);
				printf("\n");
			}else printf("Crie uma matriz primeiro\n\n");
		}else if(x == 'G' || x == 'g'){
			clear_scren();
			if(*flag){
			val_lin(*lin, p, *n);
			}else printf("Crie uma matriz primeiro\n\n");
		}else if(x == 'H' || x == 'h'){
			clear_scren();
			if(*flag){
			val_col(*col, coluna, p, *n);
			}else printf("Crie uma matriz primeiro\n\n");
		}else if(x == 'I' || x == 'i'){
			clear_scren();
			if(*flag){
				*flag = 0;
				if(*n) free(p);
				*n = 0;
			printf("Matriz removida\n\n");
			}else printf("Crie uma matriz primeiro\n\n");
		}else{
		clear_scren();
		printf("Digite uma opcao valida\n\n");
		}
	}while(1);
}