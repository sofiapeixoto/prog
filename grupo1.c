#include "grupo1.h"

void grupo_1_admin(){
    char pergunta[100];
    char r1[50];
    char r2[50];
    char r3[50];
    char r4[50];
    int rcerta;
    char linha[200];
    int  i=0;
    char *str[10];
    
    
    FILE *ficheiro;
  
    
    
    printf("Pergunta: "); gets(pergunta);
    printf("Resposta 1: "); gets(r1);
    printf("Resposta 2: "); gets(r2);
    printf("Resposta 3: "); gets(r3);
    printf("Resposta 4: "); gets(r4);
    printf("Resposta certa: ");scanf("%d",&rcerta);
        
    ficheiro =fopen("perguntas_grupo_1.txt", "a+");
    
     fprintf(ficheiro, "%s;\n%s;\n%s;\n%s;\n%s;\n%d\n",pergunta,r1,r2,r3,r4,rcerta );
        
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        
    }
    
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
            str[0]=pergunta;
            str[1]=r1;
            str[2]=r2;
            str[3]=r3;
            str[4]=r4;
            str[5]=rcerta; 
            i++;
        }
    }
    fclose(ficheiro);
    
    for(int j=0; j<i; j++){
        
    printf("1º pergunta: %s\n", str[j]=pergunta);
    printf("1Resposta 1: %s\n", str[j]=r1);
    printf("Resposta 2: %s\n", str[j]=r2);
    printf("Resposta 3: %s\n", str[j]=r3);
    printf("Resposta 4: %s\n", str[j]=r4);
    printf("Resposta certa: %s", str[j]=rcerta);
    }
    
    srand(time(NULL));
}