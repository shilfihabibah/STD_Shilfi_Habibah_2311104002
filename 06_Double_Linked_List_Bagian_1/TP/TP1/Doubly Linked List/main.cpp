#include <iostream>
using namespace std;

// Struktur node pada Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan elemen di awal list
void insertFirst_2311104002(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Fungsi untuk menambahkan elemen di akhir list
void insertLast_2311104002(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk mencetak list dari depan ke belakang
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // List kosong pada awalnya
    int firstElement, secondElement, thirdElement;

    // Memasukkan elemen pertama di awal list
    cout << "Masukkan elemen pertama: ";
    cin >> firstElement;
    insertFirst_2311104002(head, firstElement);

    // Memasukkan elemen kedua di awal list
    cout << "Masukkan elemen kedua di awal: ";
    cin >> secondElement;
    insertFirst_2311104002(head, secondElement);

    // Memasukkan elemen ketiga di akhir list
    cout << "Masukkan elemen ketiga di akhir: ";
    cin >> thirdElement;
    insertLast_2311104002(head, thirdElement);

    // Menampilkan seluruh elemen dalam list
    cout << "DAFTAR ANGGOTA LIST: ";
    printList(head);

    return 0;
}

