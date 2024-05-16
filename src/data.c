#include "config.h"

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
    char last_char;
    
    
    while(aux != NULL){
        if(last_char == '='){
            printf(BOLD_YEL " %s " reset, aux->c);
        }

        else{
            printf(" %s ", aux->c);
        }

        last_char = aux->c[0];
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

void add_in_equation(Equation **head, Equation **tail, char *c){
    Equation *new_equation = (Equation*)malloc(sizeof(Equation));

    if(new_equation == NULL) return;

    strcpy(new_equation->c, c);
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

void bubble_sort(Player **head){
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

void addFile(const char *fileName, const char *playerName, float playerTime){
    FILE *file = fopen(fileName, "a");
    if (file != NULL){
        fprintf(file, "%s: %.3f\n", playerName, playerTime);
        fclose(file);
    }
    
    else{
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