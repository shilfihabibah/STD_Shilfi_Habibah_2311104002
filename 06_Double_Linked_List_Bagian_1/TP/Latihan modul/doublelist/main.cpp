#include "doublelist.h"

int main() {
    List L;
    address P;
    infotype dataKendaraan;

    CreateList(L);

    // Input beberapa kendaraan
    dataKendaraan = {"D001", "hitam", 90};
    insertLast(L, alokasi(dataKendaraan));

    dataKendaraan = {"D003", "putih", 70};
    insertLast(L, alokasi(dataKendaraan));

    dataKendaraan = {"D004", "kuning", 90};
    insertLast(L, alokasi(dataKendaraan));

    cout << "DATA LIST 1:" << endl;
    printInfo(L);

    // Mencari kendaraan dengan nomor polisi D001
    string cariNopol = "D001";
    P = findElm(L, cariNopol);
    if (P != nullptr) {
        cout << "\nKendaraan ditemukan:" << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "\nKendaraan dengan nomor polisi " << cariNopol << " tidak ditemukan." << endl;
    }

    // Menghapus kendaraan dengan nomor polisi D003
    string hapusNopol = "D003";
    P = findElm(L, hapusNopol);
    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    } else {
        cout << "\nKendaraan dengan nomor polisi " << hapusNopol << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1 SETELAH PENGHAPUSAN:" << endl;
    printInfo(L);

    return 0;
}
