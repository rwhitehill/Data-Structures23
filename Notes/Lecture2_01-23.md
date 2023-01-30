# Lecture 2 - 01/23/23

Example of bubble sort in C++:
````C++
void bubble_sort(int array[],int n) {
    for (int i; i < n-1; i++) {
        for (int j; j < n-i-1;j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
````

### Big-O notation

Used to describe the dependence of running time (upper bound) on the number of inputs

$O(1)$ -- constant time  
$O(\log{N})$ -- log time  
$O(N)$ -- linear time  
$O(N\log{N})$ -- linear log time  
$O(N^2)$ -- quadratic time (e.g. bubble sort algorithm above)  
$O(N^3)$ -- cubic time  
* The above logarithms are base-2

### Insertion sort algorithm

Goal: find the correct position to insert element on the left-hand side

````C++
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
````

The example above is expected to process as follows:
$$51428 \rightarrow 15428 \rightarrow 14528 \rightarrow 12458 \rightarrow 12458$$






