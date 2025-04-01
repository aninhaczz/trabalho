#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 100 //tamanho màximo de uma linha no CSV
#define MAX_PROCESSOS 100 //nùmero màximo de pessoas

//estrutura para armazenar os dados do CSV
typedef struct {
    int id;
    char nome[50];
    float valor;
} Processo;
     
//função para ler o CSV e armazenar os dados em um array 
int lerCSV(const char *nomeArquivo, Processo processos[], int maxProcessos){
    FILE *arquivo = fopen(nomeArquivo, "ï"); //abre o arquivo para leitura
    if(!arquivo) {
       printf("Erro ao abrir o arquivo: %s/n", nomeArquivo);
       return 0;

    }

    char linha[MAX_LINHA];
    int count = 0;
    
    //ignora a primeira linha (cabeçalho)
    fgets(linha, MAX_LINHA, arquivo);

    //lêr cada linha do arquivo 
    while (fgets(linha, MAX_LINHA, arquivo))
      Processo p;
      char *token;

   //lêr o id (primeiro campo)
   token = strtok(linha, ",");
   if (token) p.id = atoi(token);

   //lêr o nome (segundo campo)
 token = strtok (NULL,",");
  if (token)strncpy(p.nome, token, sizeof(p.nome)- 1);

   //lêr o valor (terceiro campo)
   token = strtok (NULL, ",");
   if (token) p.valor = atof(token);
   
   //adiciona ao array
   processos[count++] = p;
} 
fclose(arquivo);
return count ;  //retorna o nùmero de processos lidos 

int main (){
   Processo processos[MAX_PROCESSOS];
   int total = lerCSV("dados.CSV" ,processos , MAX_PROCESSOS);
   
   //exibe os processos lidos
   for (int i = 0; i < total; i++ ){
    printf("ID: %d, Nome: %s, Valor: %.2f/n", processos[i].id, processos[i].nome, processos[i].valor);
   }
  return 0;
}