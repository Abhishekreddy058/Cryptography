#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate a monoalphabetic cipher sequence from a keyword
void generateCipherSequence(char keyword[], char cipherSequence[]) {
    int i, j, len;
    len = strlen(keyword);
    char key[26] = {0};

    // Remove duplicate characters from the keyword
    for (i = 0, j = 0; i < len; ++i) {
        if (!key[toupper(keyword[i]) - 'A']) {
            key[toupper(keyword[i]) - 'A'] = 1;
            cipherSequence[j++] = toupper(keyword[i]);
        }
    }

    // Fill the remaining positions in the cipher sequence with the remaining characters
    for (i = 0; i < 26; ++i) {
        if (!key[i]) {
            cipherSequence[j++] = 'A' + i;
        }
    }
    cipherSequence[j] = '\0';
}

// Function to encrypt a message using the monoalphabetic cipher
void monoalphabeticEncrypt(char message[], char keyword[]) {
    char cipherSequence[26];
    generateCipherSequence(keyword, cipherSequence);

    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char base = islower(message[i]) ? 'a' : 'A';
            message[i] = cipherSequence[message[i] - base];
        }
    }

    printf("Encrypted message: %s\n", message);
}

int main() {
    char message[1000], keyword[100];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    printf("Enter a keyword: ");
    scanf("%s", keyword);

    printf("Original message: %s\n", message);
    printf("Keyword: %s\n", keyword);

    monoalphabeticEncrypt(message, keyword);

    return 0;
}

