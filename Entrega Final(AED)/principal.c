#include <stdio.h>
#include "Cliente.h"
#include "telas.h"
#include "Produto.h"
#include "Pedido.h"


int main(int argc, char *argv[]) {
	int op1, op2, op3, op4;
	lista_cliente lc;
	lista_produto lp;
	lista_pedido lpe;
	int ID;
	int tamanho_produto = 0;
	inicializar_lista_cliente(&lc);
	inicializar_lista_produto(&lp);
	inicializar_lista_pedido(&lpe);

	do{
		op1 = menu_principal();	
		switch(op1) {

			case 1: 
				do{
					op2 = menu_cliente();
					switch(op2) {
						case 1:
							adcionar_cliente_inicio(&lc, ler_cliente(&lc));
							break;
						case 2:
							listar_cliente(&lc);
							break;
						case 3:
							break;
						case 4:
							salvar_cliente(&lc);
							break;
						case 5:
							carregar_clientes(&lc);
							break;
						case 6:
							localizar_idcliente(&lc,  ID);
							break;
						case 7:
							excluir_cliente(&lc);
							break;

						default:
							printf("Opção invalida\n");
							system("read b");

						
					}

				} while (op2 != 3);

				break;

			case 2:
				do {
					op3 = menu_produto();
					switch(op3) {
						case 1:
							adcionar_produto_inicio(&lp, ler_produto(&lp));
							tamanho_produto+=1;
							break;
						case 2:
							listar_produto(&lp);
							break;
						case 3:

							break;
						case 4:
							salvar_produto(&lp);
							break;
						case 5:
							carregar_produtos(&lp);
							break;
						case 6:
							localizar_idproduto(&lp,  ID);
							break;
						case 7:
							excluir_produto(&lp);
							if (tamanho_produto>=1){
								tamanho_produto-=1;
							}
							break;
						case 8:
							booblesort(&lp,tamanho_produto);
							break;

						default:
							printf("Opção invalida!!");
							system("read b");


					}

				}while(op3 != 3);

				break;
			

			case 3:
				 do{
					op4 = menu_pedido();
					switch(op4) {
						case 1:
							adcionar_pedido_inicio(&lpe, ler_pedido(&lp,&lc));
							break;
						case 2:
							listar_pedido(&lpe,&lp);
							break;
						case 3:
							break;
						case 4:
							salvar_pedido(&lpe);
							break;
						case 5:
							carregar_itens_pedido(&lpe);	
							break;

						default:
							printf("Opção invalida\n");
							system("read b");

						
					}

				} while (op4 != 3);

				break;
			case 4:
				printf("\nVolte Sempre!!!! \n");
				return 1;
			default:
				printf("Opção invalida\n");
				system("read b");


		}	


	} while(op1 != 4);


	return 1;



}

