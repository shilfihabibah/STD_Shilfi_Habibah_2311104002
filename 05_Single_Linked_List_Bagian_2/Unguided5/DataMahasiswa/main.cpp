#include <iostream>
#include <string>
using namespace std;

// Struktur node pada linked list
struct Node {
    int NIM;           // NIM mahasiswa
    string Nama;       // Nama mahasiswa
    Node* next;        // Pointer ke node berikutnya
};

// Fungsi untuk menambahkan data mahasiswa ke dalam linked list
void tambahMahasiswa(Node** head_ref, int NIM, string Nama) {
    Node* new_node = new Node();  // Membuat node baru
    new_node->NIM = NIM;          // Mengisi data NIM
    new_node->Nama = Nama;        // Mengisi data Nama
    new_node->next = nullptr;

    // Jika list kosong, new_node menjadi head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
    } else {
        Node* last = *head_ref;   // Menunjuk ke node terakhir
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;    // Menambahkan node baru di akhir list
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(Node* head, int NIM) {
    Node* current = head;   // Menunjuk ke node pertama

    // Traversing linked list untuk mencari mahasiswa berdasarkan NIM
    while (current != nullptr) {
        if (current->NIM == NIM) {
            cout << "Mahasiswa dengan NIM " << NIM << " ditemukan: " << current->Nama << endl;
            return;
        }
        current = current->next;
    }

    // Jika mahasiswa tidak ditemukan
    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
}

// Fungsi untuk mencetak semua data mahasiswa
void printList(Node* node) {
    while (node != nullptr) {
        cout << "NIM: " << node->NIM << ", Nama: " << node->Nama << endl;
        node = node->next;
    }
}

int main() {
    Node* head = nullptr;  // Membuat linked list kosong

    // Menambahkan beberapa mahasiswa
    tambahMahasiswa(&head, 15105, "Shilfi");
    tambahMahasiswa(&head, 24580, "Sofia");
    tambahMahasiswa(&head, 10125, "Kelvin");

    // Menampilkan semua mahasiswa
    cout << "Daftar Mahasiswa:" << endl;
    printList(head);

    // Mencari mahasiswa berdasarkan NIM
    int cariNIM;
    cout << "\nMasukkan NIM yang ingin dicari: ";
    cin >> cariNIM;
    cariMahasiswa(head, cariNIM);

    return 0;
}
