#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCAD 200
#define TAM1 50
#define TAM2 100

typedef struct
{
  char nome_vinho[TAM2];
  char qualidade_uva[TAM1];
  char tipo_vinho[TAM1];
  char origens_vinho[TAM2];
  char data_estocagem[12];
  int safra_vinho;
  int codigo_vinho;
}CADASTRO;

typedef struct
{
  char nome_vinho[TAM2];
  char qualidade_uva[TAM1];
  char tipo_vinho[TAM1];
  char origens_vinho[TAM2];
  char data_estocagem[12];
  char safra_vinho[10];
  char codigo_vinho[10];
}AUX;

char qualidade[TAM1], tipo[TAM1];


void Tipo();
void Qualidade();
int Menu();
void Cadastro();
void Remocao();
void Consulta();
void Alteracao();
void Todosvinhos();
void Safra();
void TipoVinho();
void MostraDados();
void CarregaDados();


int main()
{

  int i=0, op, cont=0, cont2=0;
  char a[10], b[10];
  CADASTRO cad[MAXCAD];
  AUX dad[MAXCAD];
  FILE *arquivo;
  FILE *contador;
  contador= fopen("dados_01.txt", "a+");
  fgets(a, 3, contador);
  fgets(b, 3, contador);
  fclose(contador);
  cont= atoi(a);
  cont2=atoi(b);

  arquivo = fopen("dados_02.txt", "r");
  if(arquivo== NULL)
  {
    printf("Não encontrado nenhum resgistro anterior!\n");
  }
  else
  {
    for(i=0; i<cont2; i++)
    {
      fgets(dad[i].nome_vinho, TAM2, arquivo);
      fgets(dad[i].qualidade_uva, TAM1, arquivo);
      fgets(dad[i].tipo_vinho, TAM1, arquivo);
      fgets(dad[i].origens_vinho, TAM2, arquivo);
      fgets(dad[i].data_estocagem, 12, arquivo);
      fgets(dad[i].safra_vinho, 10, arquivo);
      fgets(dad[i].codigo_vinho, 10, arquivo);
    }
  }
  fclose(arquivo);

  CarregaDados(&cad, &dad, cont2);

  do
  {
    Menu(&op);
    switch(op)
      {
        case 1:
          Cadastro(&cad, &cont, &cont2);
          break;
        case 2:
          Remocao(&cad, &cont, &cont2);
          break;
        case 3:
          Alteracao(&cad, cont);
          break;
        case 4:
          Consulta(&cad, &cont, &cont2);
        case 5:
          Todosvinhos(&cad, &cont, &cont2);
          break;
        case 6:
          Safra(&cad, &cont, &cont2);
          break;
        case 7:
          TipoVinho(&cad, &cont, &cont2);
          break;
        case 8:
          MostraDados(&dad, &cont2);
          break;

      }
  }while(op!=9);

  contador=fopen("dados_01.txt", "w");
  fprintf(contador, "%i\n", cont);
  fprintf(contador, "%i", cont2);
  fclose(contador);

  arquivo = fopen("dados_02.txt", "w");
  for(i=0; i<cont2; i++)
  {
    fprintf(arquivo, "%s\n", cad[i].nome_vinho);
    fprintf(arquivo, "%s\n", cad[i].qualidade_uva);
    fprintf(arquivo, "%s\n", cad[i].tipo_vinho);
    fprintf(arquivo, "%s\n", cad[i].origens_vinho);
    fprintf(arquivo, "%s\n", cad[i].data_estocagem);
    fprintf(arquivo, "%i\n", cad[i].safra_vinho);
    fprintf(arquivo, "%i\n", cad[i].codigo_vinho);
  }
  fclose(arquivo);

  return 0;
}

