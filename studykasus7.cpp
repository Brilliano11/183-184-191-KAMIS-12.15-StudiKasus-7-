#include <iostream>
using namespace std;

class Mahasiswa {
public:
    string nama;
    string nim;
    string prodi;
    string no_telp;

    void inputData() {
        cout << "| Masukkan Nama Mahasiswa : ";
        cin >> nama;
        cout << "| Masukkan NIM : ";
        cin >> nim;
        cout << "| Masukkan Prodi : ";
        cin >> prodi;
        cout << "| Masukkan No. Telp : ";
        cin >> no_telp;
    }

    void tampilkanData() {
        cout << "| Nama       : " << nama << endl;
        cout << "| NIM        : " << nim << endl;
        cout << "| Prodi      : " << prodi << endl;
        cout << "| No. Telp   : " << no_telp << endl;
        cout << "+================================+" << endl;
    }
};

void urutkanAscending(Mahasiswa mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (mahasiswa[i].nim > mahasiswa[j].nim) {
                Mahasiswa temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

void urutkanDescending(Mahasiswa mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (mahasiswa[i].nim < mahasiswa[j].nim) {
                Mahasiswa temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

void cariMahasiswa(Mahasiswa mahasiswa[], int jumlah, string nimCari) {
    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (mahasiswa[i].nim == nimCari) {
            mahasiswa[i].tampilkanData();
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "| Mahasiswa dengan NIM " << nimCari << " tidak ditemukan!" << endl;
    }
}

void tampilkanMenu() {
    cout << "+================================+" << endl;
    cout << "|              MENU              |" << endl;
    cout << "+================================+" << endl;
    cout << "| 1. Input Data Mahasiswa        |" << endl;
    cout << "| 2. Tampilkan Data Mahasiswa    |" << endl;
    cout << "| 3. Urutkan Data NIM Ascending |" << endl;
    cout << "| 4. Urutkan Data NIM Descending|"<< endl;
    cout << "| 5. Cari Mahasiswa Berdasarkan NIM |" << endl;
    cout << "| 6. Keluar                      |" << endl;
    cout << "+================================+" << endl;
    cout << "| Masukkan Pilihan : ";
}

int main() {
    int jumlahMahasiswa;
    cout << "Masukkan jumlah Mahasiswa : ";
    cin >> jumlahMahasiswa;

    Mahasiswa mahasiswa[jumlahMahasiswa];
    int pilihan;
    string nimCari;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                for (int i = 0; i < jumlahMahasiswa; i++) {
                    mahasiswa[i].inputData();
                }
                break;
            case 2:
                cout << "+================================+" << endl;
                cout << "|        DATA MAHASISWA          |" << endl;
                cout << "+================================+" << endl;
                for (int i = 0; i < jumlahMahasiswa; i++) {
                    mahasiswa[i].tampilkanData();
                }
                break;
            case 3:
                urutkanAscending(mahasiswa, jumlahMahasiswa);
                cout << "| Data NIM berhasil diurutkan secara Ascending! |" << endl;
                break;
            case 4:
                urutkanDescending(mahasiswa, jumlahMahasiswa);
                cout << "| Data NIM berhasil diurutkan secara Descending! |" << endl;
                break;
            case 5:
                cout << "| Masukkan NIM yang ingin dicari: ";
                cin >> nimCari;
                cariMahasiswa(mahasiswa, jumlahMahasiswa, nimCari);
                break;
            case 6:
                cout << "Terima Kasih" << endl;
                break;
            default:
                cout << "| Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}

