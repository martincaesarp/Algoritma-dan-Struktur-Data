#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int jumlahBuku;
    cout << "Masukkan jumlah buku: ";
    cin >> jumlahBuku;
    cin.ignore(); 

    string judulBuku[jumlahBuku];

    cout << "Masukkan judul buku:" << endl;
    for (int i = 0; i < jumlahBuku; i++) {
        getline(cin, judulBuku[i]);
    }

    bubbleSort(judulBuku, jumlahBuku);

    cout << "\nJudul buku setelah diurutkan (ascending):" << endl;
    for (int i = 0; i < jumlahBuku; i++) {
        cout << judulBuku[i] << endl;
    }

    return 0;
}
