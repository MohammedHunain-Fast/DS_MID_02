#include <iostream>

using namespace std;

int partition(int arr[], int st, int end) {
    int idx = st - 1, pivot = arr[end];
    for(int j = st; j < end; j++) {
        if(arr[j] < pivot) {
            idx++;
            swap(arr[idx], arr[j]);
        }
    } 
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
    
}

void quickSort(int arr[], int st, int end) {
    if(st < end) {
        int pivotIdx = partition(arr, st, end);
        quickSort(arr, st, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, 5 - 1);
    for(int val : arr) {
        cout << val << " ";
    }
    return 0;
    return 0;
}