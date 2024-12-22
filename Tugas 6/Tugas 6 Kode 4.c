#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    FILE *instream;
    char fname[81];
    char buffer[101];
    char *token;
    char *tokens[100];
    int tokenline[100];
    int ntokens = 0;
    int linenum = 0;
    int tnum;

    printf("Masukkan nama file (contoh: npm.txt): ");
    scanf("%80s", fname);

    if ((instream = fopen(fname, "r")) == NULL) {
        printf("Tidak dapat membuka file %s\n", fname);
        exit(-1);
    }

    while (fgets(buffer, sizeof(buffer) - 1, instream) != NULL) {
        linenum++;
        token = strtok(buffer, " \t\n");
        while (token != NULL) {
            tnum = 0;
            while ((tnum < ntokens) && (strcmp(token, tokens[tnum])))
                tnum++;
            if (tnum == ntokens) {
                tokens[tnum] = (char *)calloc(strlen(token) + 1, sizeof(char));
                strcpy(tokens[tnum], token);
                tokenline[tnum] = linenum;
                ntokens++;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    printf("\nOutput Program:\n");
    printf("Nama: Fernando Young\nNPM: 23081010069\n\n");
    for (tnum = 0; tnum < ntokens; tnum++) {
        printf("%s first appears on line %d\n", tokens[tnum], tokenline[tnum]);
    }

    fclose(instream);
}
