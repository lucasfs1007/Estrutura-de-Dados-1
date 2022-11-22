#include <stdio.h>

struct filiacao {
  char nome[80];
  char nomeMae[80];
  char nomePai[80];
};

struct filiacao separaLinhaCSV(char linha[240]) {
  struct filiacao tipo;
  int i = 0, j = 0;

  while (linha[i] != ',') {
    tipo.nome[j] = linha[i];
    i++;
    j++;
  }

  tipo.nome[j] = '\0';

  i++;
  j = 0;

  while (linha[i] != ',') {
    tipo.nomeMae[j] = linha[i];
    i++;
    j++;
  } 

  tipo.nomeMae[j] = '\0';

  i++;
  j = 0;

  while (linha[i] != '\0') {
    tipo.nomePai[j] = linha[i];
    i++;
    j++;
  }

  tipo.nomePai[j] = '\0';
  
  return tipo;
}