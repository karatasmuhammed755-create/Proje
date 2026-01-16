#include <stdio.h>


// Muhammed Karataş    
// 2420161109    
//https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=xr4tNKo0y6



int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
    int orta_ind = (ilk_ind + son_ind) / 2;

    if (search == dizi[orta_ind]) {
        return orta_ind;
    }
    else if (search > dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind);
    }
    else if (search < dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1);
    }
    else {
        return -1;
    }
}

void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

void baloncuk_sirala(int dizi[], int BOYUT) {
    int i, j;
    int takas_oldu;

    for (i = 1; i < BOYUT; i++) {
        takas_oldu = 0;
        for (j = 0; j < BOYUT - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                takas(dizi + j, dizi + j + 1);
                takas_oldu = 1;
            }
        }
        printf("iter.%2d: ", i);
        dizi_yazdir(dizi, BOYUT);
        if (takas_oldu == 0) {
            break;
        }
    }
}

int main() {
    int A[] = {98, 41, 60, 58, 8, 5, 48, 15, 72, 69, 52, 3};
    int N = sizeof(A) / sizeof(A[0]);
    int aranan, sonuc;

    printf("Orijinal dizi:\n");
    dizi_yazdir(A, N);

    printf("\nBaloncuk siralama adimlari:\n");
    baloncuk_sirala(A, N);

    printf("\nSiralanmis dizi:\n");
    dizi_yazdir(A, N);

    printf("\nAramak istediginiz deger: ");
    scanf("%d", &aranan);

    sonuc = ikili_arama(A, N, aranan, 0, N - 1);

    if (sonuc == -1) {
        printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
    }
    else {
        printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);
    }

    return 0;
}
