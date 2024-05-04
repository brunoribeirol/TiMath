#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

typedef struct Node{
    char *pergunta;
    int nivel;
    int resposta;
    struct Node *prox;
}Node;

void jogar();
int quantidadeJogadores();
Node *dificuldade();
Node *dificuldadeFacil();
Node *dificuldadeMedio();
Node *dificuldadeDificil();
void inserir(char *pergunta, int resposta,  Node **head);

int main() {
    int opcao;
    
    do{
        printf("---------Timath--------\n");
        printf("1 - Iniciar Jogo\n");
        printf("2 - LeaderBoards\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção-> ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Iniciar Jogo\n");
                jogar();
                break;
            case 2:
                printf("LeaderBoards\n");
                break;

            case 3:
                printf("Sair\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    }while(opcao != 3);
}

void jogar(){
    Node *listaPerguntas = NULL;

    quantidadeJogadores();
    dificuldade();

}

int quantidadeJogadores(){
    int numeroJogadores;
    printf("quantos jogadores vão jogar?");
    scanf("%d", numeroJogadores);
    return numeroJogadores;
}

Node *dificuldade(){
    Node *perguntas = NULL;
    int dificuldade;
    Node *perguntasFacil = NULL;
    Node *perguntasMedio = NULL;
    Node *perguntasDificil = NULL;
do{
    printf("selecione a dificuldade\n");
    printf("1 - Fácil (soma e subtração)\n");
    printf("2 - Médio (soma, subtração, multiplicação e divisão)\n");
    printf("3 - Difícil(soma, subtração, multiplicação, divisão, potenciação e radiação)\n\n");
    printf("-> ");
    scanf("%d", dificuldade);
    
    switch(dificuldade){
        case 1:
            printf("Dificuldade selecionada: Fácil\n");
            inserir("Qual é a soma de 2 + 2?",10 , perguntasFacil);
            inserir("Qual é a subtração de 5 - 2?",10 , perguntasFacil);
            inserir("Qual é a soma de 3 + 3?",10 , perguntasFacil);
            inserir("Qual é a subtração de 10 - 5?",10 , perguntasFacil);
            inserir("Qual é a soma de 4 + 4?",10 , perguntasFacil);
            perguntas = perguntasFacil;
            break;

        case 2:
            printf("Dificuldade selecionada: Médio\n");
            inserir("Qual é a soma de 2 + 2?",10 , perguntasMedio);
            inserir("Qual é a subtração de 5 - 2?",10 , perguntasMedio);
            inserir("Qual é a soma de 3 + 3?",10 , perguntasMedio);
            inserir("Qual é a subtração de 10 - 5?",10 , perguntasMedio);
            inserir("Qual é a soma de 4 + 4?",10 , perguntasMedio);
            perguntas = perguntasMedio;
            break;

        case 3:
            printf("Dificuldade selecionada: Difícil\n");
            inserir("Qual é a soma de 2 + 2?",10 , perguntasDificil);
            inserir("Qual é a subtração de 5 - 2?",10 , perguntasDificil);
            inserir("Qual é a soma de 3 + 3?",10 , perguntasDificil);
            inserir("Qual é a subtração de 10 - 5?",10 , perguntasDificil);
            inserir("Qual é a soma de 4 + 4?",10 , perguntasDificil);
            perguntas = perguntasDificil;
            break;

        default:
            printf("Opção inválida\n");
    }
}while(dificuldade < 1 || dificuldade > 3);
    return perguntas;
}

void inserir(char *pergunta, int resposta,  Node **head){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(*head == NULL){
        novo->pergunta = pergunta;
        novo->resposta = resposta;
        novo->prox = NULL;
        *head = novo;
    }
    else{
        novo->pergunta = pergunta;
        novo->resposta = resposta;
        novo->prox = *head;
        *head = novo;
    }
}
