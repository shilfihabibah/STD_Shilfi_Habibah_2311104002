#include <iostream>
#include <string>
using namespace std;

// Kelas Proyek untuk menyimpan data proyek
class Proyek {
public:
    string nama;
    int durasi; // Durasi proyek dalam bulan
    Proyek* next_proyek; // Pointer untuk proyek berikutnya

    // Konstruktor
    Proyek(string nama, int durasi) {
        this->nama = nama;
        this->durasi = durasi;
        this->next_proyek = nullptr;
    }
};

// Kelas Pegawai untuk menyimpan data pegawai dan proyek yang dikelola
class Pegawai {
public:
    string nama;
    string id_pegawai;
    Proyek* head_proyek; // Pointer untuk proyek pertama yang dikelola pegawai
    Pegawai* next_pegawai; // Pointer untuk pegawai berikutnya

    // Konstruktor
    Pegawai(string nama, string id_pegawai) {
        this->nama = nama;
        this->id_pegawai = id_pegawai;
        this->head_proyek = nullptr;
        this->next_pegawai = nullptr;
    }
};

// Kelas ManajemenData untuk mengelola data pegawai dan proyek
class ManajemenData {
public:
    Pegawai* head_pegawai; // Pointer untuk pegawai pertama

    // Konstruktor
    ManajemenData() {
        this->head_pegawai = nullptr;
    }

    // Fungsi untuk menambahkan pegawai
    void tambah_pegawai(string nama, string id_pegawai) {
        Pegawai* pegawai_baru = new Pegawai(nama, id_pegawai);
        if (!head_pegawai) {
            head_pegawai = pegawai_baru;
        } else {
            Pegawai* temp = head_pegawai;
            while (temp->next_pegawai) {
                temp = temp->next_pegawai;
            }
            temp->next_pegawai = pegawai_baru;
        }
    }

    // Fungsi untuk menambahkan proyek ke pegawai tertentu
    void tambah_proyek(string id_pegawai, string nama_proyek, int durasi) {
        Pegawai* pegawai = cari_pegawai(id_pegawai);
        if (pegawai) {
            Proyek* proyek_baru = new Proyek(nama_proyek, durasi);
            if (!pegawai->head_proyek) {
                pegawai->head_proyek = proyek_baru;
            } else {
                Proyek* temp = pegawai->head_proyek;
                while (temp->next_proyek) {
                    temp = temp->next_proyek;
                }
                temp->next_proyek = proyek_baru;
            }
        }
    }

    // Fungsi untuk mencari pegawai berdasarkan ID
    Pegawai* cari_pegawai(string id_pegawai) {
        Pegawai* temp = head_pegawai;
        while (temp) {
            if (temp->id_pegawai == id_pegawai) {
                return temp;
            }
            temp = temp->next_pegawai;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus proyek berdasarkan nama dari pegawai tertentu
    void hapus_proyek(string id_pegawai, string nama_proyek) {
        Pegawai* pegawai = cari_pegawai(id_pegawai);
        if (pegawai) {
            Proyek* prev = nullptr;
            Proyek* temp = pegawai->head_proyek;
            while (temp) {
                if (temp->nama == nama_proyek) {
                    if (prev) {
                        prev->next_proyek = temp->next_proyek;
                    } else {
                        pegawai->head_proyek = temp->next_proyek;
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next_proyek;
            }
        }
    }

    // Fungsi untuk menampilkan data pegawai dan proyek mereka
    void tampilkan_data() {
        Pegawai* temp = head_pegawai;
        while (temp) {
            cout << "Pegawai: " << temp->nama << ", ID: " << temp->id_pegawai << endl;
            Proyek* proyek_temp = temp->head_proyek;
            while (proyek_temp) {
                cout << "  Proyek: " << proyek_temp->nama << ", Durasi: " << proyek_temp->durasi << " bulan" << endl;
                proyek_temp = proyek_temp->next_proyek;
            }
            temp = temp->next_pegawai;
        }
    }
};

int main() {
    // Membuat objek ManajemenData
    ManajemenData manajemen;

    // Menambahkan pegawai
    manajemen.tambah_pegawai("Andi", "P001");
    manajemen.tambah_pegawai("Budi", "P002");
    manajemen.tambah_pegawai("Citra", "P003");

    // Menambahkan proyek untuk masing-masing pegawai
    manajemen.tambah_proyek("P001", "Aplikasi Mobile", 12);
    manajemen.tambah_proyek("P002", "Sistem Akuntansi", 8);
    manajemen.tambah_proyek("P003", "E-commerce", 10);

    // Menambahkan proyek baru untuk Andi
    manajemen.tambah_proyek("P001", "Analisis Data", 6);

    // Menghapus proyek "Aplikasi Mobile" dari Andi
    manajemen.hapus_proyek("P001", "Aplikasi Mobile");

    // Menampilkan data pegawai dan proyek mereka
    manajemen.tampilkan_data();

    return 0;
}
