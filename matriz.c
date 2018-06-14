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
	return y;
}

void clear_scren()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

char choose()
{
	int y;
	char x;

	while(!y){
		printf("Escolha a opção que deseja realizar:\n");
		printf("Fechar programa                                    -> A\n");
		printf("Criar a matriz m por n                             -> B\n");
		printf("Adicionar elementos à matriz                       -> C\n");
		printf("Modificar elementos na matriz                      -> D\n");
		printf("Mostrar informacoes individuais da matriz:         -> E\n");
		printf("Mostrar informações gerais da matriz               -> F\n");
		printf("Consultar soma dos valores de cada linha da matriz -> G\n");
		printf("Excluir a matriz m por n                           -> H\n");
		x = getchar();
		y = clear();
	}
	return x;
}

void get_limits(int *col, int *lin, int *flag)
{
	int y;

	while(1){
		while(1){
			printf("Digite o número de colunas que deseja ter em sua matriz:\n");
			scanf("%d", col);
			y = clear();
			if(y){
				break;
			}
		}
		if(*col > 0){
			break;
		}else{printf("Digite um número válido\n");}
	}
	while(1){
		while(1){
			printf("Digite o número de linhas que deseja ter em sua matriz:\n");
			scanf("%d", lin);
			y = clear();
			if(y){
				break;
			}
		}
		if(*lin > 0){
			break;
		}else{printf("Digite um número válido\n");}
	}
	*flag = 1;
}



void add_n_numbers(int col, int lin, int *add)
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
		}else if(*add <= 0)printf("Digite um numero valido de elementos\n");
		else if(*add > col*lin)printf("Digite uma quantidade de elementos que esteja dentro dos limites da matriz\n");
		else check = 1;
	}
}

int find(int col, int lin, int n, struct matriz *p)
{
	int check = 0;
	int y;
	int coluna;
	int linha;
	int i;

	while(!check){
		printf("Digite a coluna do numero que deseja selecionar:\n");
		scanf("%d", &coluna);
		y = clear();
		if(!y){
		}else if(coluna > col || coluna <= 0)printf("Digite um numero válido");
		else check = 1;
	}
	y = 0; check = 0;
	while(!check){
		printf("Digite a linha do numero que deseja selecionar:\n");
		scanf("%d", &linha);
		y = clear();
		if(!y){
		}else if(linha > lin || linha <= 0)printf("Digite um numero válido");
		else check = 1;
	}
	for(i = 0; i < n; i++){
		if(p[i].x == coluna && p[i].y == linha){
			return i;
		}
	}
	printf("Digite uma posicao ja ocupada na matriz\n");
}


void change_numbers(int col, int lin, struct matriz *p, int n, int i)
{
	int y;
	int check;
	int coluna;
	int linha;


	clear_scren();
	do{
		i = find(col, lin, n, p);
		printf("Coluna: %d	Linha: %d", p[i].x, p[i].y);
		printf("Numero antigo: %f", p[i].val);
		check = 0;
		while(!check){
			printf("Digite o numero que ira substituir o antigo:\n");
			scanf("%f", p[i].val);
			y = clear();
			if(y) return;
		}	
		printf("Digite uma posicao ja ocupada na matriz\n");
	}while(1);
}

void get_lin_col(int col, int lin, struct matriz *p, int i)
{
	int y;
	int check = 0;
	
	while(!check){
		printf("Digite a linha em que deseja adicionar o número %f\n", p[i].val);
		scanf("%d", &p[i].y);
		y = clear();
		if(!y){
		}else if(p[i].y <= 0 || p[i].y > lin) printf("Digite um numero valido\n");
		else check = 1;
	}
	y = 0;	check = 0;
	while(!check){
		printf("Digite a coluna em que deseja adicionar o número %f\n", p[i].val);
		scanf("%d", &p[i].x);
		y = clear();
		if(!y){
		}else if(p[i].x <= 0 || p[i].x > lin)printf("Digite um numero valido\n");
		else check = 1;
	}
}


void get_numbers(int col, int lin, int add, struct matriz *p, int *n)
{
	int i;
	int k;
	int y;
	int check;
	int check_all;

	for(i = 0; i<add; i++){
		y = 0;
		check_all = 0;
		while(!check_all){
			printf("Numeros restantes a serem adicionados: %d\n", add - i);
			while(!y){
				printf("Digite o número que deseja adicionar:\n");
				scanf("%f", &p[i].val);
				y = clear();
			}
			get_lin_col(col,lin,p,i);
			check_all = 1;
			for(k = 0; k < *n + i; k++){
				if(p[i].x == p[k].x && p[i].y == p[k].y && i!=k){
					check_all = 0;
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


	printf("Informações da matriz:\n");
	printf("Numero de linhas: %d	Numero de colunas: %d",lin, col);
	printf("Numero de elementos: %d", n);
	for(i = 0; i<n; i++){
		printf("Numero: %f	linha: %d	coluna: %d", p[i].val, p[i].y, p[i].x);
	}
}



int main(int argc, char const *argv[])
{
	int *add;
	int *col;
	int *lin;
	int *flag;
	int *n;
	int *nostack;
	int i;
	int k;
	char x;
	struct matriz *p;

	nostack = (int*)calloc(6, sizeof(int));
	if(!nostack){
		printf("Não foi possível alocar memória o sufuciente para seis inteiros\n");
		printf("Feche outros programas e retorne mais tarde\n");
		return 1;
	}
	flag = nostack;
	col = nostack++;
	lin = nostack++;
	add = nostack++;
	n = nostack++;
	nostack--;
	nostack--;
	nostack--;
	nostack--;

	clear_scren();
	while(1){
		x = choose();
		if(x == 'A' || x == 'a'){
			printf("Programa encerrado...\n");
			free(nostack);
			if(*flag){
				free(p);
			}
			return 0;
		}else if(x == 'B' || x == 'b'){
			if(!*flag){
			get_limits(col, lin, flag);
			clear_scren();
			}else{printf("Já exite uma matriz\n");}
		}else if(x == 'C' || x == 'c'){
			if(*flag){
				add_n_numbers(*col, *lin, add);
				p = (struct matriz *) calloc(*n + *add, sizeof(struct matriz));
				if(!p){
					printf("Não foi possivel alocar memoria o suficiente para %d 'struct matriz'\n", *n);
					return 1;
				}
				get_numbers(*col, *lin, *add, p, n);
			}else printf("Crie uma matriz primeiro\n");
		}else if(x == 'D' || x == 'd'){
			if(*flag){
				clear_scren();
				add_n_numbers(*col, *lin, add);
				clear_scren();
				for(k = 0; k < *add; k++){
				printf("Numeros restantes a serem adicionados: %d", *add - k);
				i = find(col, lin, n, p);
				change_numbers(*col, *lin, p, *n, i);
				clear_scren();
				}
			}else printf("Não existe uma matriz ainda\n");
		}else if(x == 'E' || x == 'e'){
			if(*flag){
				i = find(*col, *lin, *n, p);
				clear_scren();
				printf("Numero: %f	linha: %d	coluna: %d\n\n", p[i].val, p[i].y, p[i].x);
			}else printf("Crie uma matriz primeiro\n");
		}else if(x == 'F' || x == 'f'){
			show_info_all(*col, *lin, *n, p);
		}else if(x == 'G' || x == 'g'){
			//val_lin();
		}else if(x == 'H' || x == 'h'){
			if(*flag){
				clear_scren();
				free(p);
				*flag = 0;
				printf("Matriz removida\n");
			}else printf("Crie uma matriz primeiro\n");
		}else printf("Digite uma opcao valida\n");
	}
}
