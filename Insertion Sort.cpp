//insertion sort
//Devide the array into two part sorted and unsorted part 
//pick the element form unsorted part and place it in the correct position in sorted part
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        // Move elements greater than 'current' to one position ahead of their current position
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place 'current' in its correct position in the sorted part
        arr[j + 1] = current;
    }

    // Display the sorted array
    cout << "Array in sorted form is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

