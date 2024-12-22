// NOMOR 1
// KELOMPOK 4
#include <stdio.h>

void genap(int bilangan) {
    int hasil = 0;
    int angka;
    for (int i = 0; i < bilangan; i++) {
        scanf("%d", &angka);
        if (angka % 2 == 0) {
            hasil++;
        }
    }
    printf("Banyaknya bilangan genap adalah %d\n", hasil);
}

int main() {
    int n;
    printf("Masukkan banyaknya bilangan n: ");
    scanf("%d", &n);
    genap(n);
    return 0;
}
