#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <sys/time.h> 

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
//#include "data.h"
#include "animations.h"

#define RED_BG "\e[41m"
#define BOLD_YEL "\e[1;33m"
#define BLU "\e[0;34m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define BLK "\e[0;30m"
#define BMAG "\e[1;35m"
#define BLINK "\e[5m"
#define BG_GREEN "\e[42m"
#define MAGENTA "\e[0;35m"
#define GREEN "\e[0;32m"

#define reset "\e[0m"

#define GAME_SIZE 10

#define RANGE_MIN_SUM 1
#define RANGE_MAX_SUM 300

#define RANGE_MIN 1
#define RANGE_MAX 10

#define RANGE_MIN_DIV 1
#define RANGE_MAX_DIV 20

#define NAME_SIZE 50

typedef struct Player
{
    char name[NAME_SIZE];
    float time;
    struct Player *next;
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

void game();
void displayGame();
void displayRanking();

void random_numbers_list(Node **head, Node **tail, int first_number);
void add_node(Node **head, Node **tail, int number, char operation);
void free_numbers(Node **head, Node **tail);

void add_in_equation(Equation **head, Equation **tail, int number, char operation, int result);
void bubble_sort(Player **head);
void swap(Player *a, Player *b);
void print_equation(Equation *head);
void free_equations(Equation **head, Equation **tail);

void initRandom();
int getRandomNumber(int min, int max);
char getOperation();

void addFile(const char *fileName, const char *playerName, float playerTime);
Player* readFile(const char *fileName);
void printPlayers(Player *head);

int main()
{
    system("clear");
    tiMath();
    sleep(1);

    initRandom();

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

        switch (choice) {
            case 1:
                game();
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

void game(){
    

    Player *newPlayer = (Player*)malloc(sizeof(Player));

    printf("Digite seu nome: ");
    while ((getchar()) != '\n');
    fgets(newPlayer->name, NAME_SIZE, stdin);
    newPlayer->name[strcspn(newPlayer->name, "\n")] = 0;

    displayGame();

    Node *head = NULL;
    Node *tail = NULL;

    Equation *head_eq = NULL;
    Equation *tail_eq = NULL;

    int firstNumber =  getRandomNumber(RANGE_MIN, RANGE_MAX);
    int result = firstNumber;
    int aux_number;
    int user_answer;

    random_numbers_list(&head, &tail, firstNumber);

    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    
    for(Node *aux = head; aux != NULL; aux = aux->next) {
        system("clear");
        add_in_equation(&head_eq, &tail_eq, aux->number, aux->operation, result);

        char operation = aux->operation;

        switch (operation) {
            case '+':
                aux_number = result + aux->number;
                break;
            case '-':
                aux_number = result - aux->number;
                break;
            case '*':
                aux_number = result * aux->number;
                break;
            case '/':
                aux_number = result / aux->number;
                break;

        }

        print_equation(head_eq);

        scanf("%d", &user_answer);
        while (user_answer != aux_number) {
            system("clear");

            print_equation(head_eq);
            scanf("%d", &user_answer);
        }
        result = aux_number;
    }

    gettimeofday(&end, NULL);

    newPlayer->time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Seu tempo foi de %.3f segundos\n", newPlayer->time);

    addFile("ranking.txt", newPlayer->name, newPlayer->time);
   
    free_numbers(&head, &tail);
    free_equations(&head_eq, &tail_eq);
}

void random_numbers_list(Node **head, Node **tail, int first_number){
    int number;
    int result = first_number;
    char operation;

    for(int i = 0; i < GAME_SIZE; i++) {
        operation = getOperation();

        while(i == 0 && (operation == '/' || operation == '*')){
            operation = getOperation();
        }

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

void print_equation(Equation *head){
    Equation *aux = head;
    int count = 0;
    
    while(aux != NULL){
        if(count == 0) printf("%d %c %d = ", aux->result, aux->operation, aux->number);
        else printf(BOLD_YEL "%d" reset " %c %d = ", aux->result, aux->operation, aux->number);
        
        aux = aux->next;
        count++;
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

void bubble_sort(Player **head) {
    bool is_sorted = false;
    Player *aux, *temp;

    while (!is_sorted) {
        is_sorted = true;
        aux = *head;

        while (aux != NULL && aux->next != NULL) {
            temp = aux->next;
            if (aux->time > temp->time) {
                swap(aux, temp);
                is_sorted = false;
            }
            aux = aux->next;
        }
    }
}

void swap(Player *a, Player *b) {
    float tempTime = a->time;
    char tempName[NAME_SIZE];
    strcpy(tempName, a->name);

    a->time = b->time;
    strcpy(a->name, b->name);

    b->time = tempTime;
    strcpy(b->name, tempName);
}

void addFile(const char *fileName, const char *playerName, float playerTime)
{
    FILE *file = fopen(fileName, "a");
    if (file != NULL)
    {
        fprintf(file, "%s: %.3f\n", playerName, playerTime);
        fclose(file);
    }
    else
    {
        printf("Não foi possível abrir o arquivo de pontuações.");
    }
}

void displayRanking(){
    ranking();

    Player *players = readFile("ranking.txt");
    if (players == NULL) {
        printf("Não há jogadores no ranking.\n");
        return;
    }
    bubble_sort(&players);
    printPlayers(players);
}

Player* readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo de ranking: %s\n", fileName);
        return NULL;
    }

    Player *head = NULL;
    char line[100];
    char name[NAME_SIZE];
    float time;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%49[^:]: %f", name, &time) == 2) {
            Player *newPlayer = (Player *)malloc(sizeof(Player));
            if (newPlayer == NULL) {
                printf("Falha ao alocar memória para um novo jogador\n");
                continue;
            }
            strcpy(newPlayer->name, name);
            newPlayer->time = time;
            newPlayer->next = head;
            head = newPlayer;
        }
    }
    fclose(file);
    if (head == NULL) {
        printf("Nenhum jogador foi carregado do arquivo.\n");
    }
    return head;
}

void printPlayers(Player *head) {
    if (head == NULL) {
        printf("Lista de jogadores está vazia.\n");
        return;
    }
    Player *current = head;
    int place=1;
    while (current != NULL) {
        if (place==1) {
            printf(GREEN BLINK"%d. %s: %.3f segundos\n" reset , place, current->name, current->time);
        } else if (place==2) {
            printf(CYN"%d. %s: %.3f segundos\n" reset , place, current->name, current->time);
        } else if (place==3) {
            printf(MAGENTA"%d. %s: %.3f segundos\n" reset , place, current->name, current->time);
        }
        else {
            printf("%d. %s: %.3f segundos\n", place, current->name, current->time);
        }
        current = current->next;
        place++;
    }
}