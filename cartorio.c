#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca responsável por strings

int registro() //Criação de função de registro
{
	char arquivo[40]; //Criação de variável
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\tInsira o CPF para cadastro:\n\n\t"); //Coletando informação do usuário
	scanf("%s", cpf); //%s é referente a strings
	
	strcpy(arquivo, cpf); //Cópia de variáveis da string
	
	FILE *file; //Criação de arquivo
	file = fopen(arquivo, "w"); //Novo arquivo com título do cpf
	fprintf(file, "\n\tCPF: ");
	fprintf(file,cpf); //Escrever no arquivo criado
	fclose(file); //Fechar o arquivo criado
	
	file = fopen(arquivo, "a"); //Atualização de arquivo já criado
	fprintf(file, "\n\n\tNome: ");
	fclose(file);

	printf("\n\tInsira o nome para cadastro:\n\n\t");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);

	printf("\n\tInsira o sobrenome para cadastro:\n\n\t");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n\n\tCargo: ");
	fclose(file);

	printf("\n\tInsira o cargo para cadastro:\n\n\t");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file, "\n\n\n\n\n");
	fclose(file);
}

int consulta() //Criação de função de consulta
{
	char cpf[40]; //Constatação da variável
	char conteudo[200]; //Criação de variável
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\tInsira o CPF para consulta:\n\n\t");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Leitura de um arquivo já criado
	
	if(file == NULL) //Definição de resposta para CPF inválido
	{
		system("cls");
		printf("\n\n\n\n\tNão foi possível encontrar o CPF indicado!");
		printf("\n\n\n\n");
		system("pause");
	}
	
	system("cls");
	
	if(file != NULL)
	{
		printf("\n\tEssas são as informações encontradas:\n\n\t");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Validação para armazenar enquanto houver informação
	{
		printf("%s", conteudo);
	}
	
	if(file != NULL)
	{
		system("pause");
	}
	
	fclose(file);
}

int deletar() //Criação de função de deletar
{
	char cpf[40];
	
	printf("\n\tInsira o CPF que deseja deletar:");
	printf("\n\n\t");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		system("cls");
		printf("\n\n\n\n\tO CPF não foi encontrado!");
		printf("\n\n\n\n");
		system("pause");
	}
	
	if(file != NULL)
	{
		system("cls");
		printf("\n\n\n\n\tO CPF foi deletado com sucesso!");
		printf("\n\n\n\n");
		system("pause");
	}
	
	fclose(file);
	
	remove(cpf);
}

int main()
{
	int opcao=0; //Definição de varíavel de escolha do menu
	int repetir=1; //Definição de variável para repetição
	
	for(repetir=1;repetir=1;) //Definição de repetição
	{

		system("cls"); //Limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Funcionalidades do Software: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\n\t4 - Fechar o Programa\n");
		printf("\n\tDigite a Opção Desejada: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenamento de resposta do usuário
		
		system("cls"); //Limpar a tela
		
		switch(opcao) //Início da seleção
		{
			case 1:
			registro();
			break;
				
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("\n\n\n\tObrigado por usar o software!\n\n\n");
			return 0;
			break;
			
			default:
			printf("\n\n\n\n\tEssa opção não está disponível!\n\n\n\n"); //Fim da seleção
			system("pause");
			break;
		}
		
	}
	
}
