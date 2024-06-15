#include "grupo1.h"

void grupo_1_admin(){
typedef struct{
    char pergunta[20];
    char r1[50];
    char r2[50];
    char r3[50];
    char r4[50];
    int rcerta;
}Perguntas1;

Perguntas1 perguntas[30];


    FILE *ficheiro;
    char linha[300];
    char str[30];
    int i=0;
    
    
    printf("Pergunta: "); gets(perguntas[i].pergunta);
    printf("Resposta 1: "); gets (perguntas[i].r1);
    printf("Resposta 2: "); gets (perguntas[i].r2);
    printf("Resposta 3: "); gets (perguntas[i].r3);
    printf("Resposta 4: "); gets (perguntas[i].r4);
    printf("Resposta certa: ");scanf("%d",&perguntas[i].rcerta); 
    
    ficheiro =fopen("perguntas_grupo_1.txt", "a+");
    
        
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        
    }
    fprintf(ficheiro, "%s;\n%s;\n%s;\n%s;\n%s;\n%d\n",perguntas[i].pergunta,perguntas[i].r1,perguntas[i].r2,perguntas[i].r3,perguntas[i].r4,perguntas[i].rcerta );
    
    while(fgets(linha, sizeof(linha), ficheiro)!=NULL){
        
        char* token = strtok(linha,";");
        int i=0;
        
        while (token != NULL) {
            //printf("%s\n", token);
            str[i] =token;
            token = strtok(NULL,";");
            i++;
        }
        if(i==10){
            str[0]=perguntas[i].pergunta;
            str[1]=perguntas[i].r1;
            str[2]=perguntas[i].r2;
            str[3]=perguntas[i].r3;
            str[4]=perguntas[i].r4;
            str[5]=perguntas[i].rcerta; 
            i++;
        }
    }
    fclose(ficheiro);
    
    for(int j=0; j<i; j++){
        
    printf("1º pergunta: %s\n", perguntas[i].pergunta);
    printf("1Resposta 1: %s\n", perguntas[i].r1);
    printf("Resposta 2: %s\n", perguntas[i].r2);
    printf("Resposta 3: %s\n", perguntas[i].r3);
    printf("Resposta 4: %s\n", perguntas[i].r4);
    printf("Resposta certa: %", perguntas[i].rcerta);
    }
    
    srand(time(NULL));
    int randomPergunta = rand()% i;
     
        printf("Pergunta: %s\n", perguntas[randomPergunta].pergunta);
        printf("R1: %s\n", perguntas[randomPergunta].r1);
        printf("R2: %s\n", perguntas[randomPergunta].r2);
        printf("R3: %s\n", perguntas[randomPergunta].r3);
        printf("R4: %s\n", perguntas[randomPergunta].r4);
    
    
}