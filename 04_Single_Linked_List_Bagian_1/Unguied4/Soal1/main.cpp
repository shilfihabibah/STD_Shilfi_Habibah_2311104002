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

    // Cetak linked list
    cout << "Isi Linked List: ";
    printList(head);

    return 0;
}
