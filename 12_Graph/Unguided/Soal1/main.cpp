#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {
    int n; // Jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> kota(n);
    vector<vector<int>> graf(n, vector<int>(n, 0)); // Matriks adjacency

    // Input nama-nama kota
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama kota untuk simpul " << i + 1 << ": ";
        cin >> kota[i];
    }

    // Input bobot antar simpul
    cout << "\nMasukkan bobot antar simpul (masukkan 0 jika tidak ada hubungan):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << kota[i] << " --> " << kota[j] << ": ";
            cin >> graf[i][j];
        }
    }

    // Cetak matriks bobot
    cout << "\nMatriks Bobot:\n\t";
    for (int i = 0; i < n; i++) {
        cout << kota[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << kota[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << graf[i][j] << "\t";
        }
        cout << endl;
    }

    // Menghitung jarak antara dua kota
    string asal, tujuan;
    cout << "\nMasukkan nama kota asal: ";
    cin >> asal;
    cout << "Masukkan nama kota tujuan: ";
    cin >> tujuan;

    int idx_asal = -1, idx_tujuan = -1;

    // Cari indeks kota asal dan tujuan
    for (int i = 0; i < n; i++) {
        if (kota[i] == asal) {
            idx_asal = i;
        }
        if (kota[i] == tujuan) {
            idx_tujuan = i;
        }
    }

    // Validasi input kota
    if (idx_asal == -1 || idx_tujuan == -1) {
        cout << "Kota yang dimasukkan tidak valid.\n";
    } else {
        cout << "Jarak dari " << asal << " ke " << tujuan << " adalah: "
             << graf[idx_asal][idx_tujuan] << endl;
    }

    return 0;
}
