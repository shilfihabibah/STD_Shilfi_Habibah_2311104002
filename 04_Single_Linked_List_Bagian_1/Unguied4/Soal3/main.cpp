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

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Fungsi untuk menghitung panjang linked list
int countLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi untuk mencetak linked list
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

    // Tambah node di depan dan belakang
    insertAtFront(head, 10);
    insertAtBack(head, 20);
    insertAtFront(head, 5);

    // Cari node dengan nilai 20
    if (searchNode(head, 20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int length = countLength(head);
    cout << "Panjang linked list: " << length << endl;

    return 0;
}
