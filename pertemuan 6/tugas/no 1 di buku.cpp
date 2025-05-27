#include <iostream>
using namespace std;

int main() {
    int x[] = {0, 6, 12, 18, 24};
    const int n = sizeof(x)/sizeof(x[0]);

    int key;
    cout << "Masukkan bilangan yang dicari: ";
    cin  >> key;

    int i = 0;
    while (i < n && x[i] != key) {
        ++i;                 // telusuri satu-persatu
    }

    if (i < n)
        cout << "Bilangan ditemukan pada indeks " << i << ".\n";
    else
        cout << "Bilangan tidak ditemukan.\n";

    return 0;
}

