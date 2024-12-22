#include <stdio.h>
#include <string.h>

void main() {
    char fname[81];
    char buffer[101];
    char noncom[101];
    FILE *instream;
    char *loc;

    printf("Masukkan nama file: ");
    scanf("%80s", fname);

    if ((instream = fopen(fname, "r")) == NULL) {
        printf("Tidak dapat membuka file %s\n", fname);
        exit(-1);
    }

    while (fgets(buffer, sizeof(buffer) - 1, instream) != NULL) {
        if ((loc = strchr(buffer, '%')) != NULL) {
            strncpy(noncom, buffer, loc - buffer);
            noncom[loc - buffer] = '\0';
            printf("%s\n", noncom);
        } else {
            printf("%s", buffer);
        }
    }

    fclose(instream);
}
