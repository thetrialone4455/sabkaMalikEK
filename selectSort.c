#include<stdio.h>

void selectionSort(int a[], int n){
    int smallest, temp = 0;
    for(int i = 0; i<n-1; i++){
        smallest = i;
        for(int j = i + 1; j<n; j++){
            if(a[j] < a[smallest]){
                smallest = j;
            }
        }
        temp = a[smallest];
        a[smallest] = a[i];
        a[i] = temp;
    }
    
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int a[] = {5, 8, 2, 1, 3, 4, 6};
    selectionSort(a, 7);
    return 0;
}
