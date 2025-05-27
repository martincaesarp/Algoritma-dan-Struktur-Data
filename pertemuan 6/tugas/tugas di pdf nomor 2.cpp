#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printArray(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i)
        cout << setw(4) << a[i];
    cout << '\n';
}

void insertionSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    cout << "\n== Proses Insertion Sort ==\n";
    for (int i = 1; i < n; ++i) {
        int key = a[i];            
        int j   = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;           
        cout << "Setelah memasukkan elemen ke-" << i
             << " (key = " << key << "): ";
        printArray(a);
    }
}

int main() {
    cout << "=== Demo Insertion Sort ===\n";
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin  >> n;

    vector<int> data(n);
    cout << "Masukkan " << n << " bilangan:\n";
    for (int i = 0; i < n; ++i) cin >> data[i];

    cout << "\nData sebelum diurutkan: ";
    printArray(data);

    insertionSort(data);

    cout << "\nHasil akhir: ";
    printArray(data);
    return 0;
}