int Menu(int *n)
{
    int op;
    system("clear");
    printf("--------------------------------------------------------------------------------");
    printf("       \t\t\tGERENCIAMENTO DA ADEGA\n\n");
    printf("               Seja bem vindo e tenha um exelente degustação\n");
    printf("--------------------------------------------------------------------------------");
    printf("   1-Cadrastro\n");
    printf("   2-Remoção\n");
    printf("   3-Alteração\n");
    printf("   4-Consulta\n");
    printf("   5-Todos os vinhos\n");
    printf("   6-Safra\n");
    printf("   7-Tipo de vinho\n");
    printf("   8-Opções do desenvolvedor\n");
    printf("   9-Sair\n");
    printf("--------------------------------------------------------------------------------");
    printf("   Qual a opção desejada ?\n\n   >");
    scanf("%i", &op);
    *n = op;
}

void Tipo()
{
  int op;
  printf("\n   1-Tinto Seco\n   2-Tinto Semi-sec\n   3-Tinto\n   4-Rosado\n   5-Branco\n   6-Outro\n\n   >");
  scanf(" %i", &op);
  switch(op)
  {
    case 1:
      strcpy(tipo, "Tinto Seco");
      break;
    case 2:
      strcpy(tipo, "Tinto Semi-sec");
      break;
    case 3:
      strcpy(tipo, "Tinto ");
      break;
    case 4:
      strcpy(tipo, "Rosado");
     break;
    case 5:
      strcpy(tipo, "Branco");
      break;
    case 6:
      printf("\n   Especifique o outro tipo:\n   >");
      scanf(" %[^\n]s", tipo);
      break;
  }
}

void Qualidade()
{
  int op;
  printf("\n   1-Cabernet Sauvignon\t\t8-Sauvignon Blanc\n   2-Malbec            \t\t9-Gewurztraminer\n   3-Merlot            \t\t10-Riesling Itálico\n   4-Tannat            \t\t11-Semillón\n   5-Pinot Noir        \t\t12-Barbera\n   6-Chardonnay        \t\t13-Moscato\n");
  printf("   7-Cabernet Franc \t\t14-Outro\n\n   Selecione a qualidade da uva:\n   >");
  scanf(" %i", &op);

  switch(op)
  {
    case 1:
      strcpy(qualidade, "Cabernet Sauvignon");
      break;
    case 2:
      strcpy(qualidade, "Malbec");
      break;
    case 3:
      strcpy(qualidade, "Merlot");
      break;
    case 4:
      strcpy(qualidade, "Tannat");
     break;
    case 5:
      strcpy(qualidade, "Pinot Noir");
      break;
    case 6:
      strcpy(qualidade, "Chardonnay");
      break;
    case 7:
      strcpy(qualidade, "Cabernet Sauvignon");
      break;
    case 8:
      strcpy(qualidade, "Sauvignon Blanc");
      break;
    case 9:
      strcpy(qualidade, "Gewurztraminer");
      break;
    case 10:
      strcpy(qualidade, "Riesling Itálico");
     break;
    case 11:
      strcpy(qualidade, "Semillón");
      break;
    case 12:
      strcpy(qualidade, "Barbera");
      break;
    case 13:
      strcpy(qualidade, "Moscato");
      break;
    case 14:
      printf("\n   Especifique o outro tipo:\n   >");
      scanf(" %[^\n]s", qualidade);
      break;
  }
}


void Cadastro(CADASTRO cad[], int *cont, int *cont2)
{
  int j, i;
  printf("\n   Quantos vinhos você deseja cadastrar ?\n\n   >");
  scanf("%i", &j);
  j=j+(*cont2);
  for(i=(*cont2); i<j; i++)
  {
    system("clear");
    printf("--------------------------------------------------------------------------------");
    printf("       \t\t\t CADASTRAMENTO DE VINHOS\n\n");
    printf("--------------------------------------------------------------------------------");
    cad[i].codigo_vinho = *cont;
    printf("\n\n   Codigo do vinho: %i\n\n", cad[i].codigo_vinho);
    printf("   Nome do vinho:\n   >");
    scanf(" %[^\n]s", cad[i].nome_vinho);
    printf("\n   Selecione o tipo do vinho: \n");
    Tipo();
    strcpy(cad[i].tipo_vinho, tipo);
    printf("\n   Safra do vinho:\n   >");
    scanf("%i", &cad[i].safra_vinho);
    system("clear");
    printf("--------------------------------------------------------------------------------");
    printf("       \t\t\t CADASTRAMENTO DE VINHOS\n\n");
    printf("--------------------------------------------------------------------------------");
    printf("\n   Qual a qualidade da uva?\n   >");
    Qualidade();
    strcpy(cad[i].qualidade_uva, qualidade);
    printf("\n   Quais as origens do vinho ?\n   >");
    scanf(" %[^\n]s", cad[i].origens_vinho);
    printf("\n   Data da estocagem DD/MM/AAAA:\n   >");
    scanf(" %[^\n]s", cad[i].data_estocagem);
    *cont= *cont+1;
    *cont2= *cont2 +1;
   }
}

