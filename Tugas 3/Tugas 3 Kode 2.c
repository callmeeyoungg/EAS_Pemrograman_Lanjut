// NOMOR 2
// KELOMPOK 4
#include <stdio.h>

int hasil = 0;

void hitung(int bilangan) {
    hasil += bilangan;
}

int main() {
    int n;
    int f = 0;

    do {
        printf("Masukkan angka (input 9999 untuk mengakhiri): ");
        scanf("%d", &n);
        if (n != 9999) {
            hitung(n);
            f++;
        }
    } while (n != 9999);

    hasil = hasil / f;
    printf("Ini hasilnya bang %d\n", hasil);

    return 0;
}
