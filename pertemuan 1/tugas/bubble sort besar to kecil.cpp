#include <iostream>
using namespace std;

void bubsort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
  
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[100], n, i;
    cout << "Masukkan banyak elemen = ";
    cin >> n;
    cout << "Masukkan nilai = \n";
    for (i = 0; i < n; i++) {
        cin >> array[i];
    }
    bubsort(array, n);
    cout << "Hasil pengurutan dengan algoritma bubble sort (descending) = \n";
    for (i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
    return 0;
}
