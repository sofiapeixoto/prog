#include "jogo.h" // o ficheiro jogo.c precisa de ter incluido o jogo.h 

void mostrarPerguntas(Perguntas pergunta){
    printf("%s\n", pergunta.pergunta);
    printf("%s\n", pergunta.r1);
    printf("%s\n", pergunta.r2);
    printf("%s\n", pergunta.r3);
    printf("%s\n", pergunta.r4);
}

void mostrarPerguntasOrdem (PerguntasOrdem perguntas){
    printf("%s\n", perguntas.pergunta);
    printf("%s\n", perguntas.r1);
    printf("%s\n", perguntas.r2);
    printf("%s\n", perguntas.r3);
}

/*FUNÇÃO PARA LER A RESPOSTA DO GRUPO1. Compara a resposta dada pelo jogador com a resposta certa. */
int lerResposta(Perguntas pergunta, int *numcertas){
    int resposta;

    printf("\nResposta:");
    scanf("%d", &resposta);
    getchar();
    
    if(resposta == pergunta.rcerta){
        printf("ACERTOU! +5 PONTOS!!\n\n");
        (*numcertas)++;
        return 5;
    }else{
        printf("ERROU!!!\n\n");
        return 0;
    }
}

/*FUNÇÃO PARA LER A RESPOSTA DO GRUPO2. Compara a resposta dada pelo jogador com a resposta certa. */

int lerResposta1(Perguntas pergunta,int *numcertas){
    int resposta;
    
    
    printf("\nResposta:");
    scanf("%d", &resposta);
    if(resposta == pergunta.rcerta){
        printf("ACERTOU! +5 PONTOS!!!\n\n");
        (*numcertas)++;
        return 5;
    }else{
        printf("ERROU!!! -2 PONTOS!!! \n\n");
        return -2;
    }
}

/*FUNÇÃO PARA LER A RESPOSTA DO GRUPO3. Compara a resposta dada pelo jogador com a resposta certa. */

int lerResposta2(PerguntasOrdem perguntas, int *numcertas){
    int resposta;

    printf("\nResposta:");
    scanf("%d", &resposta);
    if(resposta == perguntas.rcerta){
        printf("ACERTOU! +5 PONTOS!!! \n\n");
        (*numcertas)++;
        return 5;
    }else{
        printf("ERROU!!!\n\n");
        return 0;
    }
}
/*Guarda o id da pergunta respondida para não se repetir*/

int jaRespondida(int id, int perguntasRespondidas[]){
    for(size_t i = 0; i < 50; i++) {
        if(perguntasRespondidas[i] == id)
            return 1;
    }
    return 0;
}

/*COLOCA AS PERGUNTAS ALEATORIAS. Escolhe um id aleatorio de uma pergunta e troca.  */
int grupo1(int *numrespondidas, int numperguntas, int *numcertas, Perguntas perguntas[], int perguntasRespondidas[], int totalperguntas){
    srand(time(NULL));
    printf("\nSELECIONA A CORRETA!! Selecionar a opção correta dentro de 4 hipóteses. Não retira pontos!!\n\n");
    int id = 0, pontos = 0;

    do{
        do {
            id = rand() % (totalperguntas + 1);
        }while(jaRespondida(id, perguntasRespondidas));
        perguntasRespondidas[*numrespondidas] = id;

        Perguntas pergunta = perguntas[id];
        mostrarPerguntas(pergunta);
        pontos += lerResposta(pergunta, numcertas);

        (*numrespondidas)++;
    }while((*numrespondidas % numperguntas) != 0);

    return pontos;
}

/*COLOCA AS PERGUNTAS ALEATORIAS. Escolhe um id aleatorio de uma pergunta e troca.  */

int grupo2(int *numrespondidas, int numperguntas,int *numcertas, Perguntas perguntas[], int perguntasRespondidas[], int totalperguntas){
    srand(time(NULL));
    printf("\nFUGA DE PONTOS!! Selecionar a opção correta dentro de 4 hipóteses. Se errar, a pontuação é retirada!\n\n");
    int id = 0, pontos = 0;

    do{
        do {
            id = rand() % (totalperguntas + 1);
        }while(jaRespondida(id, perguntasRespondidas));
        perguntasRespondidas[*numrespondidas] = id;

        Perguntas pergunta = perguntas[id];
        mostrarPerguntas(pergunta);//chamada a função de mostrar perguntas (grupo2 que é a mesma para o grupo1)
        pontos += lerResposta1(pergunta, numcertas);

        (*numrespondidas)++;
    }while(*numrespondidas % numperguntas != 0);

    return pontos;
}

/*COLOCA AS PERGUNTAS ALEATORIAS. Escolhe um id aleatorio de uma pergunta e troca.  */

int grupo3(int *numrespondidas, int numperguntas,int *numcertas, PerguntasOrdem perguntas[], int perguntasRespondidas[], int totalperguntas){
    srand(time(NULL));
    printf("\nORDENAR!! Colocar por ordem as 3 opções apresentadas. Não são retirados pontos!\n\n");
    int id = 0, pontos = 0;

    do{
        do {
            id = rand() % (totalperguntas + 1);
        }while(jaRespondida(id, perguntasRespondidas));
        perguntasRespondidas[*numrespondidas] = id;
        printf("%d", id);
        PerguntasOrdem pergunta = perguntas[id];
        mostrarPerguntasOrdem(pergunta);// chamada a função de mostrar perguntas ordem
        pontos += lerResposta2(pergunta, numcertas);

        (*numrespondidas)++;
    }while(*numrespondidas % numperguntas != 0);

    return pontos;
}
/*FUNÇÃO JOGO. Retorna a pontuação.
 É chamada a função baralhar perguntas do grupo1 e 2 em conjunto e a funçãop baralhar do grupo3. 
 É somada a pontuação de todos os grupos. */

int jogo(int numperguntas, int *numcertas){
    int pontuacao = 0;
    Perguntas perguntas[50];// perguntas vai ter a mesma estrutura de PERGUNTAS
    int perguntasRespondidas[50];
    int numrespondidas = 0;
    
    int totalperguntasFicheiro = lerPerguntas(perguntas);
    baralharPerguntas(perguntas, totalperguntasFicheiro);

    pontuacao += grupo1(&numrespondidas, numperguntas, numcertas, perguntas, perguntasRespondidas, totalperguntasFicheiro);
    pontuacao += grupo2(&numrespondidas, numperguntas, numcertas, perguntas, perguntasRespondidas, totalperguntasFicheiro);
    
    PerguntasOrdem perguntasOrdem[30];// perguntasOrdem vai ter a mesma estrutura de PerguntasOrdem
    int perguntasOrdemRespondidas[50];
    
    int totalperguntasOrdem = lerPerguntasOrdem(perguntasOrdem);
    baralharPerguntasOrdem(perguntasOrdem, totalperguntasOrdem);
    
    pontuacao += grupo3(&numrespondidas, numperguntas, numcertas, perguntasOrdem, perguntasOrdemRespondidas, totalperguntasOrdem);


    return pontuacao;
}
