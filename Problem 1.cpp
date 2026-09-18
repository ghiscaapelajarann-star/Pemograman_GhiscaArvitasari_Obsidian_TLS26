#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;

    // Input jumlah astronaut dan nilai hitungan awal
    cout << "Masukkan jumlah astronaut (N): ";
    cin >> N;

    cout << "Masukkan nilai hitungan awal (K): ";
    cin >> K;

    // Membuat list astronaut 1 sampai N
    vector<int> astronaut;

    for (int i = 1; i <= N; i++) {
        astronaut.push_back(i);
    }

    int posisi = 0;

    cout << "\nUrutan eliminasi: ";

    // Proses eliminasi sampai tersisa 1 astronaut
    while (astronaut.size() > 1) {

        // Menentukan posisi astronaut yang akan dieliminasi
        posisi = (posisi + K - 1) % astronaut.size();

        // Mengambil nomor astronaut
        int nomor = astronaut[posisi];

        // Menampilkan astronaut yang dieliminasi
        cout << nomor << " ";

        // Menghapus astronaut
        astronaut.erase(astronaut.begin() + posisi);

        // Mengecek nomor astronaut genap atau tidak
        if (nomor % 2 == 0) {
            // Jika genap, K bertambah 2
            K = K + 2;
        } else {
            // Jika ganjil, K berkurang 1
            K = K - 1;
        }

        // Jika K kurang dari 1, kembalikan menjadi 1
        if (K < 1) {
            K = 1;
        }

        // Posisi berikutnya adalah astronaut setelah yang dieliminasi
        if (posisi >= astronaut.size()) {
            posisi = 0;
        }
    }

    // Menampilkan astronaut terakhir
    cout << "\nAstronaut terakhir yang tersisa: "
         << astronaut[0] << endl;

    return 0;
}