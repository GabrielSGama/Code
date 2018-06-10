#include <stdio.h>
#include <stdlib.h>

struct matriz{
	int x;
	int y;
	int val;
};



int clear(){
	int y = 1;
	char x;

	x = getchar();
	while(x != '\n'){
		x = getchar();
		y = 0;
	}
	return y;
}

void clear_scren(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

char choose(){
	int y;
	char x;

	while(1){
		printf("Escolha a opção que deseja realizar:\n");
		printf("Fechar programa              -> A\n");
		printf("Criar a matriz m por n       -> B\n");
		printf("Adicionar elementos à matriz -> C\n");
		printf("Excluir a matriz m por n     -> D\n");
		x = getchar();
		y = clear();
		if(y){
			break;
		}
	}
	return x;
}

void get_limits(int *col, int *lin, int *flag){
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



void add_n_numbers(int col, int lin, int *add, int flag){
	int y;

	if(!flag){
		//clear_scren();
		printf("Crie uma matriz primeiro\n");
		return;
	}
	clear_scren();
	while(1){
		while(1){
			while(1){
				printf("Digite números de elementos que deseja adicionar na matriz:\n");
				scanf("%d", add);
				y = clear();
				if(y){
					break;
				}
			}
			if(*add > 0){
				break;
			}else{printf("Digite um número válido de elementos\n");}
		}
		if(*add <= col*lin /*&& quant <= freespace()*/){
			break;
		}else{printf("Digite uma quantidade de elementos que esteja dentro dos limites da matriz\n");}
	}
}
/*
struct matriz{
	int x;
	int y;
	int val;
};
*/
void get_numbers(int col, int lin, int add, struct matriz *p, int *n){
	int i;
	int k;
	int flag_posi;
	int y;

	for(i = 0; i<add; i++){
		flag_posi = 1;
		printf("Numeros restantes a serem adicionados: %d\n", add - i);
		while(1){
			printf("Digite o número que deseja adicionar:\n");
			scanf("%d", &p[i].val);
			y = clear();
			if(y){
				break;
			}
		}
		while(1){
			while(1){
				while(1){
					printf("Digite a linha em que deseja adicionar o número %d\n", p[i].val);
					scanf("%d", &p[i].y);
					y = clear();
					if(y){
						break;
					}
				}
				if(p[i].y > 0 && p[i].y <= lin){
					break;
				}else{printf("Digite um número válido\n");}
			}
			while(1){
				while(1){
					printf("Digite a coluna em que deseja adicionar o número %d\n", p[i].val);
					scanf("%d", &p[i].x);
					y = clear();
					if(y){
						break;
					}
				}
				if(p[i].x > 0 && p[i].x <= col){
					break;
				}else{printf("Digite um numero valido\n");}
			}
			for(k = 0; k < (*n + i); k++){
				if(p[i].x == p[k].x && p[i].y == p[k].y && i != k){
					flag_posi = 0;
					break;
				}
			}
			if(flag_posi){
				break;
			}else{
				printf("Espaco ja foi utilizado\n");
				printf("Escolha outra posicao\n");
			}
		}
		clear_scren();
	}
	*n = *n + add;
}

void show_info(int col, int lin, int n, struct matriz *p){
	
}


int main(int argc, char const *argv[]){
	int *add;
	int *col;
	int *lin;
	int *flag;
	int *n;
	int *nostack;
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
			add_n_numbers(*col, *lin, add, *flag);
			if(*flag){
				p = (struct matriz *) calloc(*n + *add, sizeof(struct matriz));
				if(!p){
					printf("Não foi possivel alocar memoria o suficiente para %d 'struct matriz'\n", *n);
					return 1;
				}
				get_numbers(*col, *lin, *add, p, n);
			}
		}else if(x == 'D' || x == 'd'){
			if(*flag){
				clear_scren();
				show_info(*col, *lin, *n, p);
			}else{printf("Não existe uma matriz ainda\n");}
		}else{printf("Digite uma opcao valida\n");}
	}
}