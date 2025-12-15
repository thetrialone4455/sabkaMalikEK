#include <iostream>

using namespace std;


int findB(int* arr,int st,int end,int key){

    while (st <= end)
    {
        int mid = (st+ end) / 2;

        if(arr[mid] == key){
            return mid;
        }
        else if (arr[mid] < key)    
        {
            st = mid+1;
        }else{
            end = mid-1;
        }
    }

 return -1;
}   

int main(){

    int n = 5;
    int arr[n] = {1,2,3,4,5};

    cout << findB(arr,0,n-1,100);

    return 0;
}