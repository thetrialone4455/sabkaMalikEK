#include<stdio.h>

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int lArr[n1];
    int rArr[n2];
    int x = 0, y = 0, k = l;
    
    for(int i = 0; i<n1; i++){
        lArr[i] = arr[l+i];
    }
    for(int i = 0; i<n2; i++){
        rArr[i] = arr[m+1+i];
    }
    
    while(x < n1 && y < n2){
        if(lArr[x] <= rArr[y]){
            arr[k] = lArr[x];
            k++;
            x++;
        }
        else{
            arr[k] = rArr[y];
            k++;
            y++;
        }
    }
    while(x < n1){
        arr[k] = lArr[x];
        k++;
        x++;
    }
    while(y < n2){
        arr[k] = rArr[y];
        k++;
        y++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[] = {4, 5, 2, 7, 9, 0, 1};
    mergeSort(arr, 0, 7);
    
    for(int i = 0; i < 7; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}