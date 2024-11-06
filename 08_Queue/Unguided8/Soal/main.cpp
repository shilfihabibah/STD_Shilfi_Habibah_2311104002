#include <iostream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Node {
    string nama;
    int nim;
    Node* next;
};

Node* front = nullptr; // Front of the queue
Node* back = nullptr;  // Back of the queue

// Check if the queue is empty
bool isEmpty() {
    return front == nullptr;
}

// Enqueue function with priority based on NIM
void enqueueAntrian(string nama, int nim) {
    Node* newNode = new Node{nama, nim, nullptr};

    if (isEmpty()) {
        // First element in the queue
        front = back = newNode;
    } else {
        // Insert node in order based on NIM
        if (nim < front->nim) {
            // Insert new node at the front if it has the smallest NIM
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse to find correct position based on NIM
            Node* current = front;
            while (current->next != nullptr && current->next->nim < nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;

            // Update back pointer if we insert at the end
            if (newNode->next == nullptr) {
                back = newNode;
            }
        }
    }
}


// Dequeue function (removes the front element)
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;

        // If the queue becomes empty, reset back to null
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

// Count elements in the queue
int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Clear the queue
void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

// Display all elements in the queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            i++;
        }
    }
}

int main() {
    int n, nim;
    string nama;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nama Mahasiswa: ";
        cin >> nama;
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> nim;
        enqueueAntrian(nama, nim);
    }

    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    // Example of dequeuing and viewing the queue again
    cout << "Menghapus antrian terdepan..." << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    cout << "Mengosongkan antrian..." << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
