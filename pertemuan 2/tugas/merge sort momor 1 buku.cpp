#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua subarray yang sudah terurut menjadi satu subarray terurut
void merge(int arr[], int l, int m, int r) {
    int x, y, z; // Indeks untuk iterasi array
    int n1 = m - l + 1; // Ukuran subarray kiri
    int n2 = r - m; // Ukuran subarray kanan

    int L[n1], R[n2]; // Array sementara untuk subarray kiri dan kanan

    // Salin data ke array sementara L[] dan R[]
    for (x = 0; x < n1; x++)
        L[x] = arr[l + x];
    for (y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    x = 0; // Indeks awal subarray pertama
    y = 0; // Indeks awal subarray kedua
    z = l; // Indeks awal subarray yang digabungkan

    // Gabungkan array sementara kembali ke arr[l..r]
    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) { // Jika elemen L[x] lebih kecil atau sama dengan R[y]
            arr[z] = L[x]; // Salin L[x] ke arr[z]
            x++; // Pindahkan indeks subarray kiri
        } else { // Jika elemen R[y] lebih kecil dari L[x]
            arr[z] = R[y]; // Salin R[y] ke arr[z]
            y++; // Pindahkan indeks subarray kanan
        }
        z++; // Pindahkan indeks subarray yang digabungkan
    }

    // Salin elemen sisa dari L[], jika ada
    while (x < n1) {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Salin elemen sisa dari R[], jika ada
    while (y < n2) {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// Fungsi utama merge sort rekursif
void mergeSort(int arr[], int l, int r) {
    if (l < r) { // Jika ada lebih dari satu elemen
        int m = l + (r - l) / 2; // Temukan titik tengah

        // Urutkan setengah pertama dan setengah kedua
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gabungkan setengah yang diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk menampilkan array
void show(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main() {
    int size; // Variabel untuk menyimpan ukuran array
    cout << "\nMasukan Banyak Data : ";
    cin >> size; // Baca ukuran array dari input

    int arr[size]; // Deklarasikan array dengan ukuran yang ditentukan (VLA warning)
    for (int i = 0; i < size; i++) {
        cout << "\nMasukan Data array ke-" << i << " : ";
        cin >> arr[i]; // Baca elemen array dari input
    }

    mergeSort(arr, 0, size - 1); // Panggil fungsi merge sort untuk mengurutkan array

    cout << "\nHasil\n";
    show(arr, size); // Tampilkan array yang sudah diurutkan

    return 0; // Kembalikan 0 untuk menunjukkan eksekusi berhasil
}
