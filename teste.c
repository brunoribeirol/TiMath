#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para inicializar o gerador de números aleatórios
void initRandom() {
    srand(time(NULL));
}

// Função para gerar um número aleatório entre min e max
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Função para obter uma operação aleatória
char getOperation() {
    int op = getRandomNumber(1, 4); // 1 para +, 2 para -, 3 para *, 4 para /
    switch (op) {
        case 1: return '+';
        case 2: return '-';
        case 3: return '*';
        case 4: return '/';
    }
    return '+';
}

// Função para gerar e verificar uma expressão matemática complexa
void generateAndCheckExpression() {
    int numNumbers = getRandomNumber(2, 5); // Gera de 2 a 5 números
    int numbers[numNumbers];
    char operations[numNumbers - 1];

    // Gera os números e as operações
    for (int i = 0; i < numNumbers; i++) {
        numbers[i] = getRandomNumber(1, 10);
        if (i < numNumbers - 1) {
            operations[i] = getOperation();
            // Garantir que não haverá divisão por zero e que o resultado seja inteiro
            if (operations[i] == '/') {
                while (numbers[i] % numbers[i + 1] != 0 || numbers[i + 1] == 0) {
                    numbers[i + 1] = getRandomNumber(1, 10);
                }
            }
        }
    }

    // Calcula a resposta correta
    int result = numbers[0];
    for (int i = 0; i < numNumbers - 1; i++) {
        switch (operations[i]) {
            case '+': result += numbers[i + 1]; break;
            case '-': result -= numbers[i + 1]; break;
            case '*': result *= numbers[i + 1]; break;
            case '/': result /= numbers[i + 1]; break;
        }
    }

    // Exibe a expressão para o usuário
    printf("%d", numbers[0]);
    for (int i = 0; i < numNumbers - 1; i++) {
        printf(" %c %d", operations[i], numbers[i + 1]);
    }
    printf(" = ");

    // Recebe a resposta do usuário
    int userAnswer;
    scanf("%d", &userAnswer);

    // Verifica se a resposta está correta
    if (userAnswer == result) {
        printf("Correto!\n");
    } else {
        printf("Errado! A resposta correta é %d.\n", result);
    }
}

// Função principal
int main() {
    initRandom();  // Inicializa a semente do gerador aleatório

    printf("Bem-vindo ao quiz matemático avançado!\n");

    time_t inicio, agora;

    time(&inicio);  // Marca o tempo de início

    generateAndCheckExpression();  // Gera e verifica a expressão matemática

    time(&agora);
    printf("\ntempo: %d", (int)difftime(agora, inicio)); //int
    return 0;
}
