#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsável por cadastrar os usuários no sistema
{
	
	//início da criação de variáveis/string
	char arquivo[40]; //armazenar caractere (CHARactere)
	char cpf[40]; //requisito chave para diferenciar os usuários
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF: \n"); //coletando informação do cpf do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar o valor das strings
	
	FILE *file; //cria arquivo no banco de dados "computador"
	file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever (write)
	fprintf(file, cpf); //salvar o valor da variavel dentro do arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file, ","); //separar informações cadastradas por vírgula
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome: \n"); //letreiro para usuário saber que tem que tem que incluir o nome no banco de dados
	scanf("%s",nome); //variavel pelo nome
	
	file = fopen(arquivo, "a"); //abrir o arquivo para salvar as informações do nome
	fprintf(file,nome); //salvar o valor da variavel "nome" no banco de dados
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file, ","); //separar os dados por vírgula
	fclose(file); //fechar o arquivo
	
	printf("Digite o sobrenome: \n"); //letreiro para usuário saber que tem que tem que incluir o sobrenome no banco de dados
	scanf("%s",sobrenome); //variavel pelo sobrenome
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,sobrenome); //salvar o valor da variavel "sobrenome" no arquivo
	fclose(file); //fechar o arquivo

	file = fopen(arquivo, "a"); //abrir o arquivo 
	fprintf(file, ","); //separar as informações por vírgula
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo: \n"); //letreiro para usuário saber que tem que tem que incluir informações dos cargos
	scanf("%s",cargo); //variavel pelo cargo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,cargo); //incluir as informações do cargo
	fclose(file); //fechar o arquivo

	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file, ","); //separar os dados por vírgula
	fclose(file); //fechar o arquivo
	
	system("pause"); //para manter na tela e não pular de volta para o início
			
}
int consultar()
{

	setlocale(LC_ALL, "Portuguese"); //irrelevante pois já está no MAIN - aceitar informações de acentuação em português.

	char cpf[40]; //criar caractere para incluir a informação do CPF
	char conteudo[200]; //foi incluído para trazer todas as informações cadastradas (?)
	
	printf("Digite o CPF: \n"); //letreiro para usuário ser informado do que o sistema está pedindo a informação do CPF
	scanf("%s",cpf); //localizar variavel pelo CPF
	
	FILE *file; //localizar no arquivo "file (arquivo)"
	file = fopen(cpf,"r"); //ler as informações a partir do CPF
	
	if(file == NULL) //fórmula para caso não seja localizado o CPF
	{
		printf("Arquivo não localizado! \n"); //letreiro do que vai aparecer caso não seja localizado os dados
	}

	while(fgets(conteudo, 200, file) != NULL) //Fórmula no caso o arquivo ser localizado no banco de dados
	{
		printf("\nEssas são as informações do usuário: "); //letreiro que vai aparecer para o usuário ao aparecer as informações que constam no banco de dados
		printf("%s",conteudo); //as informações que estão no arquivo
		printf("\n\n"); //espaço para baixo "perfumaria"
	}

	system("pause"); //permanecer na tela e não voltar para tela inicial
	
}

int deletar()
{
	char cpf[40]; //incluir caractere para excluir o dado
	
	printf("Digite o CPF do usuário a ser deletado: \n"); //letreiro para o usuário entender o que fazer
	scanf("%s", cpf); //variavel pelo CPF
	
	remove(cpf); //formula para deletar o CPF após o usuário inserir os dados
	
	FILE *file; //Procurar no arquivo as informações à serem deletadas
	file = fopen(cpf,"r"); //abrir o arquivo com a informação do CPF
	
	if(file == NULL) //caso não seja localizado o CPF gerar uma informação para op usuário
	{	
		printf("O usuário não se encontra no sistema!.\n"); //letreiro que aparecerá caso o CPF não seja localizado no banco de dados
		system("pause"); //para permanecer na tela e não voltar para o início
	}	
}

int main() //formula principal - para que serve o programa
{	
	int opcao=0; 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a línguagem

		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opçao: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls"); //inicio da seleção do menu
	
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de função
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;	
		} //fim da seleção
	}

	}
	
		else
		printf("Senha incorreta");
}
