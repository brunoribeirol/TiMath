#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// #include "screen.h"
// #include "keyboard.h"
// #include "timer.h"

#define RED_BG "\e[41m"
#define BOLD_YEL "\e[1;33m"
#define BLU "\e[0;34m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define BLK "\e[0;30m"
#define BMAG "\e[1;35m"

#define reset "\e[0m"

#define GAME_SIZE 10
#define RANGE_MIN 11
#define RANGE_MAX 500

#define NAME_SIZE 20
#define MAX_PLAYERS 1000

typedef struct Player
{
    char name[NAME_SIZE];
    int time;
    int n;
    struct Player *next;
} Player;

typedef struct Node
{
    char operation;
    int number;
    struct node *next;
} Node;


void tiMath();
void menu();
void gameMenu();

void ascendingGame();
void randomGame();
void displayRanking();

void random_numbers_list(Node **head, Node **tail);
void add_node(Node **head, Node **tail, int number, char operation);
void print_numbers(Node *head);
void free_numbers(Node **head, Node **tail);
//void sort_numbers(Node *head, );

void initRandom();
int getRandomNumber(int min, int max);
char getOperation();

int main()
{
    tiMath();

    initRandom();

    Node *head = NULL;
    Node *tail = NULL;
    random_numbers_list(&head, &tail);
    print_numbers(head);
    free_numbers(&head, &tail);
   

    while (1)
    {
        menu();

        int choice;
        printf(reset "Escolha a opção que deseja realizar: " reset);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED_BG "Entrada inválida. Por favor, insira um número válido." reset);
            while (getchar() != '\n')
                ;
            continue;
        }

        int gameChoice;

        switch (choice)
        {
        case 1:

            gameMenu();

            printf(reset "Escolha a opção que deseja realizar: " reset);

            if (scanf("%d", &gameChoice) != 1)
            {
                printf(RED_BG "Entrada inválida. Por favor, insira um número válido." reset);
                while (getchar() != '\n')
                    ;
                continue;
            }

            switch (gameChoice)
            {
            case 1:
                ascendingGame();
                break;
            case 2:
                randomGame();
                break;
            case 3:
                printf(RED_BG "Você encerrou o programa.\n" reset);
                return 0;
            default:
                printf(RED_BG "Opção inválida, por favor insira um número válido!" reset);
            }
            break;
        case 2:
            displayRanking();
            break;
        case 3:
            printf(RED_BG "Você encerrou o programa.\n" reset);
            return 0;
        default:
            printf(RED_BG "Opção inválida, por favor insira um número válido!" reset);
        }
    }

    return 0;
}

// FALTA AJEITAR
void tiMath()
{
    printf(BMAG

    "######   #######  ##   ##           ##   ##   ####    ##   ##  #####     #####\n"
    "##  ##   ##   #  ### ###           ##   ##    ##     ###  ##   ## ##   ##   ##\n"
    "##  ##   ## #    #######            ## ##     ##     #### ##   ##  ##  ##   ##\n"
    "#####    ####    #######            ## ##     ##     ## ####   ##  ##  ##   ##\n"
    "##  ##   ## #    ## # ##             ###      ##     ##  ###   ##  ##  ##   ##\n"
    "##  ##   ##   #  ##   ##             ###      ##     ##   ##   ## ##   ##   ##\n"
    "######   #######  ##   ##              #      ####    ##   ##  #####     #####\n");

    printf(BMAG

    "                         ##      #####\n"
    "                        ####    ##   ##\n"
    "                       ##  ##   ##   ##\n"
    "                       ##  ##   ##   ##\n"
    "                       ######   ##   ##\n"
    "                       ##  ##   ##   ##\n"
    "                       ##  ##    #####\n"

    );

    printf(BMAG
    "          ######   ####    ##   ##    ##     ######   ##   ##\n"
    "          # ## #    ##     ### ###   ####    # ## #   ##   ##\n"
    "           ##       ##     #######  ##  ##     ##     ##   ##\n"
    "           ##       ##     #######  ##  ##     ##     #######\n"
    "           ##       ##     ## # ##  ######     ##     ##   ##\n"
    "           ##       ##     ##   ##  ##  ##     ##     ##   ##\n"
    "          ####     ####    ##   ##  ##  ##    ####    ##   ##\n" reset);

    sleep(0.5);
}

void menu()
{
    printf(BOLD_YEL "\n----- MENU PRINCIPAL -----\n" reset);
    printf(BLU "1. Jogar TiMath\n" reset);
    printf(GRN "2. Visualizar Ranking\n" reset);
    printf(CYN "3. Sair\n" reset);
}

void gameMenu()
{
    printf(BOLD_YEL "\n----- QUAL MODO VOCÊ DESEJA JOGAR? -----\n" reset);
    printf(GRN "1. Modo Crescente\n" reset);
    printf(GRN "2. Modo Aleatório\n" reset);
    printf(CYN "3. Sair\n" reset);
}

