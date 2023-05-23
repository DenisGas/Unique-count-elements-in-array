#include <iostream>
using namespace std;

void printArr(const int* arr, int size) {
    cout << "\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int uniqueCountElem(const int* array, int size) {
    if (size == 0) return 0;

    printArr(array, size);

    int uniqueElem = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[j] == array[i]) {
                int notUniqueElement = array[i];
                int index = 0;
                int* newArray = new int[size];

                for (int k = 0; k < size; k++) {
                    if (array[k] != notUniqueElement) {
                        newArray[index] = array[k];
                        index++;
                    }
                }

                delete[] array;

                return uniqueCountElem(newArray, index);
            }
        }
        uniqueElem++;
    }

    delete[] array;

    return uniqueElem;
}



int main() {
    int uniqueElem = 0;
    int size = 0;

    cout << "Array size: "; cin >> size; cout << endl;

    if (size < 1)
    {
        cout << "Size must be greater than 0\n" << endl;
        return main();
    }

    int* arr = new int[size];

    cout << "Enter " << size << " elements: ";

    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    uniqueElem = uniqueCountElem(arr, size);
    cout << "\n\nNumber of unique elements: " << uniqueElem << endl;
}
