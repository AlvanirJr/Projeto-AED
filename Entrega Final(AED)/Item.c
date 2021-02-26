#include "Item.h"

void inicializar_lista_item(lista_item *l){
	
	l->inicio = NULL;
}


void adcionar_item_inicio(lista_item *l, item i){
	
	no_item *novo =  (no_item *) malloc (sizeof(no_item));
	novo->proximo = l->inicio;
	novo->dado = i;
	l->inicio = novo;

}

item ler_item(int Id_pro){

	
	item *i = (item *) malloc (sizeof(item));
	__fpurge(stdin);

	printf("Digite o codigo do item: ");
	scanf("%d", &i->IDItem);
	__fpurge(stdin);

	i->Id_produto = Id_pro;

	printf("Digite o quantidade do produto: ");
	scanf("%d", &i->Qtd_produto);
	__fpurge(stdin);

	return *i;

}



void listar_item(lista_item *l){

	

}

void salvar_item(lista_item *l){

	FILE *fp;
	fp = (FILE *) fopen("item.txt", "wb");
	if(fp != NULL){
		no_item *temp;
		temp = l->inicio;
		while(temp != NULL){
			fwrite(&temp->dado, sizeof(item), 1, fp);
			temp = temp->proximo;
		}
		fclose(fp);

	}
}

void carregar_itens(lista_item *l){

	FILE *fp;
	item *dado;
	dado = (item *) malloc(sizeof(item));

	inicializar_lista_item(l);

	fp = (FILE *) fopen("item.txt", "rb");
	if(fp != NULL){

		while(fread(dado, sizeof(item), 1, fp)){

			adcionar_item_inicio(l, *dado);
			dado = (item *) malloc(sizeof(item));
		}
		fclose(fp);
	}

}