void Remocao(CADASTRO *cad, int *cont, int *cont2)
{
  int i, n, j, res=1, msg;
  do
  {
    msg=0;
    system("clear");
    printf("--------------------------------------------------------------------------------");
    printf("       \t\t\t\t REMOÇÃO DE VINHOS\n\n");
    printf("--------------------------------------------------------------------------------");
    printf("\n   Digite o código do cadastro \n\n   >");
    scanf(" %i", &n);
    for(j=0; j<(*cont); j++)
    {
      if(j == n)
      {
        strcpy(cad[j].nome_vinho, cad[j+1].nome_vinho);
        strcpy(cad[j].qualidade_uva, cad[j+1].qualidade_uva);
        strcpy(cad[j].tipo_vinho, cad[j+1].tipo_vinho);
        strcpy(cad[j].origens_vinho, cad[j+1].origens_vinho);
        strcpy(cad[j].data_estocagem, cad[j+1].data_estocagem);
        cad[j].safra_vinho = cad[j+1].safra_vinho;
        cad[j].codigo_vinho = cad[j+1].codigo_vinho;
        for (i=j+1; i<(*cont); i++)
        {
          strcpy(cad[i].nome_vinho, cad[i+1].nome_vinho);
          strcpy(cad[i].qualidade_uva, cad[i+1].qualidade_uva);
          strcpy(cad[i].tipo_vinho, cad[i+1].tipo_vinho);
          strcpy(cad[i].origens_vinho, cad[i+1].origens_vinho);
          strcpy(cad[i].data_estocagem, cad[i+1].data_estocagem);
          cad[i].safra_vinho = cad[i+1].safra_vinho;
          cad[i].codigo_vinho = cad[i+1].codigo_vinho;

        }
        *cont2=(*cont2)-1;
        msg=1;
      }
    }
    if(msg==0)
    {
      printf("\n   Nenhum vinho encontrado com esse codigo!\n");
    }
    else if(msg==1)
         {
           printf("\n   Cadastro de vinho apagado com sucesso!\n");
         }
    printf("\n   Digite:\n\n   1-Nova remoção\n   2-Sair\n\n   >");
    scanf(" %i", &res);
  }while(res==1);
}

