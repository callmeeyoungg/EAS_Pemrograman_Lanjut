#include <stdio.h>
#include <string.h>

void main() {
    char fname[81];
    char buffer[101];
    char curraddress[201] = "";
    FILE *instream;
    int first = 1;

    printf("Masukkan file alamat: ");
    scanf("%80s", fname);

    if ((instream = fopen(fname, "r")) == NULL) {
        printf("Tidak dapat membuka file %s\n", fname);
        exit(-1);
    }

    while (fgets(buffer, sizeof(buffer) - 1, instream) != NULL) {
        if (buffer[0] == '*') {
            printf("Alamat: %s\n", curraddress);
            strcpy(curraddress, "");
            first = 1;
        } else {
            if (first) 
                first = 0;
            else 
                strcat(curraddress, ", ");
            strncat(curraddress, buffer, strlen(buffer) - 1);
        }
    }

    fclose(instream);
}