// FALTA
void ascendingGame()
{
    printf(BMAG

    "##   ##   #####   #####     #####              ####   ######   #######   #####     ####   #######  ##   ##  ######   #######\n"
    "### ###  ##   ##   ## ##   ##   ##            ##  ##   ##  ##   ##   #  ##   ##   ##  ##   ##   #  ###  ##  # ## #    ##   #\n"
    "#######  ##   ##   ##  ##  ##   ##           ##        ##  ##   ## #    #        ##        ## #    #### ##    ##      ## #\n"
    "#######  ##   ##   ##  ##  ##   ##           ##        #####    ####     #####   ##        ####    ## ####    ##      ####\n"
    "## # ##  ##   ##   ##  ##  ##   ##           ##        ## ##    ## #         ##  ##        ## #    ##  ###    ##      ## #\n"
    "##   ##  ##   ##   ## ##   ##   ##            ##  ##   ##  ##   ##   #  ##   ##   ##  ##   ##   #  ##   ##    ##      ##   #\n"
    "##   ##   #####   #####     #####              ####   #### ##  #######   #####     ####   #######  ##   ##   ####    #######\n" reset);

    sleep(0.5);

    char playerName[NAME_SIZE];
    printf("Digite seu nome: ");
    while ((getchar()) != '\n')
        ;
    fgets(playerName, NAME_SIZE, stdin);
    playerName[strcspn(playerName, "\n")] = 0;

    FILE *file = fopen("ranking.txt", "a"); // Abe o arquivo para adicionar a pontuação
    if (file != NULL)
    {
        // fprintf(file, "%s: %d\n", playerName, time);
        fclose(file);
    }
    else
    {
        printf("Não foi possível abrir o arquivo de pontuações.");
    }
}

// FALTA
void randomGame()
{
    printf(BMAG

    "##   ##   #####   #####     #####              ##     ####     #######    ##     ######    #####   ######    ####     #####\n"
    "### ###  ##   ##   ## ##   ##   ##            ####     ##       ##   #   ####    # ## #   ##   ##   ##  ##    ##     ##   ##\n"
    "#######  ##   ##   ##  ##  ##   ##           ##  ##    ##       ## #    ##  ##     ##     ##   ##   ##  ##    ##     ##   ##\n"
    "#######  ##   ##   ##  ##  ##   ##           ##  ##    ##       ####    ##  ##     ##     ##   ##   #####     ##     ##   ##\n"
    "## # ##  ##   ##   ##  ##  ##   ##           ######    ##   #   ## #    ######     ##     ##   ##   ## ##     ##     ##   ##\n"
    "##   ##  ##   ##   ## ##   ##   ##           ##  ##    ##  ##   ##   #  ##  ##     ##     ##   ##   ##  ##    ##     ##   ##\n"
    "##   ##   #####   #####     #####            ##  ##   #######  #######  ##  ##    ####     #####   #### ##   ####     #####\n" reset);

    sleep(0.5);

    char playerName[NAME_SIZE];
    printf("Digite seu nome: ");
    while ((getchar()) != '\n')
        ;
    fgets(playerName, NAME_SIZE, stdin);
    playerName[strcspn(playerName, "\n")] = 0;






    

    FILE *file = fopen("ranking.txt", "a"); // Abe o arquivo para adicionar a pontuação
    if (file != NULL)
    {
        // fprintf(file, "%s: %d\n", playerName, time);
        fclose(file);
    }
    else
    {
        printf("Não foi possível abrir o arquivo de pontuações.");
    }
}

// FALTA
void displayRanking()
{
    FILE *file = fopen("ranking.txt", "r");
    if (file == NULL)
    {
        printf(RED_BG "Não foi possível abrir o arquivo de pontuações." reset);
        return;
    }

    Player *head = NULL;

    while (1)
    {
        Player *newNode = (Player *)malloc(sizeof(Player));
        if (fscanf(file, "%s %d", newNode->name, &newNode->time) != 2)
        {
            free(newNode);
            break;
        }

        newNode->next = head;
        head = newNode;
    }

    // Número de linhas do arquivo
    int lines = 0;

    while (fgets, sizeof(MAX_PLAYERS), file)
    {
        lines++;
    }

    fclose(file);

    // Ordenar a lista por score
    Player *orderedList = NULL;

    printf(BMAG

    "  ######     ##     ##   ##  ###  ##   ####    ##   ##    ####\n"
    "  ##  ##   ####    ###  ##   ##  ##    ##     ###  ##   ##  ##\n"
    "  ##  ##  ##  ##   #### ##   ## ##     ##     #### ##  ##\n"
    "  #####   ##  ##   ## ####   ####      ##     ## ####  ##\n"
    "  ## ##   ######   ##  ###   ## ##     ##     ##  ###  ##  ###\n"
    "  ##  ##  ##  ##   ##   ##   ##  ##    ##     ##   ##   ##  ##\n"
    " #### ##  ##  ##   ##   ##  ###  ##   ####    ##   ##    #####\n" reset);
}





void random_numbers_list(Node **head, Node **tail){
    int number;
    char operation;

    for(int i = 0; i < GAME_SIZE; i++) {
        number = getRandomNumber(RANGE_MIN, RANGE_MAX);
        operation = getOperation();

        add_node(head, tail, number, operation);
    }
}

void add_node(Node **head, Node **tail, int number, char operation){
    Node *new = (Node*)malloc(sizeof(Node));

    if(new == NULL) return;

    new->operation = operation;
    new->number = number;
    new->next = NULL;

    if(*head == NULL){
        *head = new;
        *tail = new;
    }
    else{
        (*tail)->next = new;
        *tail = new;
    }
} 

void print_numbers(Node *head){
    Node *aux = head;
    while(aux != NULL){
        printf("%d %c\n", aux->number, aux->operation);
        aux = aux->next;
    }
}

void free_numbers(Node **head, Node **tail){
    Node *aux;
	if((*head) != NULL){
		aux = *head;
		*head = (*head)->next;
		free(aux);
	}
	if((*head) == NULL){
		*tail == NULL;
	}
}

void initRandom() {
    srand(time(NULL));
}

int getRandomNumber(int min, int max){
    return rand() % (max - min + 1) + min;
}

char getOperation(){
    int operation = getRandomNumber(1, 4);

    switch (operation){
        case 1 : return '+';
        case 2 : return '-';
        case 3 : return '*';
        case 4 : return '/';
    }

    return '+';
}