void Alteracao(CADASTRO *cad, int cont)
{
  int n, i, cod, res, msg;
  do
  {
    msg=0;
    printf("\n   Qual o codigo do cadastro que vc deseja alterar ?\n   >");
    scanf("%i", &n);
    system("clear");
    for(i=0; i<cont; i++)
    {
      if(n == cad[i].codigo_vinho)
      {
        msg=1;
        printf("--------------------------------------------------------------------------------");
        printf("       \t\t\t\t ALTERAÇÃO DE VINHOS\n\n");
        printf("--------------------------------------------------------------------------------");
        printf("\n   Qual o campo do cadastro você deseja alterar?\n");
        printf("\n   1-Nome do vinho\n   2-Tipo do vinho\n   3-Origens do vinho\n   4-Qualidade da uva\n   5-Safra do vinho\n   6-Data da estocagem\n\n   >");
        scanf("%i", &cod);
        switch(cod)
        {
          case 1:
              printf("\n   Qual o novo nome ?\n   >");
              scanf(" %[^\n]s", cad[i].nome_vinho);
              break;
          case 2:
              printf("\n   Alterar o tipo :\n\n");
              Tipo();
              strcpy(cad[i].tipo_vinho, tipo);
              break;
          case 3:
              printf("\n   Quais as novas origens do vinho?\n   >");
              scanf(" %[^\n]s", cad[i].origens_vinho);
              break;
          case 4:
              printf("\n   Qual o nova qualidade da uva?\n   >");
              Qualidade();
              strcmp(qualidade, cad[i].qualidade_uva);
              break;
          case 5:
              printf("\n   Qual o nova safra do vinho?\n   >");
              scanf(" %i", &cad[i].safra_vinho);
              break;
          case 6:
              printf("\n   Qual a nova data de estocagem DD/MM/AAAA:\n   >");
              scanf(" %[^\n]s", cad[i].data_estocagem);
              break;
        }
      }
    }
    if(msg==0)
    {
      printf("\n   Nenhum vinho encontrado com esse codigo!\n");
    }
    printf("\n   Digite:\n\n   1-Nova alteração\n   2-Sair\n\n   >");
    scanf(" %i", &res);
  }while(res==1);
}


void Consulta(CADASTRO *cad, int *cont, int *cont2)
{
  int n=1, i, j, sair=1, msg;

  system("clear");
  printf("--------------------------------------------------------------------------------");
  printf("      \t\t\t\t CONSULTA DE VINHOS\n\n");
  printf("--------------------------------------------------------------------------------");
  do{
      if((*cont2) == 0)
      {
        printf("\n   Você não possui vinhos cadastrados!\n\n   Gostaria de cadastrar?\n   1-Sim\n   2-Agora não\n   >");
        scanf(" %i", &n);

        if(n==1)
        {
          Cadastro(&(*cad), &(*cont), &(*cont2));
        }

        else if(n==2)
        {
          sair=2;
        }
      }
      if(n==1)
      {
        msg=0;
        printf("   Digite o codigo do vinho a ser consultado:\n\n   >");
        scanf("%i", &j);
        for(i=0; i<(*cont); i++)
        {
          if(j == cad[i].codigo_vinho)
          {
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Código do vinho:    | %i\n", cad[i].codigo_vinho);
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Nome do vinho:      | %s\n", cad[i].nome_vinho);
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Tipo do vinho:      | %s\n", cad[i].tipo_vinho);
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Qualidade da uva:   | %s\n", cad[i].qualidade_uva);
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Origens do vinho:   | %s\n", cad[i].origens_vinho);
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Safra do vinho:     | %i\n", cad[i].safra_vinho);
            printf("   ----------------------------------------------------------|\n");
            printf("   |  Data de estocagem:  | %s\n", cad[i].data_estocagem);
            printf("   ----------------------------------------------------------|\n");
            msg=1;
          }
        }
      }
      if(msg==0)
      {
        printf("\n   Nenhum vinho encontrado com esse codigo!\n");
      }
      if(n==1)
      {
        printf("\n   Digite:\n\n   1-Nova consulta\n   2-Sair\n\n   >");
        scanf(" %i", &sair);
      }
    }while(sair==1);
}

void Todosvinhos(CADASTRO *cad, int *cont, int *cont2)
{
  int n, r=1, res=1;
  do{
      system("clear");
      printf("--------------------------------------------------------------------------------");
      printf("      \t\t\tLISTAGEM DE TODOS OS VINHOS\n\n");
      printf("--------------------------------------------------------------------------------");
      for (n=0; n<(*cont2); n++)
      {
          printf("   ----------------------------------------------------------|\n");
          printf("   Código do vinho:    |   %i\n", cad[n].codigo_vinho);
          printf("   Nome do vinho:      |   %s\n", cad[n].nome_vinho);
          printf("   Tipo do vinho:      |   %s\n", cad[n].tipo_vinho);
          printf("   Qualidade da uva:   |   %s\n", cad[n].qualidade_uva);
          printf("   Origens do vinho:   |   %s\n", cad[n].origens_vinho);
          printf("   Safra do vinho:     |   %i\n", cad[n].safra_vinho);
          printf("   Data de estocagem:  |   %s\n\n", cad[n].data_estocagem);
          printf("   ----------------------------------------------------------|\n");
      }
      if((*cont2) == 0)
      {
        printf("\n   Você não possui nenhum vinho cadastrado!\n   Gostaria de cadastrar agora?\n\n   Digite:\n\n   1-Sim\n   2-Agora não\n   >");
        scanf("%i", &res);
        if(res==1)
        {
          Cadastro(&(*cad), &(*cont), &(*cont2));
        }
      }
      if(res==1)
      {
        printf("\n   Digite:\n\n   1-Atualizar\n   2-Sair\n\n   >");
        scanf(" %i", &r);
      }
      else
      {
        r=2;
      }
    }while(r==1);
}

