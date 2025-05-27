#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menukar dua elemen
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk membagi array berdasarkan pivot
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Pivot diambil dari elemen terakhir
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Jika elemen lebih kecil dari pivot, tukar
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Menempatkan pivot di posisi yang benar
    return (i + 1);
}

// Fungsi rekursif untuk melakukan Quick Sort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Rekursif untuk bagian kiri dan kanan dari pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Fungsi untuk mencetak array
void printArray(const vector<int> &arr) {
 for (size_t i=0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n, element;

    // Output header dan meminta input dari user
    cout << "Program Quick Sort\n";
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    // Mengambil input array dari user
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }

    // Menampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(arr);

    // Melakukan Quick Sort
    quickSort(arr, 0, n - 1);

    // Menampilkan hasil array yang sudah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(arr);

    return 0;
}
