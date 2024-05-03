#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 15

char* generateRandomPassword(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]|:;<>,.?/~";
    char* password = malloc((length + 1) * sizeof(char));
    if (!password) {
        fprintf(stderr, "Errore: impossibile allocare memoria\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }
    password[length] = '\0'; // Terminatore di stringa
    return password;
}

int main() {
    char* password = generateRandomPassword(PASSWORD_LENGTH);
    printf("Password generata: %s\n", password);
    free(password);
    return 0;
}
