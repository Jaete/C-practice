#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Arquivo de gerenciamento e persistência de dados
FILE *registroVendas;

//Variável de escolha para navegação no menu
int escolha = 0;

// Preço da quentinha e preço por kg
enum PrecoRefeicao{
	QUILO = 30, // Não foi explicitado nas especificações
	// do projeto o preço do KG da refeição, valor aleatório
	QUENTINHA = 20
} refeicao;

//Preço das bebidas
enum Bebidas{
	COCA_LATA = 4, COCA_2L = 10,
	PEPSI_LATA = 3, PEPSI_2L = 8
} bebida;

//Meses do ano para Relatório Mensal
enum Meses{
	JANEIRO = 1, FEVEREIRO,
	MARCO, ABRIL,
	MAIO, JUNHO,
	JULHO, AGOSTO,
	SETEMBRO, OUTUBRO,
	NOVEMBRO, DEZEMBRO
} meses;

//struct de informação para cada venda realizada
struct Vendas{
	char tipo[16]; // "a quilo" ou "quentinha"
	int peso;
	int qtdBebidas;
	float precoFinal;
};


//Funções ajudantes para reutilização de código
void printVenda(int i, struct Vendas venda){
	printf("\n\n***** [%d] *****\n", i);
	printf("Tipo: %s\n", venda.tipo);
	printf("Peso: %d\n", venda.peso);
	printf("Qtd. Bebidas: %d\n", venda.qtdBebidas);
	printf("Preço: %.2f\n", venda.precoFinal);
}

void repetirEscolha(){
	fflush(stdin);
	printf("Insira um valor válido.\n");
	fscanf(stdin, "%d", &escolha);
}

void validarEscolha(int qtdOpcoes){
	switch(qtdOpcoes){
		case 2:
			while(escolha != 1 && escolha != 2){
				repetirEscolha();
			}	
			break;
		case 3:
			while(escolha != 1 && escolha != 2 && escolha != 3){
				repetirEscolha();
			}	
			break;
		case 4:
			while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4){
				repetirEscolha();
			}	
			break;
	}	
}

void listaBebidas(){
	printf("\n\nDigite qual bebida foi vendida: \n");
	printf("1- Coca-Cola Latinha\n");
	printf("2- Coca-Cola 2 Litros\n");
	printf("3- Pepsi Latinha\n");
	printf("4- Pepsi 2 Litros\n");
}

void printDiaMes(int dia, int mes){
	switch(mes){
		case JANEIRO:
			printf("\n\n****** [%d / JANEIRO] ******\n\n", dia);
			break;
		case FEVEREIRO:
			printf("\n\n****** [%d / FEVEREIRO] ******\n\n", dia);
			break;
		case MARCO:
			printf("\n\n****** [%d / MARÇO] ******\n\n", dia);
			break;
		case ABRIL:
			printf("\n\n****** [%d / ABRIL] ******\n\n", dia);
			break;
		case MAIO:
			printf("\n\n****** [%d / MAIO] ******\n\n", dia);
			break;
		case JUNHO:
			printf("\n\n****** [%d / JUNHO] ******\n\n", dia);
			break;
		case JULHO:
			printf("\n\n****** [%d / JULHO] ******\n\n", dia);
			break;
		case AGOSTO:
			printf("\n\n****** [%d / AGOSTO] ******\n\n", dia);
			break;
		case SETEMBRO:
			printf("\n\n****** [%d / SETEMBRO] ******\n\n", dia);
			break;
		case OUTUBRO:
			printf("\n\n****** [%d / OUTUBRO] ******\n\n", dia);
			break;
		case NOVEMBRO:
			printf("\n\n****** [%d / NOVEMBRO] ******\n\n", dia);
			break;
		case DEZEMBRO:
			printf("\n\n****** [%d / DEZEMBRO] ******\n\n", dia);
			break;
	}
}

//Calculando o preço por peso, com o peso em gramas, fazendo a
//conversão para quilos
float calcularPrecoPorPeso(int peso){
	return QUILO * (peso * 0.001);
}

//Adicionando os 50 centavos da embalagem ao preço fixo da quentinha
float quentinha(){
	return QUENTINHA + 0.5;
}

