#include "config.h"

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

bool isPrime(int num){
    if (num < 2) {
        return false;
    }

    if (num == 2 || num == 3) {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}