#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "files.h"



int main() {
    
    char nome[20], sigla[10];
    printf("Bem-Vindo ao jogo de EMECA!!!\n");

    printf("Insira o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Insira a sua sigla: ");
    fgets(sigla, sizeof(sigla), stdin);
    sigla[strcspn(sigla, "\n")] = 0;

    
    printf("\nBem-Vindo, %s (%s)!\n", nome, sigla);
    printf("1- Jogo Curto\n");
    printf("2- Jogo Normal\n");
    printf("0- SAIR\n\n");
    printf("INSIRA OPÇÃO: ");
    scanf("%d", &op);
    
    
    printf("ORDENAR!! Colocar por ordem as 3 opções apresentadas. Todas as perguntas têm a mesma cotação.\n");
    ordemFile();
}