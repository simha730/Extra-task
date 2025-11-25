#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000  // Hash table size

typedef struct {
    int *arr;          // dynamic array
    int size;          // current size
    int capacity;      // array capacity
    int hash[MAX];     // value → index map
    int present[MAX];  // presence map (1 = present)
} RandomSet;

// Initialize the data structure
void initSet(RandomSet *set) {
    set->capacity = 100;
    set->size = 0;
    set->arr = (int *)malloc(sizeof(int) * set->capacity);

    for (int i = 0; i < MAX; i++) {
        set->present[i] = 0;
    }
}

// Insert O(1)
void insert(RandomSet *set, int val) {
    if (set->present[val]) {
        printf("%d already exists\n", val);
        return;
    }

    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->arr = realloc(set->arr, set->capacity * sizeof(int));
    }

    set->arr[set->size] = val;
    set->hash[val] = set->size;
    set->present[val] = 1;

    set->size++;
    printf("Inserted %d\n", val);
}

// Delete O(1)
void delete(RandomSet *set, int val) {
    if (!set->present[val]) {
        printf("%d not found\n", val);
        return;
    }

    int idx = set->hash[val];         // index of element to delete
    int lastVal = set->arr[set->size - 1];  // last element

    // swap with last
    set->arr[idx] = lastVal;
    set->hash[lastVal] = idx;

    set->size--;
    set->present[val] = 0;

    printf("Deleted %d\n", val);
}

// getRandom O(1)
int getRandom(RandomSet *set) {
    if (set->size == 0) return -1;
    int r = rand() % set->size;
    return set->arr[r];
}

// Main Example
int main() {
    srand(time(NULL));

    RandomSet set;
    initSet(&set);

    insert(&set, 10);
    insert(&set, 20);
    insert(&set, 30);
    insert(&set, 40);

    printf("Random: %d\n", getRandom(&set));

    delete(&set, 20);

    printf("Random: %d\n", getRandom(&set));

    return 0;
}
