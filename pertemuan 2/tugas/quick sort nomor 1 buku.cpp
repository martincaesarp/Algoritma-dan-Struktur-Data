#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void swap (int arr[], int pos1, int pos2) {
    int temp; // Variabel sementara untuk penyimpanan
    temp = arr[pos1]; // Simpan nilai elemen di pos1
    arr[pos1] = arr [pos2]; // Ganti nilai elemen di pos1 dengan nilai elemen di pos2
    arr[pos2] = temp; // Ganti nilai elemen di pos2 dengan nilai yang disimpan di temp
}

// Fungsi untuk mempartisi array untuk quicksort
int partition (int arr[], int low, int high, int pivot) {
    int i = low; // Indeks untuk iterasi array
    int j = low; // Indeks untuk elemen yang lebih kecil dari pivot
    while (i <= high) { // Iterasi dari low hingga high
        if (arr[i] > pivot) { // Jika elemen saat ini lebih besar dari pivot
            i++; // Pindahkan indeks i ke elemen berikutnya
        }
        else { // Jika elemen saat ini kurang dari atau sama dengan pivot
            swap (arr, i, j); // Tukar elemen di i dan j
            i++; // Pindahkan indeks i ke elemen berikutnya
            j++; // Pindahkan indeks j ke elemen berikutnya (elemen yang lebih kecil dari pivot)
        }
    }
    return j-1; // Kembalikan posisi pivot setelah partisi
}

// Fungsi quicksort rekursif
void quicksort(int arr[], int low, int high) {
    if (low < high) { // Jika ada lebih dari satu elemen dalam sub-array
        int pivot = arr[high]; // Pilih elemen terakhir sebagai pivot
        int pos = partition(arr, low, high, pivot); // Partisi array dan dapatkan posisi pivot

        quicksort(arr, low, pos-1); // Urutkan sub-array kiri dari pivot
        quicksort(arr, pos+1, high); // Urutkan sub-array kanan dari pivot
    }
}

int main ()
{
    int n; // Variabel untuk menyimpan panjang array
    cout << "Tentukan panjang array = ";
    cin>> n; // Baca panjang array dari input

    int arr[n]; // Deklarasikan array dengan panjang n (perhatikan bahwa ini adalah VLA, yang tidak standar di C++)
    for (int i = 0; i < n; i++) { // Loop untuk membaca elemen-elemen array
        cin >> arr[i]; // Baca elemen array dari input
    }
    quicksort(arr, 0, n-1); // Panggil fungsi quicksort untuk mengurutkan array
    cout << "Berikutnya adalah array yang telah di sortir = ";
    for (int i = 0; i < n; i++) { // Loop untuk mencetak elemen-elemen array yang sudah diurutkan
        cout << arr[i] << "\t"; // Cetak elemen array diikuti dengan tab
    }
    cout << endl; // Cetak newline untuk baris baru.
    return 0; // Kembalikan 0 untuk menunjukkan eksekusi berhasil
}
