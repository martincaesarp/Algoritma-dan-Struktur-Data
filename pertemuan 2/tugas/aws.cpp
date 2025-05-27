#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i < size - 1 ? " " : "");
    }
    cout << "]" << endl;
}

int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { 
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 

    printArray(arr, size);
    return (i + 1); 
}

void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high, size); 

        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main() {
    int numElements;
    cout << "Data yang akan di sort : ";
    cin >> numElements;

    int arr[numElements]; 
    cout << "Masukkan " << numElements << " angka: ";
    for (int i = 0; i < numElements; i++) {
        cin >> arr[i]; 
    }

    cout << "Quick Sort :" << endl;
    printArray(arr, numElements);

    quickSort(arr, 0, numElements - 1, numElements); 
    return 0;
}
