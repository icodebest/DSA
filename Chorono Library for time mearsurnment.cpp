#include <iostream>
#include <chrono>
using namespace std;
int main() {
    const int n = 1000;
    float arr[n];

    // Assume array values (for demonstration purposes)
    for (int i = 0; i < n; ++i)
        arr[i] = static_cast<float>(n - i);  // Sample array in reverse order

    // Measure execution time
    auto start = std::chrono::high_resolution_clock::now();

    // Sorting
    float counter = 1;
    while (counter < n) {
        for (int i = 0; i < n - counter; i++) {
            if (arr[i] > arr[i + 1]) {
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Output: Sorted array and execution time
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nExecution Time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}

