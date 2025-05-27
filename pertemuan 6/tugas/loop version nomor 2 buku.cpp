#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
using namespace std;

/* ------------------ util: ubah string ke lowercase ------------------ */
string to_lower(string s) {
    for (size_t i = 0; i < s.length(); ++i)
        s[i] = static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
    return s;
}

/* ------------- binary search: indeks jika ketemu, -1 jika tidak ----- */
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
    /* ---------- DATA PERPUSTAKAAN (sudah terurut alfabetis) ---------- */
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
    /* ----------------------------------------------------------------- */

    cout << "=== Sistem Pencarian Buku Perpustakaan ===\n"
            "Ketik judul yang ingin dicari.\n"
            "Ketik \"stop\" untuk keluar.\n\n";

    while (true) {
        cout << "Judul buku: ";
        string key;
        getline(cin, key);

        /* ------------- kondisi berhenti ------------- */
        if (to_lower(key) == "stop") {
            cout << "Terima kasih. Program dihentikan.\n";
            break;
        }

        /* ---------- lakukan pencarian binary ---------- */
        int pos = binarySearch(judul, N, to_lower(key));

        if (pos != -1) {
            cout << "\nBuku ditemukan!\n";
            cout << left << setw(30) << "Judul"    << " : " << judul[pos] << '\n'
                 << left << setw(30) << "Letak Rak" << " : " << rak[pos]   << "\n\n";
        } else {
            cout << "Maaf, judul \"" << key << "\" tidak ada di database.\n\n";
        }
    }
    return 0;
}


