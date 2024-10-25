#include "doublelist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Alokasi elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Dealokasi elemen
void dealokasi(address &P) {
    delete P;
}

// Menampilkan seluruh elemen list
void printInfo(List L) {
    address P = L.First;
    int i = 1;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

// Menambahkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

// Mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        L.First = L.First->next;
        if (L.First != nullptr) {
            L.First->prev = nullptr;
        } else {
            L.Last = nullptr;
        }
        P->next = nullptr;
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        L.Last = L.Last->prev;
        if (L.Last != nullptr) {
            L.Last->next = nullptr;
        } else {
            L.First = nullptr;
        }
        P->prev = nullptr;
    }
}

// Menghapus elemen setelah elemen tertentu
void deleteAfter(address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

