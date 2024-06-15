#include "files.h"
//
    
    typedef struct {
        char pergunta[300];
        char r1[100];
        char r2[100];
        char r3[100];
        int rcerta;
    } PerguntasOrdem;
    
//* Função de Ler Perguntas do Grupo 3. 
// Criamos um ficheiro para ler as perguntas (r). Limitamos o número máximo de perguntas para 30. 
// Verificamos de linha a linha a pergunta e as respostas que estão separadas por ';' .
// O número total de perguntas vai ser adicionado até á última linha.  
    
int lerPerguntasOrdem(PerguntasOrdem perguntas[]) {
  
    FILE *LerperguntasOrdem;
            
    LerperguntasOrdem= fopen("perguntasordem.txt", "r");
    
        if (LerperguntasOrdem == NULL) {
            printf("Não foi possível abrir o ficheiro.\n");
        return 0;
        }
        
    int totalperguntas = 0;
    char linha[700];
    
    while (fgets(linha, sizeof(linha), LerperguntasOrdem) != NULL && totalperguntas < 30) {
        char *token = strtok(linha, ";");
        if (token != NULL) {
            strncpy(perguntas[totalperguntas].pergunta, token, sizeof(perguntas[totalperguntas].pergunta) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas[totalperguntas].r1, token, sizeof(perguntas[totalperguntas].r1) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas[totalperguntas].r2, token, sizeof(perguntas[totalperguntas].r2) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas[totalperguntas].r3, token, sizeof(perguntas[totalperguntas].r3) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                perguntas[totalperguntas].rcerta = atoi(token);

            totalperguntas++;
        }
    }

    fclose(LerperguntasOrdem);
    return totalperguntas;
}

//* Função de Baralhar Perguntas do Grupo 1.
// Baralha-se as perguntas para terem uma ordem aleatória sempre que se for jogar. 

void baralharPerguntasOrdem (PerguntasOrdem perguntas[], int totalperguntas) {
    srand(time(NULL));
    for (int i = totalperguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        PerguntasOrdem temp = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = temp;
    }
}

//* Função de Meter as Perguntas do Grupo 3.
// Criamos um ficheiro .txt que contém TODAS as perguntas do GRUPO3.   

 void meterPerguntaOrdem(){
    PerguntasOrdem pergunta;
    printf("Pergunta: \n"); 
    fgets(pergunta.pergunta, 300, stdin);
    printf("Resposta1: "); 
    fgets(pergunta.r1, 100, stdin);
    printf("Resposta2: "); 
    fgets(pergunta.r2, 100, stdin);
    printf("Resposta3: "); 
    fgets(pergunta.r3, 100, stdin);
    printf("Resposta certa: "); 
    scanf("%d", &pergunta.rcerta);
    
    FILE *ficheirordem;
    ficheirordem= fopen("perguntasordem.txt","a+");
    if (ficheirordem==NULL){
        printf("Impossível abrir o ficheiro!");
    }
   
    fprintf(ficheirordem, "%s;%s;%s;%s;%d\n", pergunta.pergunta, pergunta.r1 ,pergunta.r2, pergunta.r3 ,pergunta.rcerta);
    fclose(ficheirordem);
}
 
// Função de escolha entre Jogador e Administrador
 // Damos a opçao ao utilizador. Se quiser ser jogador pergunta o nome e a sigla para poder começar a jogar.
 // Se escolher Administrador tem que colocar as credenciais.
 // Se as credenciais estiverem erradas volta a pedir para escolher entre jogador ou administrador.
 
void entraradmin(){
    int admin, grupos;
    char nome[50], sigla[10],utilizador[50], password[10] ;
    char utilizador1[] = "sofia";
    char utilizador2[] = "ines";
    char password1[] = "2006";
    
    printf("(1)Jogador ou (2)Administrador ?\n");
    scanf("%d",&admin);
    getchar();
    
    switch (admin){
     case 1:
            printf("Insira o seu nome: ");
            fgets(nome, sizeof(nome), stdin);
           
            printf("Insira a sua sigla: ");
            fgets(sigla, sizeof(sigla), stdin);
            

            break;
        
        case 2:
            while (1) {
                printf("Utilizador: ");
                scanf("%s", utilizador);

                printf("Password: ");
                scanf("%s", password);

                if ((strcmp(utilizador, utilizador1) == 0 || strcmp(utilizador, utilizador2) == 0) && strcmp(password, password1) == 0) {
                    printf("Acesso autorizado!\n");
                    printf("Qual grupo deseja aceder?\n (1)Grupo1\n (2)Grupo2\n (3)Grupo3\n");
                    scanf("%d", &grupos);

                    switch (grupos) {
                        case 1:
                            meterPerguntas1();
                            break;

                        case 2:
                            grupo_2_admin();
                            break;

                        case 3:
                            meterPerguntaOrdem();
                            break;

                        default:
                            printf("Opção inválida!\n");
                            break;
                    }
                    return 0; 
                } else {
                    printf("NÃO ESTÁ AUTORIZADO!!!\n");
                }
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}




