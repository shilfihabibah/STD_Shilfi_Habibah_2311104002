#include <iostream>
using namespace std;

// Struktur node pada linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke dalam linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(); // Membuat node baru
    Node* last = *head_ref; // Menunjuk ke head

    new_node->data = new_data;
    new_node->next = nullptr; // Set node terakhir

    if (*head_ref == nullptr) {
        *head_ref = new_node; // Jika list kosong, node baru menjadi head
        return;
    }

    while (last->next != nullptr) { // Mencari node terakhir
        last = last->next;
    }

    last->next = new_node; // Menghubungkan node baru ke akhir list
}

// Fungsi untuk mencetak elemen dalam linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Prosedur untuk mengurutkan linked list menggunakan bubble sort
void bubbleSort_2311104002(Node* head) {
    bool swapped;
    Node* current;
    Node* last_ptr = nullptr; // Digunakan untuk mempercepat proses

    if (head == nullptr) // Jika list kosong
        return;

    do {
        swapped = false;
        current = head;

        while (current->next != last_ptr) {
            if (current->data > current->next->data) {
                // Tukar data antar node
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last_ptr = current; // Mengurangi iterasi dengan menempatkan last_ptr
    } while (swapped); // Ulangi sampai tidak ada pertukaran
}

int main() {
    Node* head = nullptr; // Membuat linked list kosong

    // Memasukkan 5 elemen ke dalam linked list
    int n;
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan elemen integer: ";
        cin >> n;
        append(&head, n);
    }

    cout << "List sebelum sorting: ";
    printList(head);

    // Panggil prosedur bubbleSort untuk mengurutkan elemen
    bubbleSort_2311104002(head);

    cout << "List setelah sorting: ";
    printList(head);

    return 0;
}
