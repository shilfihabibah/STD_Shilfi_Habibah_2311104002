#include "singlelist.h"

// Prosedur untuk membuat list kosong
void createList(List &L) {
    L.First = nullptr;
}

// Fungsi untuk mengalokasikan elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

// Prosedur untuk dealokasi elemen
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Prosedur untuk mencetak elemen-elemen dalam list
void printInfo(List L) {
    address P = L.First;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Prosedur untuk menyisipkan elemen di awal list
void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.First;
        L.First = P;
    }
}

// Fungsi untuk mencari elemen berdasarkan info
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return nullptr; // Jika tidak ditemukan
}

// Fungsi untuk menghitung total info dari semua elemen
int totalInfo(List L) {
    address P = L.First;
    int total = 0;
    while (P != nullptr) {
        total += P->info;
        P = P->next;
    }
    return total;
}
