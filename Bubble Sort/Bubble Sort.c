#include <stdio.h>

int main() {
    int angka[] = {22, 10, 15, 3, 8, 2}; // Array yang akan diurutkan
    int n = sizeof(angka) / sizeof(angka[0]); // Menghitung jumlah elemen

    for (int i = 0; i < n - 1; i++) {
        int flag = 0; // Flag untuk mengecek apakah ada pertukaran
        for (int j = 0; j < n - i - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                // Tukar jika elemen yang ditemukan lebih besar
                int temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
                flag = 1; // Set flag jika pertukaran terjadi
            }
        }
        // Jika tidak ada pertukaran, array sudah terurut
        if (flag == 0) break;
    }

    // Menampilkan array yang terurut
    printf("Angka Sebelumnya: 22, 10, 15, 3, 8, 2\n\n");
    printf("Angka yang terurut:\n");
    for (int i = 0; i < n; i++) 
        printf("%d ", angka[i]); // Menampilkan array yang terurut

    printf("\n");

    return 0; // Mengembalikan nilai 0
}
