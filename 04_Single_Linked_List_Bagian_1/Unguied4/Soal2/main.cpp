#include <iostream>
using namespace std;

// Definisi node dari linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di depan
void insertAtFront(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertAtBack(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // Jika node pertama memiliki nilai yang dicari
    if (temp != nullptr && temp->data == key) {
        head = temp->next;  // Ganti head dengan node berikutnya
        delete temp;  // Hapus node
        return;
    }

    // Mencari node yang memiliki nilai tertentu
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Jika nilai tidak ditemukan
    if (temp == nullptr) {
        cout << "Node dengan nilai " << key << " tidak ditemukan!" << endl;
        return;
    }

    // Hapus node
    prev->next = temp->next;
    delete temp;
}

// Fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Tambah node di depan
    insertAtFront(head, 10);

    // Tambah node di belakang
    insertAtBack(head, 20);

    // Tambah node di depan
    insertAtFront(head, 5);

    // Cetak linked list sebelum penghapusan
    cout << "Isi Linked List sebelum penghapusan: ";
    printList(head);

    // Hapus node dengan nilai 10
    deleteNode(head, 10);

    // Cetak linked list setelah penghapusan
    cout << "Isi Linked List setelah penghapusan: ";
    printList(head);

    return 0;
}

