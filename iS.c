#include<stdio.h>

void insertionSort(int arr[], int n){
    int t = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                t = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = t;
            }
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[6] = {5, 8, 4, 3, 1, 2};
    insertionSort(arr, 6);
    return 0;
}