#include <iostream>
using namespace std;

// Struktur node pada linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke dalam linked list secara terurut
void insertSorted_2311104002(Node** head_ref, int new_data) {
    Node* new_node = new Node(); // Membuat node baru
    new_node->data = new_data;
    new_node->next = nullptr;

    // Jika list kosong atau elemen baru lebih kecil dari elemen pertama
    if (*head_ref == nullptr || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node; // Elemen baru menjadi head
    } else {
        Node* current = *head_ref;

        // Cari posisi yang tepat untuk menyisipkan elemen baru
        while (current->next != nullptr && current->next->data < new_node->data) {
            current = current->next;
        }

        // Menyisipkan elemen baru di antara current dan current->next
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Fungsi untuk mencetak elemen dalam linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Membuat linked list kosong

    // Memasukkan 4 elemen secara terurut ke dalam linked list
    int n;
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan elemen integer: ";
        cin >> n;
        insertSorted_2311104002(&head, n); // Menambahkan elemen secara terurut
    }

    cout << "List sebelum menambah elemen baru: ";
    printList(head);

    // Meminta pengguna memasukkan elemen tambahan
    int new_val;
    cout << "Masukkan elemen tambahan yang akan disisipkan secara terurut: ";
    cin >> new_val;

    // Menyisipkan elemen tambahan secara terurut
    insertSorted_2311104002(&head, new_val);

    cout << "List setelah menambah elemen baru: ";
    printList(head);

    return 0;
}
