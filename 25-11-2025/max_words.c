#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

// Structure for word frequency
typedef struct {
    char word[MAX_LEN];
    int count;
} WordFreq;

int main() {
    char paragraph[1000];
    WordFreq freq[MAX_WORDS];
    int wordCount = 0;

    printf("Enter paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Convert paragraph to lowercase
    for (int i = 0; paragraph[i]; i++) {
        paragraph[i] = tolower(paragraph[i]);
    }

    char *word = strtok(paragraph, " ,.-!?;\n");

    while (word != NULL) {
        int found = 0;

        // check if word already exists in list
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(freq[i].word, word) == 0) {
                freq[i].count++;
                found = 1;
                break;
            }
        }

        // add new word
        if (!found) {
            strcpy(freq[wordCount].word, word);
            freq[wordCount].count = 1;
            wordCount++;
        }

        word = strtok(NULL, " ,.-!?;\n");
    }

    // Find top 3 frequencies
    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (freq[j].count > freq[i].count) {
                WordFreq temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }

    printf("\nTop 3 words:\n");
    for (int i = 0; i < 3 && i < wordCount; i++) {
        printf("%s → %d times\n", freq[i].word, freq[i].count);
    }

    return 0;
}
