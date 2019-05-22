#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cad //Definição dos campos do cadastro da adega
{
  char nome_vinho[100];
  char regiao_vinho[100];
  char nome_produtor;
  char tipo_vinho;
  char pais_vinho;
  int data_estocagem;
  int safra_vinho;
  int codigo_vinho;
};

int main()
{
  //Declaração de variaveis
  struct cad cadastro_principal[100];
  int senha, opcao, opcao2, quant;
  printf("                           GERENCIAMENTO DA ADEGA\n\n");
  printf("usuário: administrador\nsenha:");
  scanf("%i", &senha);
  switch (senha)
  {
    case 123456:
    while(opcao!=8){
        while(opcao2!='s')
        {
          system("cls");
          printf("-------------------------------------------------------------------------------------");
          printf("\t\t\t\tGERENCIAMENTO DA ADEGA\n");
          printf("Seja bem vindo e tenha um exelente degustação\n");
          printf("____________________________________________________________________________________\n");
          printf("1-Cadrastro\n");
          printf("2-Remoção\n");
          printf("3-Alteração\n");
          printf("4-Consulta\n");
          printf("5-Todos os vinhos\n");
          printf("6-Safra\n");
          printf("7-Data da estocagem\n");
          printf("8-Sair\n");
          printf("-------------------------------------------------------------------------------------");
          printf("Qual a opção desejada :");
          scanf("%i", &opcao);
        }
    }
  }
}
