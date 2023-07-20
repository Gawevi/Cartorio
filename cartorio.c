#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca respons�vel por strings

int registro() //Cria��o de fun��o de registro
{
	char arquivo[40]; //Cria��o de vari�vel
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\tInsira o CPF para cadastro:\n\n\t"); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s � referente a strings
	
	strcpy(arquivo, cpf); //C�pia de vari�veis da string
	
	FILE *file; //Cria��o de arquivo
	file = fopen(arquivo, "w"); //Novo arquivo com t�tulo do cpf
	fprintf(file, "\n\tCPF: ");
	fprintf(file,cpf); //Escrever no arquivo criado
	fclose(file); //Fechar o arquivo criado
	
	file = fopen(arquivo, "a"); //Atualiza��o de arquivo j� criado
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

int consulta() //Cria��o de fun��o de consulta
{
	char cpf[40]; //Constata��o da vari�vel
	char conteudo[200]; //Cria��o de vari�vel
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\tInsira o CPF para consulta:\n\n\t");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Leitura de um arquivo j� criado
	
	if(file == NULL) //Defini��o de resposta para CPF inv�lido
	{
		system("cls");
		printf("\n\n\n\n\tN�o foi poss�vel encontrar o CPF indicado!");
		printf("\n\n\n\n");
		system("pause");
	}
	
	system("cls");
	
	if(file != NULL)
	{
		printf("\n\tEssas s�o as informa��es encontradas:\n\n\t");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Valida��o para armazenar enquanto houver informa��o
	{
		printf("%s", conteudo);
	}
	
	if(file != NULL)
	{
		system("pause");
	}
	
	fclose(file);
}

int deletar() //Cria��o de fun��o de deletar
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
		printf("\n\n\n\n\tO CPF n�o foi encontrado!");
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
	int opcao=0; //Defini��o de var�avel de escolha do menu
	int repetir=1; //Defini��o de vari�vel para repeti��o
	
	for(repetir=1;repetir=1;) //Defini��o de repeti��o
	{

		system("cls"); //Limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Funcionalidades do Software: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\n\t4 - Fechar o Programa\n");
		printf("\n\tDigite a Op��o Desejada: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenamento de resposta do usu�rio
		
		system("cls"); //Limpar a tela
		
		switch(opcao) //In�cio da sele��o
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
			printf("\n\n\n\n\tEssa op��o n�o est� dispon�vel!\n\n\n\n"); //Fim da sele��o
			system("pause");
			break;
		}
		
	}
	
}
