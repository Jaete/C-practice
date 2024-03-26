#include <stdio.h>
#include <locale.h>

FILE *file;
int choice = 0;

int main(){	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Bem vindo � Minha Biblioteca!\n\n");
	printf("Vamos cadastrar um livro novo?\n");
	printf("1- Sim\t 2- Quero apenas ver os livros\t 3- Sair\n");
	scanf("%d", &choice);
	// Caminhos "infelizes" primeiro, como uma valida��o "inversa"
	// Come�a por validar a escolha
	while(choice != 1 && choice != 2 && choice != 3){
		printf("Insira uma op��o v�lida.\n");
		scanf("%d", &choice);
	}
	// Pula direto pra mostrar os livros
	if(choice == 2){
		goto show_books; // Me perdoa
	}
	// Sai do programa j� de cara
	if(choice == 3){
		printf("\n\n#=================================#\n");
		printf("Obrigado por usar a Minha Biblioteca!\n\n");
		exit(0);
	}
	// Em caso impl�cito do usu�rio ter digitado 1
	register_book:
	file = fopen("file.txt", "a");
	//Valida��o se o arquivo existe 
	if(file == NULL) {
        printf("Erro ao abrir o arquivo ao registrar um livro.");
        exit(1);
    }
	do{
		fflush(stdin); // Buffer
		//Cadastrando o livro
		char title[64];
		char author[100];
		int pages;
		printf("Qual � o nome desse livro?\n");
		scanf(" %[^\n]", title);
		fflush(stdin); // Buffer
		printf("Qual � o autor de '%s'?\n", title);
		scanf(" %[^\n]", author);
		fflush(stdin);
		printf("Quantas paginas tem '%s'?\n", title);
		scanf("%d", &pages);
		fprintf(file, "%s\n", title);
		fprintf(file, "%s\n", author);
		fprintf(file, "%d\n", pages);
		
		//Livro finalizado, perguntando novamente
		printf("Vamos cadastrar um novo livro?\n");
		printf("1- Sim\t 2-N�o\n");
		scanf("%d", &choice);
		// Valida��o de escolha
		while(choice != 1 && choice != 2){
			printf("Insira uma op��o v�lida.\n");
			scanf("%d", &choice);
		}
	}while(choice == 1);
	fclose(file);
	//Em caso impl�cito do usu�rio ter recusado adicionar um novo livro em algum momento
	show_books:
	file = fopen("file.txt", "r");
	printf("Gostaria de ver os livros como um todo ou apenas os que tem mais de 300 p�ginas?\n");
	printf("1- Como um todo\t2- Mais que 300 p�ginas\t3- Sair\n"); // Expandindo um pouco o exerc�cio
	scanf("%d", &choice);
	//Valida��o de escolha
	while(choice != 1 && choice != 2 && choice != 3){
		printf("Insira uma op��o v�lida.\n");
		scanf("%d", &choice);
	}
	// As vezes o usu�rio n�o quer ver os livros depois de registrar um
	if(choice == 3){
		printf("\n\n#=================================#\n");
		printf("Obrigado por usar a Minha Biblioteca!\n\n");
		exit(0);
	}
	//Valida��o se o arquivo existe 
	if(file == NULL) {
        printf("Erro ao abrir o arquivo ao ler os dados da biblioteca.");
        exit(1);
    }
	//Vari�veis necess�rias para a leitura dos dados (ambos os casos)
	int count = 1;
	char read[100];
	if(choice == 1){
		printf("Aqui est�o todos os livros que voc� cadastrou: \n\n");
		// Um loop que conta se a linha atual � 1, 2 ou 3 para imprimir certinho
		while(fgets(read, 100, file)){
			if(count == 1){
				printf("#====================#\n");
				printf("T�tulo: %s", read);
				count = count +1;
			}else if(count == 2){
				printf("Autor(es): %s", read);
				count = count +1;
			}else{
				printf("P�ginas: %s", read);
				count = 1;
			}
		}
		fclose(file);
	}else{
		printf("\nAqui est�o os livros que voc� cadastrou que cont�m mais de 300 p�ginas: \n\n");
		while(fgets(read, 100, file)){
			char title[50];
			char authors[100];
			int pages;
			//Faz a leitura de todas as linhas como no caso acima mas n�o printa nada ainda
			if(count == 1){
				strcpy(title, read);
				count = count +1;
			}else if(count == 2){
				strcpy(authors, read);
				count = count +1;
			}else{
				pages = atoi(read);
				count = 1;
			}
			// Apenas printa se pages > 300
			if(pages > 300){
				printf("#====================#\n");
				printf("Titulo: %s\n", title);
				printf("Autor(es): %s\n", authors);
				printf("P�ginas: %d\n", pages);
			}
		}
		fclose(file);
	}
	// Fica permissivo do usu�rio registrar um livro AP�S ter visto os livros
	// O usu�rio s� sai do programa se quiser
	printf("\n\nGostaria de cadastrar um livro?\n");
	printf("1 - Sim\t2- Sair\n");
	scanf("%d", &choice);
	if (choice == 1){
		goto register_book;
	}
	//Caso impl�cito de ter sido digitado 2
	printf("\n\n#=================================#\n");
	printf("Obrigado por usar a Minha Biblioteca!\n\n");
	exit(0);
}
