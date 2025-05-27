#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
private:
    int front, rear;
    string data[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Antrian penuh!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        data[rear] = name;
        cout << name << " masuk ke dalam antrian." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        cout << data[front] << " telah dilayani dan keluar dari antrian." << endl;
        if (front == rear) {
            front = rear = -1;  // reset queue
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        cout << "Isi antrian: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue antrian;
    int pilihan;
    string nama;

    do {
        cout << "\n=== Menu Antrian Loket ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                antrian.enqueue(nama);
                break;
            case 2:
                antrian.dequeue();
                break;
            case 3:
                antrian.display();
                break;
            case 4:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

