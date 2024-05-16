#include "config.h"

void random_numbers_list(Node **head, Node **tail, int first_number){
    int number;
    int result = first_number;
    char operation;

     for(int i = 0; i < GAME_SIZE; i++) {
        operation = getOperation();

        if(i == 0){
            operation = '+';
        }

        while(isPrime(result) && operation == '/'){
            operation = getOperation();
        }

        number = getRandomNumber(RANGE_MIN_SUM, RANGE_MAX_SUM);

        if(operation == '/'){
            while(result % number != 0 || number == 1){ 
                number = getRandomNumber(RANGE_MIN_DIV, RANGE_MAX_DIV);
            }
        }

        if(operation == '-'){
            while (result - number < 1){
                number = getRandomNumber(RANGE_MIN_SUM, RANGE_MAX_SUM);
            }     
        }

        if (operation == '*' && number == 1)
        {
            number = getRandomNumber(RANGE_MIN_SUM, RANGE_MAX_SUM);
        }

        switch (operation) {
            case '+': result = result + number; break;
            case '-': result = result - number; break;
            case '*': result = result * number; break;
            case '/': result = result / number; break;
        }
        
        //printf("\n %c %d \n", operation, number);
        add_node(head, tail, number, operation);
    }
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

    int firstNumber =  getRandomNumber(1, 10);
    int result = firstNumber;
    int user_answer;

    random_numbers_list(&head, &tail, firstNumber);

    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    char str[5];
    snprintf(str, sizeof(str), "%d", firstNumber);
    add_in_equation(&head_eq, &tail_eq, str);

    Node *aux = head;
    for(int i = 1; i <= 3; i++){
       for(int x = 0; x < 2; x++){
            for(int j = 0; j < i; j++){
                system("clear");
    
                char operation = aux->operation;
                str[0] = operation;
                str[1] = '\0';
                add_in_equation(&head_eq, &tail_eq, str);
    
                snprintf(str, sizeof(str), "%d", aux->number);
                add_in_equation(&head_eq, &tail_eq, str);
    
                switch (operation){
                    case '+': result += aux->number; break;
                    case '-': result -= aux->number; break;
                    case '*': result *= aux->number; break;
                    case '/': result /= aux->number; break;
                }
    
                aux = aux->next;
            }
            
            add_in_equation(&head_eq, &tail_eq, "=");
            print_equation(head_eq);

            scanf("%d", &user_answer);
            while (user_answer != result) {
                system("clear");

                printf(RED "Resposta incorreta, tente novamente.\n" reset);
                print_equation(head_eq);
                scanf("%d", &user_answer);
            }

            snprintf(str, sizeof(str), "%d", result);
            add_in_equation(&head_eq, &tail_eq, str);
       }

    }

    gettimeofday(&end, NULL);

    newPlayer->time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Seu tempo foi de " RED "%.3f" reset " segundos\n", newPlayer->time);

    addFile("ranking.txt", newPlayer->name, newPlayer->time);
   
    free_numbers(&head, &tail);
    free_equations(&head_eq, &tail_eq);
}

int main(){
    system("clear");
    tiMath();
    sleep(0.5);

    initRandom();

    while (1){
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
