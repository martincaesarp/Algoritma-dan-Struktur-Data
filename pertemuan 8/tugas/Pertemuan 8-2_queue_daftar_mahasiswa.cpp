#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;
string queue[MAX];
int front = -1, rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(string nama) {
    if (isFull()) {
        cout << "Antrian penuh, tidak bisa menambahkan mahasiswa lagi." << endl;
    } else {
        if (front == -1) front = 0;
        queue[++rear] = nama;
        cout << nama << " telah masuk ke dalam antrian." << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong, tidak ada mahasiswa yang bisa dikeluarkan." << endl;
    } else {
        cout << queue[front] << " telah selesai dan keluar dari antrian." << endl;
        front++;
    }
}

void tampilkan() {
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
    } else {
        cout << "Daftar mahasiswa dalam antrian: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "\nMenu:\n1. Tambah Mahasiswa (enqueue)\n2. Layani Mahasiswa (dequeue)\n3. Tampilkan Antrian\n4. Keluar\nPilih: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                getline(cin, nama);
                enqueue(nama);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilkan();
                break;
            case 4:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}

