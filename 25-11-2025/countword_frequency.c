#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

typedef struct {
    char word[MAX_LEN];
    int count;
} WordCount;

int main() {
    char text[5000];
    WordCount wc[MAX_WORDS];
    int wc_size = 0;

    printf("Enter a paragraph:\n");
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, " \t\n");
    while (token != NULL) {
        // Normalize token: lowercase + strip punctuation
        char clean[MAX_LEN];
        int j = 0;

        for (int i = 0; token[i] != '\0' && j < MAX_LEN-1; i++) {
            if (isalnum((unsigned char)token[i])) {
                clean[j++] = tolower(token[i]);
            }
        }
        clean[j] = '\0';

        // Ignore empty strings
        if (strlen(clean) > 0) {

            // Check if the word already exists
            int found = 0;
            for (int i = 0; i < wc_size; i++) {
                if (strcmp(wc[i].word, clean) == 0) {
                    wc[i].count++;
                    found = 1;
                    break;
                }
            }

            // If new word, add it
            if (!found && wc_size < MAX_WORDS) {
                strcpy(wc[wc_size].word, clean);
                wc[wc_size].count = 1;
                wc_size++;
            }
        }

        token = strtok(NULL, " \t\n");
    }

    // Sort by frequency (descending)
    for (int i = 0; i < wc_size - 1; i++) {
        for (int j = i + 1; j < wc_size; j++) {
            if (wc[j].count > wc[i].count) {
                WordCount temp = wc[i];
                wc[i] = wc[j];
                wc[j] = temp;
            }
        }
    }

    // Print top 3
    printf("\nTop 3 most common words:\n");
    for (int i = 0; i < 3 && i < wc_size; i++) {
        printf("%s: %d\n", wc[i].word, wc[i].count);
    }

    return 0;
}
