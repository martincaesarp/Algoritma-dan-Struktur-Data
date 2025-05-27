#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah nama: ";
    cin >> n;

    vector<string> nama(n);
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        cout << "Nama ke-" << i + 1 << ": ";
        getline(cin, nama[i]);
    }

    cout << "\nSebelum diurutkan:\n";
    for (int i = 0; i < n; ++i) {
        cout << nama[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n; ++i) {
        string key = nama[i];
        int j = i - 1;

        while (j >= 0 && nama[j].length() > key.length()) {
            nama[j + 1] = nama[j];
            j = j - 1;
        }
        nama[j + 1] = key;
    }

    cout << "\nSetelah diurutkan berdasarkan panjang karakter:\n";
    for (int i = 0; i < n; ++i) {
        cout << nama[i] << " ";
    }
    cout << endl;

    return 0;
}

