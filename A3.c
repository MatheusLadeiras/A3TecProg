/* PLANEJAMENTO
base com 10 clientes inicialmente

Pag 9

struct {
char nome[30]
int ano
float gastos (baseado nos gastos do mês)
} Cliente;

Funções: 
Adicionar cliente X
Remover Cliente X
Atualizar os gastos de um cliente X
Zerar float gastos X
listar o cliente com maior "gastos" X
mostrar "gastos" de um cliente especifico

Em caso de terem mais clientes do que previstos, um novo bloco de +10 clientes deve ser adicionado
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int a = 0;
int e = 0;
int x = 0; 
int o = 3;
int u = 0;
int novoCliente = 3;
int selecionar, c;
float maior;
char* nomeMaior;
int tLista = 10;

typedef struct Clientes {
	char nome[30];
	int ano;
	float gastos;
};

struct Clientes *cliente;
	

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	cliente = (struct Clientes *)malloc(sizeof(tLista));

	strcpy(cliente[0].nome, "José");
	cliente[0].ano = 1998;
	cliente[0].gastos = 17.43;

	strcpy(cliente[1].nome, "João");
	cliente[1].ano = 1984;
	cliente[1].gastos = 78.34;

	strcpy(cliente[2].nome, "Josesvaldo");
	cliente[2].ano = 2001;
	cliente[2].gastos = 26.92;
	
	for(o=3; o <=9 + x; o++) {
    strcpy(cliente[o].nome, "Não definido");
    cliente[o].ano = 0;
    cliente[o].gastos = 0.00;
    }
    
	menu();
	return 0;
}
void menu() {
		int i;
		do{
			printf("Alternativas disponiveis: \n");
			printf("1 para adicionar um cliente ao cadastro!\n");
			printf("2 para remover um cliente ao cadastro!\n");
			printf("3 para atualizar os gastos de um cliente\n");
			printf("4 para zerar os gastos dos clientes\n");
			printf("5 para apontar o cliente com maiores gastos\n");
			printf("6 para checar os gastos de um cliente específico\n");
			printf("7 para Sair\n");
			// printf("8 para Aumentar o número de clientes!\n");
			printf("Selecione a alternativa.   "); 
			scanf("%i", &i );
			printf("======================================================================================================\n");
			
			switch(i) {
				case 1:
    				if(novoCliente <= 9 + x) {
    					printf("Qual o nome do cliente? ");
    					scanf("%s%*c", &cliente[novoCliente].nome);
    					printf("Em que ano nasceu o cliente? ");
    					scanf("%d%*c", &cliente[novoCliente].ano);
    					printf("Quanto o cliente gastou? ");
    					scanf("%f%*c", &cliente[novoCliente].gastos);
    					
    		
    					printf("==================================================================================================\n");
    					printf("O cliente foi cadastrado.\n");
    					printf("==================================================================================================\n");
    		
    					novoCliente = novoCliente + 1;
    					listagemIndexada();
            		} else {
            			tLista = tLista+10;
						x = x+10;
						for(o=10; o <=9 + x; o++) {
    						strcpy(cliente[o].nome, "Não definido");
    						cliente[o].ano = 0;
    						cliente[o].gastos = 0.00;
						}
    					
    					printf("Qual o nome do cliente? ");
    					scanf("%s%*c", &cliente[novoCliente].nome);
    					printf("Em que ano nasceu o cliente? ");
    					scanf("%d%*c", &cliente[novoCliente].ano);
    					printf("Quanto o cliente gastou? ");
    					scanf("%f%*c", &cliente[novoCliente].gastos);
    					
    		
    					printf("==================================================================================================\n");
    					printf("O cliente foi cadastrado.\n");
    					printf("==================================================================================================\n");
    		
    					novoCliente = novoCliente + 1;
						listagemIndexada();
					}
    			break;
    			case 2:
    				if (novoCliente < 1) {
						printf("Não há clientes para serem deletados, retornando ao menu\n");
						printf("======================================================================================================\n");
					} else {
						printf("Escolha o cliente a ser removido: \n");
	    				listagemIndexada();
						
	    				printf("Insira o índice do cliente:   ");
	    				scanf("%i%*c", &selecionar);
	    				
	    				if(selecionar <= 0) {
	    					printf("Houve um erro na seleção de cliente, retornando ao menu\n");
						} else if(selecionar >= 11 + x) {
	    					printf("Houve um erro na seleção de cliente, retornando ao menu\n");
	    				} else if(novoCliente < selecionar) {
	    					printf("Houve um erro na seleção de cliente, retornando ao menu\n");
						} else {
							printf("Deletando...\n");
							for (c = selecionar - 1; c < 8 + x; c++ ) {
								cliente[c] = cliente[c + 1];
							}
							novoCliente = novoCliente - 1;
						}
						printf("======================================================================================================\n");
						listagemIndexada();
					};
				break;
				case 3:
					printf("Escolha o cliente a ter seus gastos atualizados: \n");
	    				listagemIndexada();
						
	    				printf("Insira o índice do cliente:   ");
	    				scanf("%i%*c", &selecionar);
	    				selecionar = selecionar - 1;
	    				printf("Insira o novo valor que será adicionado:   ");
	    				scanf("%2f%*c", &cliente[selecionar].gastos);
	    				
	    				listagemIndexada();
	    				
				break;
				case 4:
					printf("Zerando os gastos:\n");
						for(a=0; a <=9 + x; a++) {
						    cliente[a].gastos = 0.00;
						}
					listagemIndexada();
				break;
				case 5:
					maior = cliente[0].gastos;
					nomeMaior = cliente[0].nome;
					for (a = 0; a < 9 + x; a++) {
					       if (cliente[a].gastos > maior){
					       		maior = cliente[a].gastos;
					       		nomeMaior = cliente[a].nome;
						   }
					    }
					printf ("O cliente com maiores gastos é %s, ele gastou um total de %.2f \n", nomeMaior, maior); 
					printf("======================================================================================================\n");
				break;
				case 6:
					printf("Escolha um cliente para ver suas compras: \n");
	    				listagemIndexadaSemGastos();
						
	    				printf("Insira o índice do cliente:   ");
	    				scanf("%i%*c", &selecionar);
	    				selecionar = selecionar - 1;
	    				printf("======================================================================================================\n");
	    				printf("Esse cliente gastou um total de %.2f  \n", cliente[selecionar].gastos);
						printf("======================================================================================================\n");
				break;
				case 7:
					printf("Fechando o sistema!\n");
				break;
				case 8:
					printf("Função desativada, apenas para testes\n");
					printf("======================================================================================================\n");
					/*/tLista = tLista+10;
					x = x+10;
					for(o=10; o <=9 + x; o++) {
    					strcpy(cliente[o].nome, "Não definido");
    					cliente[o].ano = 0;
    					cliente[o].gastos = 0.00;
    				} /*/
    			break;
			}
		} while(i!=7);
		// imprimir();
	} 
	
void imprimir() {
    printf("======================================================================================================\n");
    for (u=0; u <= 9 + x; u++) {
    	if(cliente[u].ano != 0) { 
        	printf( "Cliente: %s, ano de nascimento: %d, valor total gasto conosco: %.2f\n", cliente[u].nome, cliente[u].ano, cliente[u].gastos);
    }   else {
				//printf( "%i\n", u+1);
	}}
    printf("======================================================================================================\n");
} 

void listagemIndexada() {
    for (u=0; u <= 9 + x; u++) {
    	if(cliente[u].ano != 0) { 
        	printf( "%i) Cliente: %s, ano de nascimento: %d, valor total gasto conosco: %.2f\n", u+1, cliente[u].nome, cliente[u].ano, cliente[u].gastos);
    }   else {}}
    printf("======================================================================================================\n");
} 
void listagemIndexadaSemGastos() {
    for (u=0; u <= 9 + x; u++) {
    	if(cliente[u].ano != 0) { 
        	printf( "%i) Cliente %s nascido em %d\n", u+1, cliente[u].nome, cliente[u].ano);
    }   else {}}
}


