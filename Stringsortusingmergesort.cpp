#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(string array[], int left, int mid, int right)
{
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    string leftArray[sizeLeft];
    string rightArray[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeRight; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < sizeLeft && j < sizeRight)
    {
        if (leftArray[i].length() <= rightArray[j].length())
        {
            array[k] = leftArray[i];
            i++;
        } else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeft)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < sizeRight)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(string array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int numOfSets;
    cout << "Enter the number of sets: ";
    cin >> numOfSets;

    int setNumber = 1;

    while (numOfSets--)
    {
        int size;
        cout << "Enter the size of Set " << setNumber << ": ";
        cin >> size;
        setNumber++;

        vector<string> stringArray(size);

        for (int i = 0; i < size; i++)
        {
            cout << "Enter String " << i + 1 << ": ";
            cin >> stringArray[i];
        }

        mergeSort(stringArray.data(), 0, size - 1);

        cout << "Sorted Set " << setNumber - 1 << ": ";
        for (int i = 0; i < size; i++)
        {
            cout << stringArray[i] << " ";
        }
        cout << endl << endl;
    }

    return 0;
}

