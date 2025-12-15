#include <stdio.h>

#define SIZE 11

int main() {
    int hash[SIZE];
    int keys[] = {21, 32, 43, 54, 65};
    int n = 5;

    // initialize hash table
    for(int i = 0; i < SIZE; i++)
        hash[i] = -1;

    // insert keys
    for(int i = 0; i < n; i++) {
        int key = keys[i];
        int index = key % SIZE;

        // linear probing with step = 2
        while(hash[index] != -1) {
            index = (index + 2) % SIZE;
        }

        hash[index] = key;
    }

    // display table
    for(int i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, hash[i]);

    return 0;
}
