#include <iostream>
using namespace std;

// Fungsi untuk mencari elemen menggunakan linear search
void searchElement_2311104002(int L[], int size, int i) {
    int position = 1; // Posisi awal elemen
    bool found = false; // Flag untuk mengecek apakah elemen ditemukan atau tidak

    // Linear search untuk mencari elemen dalam array
    for (int index = 0; index < size; index++) {
        if (L[index] == i) {
            found = true;
            cout << "Elemen ditemukan pada posisi urutan ke-" << position
                 << ", alamat: " << &L[index] << endl;
            break;
        }
        position++;
    }

    // Jika elemen tidak ditemukan
    if (!found) {
        cout << "Elemen " << i << " tidak ditemukan dalam list." << endl;
    }
}

int main() {
    int L[6]; // Array untuk menampung 6 elemen integer

    // Memasukkan 6 elemen integer ke dalam array
    for (int i = 0; i < 6; i++) {
        cout << "Masukkan elemen integer: ";
        cin >> L[i];
    }

    // Meminta pengguna untuk memasukkan nilai yang ingin dicari
    int searchVal;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> searchVal;

    // Panggil fungsi searchElement
    searchElement_2311104002(L, 6, searchVal);

    return 0;
}
