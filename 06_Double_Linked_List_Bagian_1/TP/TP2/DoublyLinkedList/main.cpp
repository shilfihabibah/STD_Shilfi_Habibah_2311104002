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

    // Menghapus elemen pertama
    void deleteFirst_2311104002() {
        if (head == nullptr) {
            cout << "List kosong, tidak ada elemen yang bisa dihapus.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    // Menghapus elemen terakhir
    void deleteLast_2311104002() {
        if (head == nullptr) {
            cout << "List kosong, tidak ada elemen yang bisa dihapus.\n";
            return;
        }
        Node* temp = head;
        if (temp->next == nullptr) { // Hanya satu elemen dalam list
            head = nullptr;
            delete temp;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    // Menampilkan elemen-elemen dalam list
    void display() {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }
        Node* temp = head;
        cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(10);
    dll.append(15);
    dll.append(20);

    // Hapus elemen pertama dan terakhir
    dll.deleteFirst_2311104002();
    dll.deleteLast_2311104002();

    // Tampilkan elemen setelah penghapusan
    dll.display();

    return 0;
}
