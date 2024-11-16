#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

// Variabel global
Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
bool isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "Node " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "Pohon sudah dibuat." << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (!node || node->left != NULL) {
        cout << "Child kiri sudah ada atau node tidak valid!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
    if (!node || node->right != NULL) {
        cout << "Child kanan sudah ada atau node tidak valid!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Tampilkan Child dan Descendant
void tampilkanChild(Pohon *node) {
    if (!node) {
        cout << "Node tidak valid!" << endl;
        return;
    }
    cout << "Child dari node " << node->data << ": ";
    if (node->left) cout << "Kiri: " << node->left->data << " ";
    if (node->right) cout << "Kanan: " << node->right->data << " ";
    if (!node->left && !node->right) cout << "(tidak ada child)";
    cout << endl;
}

void tampilkanDescendant(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << node->left->data << " ";
        tampilkanDescendant(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        tampilkanDescendant(node->right);
    }
}

// Periksa Properti BST
bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Hitung Simpul Daun
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Fungsi main
int main() {
    init();
    int pilihan;
    char data, parent;
    Pohon *node;

    do {
        cout << "\n=== Menu Binary Tree ===\n";
        cout << "1. Buat Root\n";
        cout << "2. Tambah Child Kiri\n";
        cout << "3. Tambah Child Kanan\n";
        cout << "4. Tampilkan Child\n";
        cout << "5. Tampilkan Descendant\n";
        cout << "6. Periksa Properti BST\n";
        cout << "7. Hitung Simpul Daun\n";
        cout << "8. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            if (isEmpty()) {
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
            } else {
                cout << "Root sudah ada!" << endl;
            }
            break;

        case 2:
            cout << "Masukkan data parent: ";
            cin >> parent;
            cout << "Masukkan data child kiri: ";
            cin >> data;
            node = root;
            while (node && node->data != parent) {
                node = node->left ? node->left : node->right;
            }
            if (node) insertLeft(data, node);
            else cout << "Parent tidak ditemukan!" << endl;
            break;

        case 3:
            cout << "Masukkan data parent: ";
            cin >> parent;
            cout << "Masukkan data child kanan: ";
            cin >> data;
            node = root;
            while (node && node->data != parent) {
                node = node->left ? node->left : node->right;
            }
            if (node) insertRight(data, node);
            else cout << "Parent tidak ditemukan!" << endl;
            break;

        case 4:
            cout << "Masukkan data node: ";
            cin >> parent;
            node = root;
            while (node && node->data != parent) {
                node = node->left ? node->left : node->right;
            }
            if (node) tampilkanChild(node);
            else cout << "Node tidak ditemukan!" << endl;
            break;

        case 5:
            cout << "Masukkan data node: ";
            cin >> parent;
            node = root;
            while (node && node->data != parent) {
                node = node->left ? node->left : node->right;
            }
            if (node) {
                cout << "Descendant dari node " << node->data << ": ";
                tampilkanDescendant(node);
                cout << endl;
            } else {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;

        case 6:
            cout << "Memeriksa apakah pohon valid BST...\n";
            cout << (is_valid_bst(root, CHAR_MIN, CHAR_MAX) ? "Valid" : "Tidak valid") << endl;
            break;

        case 7:
            cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
            break;

        case 8:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (pilihan != 8);

    return 0;
}
