#include "files.h"

void OrdemFile(){
    char pergunta[300];
    char r1[100], r2[100], r3[100], linha[100],*str[4];
    int rcerta;
    int i = 0;
    
    
    printf("Pergunta: "); gets(pergunta);
    printf("Resposta1: "); gets(r1);
    printf("Resposta2: "); gets(r2);
    printf("Resposta3: "); gets(r3);
    printf("Resposta certa: "); scanf("%d", &rcerta);
    
FILE *ficheirordem;
    ficheirordem= fopen("perguntasordem.txt","a+");
    

    fprintf(ficheirordem, "%s;%s;%s;%s;%d\n", pergunta, r1 ,r2 ,r3 ,rcerta);
    
    if (ficheirordem==NULL){
        printf("Impossível abrir o ficheiro!");
    }

    while(fgets(linha, sizeof(linha), ficheirordem)!=NULL){
        char* token = strtok(linha,";");
        while (token != NULL) {
            //printf("%s\n", token);
            str[i] = token;
            token = strtok(NULL,";");
            i++;      
    }
        
   if(i==4){
            str[0]=pergunta;
            str[1]= r1;
            str[2]= r2;
            str[3]= r3;
            str[4]= rcerta; 
            i++;
        }
    }
    fclose(ficheirordem);

    for(int j=0; j<i; j++){

    printf("1º pergunta: %s\n", str[j]= pergunta);
    printf("1Resposta 1: %s\n", str[j]= r1);
    printf("Resposta 2: %s\n", str[j]= r2);
    printf("Resposta 3: %s\n", str[j]= r3);
    printf("Resposta certa: %s", str[j]= rcerta);
    }


}

void entraradmin(){
    int admin;
    char nome[50], sigla[10],utilizador[50], password[4] ;
    char utilizador1[] = "sofia";
    char utilizador2[] = "ines";
    char password1[] = "2006";
    
    printf("(1)Jogador ou (2)admin?");
    scanf("%d",&admin);
    getchar();
    
    switch (admin){
        case 1:
        printf("Insira o seu nome: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        printf("Insira a sua sigla: ");
        fgets(sigla, sizeof(sigla), stdin);
        sigla[strcspn(sigla, "\n")] = 0;  
        break;
        
        case 2:
        printf("Utilizador:");
        scanf("%s",&utilizador);
        printf("Password:");
        scanf("%s",&password);
        if ((strcmp(utilizador, utilizador1) == 0 || strcmp(utilizador, utilizador2) == 0) && strcmp(password, password1) == 0) {
            printf("Acesso autorizado!\n");
            ordemFile();
        }else{
            printf("NÃO ESTÁ AUTORIZADO!!!");
           
        }break;
        
        default:
        printf("Opção inválida!\n");
        break;
    }
}




