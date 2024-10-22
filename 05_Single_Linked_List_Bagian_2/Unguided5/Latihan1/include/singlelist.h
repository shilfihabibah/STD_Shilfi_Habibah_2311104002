#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Prosedur untuk membuat list kosong
void createList(List &L);

// Fungsi untuk mengalokasikan elemen baru
address alokasi(infotype x);

// Prosedur untuk dealokasi elemen
void dealokasi(address &P);

// Prosedur untuk mencetak elemen list
void printInfo(List L);

// Prosedur untuk menyisipkan elemen di awal list
void insertFirst(List &L, address P);

// Fungsi untuk mencari elemen berdasarkan info
address findElm(List L, infotype x);

// Fungsi untuk menghitung total info dari semua elemen
int totalInfo(List L);

#endif
