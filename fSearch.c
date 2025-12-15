#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int n, int key) {

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }


    return -1;
}

int main() {
    int n = 7;
    int arr[7] = {1, 3, 5, 7, 9, 11, 13};

    int key = 7;
    int result = fibonacciSearch(arr, n, key);

    cout << result;
    return 0;
}