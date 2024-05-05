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

#define NAME_SIZE 20
#define MAX_PLAYERS 1000

typedef struct Player
{
    char name[NAME_SIZE];
    int time;
    int n;
    struct Player *next;
} Player;

void tiMath();

void menu();
void gameMenu();
void add();

void displayRanking();

ascendingGame();
randomGame();

int main()
{
    tiMath();
    while (1)
    {
        menu();

        int choice;
        printf(reset "Escolha a opção que deseja realizar: " reset);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED_BG "Entrada inválida. Por favor, insira um número.\n" reset);
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:

            int gameChoice;
            printf(reset "Escolha a opção que deseja realizar: " reset);

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
                printf(RED_BG "Opção inválida, por favor insira um número válido!\n" reset);
            }
            break;
        case 2:
            displayRanking();
            break;
        case 3:
            printf(RED_BG "Você encerrou o programa.\n" reset);
            return 0;
        default:
            printf(RED_BG "Opção inválida, por favor insira um número válido!\n" reset);
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

           "                                      ##      #####\n"
           "                                     ####    ##   ##\n"
           "                                    ##  ##   ##   ##\n"
           "                                    ##  ##   ##   ##\n"
           "                                    ######   ##   ##\n"
           "                                    ##  ##   ##   ##\n"
           "                                    ##  ##    #####\n"

    );

    printf(BMAG
           "                      ######   ####    ##   ##    ##     ######   ##   ##\n"
           "                      # ## #    ##     ### ###   ####    # ## #   ##   ##\n"
           "                       ##       ##     #######  ##  ##     ##     ##   ##\n"
           "                       ##       ##     #######  ##  ##     ##     #######\n"
           "                       ##       ##     ## # ##  ######     ##     ##   ##\n"
           "                       ##       ##     ##   ##  ##  ##     ##     ##   ##\n"
           "                      ####     ####    ##   ##  ##  ##    ####    ##   ##\n");
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

void displayRanking()
{
    FILE *file = fopen("ranking.txt", "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo de pontuações.\n");
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


    //Número de linhas do arquivo
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
           " #### ##  ##  ##   ##   ##  ###  ##   ####    ##   ##    #####\n");
}