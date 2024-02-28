#include <iostream>
using namespace std;

// Merge function to merge two sorted subarrays a[l..mid] and b[mid+1..r] into a single sorted array arr[l..r]
void merge(int arr[], int l, int mid, int r) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - l + 1; // Size of the left subarray
    int n2 = r - mid;     // Size of the right subarray

    // Create temporary arrays to hold the data of the two subarrays
    int a[n1]; // Left subarray
    int b[n2]; // Right subarray

    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    // Merge the two subarrays back into the original array arr[l..r]
    int i = 0; // Initial index of the left subarray
    int j = 0; // Initial index of the right subarray
    int k = l; // Initial index of the merged array

    // Compare elements from both subarrays and merge them in ascending order
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++;
            i++;
        } else {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    // Copy the remaining elements of a[] if any
    while (i < n1) {
        arr[k] = a[i];
        k++;
        i++;
    }

    // Copy the remaining elements of b[] if any
    while (j < n2) {
        arr[k] = b[j];
        k++;
        j++;
    }
}

// Recursive function to perform merge sort on the array arr[l..r]
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        // Calculate the middle index of the array
        int mid = l + (r - l) / 2;

        // Recursively sort the left and right halves
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);

        // Merge the sorted halves
        merge(arr, l, mid, r);
    }
}

// Main function to test the merge sort implementation
int main() {
    // Test array
    int arr[] = {5, 7, 1, 90, 32};

    // Perform merge sort on the array
    mergesort(arr, 0, 4);

    // Print the sorted array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

