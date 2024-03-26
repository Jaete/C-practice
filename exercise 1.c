#include <stdio.h>
#include <locale.h>

FILE *file;
int choice = 0;

int main(){	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Bem vindo à Minha Biblioteca!\n\n");
	printf("Vamos cadastrar um livro novo?\n");
	printf("1- Sim\t 2- Quero apenas ver os livros\t 3- Sair\n");
	scanf("%d", &choice);
	// Caminhos "infelizes" primeiro, como uma validação "inversa"
	// Começa por validar a escolha
	while(choice != 1 && choice != 2 && choice != 3){
		printf("Insira uma opção válida.\n");
		scanf("%d", &choice);
	}
	// Pula direto pra mostrar os livros
	if(choice == 2){
		goto show_books; // Me perdoa
	}
	// Sai do programa já de cara
	if(choice == 3){
		printf("\n\n#=================================#\n");
		printf("Obrigado por usar a Minha Biblioteca!\n\n");
		exit(0);
	}
	// Em caso implícito do usuário ter digitado 1
	register_book:
	file = fopen("file.txt", "a");
	//Validação se o arquivo existe 
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
		printf("Qual é o nome desse livro?\n");
		scanf(" %[^\n]", title);
		fflush(stdin); // Buffer
		printf("Qual é o autor de '%s'?\n", title);
		scanf(" %[^\n]", author);
		fflush(stdin);
		printf("Quantas paginas tem '%s'?\n", title);
		scanf("%d", &pages);
		fprintf(file, "%s\n", title);
		fprintf(file, "%s\n", author);
		fprintf(file, "%d\n", pages);
		
		//Livro finalizado, perguntando novamente
		printf("Vamos cadastrar um novo livro?\n");
		printf("1- Sim\t 2-Não\n");
		scanf("%d", &choice);
		// Validação de escolha
		while(choice != 1 && choice != 2){
			printf("Insira uma opção válida.\n");
			scanf("%d", &choice);
		}
	}while(choice == 1);
	fclose(file);
	//Em caso implícito do usuário ter recusado adicionar um novo livro em algum momento
	show_books:
	file = fopen("file.txt", "r");
	printf("Gostaria de ver os livros como um todo ou apenas os que tem mais de 300 páginas?\n");
	printf("1- Como um todo\t2- Mais que 300 páginas\t3- Sair\n"); // Expandindo um pouco o exercício
	scanf("%d", &choice);
	//Validação de escolha
	while(choice != 1 && choice != 2 && choice != 3){
		printf("Insira uma opção válida.\n");
		scanf("%d", &choice);
	}
	// As vezes o usuário não quer ver os livros depois de registrar um
	if(choice == 3){
		printf("\n\n#=================================#\n");
		printf("Obrigado por usar a Minha Biblioteca!\n\n");
		exit(0);
	}
	//Validação se o arquivo existe 
	if(file == NULL) {
        printf("Erro ao abrir o arquivo ao ler os dados da biblioteca.");
        exit(1);
    }
	//Variáveis necessárias para a leitura dos dados (ambos os casos)
	int count = 1;
	char read[100];
	if(choice == 1){
		printf("Aqui estão todos os livros que você cadastrou: \n\n");
		// Um loop que conta se a linha atual é 1, 2 ou 3 para imprimir certinho
		while(fgets(read, 100, file)){
			if(count == 1){
				printf("#====================#\n");
				printf("Título: %s", read);
				count = count +1;
			}else if(count == 2){
				printf("Autor(es): %s", read);
				count = count +1;
			}else{
				printf("Páginas: %s", read);
				count = 1;
			}
		}
		fclose(file);
	}else{
		printf("\nAqui estão os livros que você cadastrou que contém mais de 300 páginas: \n\n");
		while(fgets(read, 100, file)){
			char title[50];
			char authors[100];
			int pages;
			//Faz a leitura de todas as linhas como no caso acima mas não printa nada ainda
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
				printf("Páginas: %d\n", pages);
			}
		}
		fclose(file);
	}
	// Fica permissivo do usuário registrar um livro APÓS ter visto os livros
	// O usuário só sai do programa se quiser
	printf("\n\nGostaria de cadastrar um livro?\n");
	printf("1 - Sim\t2- Sair\n");
	scanf("%d", &choice);
	if (choice == 1){
		goto register_book;
	}
	//Caso implícito de ter sido digitado 2
	printf("\n\n#=================================#\n");
	printf("Obrigado por usar a Minha Biblioteca!\n\n");
	exit(0);
}
