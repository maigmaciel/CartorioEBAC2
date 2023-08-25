#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	//in�cio da cria��o de vari�veis/string
	char arquivo[40]; //armazenar caractere (CHARactere)
	char cpf[40]; //requisito chave para diferenciar os usu�rios
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF: \n"); //coletando informa��o do cpf do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar o valor das strings
	
	FILE *file; //cria arquivo no banco de dados "computador"
	file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever (write)
	fprintf(file, cpf); //salvar o valor da variavel dentro do arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file, ","); //separar informa��es cadastradas por v�rgula
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome: \n"); //letreiro para usu�rio saber que tem que tem que incluir o nome no banco de dados
	scanf("%s",nome); //variavel pelo nome
	
	file = fopen(arquivo, "a"); //abrir o arquivo para salvar as informa��es do nome
	fprintf(file,nome); //salvar o valor da variavel "nome" no banco de dados
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file, ","); //separar os dados por v�rgula
	fclose(file); //fechar o arquivo
	
	printf("Digite o sobrenome: \n"); //letreiro para usu�rio saber que tem que tem que incluir o sobrenome no banco de dados
	scanf("%s",sobrenome); //variavel pelo sobrenome
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,sobrenome); //salvar o valor da variavel "sobrenome" no arquivo
	fclose(file); //fechar o arquivo

	file = fopen(arquivo, "a"); //abrir o arquivo 
	fprintf(file, ","); //separar as informa��es por v�rgula
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo: \n"); //letreiro para usu�rio saber que tem que tem que incluir informa��es dos cargos
	scanf("%s",cargo); //variavel pelo cargo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,cargo); //incluir as informa��es do cargo
	fclose(file); //fechar o arquivo

	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file, ","); //separar os dados por v�rgula
	fclose(file); //fechar o arquivo
	
	system("pause"); //para manter na tela e n�o pular de volta para o in�cio
			
}
int consultar()
{

	setlocale(LC_ALL, "Portuguese"); //irrelevante pois j� est� no MAIN - aceitar informa��es de acentua��o em portugu�s.

	char cpf[40]; //criar caractere para incluir a informa��o do CPF
	char conteudo[200]; //foi inclu�do para trazer todas as informa��es cadastradas (?)
	
	printf("Digite o CPF: \n"); //letreiro para usu�rio ser informado do que o sistema est� pedindo a informa��o do CPF
	scanf("%s",cpf); //localizar variavel pelo CPF
	
	FILE *file; //localizar no arquivo "file (arquivo)"
	file = fopen(cpf,"r"); //ler as informa��es a partir do CPF
	
	if(file == NULL) //f�rmula para caso n�o seja localizado o CPF
	{
		printf("Arquivo n�o localizado! \n"); //letreiro do que vai aparecer caso n�o seja localizado os dados
	}

	while(fgets(conteudo, 200, file) != NULL) //F�rmula no caso o arquivo ser localizado no banco de dados
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //letreiro que vai aparecer para o usu�rio ao aparecer as informa��es que constam no banco de dados
		printf("%s",conteudo); //as informa��es que est�o no arquivo
		printf("\n\n"); //espa�o para baixo "perfumaria"
	}

	system("pause"); //permanecer na tela e n�o voltar para tela inicial
	
}

int deletar()
{
	char cpf[40]; //incluir caractere para excluir o dado
	
	printf("Digite o CPF do usu�rio a ser deletado: \n"); //letreiro para o usu�rio entender o que fazer
	scanf("%s", cpf); //variavel pelo CPF
	
	remove(cpf); //formula para deletar o CPF ap�s o usu�rio inserir os dados
	
	FILE *file; //Procurar no arquivo as informa��es � serem deletadas
	file = fopen(cpf,"r"); //abrir o arquivo com a informa��o do CPF
	
	if(file == NULL) //caso n�o seja localizado o CPF gerar uma informa��o para op usu�rio
	{	
		printf("O usu�rio n�o se encontra no sistema!.\n"); //letreiro que aparecer� caso o CPF n�o seja localizado no banco de dados
		system("pause"); //para permanecer na tela e n�o voltar para o in�cio
	}	
}

int main() //formula principal - para que serve o programa
{	
	int opcao=0; 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a l�nguagem

		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op�ao: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio
	
		system("cls"); //inicio da sele��o do menu
	
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de fun��o
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
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;	
		} //fim da sele��o
	}

	}
	
		else
		printf("Senha incorreta");
}
