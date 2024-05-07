// void randomGame()
// {
//     printf(BMAG

//     "##   ##   #####   #####     #####              ##     ####     #######    ##     ######    #####   ######    ####     #####\n"
//     "### ###  ##   ##   ## ##   ##   ##            ####     ##       ##   #   ####    # ## #   ##   ##   ##  ##    ##     ##   ##\n"
//     "#######  ##   ##   ##  ##  ##   ##           ##  ##    ##       ## #    ##  ##     ##     ##   ##   ##  ##    ##     ##   ##\n"
//     "#######  ##   ##   ##  ##  ##   ##           ##  ##    ##       ####    ##  ##     ##     ##   ##   #####     ##     ##   ##\n"
//     "## # ##  ##   ##   ##  ##  ##   ##           ######    ##   #   ## #    ######     ##     ##   ##   ## ##     ##     ##   ##\n"
//     "##   ##  ##   ##   ## ##   ##   ##           ##  ##    ##  ##   ##   #  ##  ##     ##     ##   ##   ##  ##    ##     ##   ##\n"
//     "##   ##   #####   #####     #####            ##  ##   #######  #######  ##  ##    ####     #####   #### ##   ####     #####\n" reset);

//     sleep(0.5);

//     char playerName[NAME_SIZE];
//     printf("Digite seu nome: ");
//     while ((getchar()) != '\n')
//         ;
//     fgets(playerName, NAME_SIZE, stdin);
//     playerName[strcspn(playerName, "\n")] = 0;


//     Node *head = NULL;
//     Node *tail = NULL;

//     random_numbers_list(&head, &tail);

//     int firstNumber =  getRandomNumber(1, 10);

    

//     FILE *file = fopen("ranking.txt", "a"); // Abe o arquivo para adicionar a pontuação
//     if (file != NULL)
//     {
//         // fprintf(file, "%s: %d\n", playerName, time);
//         fclose(file);
//     }
//     else
//     {
//         printf("Não foi possível abrir o arquivo de pontuações.");
//     }
// }