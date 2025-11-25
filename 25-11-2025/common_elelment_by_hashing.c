#include <stdio.h>

#define MAX 1000   // adjust based on expected values

void findCommon(int arr1[], int n1, int arr2[], int n2) {
    int hash[MAX] = {0};

    // Hash the elements of the first array
    for (int i = 0; i < n1; i++) {
        hash[arr1[i]] = 1;
    }

    // Check elements of second array
    printf("Common elements: ");
    for (int i = 0; i < n2; i++) {
        if (hash[arr2[i]] == 1) {
            printf("%d ", arr2[i]);
            hash[arr2[i]] = 0; // prevent duplicates in output
        }
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6,7};
    int arr2[] = {4, 5, 6, 7, 8};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findCommon(arr1, n1, arr2, n2);

    return 0;
}
