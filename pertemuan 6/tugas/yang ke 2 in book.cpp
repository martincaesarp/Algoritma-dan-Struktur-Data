#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
using namespace std;

// fungsi pembantu: ubah string jadi lowercase (tanpa lambda)
string to_lower(string s) {
    for (size_t i = 0; i < s.length(); ++i)
        s[i] = static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
    return s;
}

// binary search: kembalikan indeks bila ketemu, -1 jika tidak
int binarySearch(const string judul[], int n, const string& keyLower) {
    int L = 0, R = n - 1;
    while (L <= R) {
        int mid = (L + R) / 2;
        string midLower = to_lower(judul[mid]);

        if (midLower == keyLower)
            return mid;
        else if (midLower < keyLower)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}

int main() {
    const int N = 10;
    string judul[N] = {
        "Algoritma Pemrograman",
        "Basis Data Lanjut",
        "Clean Code",
        "Design Patterns",
        "Jaringan Komputer",
        "Machine Learning",
        "Operating System Concepts",
        "Pemrograman Web",
        "Rekayasa Perangkat Lunak",
        "Struktur Data"
    };

    string rak[N] = {
        "Rak A1", "Rak A2", "Rak B1", "Rak B3", "Rak C1",
        "Rak C4", "Rak D2", "Rak E1", "Rak E4", "Rak F2"
    };

    cout << "=== Sistem Pencarian Buku Perpustakaan ===\n";
    cout << "Masukkan judul buku yang ingin dicari: ";
    string key;
    getline(cin, key);

    int pos = binarySearch(judul, N, to_lower(key));

    if (pos != -1) {
        cout << "\nBuku ditemukan!\n";
        cout << left << setw(30) << "Judul"    << " : " << judul[pos] << '\n'
             << left << setw(30) << "Letak Rak" << " : " << rak[pos]   << '\n';
    } else {
        cout << "\nMaaf, judul \"" << key << "\" tidak ada di database.\n";
    }
    return 0;
}

