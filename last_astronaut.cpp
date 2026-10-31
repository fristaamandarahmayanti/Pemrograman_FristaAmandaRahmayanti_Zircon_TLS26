#include <iostream>

using namespace std;

// Fungsi user-defined untuk menghitung jumlah astronot yang masih aktif
int hitungAktif(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan nilai awal K: ";
    cin >> k;

    int astronauts[1000]; // Asumsi maksimal 1000 astronot
    for (int i = 0; i < n; i++) {
        astronauts[i] = 1; // 1 = aktif, 0 = tereliminasi
    }

    int current_pos = 0;
    cout << "Urutan eliminasi: ";

    while (hitungAktif(astronauts, n) > 1) {
        int count = 0;
        while (count < k) {
            if (astronauts[current_pos] == 1) {
                count++;
            }
            if (count < k) {
                current_pos = (current_pos + 1) % n;
            }
        }

        // Eliminasi astronot pada posisi saat ini
        astronauts[current_pos] = 0;
        int eliminated_num = current_pos + 1;
        cout << eliminated_num << " ";

        // Aturan perubahan nilai K
        if (eliminated_num % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }

        // K tidak boleh kurang dari 2
        if (k < 2) {
            k = 2;
        }

        // Geser pointer ke astronot aktif berikutnya
        while (astronauts[current_pos] == 0) {
            current_pos = (current_pos + 1) % n;
        }
    }

    // Mencari astronot terakhir yang bertahan
    int last_astronaut = 0;
    for (int i = 0; i < n; i++) {
        if (astronauts[i] == 1) {
            last_astronaut = i + 1;
            break;
        }
    }

    cout << "\nAstronot terakhir yang bertahan: " << last_astronaut << endl;
    return 0;
}