// Richard Whitehill
// a simple example of insertion sort
#include <iostream>

void insertion_sort(int arr[], int n);

int main() {
    
    int arr[] = {5,1,4,2,8}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    
    for (int i=0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