//Adicionando bebida a partir da escolha feita no input, pré validado
int adicionarBebida(int bebida, int quantidade){
	switch(bebida){
		case 1:
			return COCA_LATA * quantidade;
			break;
		case 2:
			return COCA_2L * quantidade;
			break;
		case 3:
			return PEPSI_LATA * quantidade;
			break;
		case 4:
			return PEPSI_2L * quantidade;
			break;
		default:
			return 0;
	}
}

//Checando qual mês é a partir do input recebido, pré validado, para uso de escrita
void registrarMes(int mes){
	switch(mes){
		case JANEIRO:
			registroVendas = fopen("registroVendasJaneiro", "ab");
			break;
		case FEVEREIRO:
			registroVendas = fopen("registroVendasFevereiro", "ab");
			break;
		case MARCO:
			registroVendas = fopen("registroVendasMarco", "ab");
			break;
		case ABRIL:
			registroVendas = fopen("registroVendasAbril", "ab");
			break;
		case MAIO:
			registroVendas = fopen("registroVendasMaio", "ab");
			break;
		case JUNHO:
			registroVendas = fopen("registroVendasJunho", "ab");
			break;
		case JULHO:
			registroVendas = fopen("registroVendasJulho", "ab");
			break;
		case AGOSTO:
			registroVendas = fopen("registroVendasAgosto", "ab");
			break;
		case SETEMBRO:
			registroVendas = fopen("registroVendasSetembro", "ab");
			break;
		case OUTUBRO:
			registroVendas = fopen("registroVendasOutubro", "ab");
			break;
		case NOVEMBRO:
			registroVendas = fopen("registroVendasNovembro", "ab");
			break;
		case DEZEMBRO:
			registroVendas = fopen("registroVendasDezembro", "ab");
			break;
	}
}

//Checando qual mês é a partir do input recebido, pré validado, para uso de leitura
void analisarMes(int mes){
	switch(mes){
		case JANEIRO:
			registroVendas = fopen("registroVendasJaneiro", "rb");
			break;
		case FEVEREIRO:
			registroVendas = fopen("registroVendasFevereiro", "rb");
			break;
		case MARCO:
			registroVendas = fopen("registroVendasMarco", "rb");
			break;
		case ABRIL:
			registroVendas = fopen("registroVendasAbril", "rb");
			break;
		case MAIO:
			registroVendas = fopen("registroVendasMaio", "rb");
			break;
		case JUNHO:
			registroVendas = fopen("registroVendasJunho", "rb");
			break;
		case JULHO:
			registroVendas = fopen("registroVendasJulho", "rb");
			break;
		case AGOSTO:
			registroVendas = fopen("registroVendasAgosto", "rb");
			break;
		case SETEMBRO:
			registroVendas = fopen("registroVendasSetembro", "rb");
			break;
		case OUTUBRO:
			registroVendas = fopen("registroVendasOutubro", "rb");
			break;
		case NOVEMBRO:
			registroVendas = fopen("registroVendasNovembro", "rb");
			break;
		case DEZEMBRO:
			registroVendas = fopen("registroVendasDezembro", "rb");
			break;
	}
}

//Checando qual mês é a partir do input recebido, pré validado, para uso de print na tela
char *stringMes(int mes){
	switch(mes){
			case JANEIRO:
				return "[JANEIRO]";
			case FEVEREIRO:
				return "[FEVEREIRO]";
			case MARCO:
				return "[MARÇO]";
			case ABRIL:
				return "[ABRIL]";
			case MAIO:
				return "[MAIO]";
			case JUNHO:
				return "[JUNHO]";
			case JULHO:
				return "[JULHO]";
			case AGOSTO:
				return "[AGOSTO]";
			case SETEMBRO:
				return "[SETEMBRO]";
			case OUTUBRO:
				return "[OUTUBRO]";
			case NOVEMBRO:
				return "[NOVEMBRO]";
			case DEZEMBRO:
				return "[DEZEMBRO]";
		}
}

