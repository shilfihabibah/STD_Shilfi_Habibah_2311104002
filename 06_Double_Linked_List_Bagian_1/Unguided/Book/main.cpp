#include <iostream>
#include <string>
using namespace std;

// Definisi struktur untuk menyimpan informasi buku
struct Buku {
    int id;
    string judul;
    string penulis;
};

// Definisi struktur node dalam Doubly Linked List
struct Node {
    Buku data;
    Node* next;
    Node* prev;
};

// Definisi struktur Doubly Linked List
struct DoublyLinkedList {
    Node* head;
    Node* tail;

    // Inisialisasi list kosong
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk membuat node baru
    Node* createNode(int id, string judul, string penulis) {
        Node* newNode = new Node;
        newNode->data.id = id;
        newNode->data.judul = judul;
        newNode->data.penulis = penulis;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    // Fungsi untuk menambahkan buku di akhir list
    void addBookAtEnd(int id, string judul, string penulis) {
        Node* newNode = createNode(id, judul, penulis);

        if (head == nullptr) { // Jika list kosong
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Fungsi untuk menampilkan daftar buku dari awal ke akhir
    void displayBooksForward() {
        if (head == nullptr) {
            cout << "Daftar buku kosong.\n";
            return;
        }

        Node* temp = head;
        cout << "Daftar buku dari awal ke akhir:\n";
        while (temp != nullptr) {
            cout << "ID Buku     : " << temp->data.id << endl;
            cout << "Judul Buku  : " << temp->data.judul << endl;
            cout << "Penulis Buku: " << temp->data.penulis << endl;
            cout << "-------------------------\n";
            temp = temp->next;
        }
    }

    // Fungsi untuk menampilkan daftar buku dari akhir ke awal
    void displayBooksBackward() {
        if (tail == nullptr) {
            cout << "Daftar buku kosong.\n";
            return;
        }

        Node* temp = tail;
        cout << "Daftar buku dari akhir ke awal:\n";
        while (temp != nullptr) {
            cout << "ID Buku     : " << temp->data.id << endl;
            cout << "Judul Buku  : " << temp->data.judul << endl;
            cout << "Penulis Buku: " << temp->data.penulis << endl;
            cout << "-------------------------\n";
            temp = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList listBuku;

    // Menambahkan buku ke dalam list
    listBuku.addBookAtEnd(2004, "Belajar ngoding", "Putra Teddy");
    listBuku.addBookAtEnd(2005, "Kalkulus 2", "Dimas Sanjaya");
    listBuku.addBookAtEnd(2006, "Logika Matematika", "Dwi Putri");

    // Menampilkan daftar buku dari awal ke akhir
    listBuku.displayBooksForward();

    // Menampilkan daftar buku dari akhir ke awal
    listBuku.displayBooksBackward();

    return 0;
}
