#include <stdio.h>
#include <string.h>

void main() {
    FILE *instream;
    FILE *outstream;
    char basefname[81];
    char readfname[101];
    char savefname[81];
    char buffer[101];
    int fnum;

    printf("Masukkan nama prefix untuk file yang akan dipindah (contoh: data): ");
    scanf("%80s", basefname);

    printf("Masukkan nama file untuk menyimpan outputnya (contoh: output.txt): ");
    scanf("%80s", savefname);

    if ((outstream = fopen(savefname, "w")) == NULL) {
        printf("Tidak dapat membuka %s\n", savefname);
        exit(-1);
    }

    for (fnum = 0; fnum < 2; fnum++) {
        sprintf(readfname, "%s.%d", basefname, fnum);
        if ((instream = fopen(readfname, "r")) == NULL) {
            printf("Tidak dapat membuka file input %s\n", readfname);
            exit(-1);
        }

        while (fgets(buffer, sizeof(buffer) - 1, instream) != NULL) {
            fputs(buffer, outstream);
        }

        fclose(instream);
    }

    fclose(outstream);
}
