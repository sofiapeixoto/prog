#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "files.h"
#include "grupo1.h"
#include "grupo2.h"


int main() {
    int numperguntas, pontos, potuacao=0, op;
    char nome[20], sigla[10];
    int i=0
    printf("Bem-Vindo ao jogo de EMECA!!!\n");
    
    void entraradmin();
    
    printf ("\nBem-Vindo, %s (%s)!\n", nome, sigla);
    printf ("1- Jogo Curto\n");
    printf ("2- Jogo Normal\n");
    printf ("0- SAIR\n\n");
    printf ("INSIRA OPÇÃO: ");
    scanf("%d", &op);
    
    switch (op) {
        case 1:
            numperguntas = 2;
            break;
        case 2:
            numperguntas = 4;
            break;
        case 0:
            printf("A sair do jogo...\n");
            return 0;
            
        default:
            printf("Opção inválida!!\n");
            return 0;
    }
    
    printf("SELECIONA A CORRETA!! Selecionar a opção correta dentro de 4 hipóteses. Não retira pontos!!");
    
    
    
    
}