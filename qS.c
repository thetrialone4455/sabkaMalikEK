#include<stdio.h>

int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i = l - 1;
    
    for(int j = l; j < h; j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[h];
    arr[h] = t;
    
    return i+1;
}


void quickS(int arr[], int l, int h){
    if(l < h){
        int pi = partition(arr, l, h);
        
        quickS(arr, l, pi-1);
        quickS(arr, pi+1, h);
    }
}

int main(){
    int arr[] = {4, 5, 12, 7, 2, 0, 9, 4};
    quickS(arr, 0, 8);
    
    for(int i = 0; i<8; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}