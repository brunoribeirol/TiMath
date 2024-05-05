#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;
    double elapsed;
    int i;
    char answer[100];  // Assuming answers are short text

    printf("You will be asked 15 questions. Press enter to start.\n");
    fgets(answer, sizeof(answer), stdin);  // Wait for user to press enter

    gettimeofday(&start, NULL);  // Start timing

    // Loop through each question
    for (i = 1; i <= 15; i++) {
        printf("Question %d: What is 2 + %d?\n", i, i);  // Example question
        printf("Answer: ");
        fgets(answer, sizeof(answer), stdin);  // Read user's answer
    }

    gettimeofday(&end, NULL);  // End timing

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;  // Calculate elapsed time
    printf("You completed the questions in %.6f seconds.\n", elapsed);

    return 0;
}
