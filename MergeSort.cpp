#include <iostream>

using namespace std;

void merge(int arr[], int st, int mid, int end) {
    int i = st, j = mid + 1;
    int k = 0;
    int temp[100] = {0};
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = st, k = 0; i <= end; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int st, int end) {
    if(st < end) {
        int mid = (st + end) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, 5 - 1);
    for(int val : arr) {
        cout << val << " ";
    }
    return 0;
}