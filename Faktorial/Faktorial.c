#include <stdio.h>

int main() {
    int angka, faktorial = 1;

    printf("Masukkan angka: ");
    scanf("%d", &angka);

    if (angka < 0) {
        printf("Faktorial tidak didefinisikan untuk bilangan negatif.\n");
    } else {
        for (int i = 1; i <= angka; i++) {
            faktorial *= i;
        }
        printf("Faktorial dari %d adalah %d\n", angka, faktorial);
    }

    return 0;
}
