#include "singlelist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = nullptr;

    // Membuat list kosong
    createList(L);

    // Menambahkan elemen-elemen ke dalam list
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // Menampilkan list
    cout << "Elemen dalam list: ";
    printInfo(L);

    // Mencari elemen dengan info 8
    address found = findElm(L, 8);
    if (found != nullptr) {
        cout << "Elemen dengan info 8 ditemukan." << endl;
    } else {
        cout << "Elemen dengan info 8 tidak ditemukan." << endl;
    }

    // Menghitung total info dari semua elemen
    int total = totalInfo(L);
    cout << "Total nilai elemen dalam list: " << total << endl;

    return 0;
}

