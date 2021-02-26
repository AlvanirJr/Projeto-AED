#include "Cliente.h"

void inicializar_lista_cliente(lista_cliente *l){
	
	l->inicio = NULL;
}


void adcionar_cliente_inicio(lista_cliente *l, cliente c){
	
	no_cliente *novo =  (no_cliente *) malloc (sizeof(no_cliente));
	novo->proximo = l->inicio;
	novo->dado = c;
	l->inicio = novo;

}

cliente ler_cliente(lista_cliente *l){
	
	cliente *c = (cliente *) malloc (sizeof(cliente));
	__fpurge(stdin);

	int codCLiente;
	cliente *temp = NULL;

	do{

		printf("Digite o codigo do cliente: \n");
		scanf("%d", &codCLiente);
		__fpurge(stdin);

		temp = localizar_idcliente_simple(l, codCLiente);

		if (temp!=NULL){

			printf("\n\n ID JA CADASTRADO \n\n" );

		}

	}while (temp!=NULL);

	c->IDcliente = codCLiente;

	printf("Digite o nome do cliente: \n");
	fgets(c->nome, sizeof(c->nome), stdin);

	__fpurge(stdin);
	printf("Digite o endereco do cliente: \n");
	fgets(c->endereco, sizeof(c->endereco), stdin);

	__fpurge(stdin);
	printf("Digite o telefone para contato: \n");
	fgets(c->telefone, sizeof(c->telefone), stdin);

	return *c;

}

void listar_cliente(lista_cliente *l){

	no_cliente *temp;
	temp = l->inicio;
	printf("---------------Lista de clientes------------\n");
	while(temp != NULL){
		//printf("%d\n%s\n%s\n%d\n", temp->dado.IDcliente, temp->dado.nome, temp->dado.endereco, temp->dado.telefone);
		printf("\nIdentificao do cliente: %d\n", temp->dado.IDcliente);
		printf("\nNome: %s", temp->dado.nome);
		printf("\nEndereco: %s", temp->dado.endereco);
		printf("\ncontato: %s\n", temp->dado.telefone);
		temp = temp->proximo;

	}

	printf("-----------------------------------------------\n");
	system("read b");

}

void salvar_cliente(lista_cliente *l){

	FILE *fp;
	fp = (FILE *) fopen("cliente.txt", "wb");
	if(fp != NULL){
		no_cliente *temp;
		temp = l->inicio;
		while(temp != NULL){
			fwrite(&temp->dado, sizeof(cliente), 1, fp);
			temp = temp->proximo;
		}
		fclose(fp);

	}
}



void carregar_clientes(lista_cliente *l){

	FILE *fp;
	cliente *dado;
	dado = (cliente *) malloc(sizeof(cliente));

	inicializar_lista_cliente(l);

	fp = (FILE *) fopen("cliente.txt", "rb");
	if(fp != NULL){

		while(fread(dado, sizeof(cliente), 1, fp)){

			adcionar_cliente_inicio(l, *dado);
			dado = (cliente *) malloc(sizeof(cliente));
		}
		fclose(fp);
	}




}

cliente* localizar_idcliente(lista_cliente*l, int ID) {
	cliente *c = NULL;
	no_cliente *temp;
	temp = l->inicio;
	int Id;
	printf("Digite o ID do cliente que deseja pesquisar: ");
	scanf("%d", &Id);

	while(temp != NULL) {
		if(temp->dado.IDcliente == Id) {
			c = &temp->dado;
			break;
		}
		temp = temp->proximo;
	}

	if (c!=NULL){

	printf("-----------------------------------------------\n");
	
		printf("\nIdentificao do cliente: %d\n", c->IDcliente);
		printf("\nNome: %s", c->nome);
		printf("\nEndereco: %s", c->endereco);
		printf("\ncontato: %s\n", c->telefone);
	
	printf("-----------------------------------------------\n");

	}else{

		printf("\n CLIENTE NAO ECONTRADO! \n");

	}

	system("read b");


	return c;
}

cliente* localizar_idcliente_simple(lista_cliente*l, int ID) {
	cliente *c = NULL;
	no_cliente *temp;
	temp = l->inicio;

	while(temp != NULL) {
		if(temp->dado.IDcliente == ID) {
			c = &temp->dado;
			break;
		}
		temp = temp->proximo;
	}

	return c;
}

void excluir_cliente(lista_cliente *l){

	no_cliente *temp, *retorno;
	temp = l->inicio;

	int Id;
	printf("Digite o ID que deseja pesquisar: \n");
	scanf("%d", &Id);

	if (temp->proximo == NULL){

		l->inicio = NULL;

	}else{
		while (temp != NULL && temp->dado.IDcliente != Id) {
		
		    retorno = temp;
		    temp = temp->proximo;
		
		}
		if (temp != NULL) {
		
		    retorno->proximo = temp->proximo;
		    free (temp);
		
		}
	}


	printf("-----------------------------------------------\n");
	printf("-------------------REMOVIDO--------------------\n");
	printf("-----------------------------------------------\n");
	system("read b");

}
