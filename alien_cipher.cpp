#include <iostream>

using namespace std;

// Fungsi user-defined untuk mengubah karakter huruf ke nilai angka (1-26)
int getAlphabetValue(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return 0;
}

// Fungsi user-defined untuk mengubah angka kembali ke karakter huruf kapital
char getCharFromValue(int val) {
    while (val > 26) {
        val -= 26;
    }
    while (val < 1) {
        val += 26;
    }
    return (char)(val + 'A' - 1);
}

int main() {
    char message[1000];
    cout << "Masukkan pesan: ";
    cin >> message;

    // Menghitung panjang string secara manual tanpa fungsi strlen() luar
    int len = 0;
    while (message[len] != '\0') {
        len++;
    }

    cout << "Pesan Ter-sandi: ";
    // Huruf pertama tidak mengalami perubahan
    cout << message[0];

    // Proses pergeseran untuk huruf berikutnya
    for (int i = 1; i < len; i++) {
        int prev_val = getAlphabetValue(message[i - 1]);
        int curr_val = getAlphabetValue(message[i]);
        
        int new_val = curr_val + prev_val;
        char encrypted_char = getCharFromValue(new_val);
        
        cout << encrypted_char;
    }
    cout << endl;

    return 0;
}