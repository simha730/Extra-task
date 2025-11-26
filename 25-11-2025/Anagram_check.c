#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHAR_SET 256   // ASCII character set

int areAnagrams(const char *s1, const char *s2) {
    int count[CHAR_SET] = {0};

    // If lengths differ, cannot be anagrams
    if (strlen(s1) != strlen(s2))
        return 0;

    // Count characters from s1 and s2
    for (int i = 0; s1[i] != '\0'; i++) {
        unsigned char c1 = tolower(s1[i]);
        unsigned char c2 = tolower(s2[i]);

        count[c1]++;   // increment for s1
        count[c2]--;   // decrement for s2
    }

    // If all counts return to zero, they are anagrams
    for (int i = 0; i < CHAR_SET; i++) {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    char str1[200], str2[200];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove trailing newline if present
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    if (areAnagrams(str1, str2))
        printf("Anagrams\n");
    else
        printf("Not Anagrams\n");

    return 0;
}