void Safra(CADASTRO *cad, int *cont, int *cont2)
{
  system("clear");
  printf("-------------------------------------------------------------------------------");
  printf("      \t\t\t\t SAFRA DOS VINHOS\n\n");
  printf("--------------------------------------------------------------------------------");
  int i, op=1, n, safra, msg, msg2, op2;
  if ((*cont) ==0)
  {
    printf("   Você não possui vinhos cadastados!\n\n   Gostaria de cadastrar ?\n\n   1-Sim\n   2-Agora não\n   >");
    scanf("%i", &op2);
    if(op2==1)
    {
      Cadastro(&(*cad), &(*cont), &(*cont2));
    }
  }
  if(op==1)
  {
    do
    {
      system("clear");
      printf("-------------------------------------------------------------------------------");
      printf("      \t\t\t\t SAFRA DOS VINHOS\n\n");
      printf("--------------------------------------------------------------------------------");
      msg=0;
      msg2=0;
      printf("\n   Digite uma safra para consulta\n   >");
      scanf(" %i", &safra);
      system("clear");
      printf("-------------------------------------------------------------------------------");
      printf("      \t\t\t\t SAFRA DOS VINHOS\n\n");
      printf("--------------------------------------------------------------------------------");
      printf("   ----------------------------------------------------------|\n");
      for (i=0; i<(*cont2); i++)
      {
        if(safra == cad[i].safra_vinho)
        {
          printf("   |   Nome do vinho  : %s \n", cad[i].nome_vinho);
          printf("   |   Codigo do vinho: %i | safra de : %i |\n", cad[i].codigo_vinho, cad[i].safra_vinho);
          printf("   ----------------------------------------------------------|\n");
          msg=1;
        }
      }
      if(msg==0)
      {
        printf("\n   Não existem vinhos cadastrados com essa safra!\n");
      }
      printf("\n   Digite:\n\n   1-Nova pesquisa\n   2-Atualizar safra\n   3-sair\n\n   >");
      scanf(" %i", &op);
      switch(op)
      {
        case 2:
        printf("\n   Qual o codigo do cadastro que você deseja atualizar ?\n   >");
        scanf("%i", &n);
        for(i=0; i<(*cont); i++)
        {
          if(n == cad[i].codigo_vinho)
          {
            printf("\n   Qual o nova safra do vinho\n   >");
            scanf(" %i", &cad[i].safra_vinho);
            msg2=1;
            break;
          }
        }
        if(msg2==0)
        {
          printf("\n   Esse cadastro não existe!");
        }
        break;
      }
    }while(op!=3);
  }
}



