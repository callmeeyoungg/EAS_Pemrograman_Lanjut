#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Implementasi insertion sort dengan fokus pada kolom tertentu
void insertionSort(Mahasiswa m[], int n, int type) {
    int i, j;
    Mahasiswa key;

    for (i = 1; i < n; i++) {
        key = m[i];
        j = i - 1;

        // Pengurutan berdasarkan tipe yang dipilih
        while (j >= 0 && ((type == 1 && strcmp(m[j].nama, key.nama) > 0) ||
                          (type == 2 && strcmp(m[j].npm, key.npm) > 0) ||
                          (type == 3 && m[j].ipk > key.ipk) ||
                          (type == 4 && strcmp(m[j].programStudi, key.programStudi) > 0))) {
            m[j + 1] = m[j];
            j = j - 1;
        }
        m[j + 1] = key;
    }
}

// Implementasi selection sort dengan fokus pada kolom tertentu
void selectionSort(Mahasiswa m[], int n, int type) {
    int i, j, min_idx;
    Mahasiswa temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if ((type == 1 && strcmp(m[j].nama, m[min_idx].nama) < 0) ||
                (type == 2 && strcmp(m[j].npm, m[min_idx].npm) < 0) ||
                (type == 3 && m[j].ipk < m[min_idx].ipk) ||
                (type == 4 && strcmp(m[j].programStudi, m[min_idx].programStudi) < 0)) {
                min_idx = j;
            }
        }
        temp = m[min_idx];
        m[min_idx] = m[i];
        m[i] = temp;
    }
}

// Fungsi untuk menampilkan data
void displayData(Mahasiswa m[], int count, int sortType, int type) {
    if (sortType == 1) {
        insertionSort(m, count, type);
    } else {
        selectionSort(m, count, type);
    }

    printf("\nData Mahasiswa Terurut:\n");
    for (int i = 0; i < count; i++) {
        switch (type) {
        case 1:
            printf("%s\n", m[i].nama);
            break;
        case 2:
            printf("%s\n", m[i].npm);
            break;
        case 3:
            printf("%.2f\n", m[i].ipk);
            break;
        case 4:
            printf("%s\n", m[i].programStudi);
            break;
        }
    }
}

int main() {
    Mahasiswa m[100]; // Asumsikan maksimal 100 mahasiswa
    int count = 0;
    int choice, displayType, type;

    while (1) {
        printf("\nMenu Manajemen Data Mahasiswa\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Membersihkan buffer setelah input

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
            printf("Pilih metode sorting:\n");
            printf("1. Insertion Sort\n");
            printf("2. Selection Sort\n");
            printf("Masukkan pilihan metode: ");
            scanf("%d", &displayType);
            clearInputBuffer();
            printf("Pilih kolom untuk tampilan:\n");
            printf("1. Nama\n");
            printf("2. NPM\n");
            printf("3. IPK\n");
            printf("4. Program Studi\n");
            printf("Masukkan pilihan Anda: ");
            scanf("%d", &type);
            clearInputBuffer();
            displayData(m, count, displayType, type);
            break;

        case 3:
            printf("Program selesai.\n");
            return 0;

        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
