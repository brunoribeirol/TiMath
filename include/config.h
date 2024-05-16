#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <sys/time.h> 
#include <math.h> 

#include "animations.h"
#include "data.h"
#include "random.h"

#define GAME_SIZE 12

#define NAME_SIZE 50

#define RANGE_MIN_SUM 1
#define RANGE_MAX_SUM 10  

#define RANGE_MIN_DIV 1
#define RANGE_MAX_DIV 10

#define RED_BG "\e[41m"
#define RED "\e[0;31m"
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
#define BOLD_BLUE "\e[1;34m"
#define BOLD_CYAN "\e[1;36m"
#define reset "\e[0m"

#endif