//Adicionando uma venda de refeição manualmente, com o programa presumindo
//que é a refeição à quilo.
void vendaRefeicaoManual(){
	struct Vendas venda;
	strcpy(venda.tipo, "A quilo");
	printf("Digite o peso em gramas da refeição vendida: ");
	fflush(stdin);
	fscanf(stdin, "%d", &venda.peso);
	float preco = calcularPrecoPorPeso(venda.peso);
	printf("\n\nO preço por %d gramas é %.2f", venda.peso, preco);
	printf("\n\nHouve bebida nessa venda?\n");
	printf("1- Sim\t2- Não\n");
	fflush(stdin);
	fscanf(stdin, "%d", &escolha);
	validarEscolha(2);
	if(escolha != 2){
		listaBebidas();
		fflush(stdin);
		fscanf(stdin, "%d", &escolha);
		validarEscolha(4);
		printf("E quantas bebidas vão ser?\n");
		fflush(stdin);
		fscanf(stdin, "%d", &venda.qtdBebidas);
		if(venda.qtdBebidas != 0){
			preco = preco + adicionarBebida(escolha, venda.qtdBebidas);
		}
		venda.precoFinal = preco;
		printf("\nO preço final da refeição com bebidas é de: %.2f", venda.precoFinal);
	}else{
		venda.precoFinal = preco;
		printf("\nO preço final da refeição é de: %.2f", venda.precoFinal);
	}
	printf("\n\nE quando foi feita essa venda?\n");
	printf("Inserir o mês de venda.\n");
	printf("Exemplo:\nJaneiro -> 1\nFevereiro -> 2\n");
	fscanf(stdin, "%d", &meses);
	registrarMes(meses);
	printf("\nTipo: %s\n", venda.tipo);
	printf("Peso: %d\n", venda.peso);
	printf("Qtd. Bebidas: %d\n", venda.qtdBebidas);
	printf("Preço: %.2f\n", venda.precoFinal);
	fwrite(&venda, sizeof(venda), 1, registroVendas);
	fclose(registroVendas);
	printf("Venda registrada!\n");
}

//Adicionando uma venda de refeição manualmente, com o programa presumindo
//que é a quentinha.
void vendaQuentinhaManual(){
	struct Vendas venda;
	strcpy(venda.tipo, "Quentinha");
	venda.peso = 600;
	venda.precoFinal = quentinha();
	printf("\n\nHouve bebida nessa venda?\n");
	printf("1- Sim\t2- Não\n");
	fscanf(stdin, "%d", &escolha);
	validarEscolha(2);
	if(escolha != 2){
		listaBebidas();
		fflush(stdin);
		fscanf(stdin, "%d", &escolha);
		validarEscolha(4);
		printf("\nE quantas bebidas vão ser?\n");
		fflush(stdin);
		fscanf(stdin, "%d", &venda.qtdBebidas);
		venda.precoFinal += adicionarBebida(escolha, venda.qtdBebidas);
		printf("\nO preço final da quentinha com bebidas é de: %.2f", venda.precoFinal);
	}else{
		printf("\nO preço final da quentinha é de: %.2f", venda.precoFinal);
	}
	printf("\n\nE quando foi feita essa venda?\n");
	printf("Inserir o mês de venda.\n");
	printf("Exemplo:\nJaneiro -> 1\nFevereiro -> 2\n");
	fscanf(stdin, "%d", &meses);
	registrarMes(meses);
	printf("\nTipo: %s\n", venda.tipo);
	printf("Peso: %d\n", venda.peso);
	printf("Qtd. Bebidas: %d\n", venda.qtdBebidas);
	printf("Preço: %.2f\n", venda.precoFinal);
	fwrite(&venda, sizeof(venda), 1, registroVendas);
	fclose(registroVendas);
	printf("Venda registrada!\n");
}

