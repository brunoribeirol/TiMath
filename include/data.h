#include "config.h"

typedef struct Player{
    char name[50];
    float time;
    struct Player *next;
} Player;

typedef struct Node{
    char operation;
    int number;
    struct Node *next;
} Node;

typedef struct Equation{
    char c[5];
    struct Equation *next;
} Equation;

void add_node(Node **head, Node **tail, int number, char operation);

void print_equation(Equation *head);

void free_numbers(Node **head, Node **tail);

void free_equations(Equation **head, Equation **tail);

void add_in_equation(Equation **head, Equation **tail, char *c);

void bubble_sort(Player **head);

void swap(Player *a, Player *b);

void addFile(const char *fileName, const char *playerName, float playerTime);

void displayRanking();

Player* readFile(const char *fileName);

void printPlayers(Player *head);

