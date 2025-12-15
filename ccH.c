#include <stdio.h>

#define SIZE 11

int h1(int key) {
    return key % SIZE;
}

int h2(int key) {
    return (key / SIZE) % SIZE;
}

int main() {
    int table1[SIZE], table2[SIZE];
    int keys[] = {20, 50, 53, 75, 100};
    int n = 5;

    // initialize tables
    for(int i = 0; i < SIZE; i++) {
        table1[i] = -1;
        table2[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        int key = keys[i];
        int pos1 = h1(key);

        if(table1[pos1] == -1) {
            table1[pos1] = key;
        } else {
            int temp = table1[pos1];
            table1[pos1] = key;

            int pos2 = h2(temp);
            table2[pos2] = temp;
        }
    }

    // display tables
    printf("Table 1:\n");
    for(int i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, table1[i]);

    printf("\nTable 2:\n");
    for(int i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, table2[i]);

    return 0;
}