//Preenchendo as 100 vendas diárias aleatoriamente
void vendasDiaria(){
	struct Vendas venda;
	int random;
	int qtdVenda;
	for(qtdVenda = 1; qtdVenda <= 100; qtdVenda++){
		// Random de 1 ou 0
		random = rand()%2;
		if(random == 0){
			//A quilo
			strcpy(venda.tipo, "A quilo");
			venda.peso = rand()%(900 + 1 - 300) + 300; // Peso aleatório entre 300 e 900 gramas
			venda.qtdBebidas = rand()%(2 + 1 - 0) + 0; // Quantidade aleatória de bebidas entre 0 e 2
			venda.precoFinal = calcularPrecoPorPeso(venda.peso);
			if(venda.qtdBebidas != 0){
				// Se houver bebida
				int bebida = rand()%(4 + 1 - 1) + 1; // Qual das bebidas, aleatorio
				venda.precoFinal += adicionarBebida(bebida, venda.qtdBebidas);
			}
			fwrite(&venda, sizeof(venda), 1, registroVendas); // Registra no arquivo
		}else{
			//Quentinha
			strcpy(venda.tipo, "Quentinha");
			venda.peso = 600; //Peso padrão da quentinha
			venda.qtdBebidas = rand()%(2 + 1 - 0) + 0; // Quantidade aleatória de bebidas entre 0 e 2
			venda.precoFinal = quentinha(); // Preço padrão da quentinha
			if(venda.qtdBebidas != 0){
				//Se houver bebida
				int bebida = rand()%(4 + 1 - 1) + 1; // Qual das bebidas, aleatorio
				venda.precoFinal += adicionarBebida(bebida, venda.qtdBebidas);
			}
			fwrite(&venda, sizeof(venda), 1, registroVendas); // Registra no arquivo
		}
	}
}

//Preenchendo os dados equivalentes a 1 ano de vendas
void preencherDados(){
	int mes;
	//Loop para cada mês
	for(mes = JANEIRO; mes <= DEZEMBRO; mes++){
		int dia;
		//Abre um novo arquivo binário para cada mês
		registrarMes(mes);
		if(mes == FEVEREIRO){ // Se mês fevereiro, loop dos dias tem apenas 28 iterações
			for(dia = 1; dia <= 28; dia++){
				vendasDiaria();
			}
		}else{
			//Se mês não é fevereiro, loop dos dias tem 30 iterações, sendo o "mês comercial"
			for(dia = 1; dia <= 30; dia++){
				vendasDiaria();
			}	
		}
		fclose(registroVendas);
	}
	if(registroVendas != NULL){ // Checa se por ventura o arquivo não está ainda aberto
		fclose(registroVendas); // e fecha se estiver
	}
	printf("\n\n**** Vendas geradas com sucesso! ****\n\n");
}

// Relatório diário, onde pode-se escolher o mês e o dia para ver os valores.
void relatorioDiario(){
	struct Vendas venda;
	int mes, dia, i;
	int quentinha = 0;
	int quilo = 0;
	float faturamentoDiario, pesoVendido;
	printf("Insira o número equivalente ao mês que deseja consultar.\n");
	printf("Exemplo:\n Janeiro -> 1\n");
	printf("Fevereiro -> 2\n");
	fflush(stdin);
	fscanf(stdin, "%d", &mes);
	analisarMes(mes); // abrindo o arquivo de leitura do mês solicitado
	printf("Insira o valor do dia do mês.\n");
	fflush(stdin);
	fscanf(stdin, "%d", &dia);
	fseek(registroVendas, sizeof(venda) * (dia - 1) * 100, SEEK_SET); //movendo o ponteiro para o dia específico
	printDiaMes(dia, mes);
	for(i = 1; i <= 100; i++){
		fread(&venda, sizeof(venda), 1, registroVendas);
		if(strcmp(venda.tipo, "A quilo")){
			quilo++;
		}
		if(strcmp(venda.tipo, "Quentinha")){
			quentinha++;
		}
		faturamentoDiario += venda.precoFinal; // adicionando ao faturamento diário
		pesoVendido += venda.peso; // adicionando ao peso vendido diário
	}
	pesoVendido = (pesoVendido * 0.001); // convertendo para kg
	//mostrando o faturamento total do dia
	printf("****** Faturamento do dia ******\n");
	printf("Quentinhas vendidas: %d\n", quentinha);
	printf("Refeições a quilo vendidas: %d\n", quilo);
	printf("Total de peso de comida vendido: %.2fkg\n", pesoVendido);
	printf("Total de faturamento: R$%.2f", faturamentoDiario);
}

