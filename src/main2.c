#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"

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

typedef struct node
{
    int n;
    struct node *next;
} Node;

void menu();
void add();

// void game();
// void displayRanking();

int main()
{
    while (1)
    {
        menu();

        int choice;
        // printf(reset "Escolha a opção que deseja realizar: " reset);

        if (scanf("%d", &choice) != 1)
        {
            // printf(RED_BG "Entrada inválida. Por favor, insira um número.\n" reset);
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            // game();
            break;
        case 2:
            // displayRanking();
            break;
        case 3:
            // printf(RED_BG "Você encerrou o programa.\n" reset);
            return 0;
        default:
            // printf(RED_BG "Opção inválida, por favor insira um número válido!\n" reset);
        }
    }

    return 0;
}

void menu() {
    // printf(BOLD_YEL "\n----- MENU PRINCIPAL -----\n" reset);
    // printf(BLU "1. Jogar TiMath\n" reset);
    // printf(GRN "2. Visualizar Ranking\n" reset);
    // printf(CYN "3. Sair\n" reset);
}



