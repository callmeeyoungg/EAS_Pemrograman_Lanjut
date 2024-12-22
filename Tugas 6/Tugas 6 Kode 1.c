#include <stdio.h>
#include <string.h>

void main() {
    char fname[81];
    char prevline[101] = "";
    char buffer[101] = "";
    FILE *instream;

    printf("Masukkan nama file yang akan diperiksa: ");
    scanf("%80s", fname);

    if ((instream = fopen(fname, "r")) == NULL) {
        printf("Tidak dapat membuka file %s\n", fname);
        exit(-1);
    }

    while (fgets(buffer, sizeof(buffer) - 1, instream) != NULL) {
        if (!strcmp(buffer, prevline))
            printf("Baris duplikat ditemukan: %s", buffer);
        else if (!strncmp(buffer, prevline, 10))
            printf("Awal baris sama:\n %s %s", prevline, buffer);
        strcpy(prevline, buffer);
    }

    fclose(instream);
}
