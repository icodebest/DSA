#include <iostream>
#include <chrono>
using namespace std;

int main() {
    // Record the start time
    auto start = chrono::high_resolution_clock::now();

    // Code to be timed (replace this with your actual code)
    for (int i = 0; i < 1000000; i++) {
        // Code to be timed goes here
    }

    // Record the end time
    auto stop = chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Print the execution time
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}

