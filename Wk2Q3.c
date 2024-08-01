#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

int main() {
    char paragraph[10000];
    WordFreq wordList[MAX_WORDS];
    int wordCount = 0;

    // Input the paragraph
    printf("Enter a paragraph (end input with Ctrl+D or Ctrl+Z):\n");
    if (fgets(paragraph, sizeof(paragraph), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \t\n,.!?\r");
    while (token != NULL) {
        // Convert token to lowercase
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordList[i].word, token) == 0) {
                wordList[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add new word to the list
        if (!found) {
            if (wordCount < MAX_WORDS) {
                strcpy(wordList[wordCount].word, token);
                wordList[wordCount].count = 1;
                wordCount++;
            } else {
                printf("Maximum word limit reached.\n");
                break;
            }
        }

        token = strtok(NULL, " \t\n,.!?\r");
    }

    // Print the word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return 0;
}