// Realizando o relatório mensal
void relatorioMensal(){
	struct Vendas vendaAtual;
	int mes;
	int quilo = 0;
	int quentinha = 0;
	float faturamentoMensal[DEZEMBRO];
	float pesoVendido;
	char string[25];
	// Loop para cada mês
	printf("\n\n****** Faturamento Mensal ******\n\n");
	for(mes = JANEIRO; mes <= DEZEMBRO; mes++){
		analisarMes(mes);
		while(fread(&vendaAtual, sizeof(vendaAtual), 1, registroVendas)){
			if(strcmp(vendaAtual.tipo, "A quilo")){
				quilo++;
			}
			if(strcmp(vendaAtual.tipo, "Quentinha")){
				quentinha++;
			}
			faturamentoMensal[mes - 1] += vendaAtual.precoFinal;
			pesoVendido += vendaAtual.peso;
		}
		strcpy(string, stringMes(mes));
		printf("**** %s ****\n", string);
		printf("Quentinhas vendidas: %d\n", quentinha);
		printf("Refeições a quilo vendidas: %d\n", quilo);
		printf("Total de peso de comida vendido: %.2fkg\n", pesoVendido * 0.001);
		printf("\nFaturamento: R$%.2f\n\n", faturamentoMensal[mes - 1]);
		fclose(registroVendas);
		quentinha = 0;
		quilo = 0;
		pesoVendido = 0;
	}
}

void compararVendas(){
	struct Vendas vendaAtual;
	float faturamentoMensal[DEZEMBRO];
	int mes, i;
	int meses[DEZEMBRO];
	for(mes = JANEIRO; mes <= DEZEMBRO; mes++){
		analisarMes(mes);
		while(fread(&vendaAtual, sizeof(vendaAtual), 1, registroVendas)){
			faturamentoMensal[mes - 1] += vendaAtual.precoFinal;
		}
		meses[mes - 1] = mes;
		fclose(registroVendas);
	}
	for(i = JANEIRO - 1; i < DEZEMBRO; i++){
		int mem, memMeses; // memoria pra auxiliar
		int j; // iterador do loop interno
		for(j = i; j < DEZEMBRO; j++){
			if(faturamentoMensal[i] < faturamentoMensal[j]){
				//Reordenando o faturamento do mês
				mem = faturamentoMensal[j];
				faturamentoMensal[j] = faturamentoMensal[i];
				faturamentoMensal[i] = mem;
				//Reordenando o mês em si
				memMeses = meses[j];
				meses[j] = meses[i];
				meses[i] = memMeses;
			}
		}
	}
	int l;
	char string[25];
	for(l = 0; l < DEZEMBRO; l++){
		strcpy(string, stringMes(meses[l]));
		printf("**** %s ****", string);
		printf("\nFaturamento: R$%.2f\n\n", faturamentoMensal[l]);
	}
	printf("\n\n**** Mês com maior faturamento ****\n");
	strcpy(string, stringMes(meses[0]));
	printf("%s\n\n", string);
	printf("**** Mês com menor faturamento ****\n");
	strcpy(string, stringMes(meses[11]));
	printf("%s\n\n", string);
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	printf("Bem vindo ao sistema de registro de vendas!");
	do{
		printf("\n\nO que deseja fazer?\n");
		printf("1- Inserir nova venda manualmente (A quilo)\n");
		printf("2- Inserir nova venda manualmente (Quentinha)\n");
		printf("3- Gerar 1 ano de vendas automaticamente.\n");
		printf("4- Relatorio diario.\n");
		printf("5- Relatorio mensal.\n");
		printf("6- Mês com maior faturamento.\n");
		printf("7- Sair\n\n");
		fflush(stdin);
		fscanf(stdin, "%d", &escolha);
		switch(escolha){
			case 1:
				vendaRefeicaoManual();
				break;
			case 2:
				vendaQuentinhaManual();
				break;
			case 3:
				preencherDados();
				break;
			case 4:
				relatorioDiario();
				break;
			case 5:
				relatorioMensal();
				break;
			case 6:
				compararVendas();
				break;
			case 7:
				printf("\n\n***** Obrigado! *****\n");
				return 0;
			default:
				printf("Insira um valor válido.\n");
				break;
		}
	}while(escolha != 7);
}
