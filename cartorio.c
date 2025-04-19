#include <stdio.h> //biblioteca de comunicação com o usoário 
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun�ao responsavel por cadastrar os usuarios no sistema 
{
	//inicio da cria�ao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria�ao de variaveis/string
	
	printf("digite o CPF a ser cadastrado:"); //coletando informa�ao do usuario
	scanf("%s", cpf);  // "%s" refere-se ao salvar a string 
	
	strcpy(arquivo, cpf);  //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);  //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Português"); //Definindo a linguagem 
	
     char cpf[40];
     char conteudo[200];
     
     printf("digite o CPF a ser consultado:");
     scanf("%s", cpf);
     
     FILE *file;
     file = fopen(cpf, "r");
     
     if (file == NULL)
    {
    	 printf("nao foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	 while (fgets(conteudo, 200, file) != NULL);
    {
	     printf("\nEssas sao as informacoes do usuario:");
	     printf("%s", conteudo);
  	     printf("\n\n");
    }
        system ("pause"); 
		
			 
}

int deletar()
{
        char cpf[40];
        
        printf("digite o cpf do usuario a ser deletado: ");
        scanf("%s",cpf);
        
        remove(cpf);
        
        FILE *file;
        file = fopen(cpf,"r");
        
        if(file == NULL)
        {
        	printf("cpf deletado com sucesso, usuario nao se encontra no sistema! \n");
        	system("pause");  	
		}
        
	
	 
}


int main ()
{
	int opcao=0; //Defenindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
{
		
	system("cls");
	
	setlocale(LC_ALL, "Português"); //Definindo a linguagem 
	
	printf("\t Cartorio da EBAC\n\n"); //inicio do menu
	printf("Escolha a opcao desejada do menu\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n\n");  
	printf("opcao: ");  //fim do menu
	
	scanf("%d" , &opcao);  //armazenando a escolha do usuario 
	
	system("cls"); // responsavel por limpar a tela 
	
	switch(opcao) // inicio da seleçao do menu
	{
		case 1:
		registro(); // chamada de função 
		system("pause");
		break;
		
		case 2:
		consulta();
		system("pause");
		break;
		
		case 3:
		deletar();
        system("pause");
		break;
		
		case 4:
		break;
		
		default:
		printf("Essa opcao nao esta disponivel\n");
		system("pause");
		break;	
	}  //fim da seleção
		
    
} 
    
	
}
		
