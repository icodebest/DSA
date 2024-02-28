#include <iostream>
using namespace std;

void adjustHeap(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        adjustHeap(a, n, largest);
    }
}

void heapSorting(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        adjustHeap(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        adjustHeap(a, i, 0);
    }
}

void displayArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int inputArray[size];
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> inputArray[i];
    }

    cout << "Before sorting, array elements are - \n";
    displayArray(inputArray, size);

    heapSorting(inputArray, size);

    cout << "\nAfter sorting, array elements are - \n";
    displayArray(inputArray, size);

    return 0;
}

