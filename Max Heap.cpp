#include <iostream>

using namespace std;

// Class for a Max Heap data structure
class MaxHeap {
private:
    int* heap; // Array to store the heap elements
    int size; // Current size of the heap
    int capacity; // Maximum capacity of the heap

    // Helper function to swap two elements in the heap array
    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Helper function to maintain the heap property after insertion or deletion
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1; // Index of the left child
        int right = 2 * i + 2; // Index of the right child

        // Find the index of the largest element among the node and its children
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        // If the largest element is not the node itself, swap and continue heapifying
        if (largest != i) {
            swap(i, largest);
            heapify(largest);
        }
    }

public:
    // Constructor to initialize an empty MaxHeap with a given capacity
    MaxHeap(int capacity) {
        heap = new int[capacity]; // Allocate memory for the heap array
        size = 0; // Initialize current size to 0
        this->capacity = capacity; // Set the maximum capacity
    }

    // Function to insert a new element into the heap
    void insert(int val) {
        if (size == capacity) { // Check if the heap is full
            cout << "Heap is full! Cannot insert." << endl;
            return;
        }

        heap[size++] = val; // Insert the new element at the end of the array
        int i = size - 1; // Index of the newly inserted element
        int parent = (i - 1) / 2; // Index of its parent node

        // Maintain the heap property by swapping with parent until the heap is valid
        while (i > 0 && heap[i] > heap[parent]) {
            swap(i, parent);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    // Function to remove and return the maximum element from the heap
    int removeMax() {
        if (size == 0) { // Check if the heap is empty
            cout << "Heap is empty! Cannot remove." << endl;
            return -1;
        }

        int max = heap[0]; // Save the maximum element
        heap[0] = heap[--size]; // Replace the root with the last element
        heapify(0); // Heapify the root to restore the heap property
        return max; // Return the maximum element
    }

    // Function to print the elements of the heap
    void print() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    // Destructor to deallocate memory used by the heap array
    ~MaxHeap() {
        delete[] heap;
    }
};

// Function to test the MaxHeap class
void test() {
    MaxHeap h(15); // Create a MaxHeap object with capacity 15

    // Array of elements to insert into the heap
    int arr[] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
    int arrSize = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Insert each element from the array into the heap and print the heap after each insertion
    for (int i = 0; i < arrSize; ++i) {
        int x = arr[i];
        h.insert(x);
        cout << "Inserted " << x << ", heap: ";
        h.print();
    }

    cout << endl << "Remove Operations : " << endl;

    // Remove and print the maximum element from the heap several times
    for (int i = 0; i < 7; ++i) {
        int max = h.removeMax();
        cout << "Removed " << max << ", heap: ";
        h.print();
    }
}

// Main function to test the MaxHeap class
int main() {
    test(); // Call the test function
    return 0; // Return 0 to indicate successful completion
}

