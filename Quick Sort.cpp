#include <iostream>

using namespace std;

// Function to partition the array into two halves and return the index of the pivot element
int partition(int arr[], int low, int high) {
    // Choose the pivot element (in this case, the last element in the array)
    int pivot = arr[high];

    // Initialize the index of the smaller element
    int i = low - 1;

    // Traverse the array and rearrange elements based on whether they are less than or equal to the pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            // If the current element is less than or equal to the pivot, swap it with the element at index i+1
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at index i+1 to place it in its correct sorted position
    swap(arr[i + 1], arr[high]);

    // Return the index of the pivot element
    return i + 1;
}

// Recursive function to perform the quicksort algorithm on the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition index and recursively sort the two subarrays
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Test array
    int blocksToSort[] = {4, 2, 7, 1, 9, 5};
    int size = sizeof(blocksToSort) / sizeof(blocksToSort[0]);

    // Print the original array
    cout << "Original Blocks: ";
    for (int i = 0; i < size; i++) {
        cout << blocksToSort[i] << " ";
    }
    cout << endl;

    // Perform quicksort on the array
    quickSort(blocksToSort, 0, size - 1);

    // Print the sorted array
    cout << "Sorted Blocks: ";
    for (int i = 0; i < size; i++) {
        cout << blocksToSort[i] << " ";
    }
    cout << endl;

    return 0;
}

