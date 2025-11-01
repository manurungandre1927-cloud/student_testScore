#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string namaDepan;
    string namaBelakang;
    int nilaiTes;
    char nilaiHuruf;
};

void inputData(Mahasiswa m[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama depan, nama belakang, dan nilai: ";
        cin >> m[i].namaDepan >> m[i].namaBelakang >> m[i].nilaiTes;
    }
}

void beriNilaiHuruf(Mahasiswa m[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        if (m[i].nilaiTes >= 90) m[i].nilaiHuruf = 'A';
        else if (m[i].nilaiTes >= 80) m[i].nilaiHuruf = 'B';
        else if (m[i].nilaiTes >= 70) m[i].nilaiHuruf = 'C';
        else if (m[i].nilaiTes >= 60) m[i].nilaiHuruf = 'D';
        else m[i].nilaiHuruf = 'F';
    }
}

int cariNilaiTertinggi(Mahasiswa m[], int jumlah) {
    int maxNilai = m[0].nilaiTes;
    for (int i = 1; i < jumlah; i++)
        if (m[i].nilaiTes > maxNilai)
            maxNilai = m[i].nilaiTes;
    return maxNilai;
}

void tampilkanTertinggi(Mahasiswa m[], int jumlah, int nilaiTertinggi) {
    cout << "\nNilai tertinggi: " << nilaiTertinggi << endl;
    cout << "Diperoleh oleh:\n";
    for (int i = 0; i < jumlah; i++)
        if (m[i].nilaiTes == nilaiTertinggi)
            cout << m[i].namaDepan << " " << m[i].namaBelakang << endl;
}

int main() {
    const int jumlah = 20;
    Mahasiswa mhs[jumlah];

    inputData(mhs, jumlah);
    beriNilaiHuruf(mhs, jumlah);

    int tertinggi = cariNilaiTertinggi(mhs, jumlah);
    tampilkanTertinggi(mhs, jumlah, tertinggi);

    cout << "\nData lengkap mahasiswa:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << mhs[i].namaDepan << " "
             << mhs[i].namaBelakang << " "
             << mhs[i].nilaiTes << " "
             << mhs[i].nilaiHuruf << endl;
    }

    return 0;
}
