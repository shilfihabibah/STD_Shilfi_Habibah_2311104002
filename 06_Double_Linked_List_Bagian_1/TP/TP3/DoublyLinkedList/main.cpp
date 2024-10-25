#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Menambahkan elemen di akhir list
    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {  // Jika list kosong
            newNode->prev = nullptr;
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

    // Menampilkan elemen dari depan ke belakang
    void displayForward() {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }
        Node* temp = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Menampilkan elemen dari belakang ke depan
    void displayBackward() {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }
        Node* temp = head;
        // Mencari node terakhir
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "Daftar elemen dari belakang ke depan: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Menambahkan 4 elemen ke dalam list
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);

    // Tampilkan elemen dari depan ke belakang
    dll.displayForward();

    // Tampilkan elemen dari belakang ke depan
    dll.displayBackward();

    return 0;
}
