#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nama[100];
    char npm[20];
    float ipk;
    char programStudi[50];
} Mahasiswa;

// Fungsi untuk membersihkan buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Fungsi untuk memasukkan data mahasiswa
void inputData(Mahasiswa *m) {
    printf("Masukkan nama mahasiswa: ");
    fgets(m->nama, sizeof(m->nama), stdin);
    m->nama[strcspn(m->nama, "\n")] = 0; // Menghilangkan newline

    printf("Masukkan NPM mahasiswa: ");
    fgets(m->npm, sizeof(m->npm), stdin);
    m->npm[strcspn(m->npm, "\n")] = 0;

    printf("Masukkan IPK mahasiswa: ");
    scanf("%f", &m->ipk);
    clearInputBuffer(); // Membersihkan buffer

    printf("Masukkan Program Studi: ");
    fgets(m->programStudi, sizeof(m->programStudi), stdin);
    m->programStudi[strcspn(m->programStudi, "\n")] = 0;
}

// Fungsi untuk menampilkan data mahasiswa
void displayData(Mahasiswa m[], int count) {
    printf("\nData Mahasiswa:\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s\n", m[i].nama);
        printf("NPM: %s\n", m[i].npm);
        printf("IPK: %.2f\n", m[i].ipk);
        printf("Program Studi: %s\n\n", m[i].programStudi);
    }
}

// Fungsi Jump Search berdasarkan nama
int jumpSearchByName(Mahasiswa m[], int count, char *target) {
    int step = sqrt(count);
    int prev = 0;

    while (prev < count && strcmp(m[(step < count ? step : count) - 1].nama, target) < 0) {
        prev = step;
        step += sqrt(count);
        if (prev >= count) {
            return -1;
        }
    }

    for (int i = prev; i < (step < count ? step : count); i++) {
        if (strcmp(m[i].nama, target) == 0) {
            return i;
        }
    }

    return -1;
}

// Fungsi Jump Search berdasarkan NPM
int jumpSearchByNPM(Mahasiswa m[], int count, char *target) {
    int step = sqrt(count);
    int prev = 0;

    while (prev < count && strcmp(m[(step < count ? step : count) - 1].npm, target) < 0) {
        prev = step;
        step += sqrt(count);
        if (prev >= count) {
            return -1;
        }
    }

    for (int i = prev; i < (step < count ? step : count); i++) {
        if (strcmp(m[i].npm, target) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Mahasiswa m[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\nMenu Manajemen Data Mahasiswa\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data\n");
        printf("3. Cari Mahasiswa (Jump Search)\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
        case 1:
            if (count < 100) {
                inputData(&m[count]);
                count++;
            } else {
                printf("Kapasitas Data Penuh!\n");
            }
            break;

        case 2:
            displayData(m, count);
            break;

        case 3: {
            if (count == 0) {
                printf("Belum ada data mahasiswa.\n");
                break;
            }

            int searchType;
            printf("Pilih metode pencarian:\n");
            printf("1. Berdasarkan Nama\n");
            printf("2. Berdasarkan NPM\n");
            printf("Masukkan pilihan Anda: ");
            scanf("%d", &searchType);
            clearInputBuffer();

            if (searchType == 1) {
                char target[100];
                printf("Masukkan nama mahasiswa yang dicari: ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = 0;

                int result = jumpSearchByName(m, count, target);
                if (result != -1) {
                    printf("Mahasiswa ditemukan:\n");
                    printf("Nama: %s\n", m[result].nama);
                    printf("NPM: %s\n", m[result].npm);
                    printf("IPK: %.2f\n", m[result].ipk);
                    printf("Program Studi: %s\n", m[result].programStudi);
                } else {
                    printf("Mahasiswa dengan nama \"%s\" tidak ditemukan.\n", target);
                }
            } else if (searchType == 2) {
                char target[20];
                printf("Masukkan NPM mahasiswa yang dicari: ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = 0;

                int result = jumpSearchByNPM(m, count, target);
                if (result != -1) {
                    printf("Mahasiswa ditemukan:\n");
                    printf("Nama: %s\n", m[result].nama);
                    printf("NPM: %s\n", m[result].npm);
                    printf("IPK: %.2f\n", m[result].ipk);
                    printf("Program Studi: %s\n", m[result].programStudi);
                } else {
                    printf("Mahasiswa dengan NPM \"%s\" tidak ditemukan.\n", target);
                }
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        }

        case 4:
            printf("Keluar dari program.\n");
            return 0;

        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
    }

    return 0;
}
