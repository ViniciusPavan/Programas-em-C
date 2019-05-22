// Vinicius Pavan dos Santos ra:111838
//imprementação realizada para a materia de
// Fundamentos de Algoritimo na linguagem C
#include <stdio.h>
#include <stdlib.h>

#define MAXCAD 200
#define TAM1 50
#define TAM2 100


// CONTADORES
int i, j;
long int total;


//VARIAVEIS DE VERIFICAÇÃO
char ok;
int op, senha;


//REGISTROS

struct reg1
{
  char nome_vinho[TAM2];
  char regiao_vinho[TAM2];
  char nome_produtor[TAM2];
  char tipo_vinho[TAM1];
  char pais_vinho[TAM1];
  int data_estocagem;
  int safra_vinho;
  int codigo_vinho;
};


//DECLARAÇÃO DO REGISTRO

struct reg1 Cad[MAXCAD];


//TAMANHO DOS REGISTROS

int REG[2] = {0, sizeof (struct reg1)};


//FUNÇÕES


int Cadastro1();
int Remocao2();
int Alteracao3();
int Consulta4();
int Listagem5();
int Safra6();
int Tipo7();
int Sair();

void Menu();
char Tipo();



//ARQUIVOS

FILE *arquivo[2];


//FUNÇÃO PARA ABERTURA DE Arquivos

int AbrirCad();


//FUNÇÃO PRINCIPAL

int main()
{
  int marca1 = 0;
  int op, marca = 00;

  if (marca == 0)
  {

    marca1 = AbrirCad();
    marca = 1;

  }

  do
  {

    Menu();
    scanf(" %i\n", &op);
    system("clear");
    switch (op)
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:

      default:
          if (op != 0)
          {
            system("clear");
            printf("OPÇÃO INVALIDA !!");
            break;
          }
    }
  } while(op != 0);
  return 0;
}



// Menu()
void Menu()
{
  system("clear");
  printf("--------------------------------------------------------------------------------");
  printf("                           GERENCIAMENTO DA ADEGA\n\n");
  printf("               Seja bem vindo e tenha um exelente degustação\n");
  printf("________________________________________________________________________________\n");
  printf("1-Cadrastro\n");
  printf("2-Remoção\n");
  printf("3-Alteração\n");
  printf("4-Consulta\n");
  printf("5-Todos os vinhos\n");
  printf("6-Safra\n");
  printf("7-tipo de vinho\n");
  printf("8-Sair\n");
  printf("--------------------------------------------------------------------------------");
  printf("Qual a opção desejada ?\n\n>");
}


// ABRIR ARQUIVO

int AbrirCad()
{

}

//LIMPAR O BUFFER

void limparBuffer()
{

    char c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

// SAIR

int Sair()
{
    char ok;
    printf("Você deseja sair deste cadastramento? (S/N)\n");
    ok = getchar();
    limparBuffer();
    if (ok == 'S' || ok == 's')
    {
      return 1;
    }
    return 0;
}

// TIPO DO VINHO
char Tipo(n)
{
  char temp;
  switch(n)
  {
    case 1

  }

}
