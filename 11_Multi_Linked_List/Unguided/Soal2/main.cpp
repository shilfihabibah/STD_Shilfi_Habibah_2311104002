#include <iostream>
#include <string>
using namespace std;

// Kelas Buku untuk menyimpan data buku yang dipinjam
class Buku {
public:
    string judul;
    string tanggal_pengembalian; // Tanggal pengembalian buku
    Buku* next_buku; // Pointer untuk buku berikutnya

    // Konstruktor
    Buku(string judul, string tanggal_pengembalian) {
        this->judul = judul;
        this->tanggal_pengembalian = tanggal_pengembalian;
        this->next_buku = nullptr;
    }
};

// Kelas Anggota untuk menyimpan data anggota dan buku yang dipinjam
class Anggota {
public:
    string nama;
    string id_anggota;
    Buku* head_buku; // Pointer untuk buku pertama yang dipinjam oleh anggota
    Anggota* next_anggota; // Pointer untuk anggota berikutnya

    // Konstruktor
    Anggota(string nama, string id_anggota) {
        this->nama = nama;
        this->id_anggota = id_anggota;
        this->head_buku = nullptr;
        this->next_anggota = nullptr;
    }
};

// Kelas ManajemenPerpustakaan untuk mengelola data anggota dan buku yang dipinjam
class ManajemenPerpustakaan {
public:
    Anggota* head_anggota; // Pointer untuk anggota pertama

    // Konstruktor
    ManajemenPerpustakaan() {
        this->head_anggota = nullptr;
    }

    // Fungsi untuk menambahkan anggota
    void tambah_anggota(string nama, string id_anggota) {
        Anggota* anggota_baru = new Anggota(nama, id_anggota);
        if (!head_anggota) {
            head_anggota = anggota_baru;
        } else {
            Anggota* temp = head_anggota;
            while (temp->next_anggota) {
                temp = temp->next_anggota;
            }
            temp->next_anggota = anggota_baru;
        }
    }

    // Fungsi untuk menambahkan buku yang dipinjam oleh anggota tertentu
    void tambah_buku(string id_anggota, string judul_buku, string tanggal_pengembalian) {
        Anggota* anggota = cari_anggota(id_anggota);
        if (anggota) {
            Buku* buku_baru = new Buku(judul_buku, tanggal_pengembalian);
            if (!anggota->head_buku) {
                anggota->head_buku = buku_baru;
            } else {
                Buku* temp = anggota->head_buku;
                while (temp->next_buku) {
                    temp = temp->next_buku;
                }
                temp->next_buku = buku_baru;
            }
        }
    }

    // Fungsi untuk mencari anggota berdasarkan ID
    Anggota* cari_anggota(string id_anggota) {
        Anggota* temp = head_anggota;
        while (temp) {
            if (temp->id_anggota == id_anggota) {
                return temp;
            }
            temp = temp->next_anggota;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus anggota dan seluruh buku yang dipinjam
    void hapus_anggota(string id_anggota) {
        Anggota* prev = nullptr;
        Anggota* temp = head_anggota;
        while (temp) {
            if (temp->id_anggota == id_anggota) {
                if (prev) {
                    prev->next_anggota = temp->next_anggota;
                } else {
                    head_anggota = temp->next_anggota;
                }
                // Hapus seluruh buku yang dipinjam oleh anggota
                Buku* buku_temp = temp->head_buku;
                while (buku_temp) {
                    Buku* to_delete = buku_temp;
                    buku_temp = buku_temp->next_buku;
                    delete to_delete;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next_anggota;
        }
    }

    // Fungsi untuk menampilkan data anggota dan buku yang dipinjam
    void tampilkan_data() {
        Anggota* temp = head_anggota;
        while (temp) {
            cout << "Anggota: " << temp->nama << ", ID: " << temp->id_anggota << endl;
            Buku* buku_temp = temp->head_buku;
            while (buku_temp) {
                cout << "  Buku: " << buku_temp->judul << ", Tanggal Pengembalian: " << buku_temp->tanggal_pengembalian << endl;
                buku_temp = buku_temp->next_buku;
            }
            temp = temp->next_anggota;
        }
    }
};

int main() {
    // Membuat objek ManajemenPerpustakaan
    ManajemenPerpustakaan manajemen;

    // Menambahkan anggota
    manajemen.tambah_anggota("Rani", "A001");
    manajemen.tambah_anggota("Dito", "A002");
    manajemen.tambah_anggota("Vina", "A003");

    // Menambahkan buku yang dipinjam oleh anggota
    manajemen.tambah_buku("A001", "Pemrograman C++", "01/12/2024");
    manajemen.tambah_buku("A002", "Algoritma Pemrograman", "15/12/2024");
    manajemen.tambah_buku("A003", "Struktur Data", "10/12/2024");

    // Menambahkan buku baru untuk Rani
    manajemen.tambah_buku("A001", "Struktur Data", "10/12/2024");

    // Menghapus anggota Dito beserta buku yang dipinjam
    manajemen.hapus_anggota("A002");

    // Menampilkan seluruh data anggota dan buku yang dipinjam
    manajemen.tampilkan_data();

    return 0;
}