void TipoVinho(CADASTRO *cad, int *cont, int *cont2)
{
  int i, r=1, msg=0, msg2=0, cod;
  if((*cont == 0))
  {
    system("clear");
    printf("-------------------------------------------------------------------------------");
    printf("      \t\t\t\t TIPO DE VINHOS\n\n");
    printf("--------------------------------------------------------------------------------");
    printf("\n   Você não possui vinhos cadastrados !\n\n   Deseja cadastrar?\n   1-Sim\n   2-Não\n   >");
    scanf("%i", &r);
    msg2=1;
    if(r==1)
    {
      Cadastro(&(*cad), &(*cont), &(*cont2));
    }
  }
  if(msg2==0)
  {
   do
   {
      system("clear");
      printf("-------------------------------------------------------------------------------");
      printf("      \t\t\t\t TIPO DE VINHOS\n\n");
      printf("--------------------------------------------------------------------------------");
      printf("   Selecione o tipo de vinho:\n");
      Tipo();
      system("clear");
      printf("-------------------------------------------------------------------------------");
      printf("      \t\t\t\t TIPO DE VINHOS\n\n");
      printf("--------------------------------------------------------------------------------");
      printf("   ----------------------------------------------------------|\n");
      for(i=0; i<(*cont); i++)
      {
        if(strcmp(cad[i].tipo_vinho, tipo)==0)
        {
          msg=1;
          printf("   |   Nome do vinho  : %s \n", cad[i].nome_vinho);
          printf("   |   Codigo do vinho: %i | tido do vinho : %s |\n", cad[i].codigo_vinho, cad[i].tipo_vinho);
          printf("   ----------------------------------------------------------|\n");
        }
      }
      if(msg==0)
      {
        printf("   Não encontrado vinhos deste tipo !\n");
      }
      printf("\n   Digite:\n\n   1-Nova pesquisa\n   2-Atualizar tipo\n   3-Sair\n   >");
      scanf("%i", &r);
      if (r==2)
      {
        printf("\n   Digite o código do vinho, para alteração\n   >");
        scanf("%i", &cod);
        for(i=0; i<(*cont2); i++)
        {
          if(i==cad[i].codigo_vinho)
          printf("\n   Alterar o tipo :\n\n");
          Tipo();
          strcpy(cad[i].tipo_vinho, tipo);
        }
      }
    }while(r!=3);
  }
}
void MostraDados(AUX *dad, int *cont2)
{
  int n, r=0;
  do
  {
    for(n=0; n<(*cont2); n++)
    {
      printf("   ----------------------------------------------------------|\n");
      printf("   Código do vinho:    |   %s\n", dad[n].codigo_vinho);
      printf("   Nome do vinho:      |   %s\n", dad[n].nome_vinho);
      printf("   Tipo do vinho:      |   %s\n", dad[n].tipo_vinho);
      printf("   Qualidade da uva:   |   %s\n", dad[n].qualidade_uva);
      printf("   Origens do vinho:   |   %s\n", dad[n].origens_vinho);
      printf("   Safra do vinho:     |   %s\n", dad[n].safra_vinho);
      printf("   Data de estocagem:  |   %s\n\n", dad[n].data_estocagem);
      printf("   ----------------------------------------------------------|\n");
    }
    printf("   Digite:\n   1-Sair\n\n   >");
    scanf("%i", &r);
  }while(r!=1);
}


void CarregaDados(CADASTRO *cad, AUX *dad, int cont2)
{
  int i, j;
  for(i=0; i<cont2; i++)
  {
    strcpy(cad[i].nome_vinho, dad[i].nome_vinho);
    cad[i].nome_vinho[strcspn(cad[i].nome_vinho, "\n")] = '\0';
    strcpy(cad[i].qualidade_uva, dad[i].qualidade_uva);
    cad[i].qualidade_uva[strcspn(cad[i].qualidade_uva, "\n")] = '\0';
    strcpy(cad[i].tipo_vinho, dad[i].tipo_vinho);
    cad[i].tipo_vinho[strcspn(cad[i].tipo_vinho, "\n")] = '\0';
    strcpy(cad[i].origens_vinho, dad[i].origens_vinho);
    cad[i].origens_vinho[strcspn(cad[i].origens_vinho, "\n")] = '\0';
    strcpy(cad[i].data_estocagem, dad[i].data_estocagem);
    cad[i].data_estocagem[strcspn(cad[i].data_estocagem, "\n")] = '\0';
    j= atoi((dad[i]).safra_vinho);
    cad[i].safra_vinho = j;
    j= atoi((dad[i]).codigo_vinho);
    cad[i].codigo_vinho = j;
    }
}
