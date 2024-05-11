#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <sys/time.h>

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
//Ajietar range
#define RANGE_MIN 1
#define RANGE_MAX 10

#define NAME_SIZE 50
#define MAX_PLAYERS 1000 //Ver depois

typedef struct Player
{
    char name[NAME_SIZE];
    float time;
    struct Player *next; //precisa???
} Player;

typedef struct Node
{
    char operation;
    int number;
    struct Node *next;
} Node;

typedef struct Equation{
    char operation;
    int result;
    int number;
    struct Equation *next;
} Equation;


void tiMath();
void menu();
void gameMenu();

void game();
void displayAscendingGame();
void displayRanking();

void random_numbers_list(Node **head, Node **tail, int first_number);
void add_node(Node **head, Node **tail, int number, char operation);
void free_numbers(Node **head, Node **tail);

void add_in_equation(Equation **head, Equation **tail, int number, char operation, int result);
void bubble_sort(Node **head, Node **tail);
void swap(Node *a, Node *b);
void print_equation(Equation *head, int turn);
void free_equations(Equation **head, Equation **tail);



void initRandom();
int getRandomNumber(int min, int max);
char getOperation();

void addFile(const char *fileName, const char *playerName, float elapsed);

int main()
{
    system("clear");
    tiMath();

    initRandom();

    //Node *head = NULL;
    //Node *tail = NULL;
    
    //int firstNumber =  getRandomNumber(1, 10);
    //printf("%d\n", firstNumber);

    //random_numbers_list(&head, &tail);
    //print_equation(head);
    //free_numbers(&head, &tail);
   

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

        switch (choice) {
            case 1:
                gameMenu();
                printf(reset "Escolha a opção que deseja realizar: " reset);

                if (scanf("%d", &gameChoice) != 1) {
                    printf(RED_BG "Entrada inválida. Por favor, insira um número válido." reset);
                    while (getchar() != '\n');
                    continue;
                }

                switch (gameChoice) {
                    case 1:
                        game();
                        break;
                    case 2: 
                    //Ajeitar para o caso de Modo aleattório?
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
void tiMath(){
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

void menu(){
    printf(BOLD_YEL "\n----- MENU PRINCIPAL -----\n" reset);
    printf(BLU "1. Jogar TiMath\n" reset);
    printf(GRN "2. Visualizar Ranking\n" reset);
    printf(CYN "3. Sair\n" reset);
}

void gameMenu(){
    printf(BOLD_YEL "\n----- QUAL MODO VOCÊ DESEJA JOGAR? -----\n" reset);
    printf(GRN "1. Modo Crescente\n" reset);
    printf(GRN "2. Modo Aleatório\n" reset);
    printf(CYN "3. Sair\n" reset);
}

// FALTA
void game(){
    displayAscendingGame();

    Player *newPlayer = (Player*)malloc(sizeof(Player));

    printf("Digite seu nome: ");
    while ((getchar()) != '\n');
    fgets(newPlayer->name, NAME_SIZE, stdin);
    newPlayer->name[strcspn(newPlayer->name, "\n")] = 0;

    Node *head = NULL;
    Node *tail = NULL;

    Equation *head_eq = NULL;
    Equation *tail_eq = NULL;

    int firstNumber =  getRandomNumber(RANGE_MIN, RANGE_MAX);
    int result = firstNumber;
    int aux_number;
    int user_answer;

    random_numbers_list(&head, &tail, firstNumber);
    //bubble_sort(&head, &tail);

    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    
    for(Node *aux = head; aux != NULL; aux = aux->next) {
        int turn=0;
        system("clear");
        add_in_equation(&head_eq, &tail_eq, aux->number, aux->operation, result);

        char operation = aux->operation;

        switch (operation) {
            case '+':
                aux_number = result + aux->number;
                break;
            case '-':
                aux_number = result - aux->number;
                break; //Tratar o erro para o número não dar negativo
            case '*':
                aux_number = result * aux->number;
                break;
            case '/':
                aux_number = result / aux->number;
                break; //Tratar o erro para o número ser divisível

            //Só está funcionando com aux_number = result + aux->number
            
            // if (result >= aux->number)
            // {
            //     aux_number = result / aux->number;
            // }

            /*
            Número negativo nao
                Negativo nao pode dividir
            Divisao quebrada nao
            Não pode ter multiplicação por 0
            Segundo número não pode ser maior do que o 1
            */

        }
       // printf("%d = %d %c %d\n", aux_number, result, operation, aux->number);
        print_equation(head_eq, turn);

        scanf("%d", &user_answer);
        while (user_answer != aux_number) {
            system("clear");

            print_equation(head_eq, turn);
            scanf("%d", &user_answer);
        }
        turn++;
        result = aux_number;
    }


    gettimeofday(&end, NULL);  // End timing

    newPlayer->time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("You completed the questions in %.3f seconds.\n", newPlayer->time);

    addFile("ranking.txt", newPlayer->name, newPlayer->time);
   
    free_numbers(&head, &tail);
    free_equations(&head_eq, &tail_eq);
    // free(newPlayer);
}

void displayAscendingGame(){
    printf(BMAG

    "##   ##   #####   #####     #####              ####   ######   #######   #####     ####   #######  ##   ##  ######   #######\n"
    "### ###  ##   ##   ## ##   ##   ##            ##  ##   ##  ##   ##   #  ##   ##   ##  ##   ##   #  ###  ##  # ## #    ##   #\n"
    "#######  ##   ##   ##  ##  ##   ##           ##        ##  ##   ## #    #        ##        ## #    #### ##    ##      ## #\n"
    "#######  ##   ##   ##  ##  ##   ##           ##        #####    ####     #####   ##        ####    ## ####    ##      ####\n"
    "## # ##  ##   ##   ##  ##  ##   ##           ##        ## ##    ## #         ##  ##        ## #    ##  ###    ##      ## #\n"
    "##   ##  ##   ##   ## ##   ##   ##            ##  ##   ##  ##   ##   #  ##   ##   ##  ##   ##   #  ##   ##    ##      ##   #\n"
    "##   ##   #####   #####     #####              ####   #### ##  #######   #####     ####   #######  ##   ##   ####    #######\n" reset);

    sleep(0.5);
}

// FALTA
void displayRanking(){
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
        if (fscanf(file, "%s %f", newNode->name, &newNode->time) != 2)
        {
            free(newNode);
            break;
        }

        newNode->next = head;
        head = newNode;
    }

    // // Número de linhas do arquivo
    // int lines = 0;

    // while (fgets, sizeof(MAX_PLAYERS), file)
    // {
    //     lines++;
    // }

    // fclose(file);

    // // Ordenar a lista por score
    // Player *orderedList = NULL;

    printf(BMAG

    "  ######     ##     ##   ##  ###  ##   ####    ##   ##    ####\n"
    "  ##  ##   ####    ###  ##   ##  ##    ##     ###  ##   ##  ##\n"
    "  ##  ##  ##  ##   #### ##   ## ##     ##     #### ##  ##\n"
    "  #####   ##  ##   ## ####   ####      ##     ## ####  ##\n"
    "  ## ##   ######   ##  ###   ## ##     ##     ##  ###  ##  ###\n"
    "  ##  ##  ##  ##   ##   ##   ##  ##    ##     ##   ##   ##  ##\n"
    " #### ##  ##  ##   ##   ##  ###  ##   ####    ##   ##    #####\n" reset);
}

void random_numbers_list(Node **head, Node **tail, int first_number){
    int number;
    int result = first_number;
    char operation;

    for(int i = 0; i < GAME_SIZE; i++) {
        operation = getOperation();
        number = getRandomNumber(RANGE_MIN, RANGE_MAX);

        if(operation == '/'){
            while(result % number != 0){
                number = getRandomNumber(RANGE_MIN, RANGE_MAX);
            }
        }

        if(operation == '-'){
            while (result - number < 1){
                number = getRandomNumber(RANGE_MIN, RANGE_MAX);
            }     
        }

        switch (operation) {
            case '+': result = result + number; break;
            case '-': result = result - number; break;
            case '*': result = result * number; break;
            case '/': result = result / number; break;
        }
        
        add_node(head, tail, number, operation);
    }
}



void add_node(Node **head, Node **tail, int number, char operation){
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->operation = operation;
    newNode->number = number;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
} 

void print_equation(Equation *head, int turn){
    Equation *aux = head;
    while(aux != NULL){
        printf("%d %c %d = ", aux->result, aux->operation, aux->number);
        aux = aux->next;
    }
}

void free_numbers(Node **head, Node **tail){
    Node* aux;
 
    while (*head != NULL) {
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }

    *tail = NULL;
}

void free_equations(Equation **head, Equation **tail){
    Equation* aux;
 
    while (*head != NULL) {
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }

    *tail = NULL;
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

void add_in_equation(Equation **head, Equation **tail, int number, char operation, int result){
    Equation *new_equation = (Equation*)malloc(sizeof(Equation));

    if(new_equation == NULL) return;

    new_equation->operation = operation;
    new_equation->number = number;
    new_equation->result = result;
    new_equation->next = NULL;

    if(*head == NULL){
        *head = new_equation;
        *tail = new_equation;
    }
    else{
        (*tail)->next = new_equation;
        *tail = new_equation;
    }
}

void bubble_sort(Node **head, Node **tail){
    bool is_sorted = false;
    for(Node *aux = *head; aux != NULL && is_sorted == false; aux = aux->next){
        is_sorted = true;
        for(Node *temp = *head; temp->next != NULL; temp = temp->next){
            if(temp->number > temp->next->number){
                swap(temp, temp->next);
                is_sorted = false;
            }
        }
    }
}

void swap(Node *a, Node *b){
    int aux_number = a->number;
    int aux_char = a->operation;

    a->number = b->number;
    a->operation = b->operation;

    b->number = aux_number;
    b->operation = aux_char;
}

void addFile(const char *fileName, const char *playerName, float elapsed)
{
    FILE *file = fopen(fileName, "a"); // Abe o arquivo para adicionar a pontuação
    if (file != NULL)
    {
        fprintf(file, "%s: %f\n", playerName, elapsed);
        fclose(file);
    }
    else
    {
        printf("Não foi possível abrir o arquivo de pontuações.");
    }

}