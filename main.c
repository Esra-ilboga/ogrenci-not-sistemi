#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_OGR 100

// Baþlatma
int N, S;
double B, D;
char cevap_anahtari[MAX_OGR];
char ogrenci_cevaplari[MAX_OGR][MAX_OGR];
double HBN[MAX_OGR];
double ortalama = 0.0;
double standart_sapma = 0.0;
double T_skoru[MAX_OGR];

// Rastgele cevap anahtari üretme
void cevap_anahtari_uret(char cevap_anahtari[], int S) {
    for (int i = 0; i < S; i++) {
        cevap_anahtari[i] = 'A' + rand() % 4; // A, B, C veya D
    }
}

// Rastgele ögrenci cevaplari olusturma
void sinavi_uygula(char ogrenci_cevaplari[][MAX_OGR], char cevap_anahtari[], int N, int S, double B, double D) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S; j++) {
            double rastgele_deger = ((double)rand() / (double)RAND_MAX);

            if (rastgele_deger < B) { // Bos biirakma ihtimali
                ogrenci_cevaplari[i][j] = '-'; // Boþ cevap
            } else if (rastgele_deger < B + D) { // Dogru cevap ihtimali
                ogrenci_cevaplari[i][j] = cevap_anahtari[j]; // Dogru cevap
            } else { // Yanlis cevap ihtimali
                char yanlis_cevap;
                do {
                    yanlis_cevap = 'A' + rand() % 4;
                } while (yanlis_cevap == cevap_anahtari[j]); // Yanlis cevap
                ogrenci_cevaplari[i][j] = yanlis_cevap;
            }
        }
    }
}

// Öðrenci cevaplarini yazdirma
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][MAX_OGR], int N, int S) {
    for (int i = 0; i < N; i++) {
        printf("Öðrenci %d: ", i + 1);
        for (int j = 0; j < S; j++) {
            printf("%d = %c | ", j + 1, ogrenci_cevaplari[i][j]);
        }
        printf("\n");
    }
}

// Öðrencilerin puanlarini hesaplama
void ogrencileri_puanla(char ogrenci_cevaplari[][MAX_OGR], char cevap_anahtari[], double HBN[], int N, int S) {
    for (int i = 0; i < N; i++) {
        double puan = 0;
        for (int j = 0; j < S; j++) {
            if (ogrenci_cevaplari[i][j] == cevap_anahtari[j]) {
                puan += 100.0 / S; // Doðru cevaplar için
            } else if (ogrenci_cevaplari[i][j] == '-') {
                // Bos cevaplar için bir sey yapilmaz
            } else {
                puan -= 25.0 / S; // Yanlis cevaplar için
            }
        }
        HBN[i] = puan;
    }
}

// Sýnýf ortalamasini hesaplama
double sinif_ortalamasi_hesapla(double HBN[], int N) {
    double toplam = 0;
    for (int i = 0; i < N; i++) {
        toplam += HBN[i];
    }
    return toplam / N; // Sinif ortalamasi
}

// Standart sapmayi hesaplama
double standart_sapma_hesapla(double ortalama, double HBN[], int N) {
    double toplam = 0;
    for (int i = 0; i < N; i++) {
        toplam += pow(HBN[i] - ortalama, 2.0); // Kare farklarin toplami
    }
    return sqrt(toplam / N); // Standart sapma
}

// T-skoru hesaplama ve harf notlari
void T_skoru_hesapla(double ortalama, double HBN[], int N, double standart_sapma, double T_skoru[]) {
    for (int i = 0; i < N; i++) {
        T_skoru[i] = 60 + 10 * ((HBN[i] - ortalama) / standart_sapma);
        printf("Ogrenci %d - T-skoru: %.2f - ", i + 1, T_skoru[i]);

        // Harf notunu belirle
        double skor = T_skoru[i]; // Harf notu hesaplamasi için skoru kullan

        if ((ortalama > 80) && (ortalama <= 100)) {
            if (skor >= 67) {
                printf("Harf notu: AA\n");
            } else if ((skor <= 66.99) && (skor > 62)) {
                printf("Harf notu: BA\n");
            } else if ((skor <= 61.99) && (skor > 57)) {
                printf("Harf notu: BB\n");
            } else if ((skor <= 56.99) && (skor > 52)) {
                printf("Harf notu: CB\n");
            } else if ((skor <= 51.99) && (skor > 47)) {
                printf("Harf notu: CC\n");
            } else if ((skor <= 46.99) && (skor > 42)) {
                printf("Harf notu: DC\n");
            } else if ((skor <= 41.99) && (skor > 37)) {
                printf("Harf notu: DD\n");
            } else if ((skor <= 36.99) && (skor > 32)) {
                printf("Harf notu: FD\n");
            } else {
                printf("Harf notu: FF\n");
            }
        } else if ((ortalama > 70) && (ortalama <= 80)) {
            if (skor >= 69) {
                printf("Harf notu: AA\n");
            } else if ((skor <= 68.99) && (skor > 64)) {
                printf("Harf notu: BA\n");
            } else if ((skor <= 63.99) && (skor > 59)) {
                printf("Harf notu: BB\n");
            } else if ((skor <= 58.99) && (skor > 54)) {
                printf("Harf notu: CB\n");
            } else if ((skor <= 53.99) && (skor > 49)) {
                printf("Harf notu: CC\n");
            } else if ((skor <= 48.99) && (skor > 44)) {
                printf("Harf notu: DC\n");
            } else if ((skor <= 43.99) && (skor > 39)) {
                printf("Harf notu: DD\n");
            } else if ((skor <= 38.99) && (skor > 34)) {
                printf("Harf notu: FD\n");
            } else {
                printf("Harf notu: FF\n");
            }
        } else if ((ortalama > 62.5) && (ortalama <= 70)) {
            if (skor >= 71) {
                printf("Harf notu: AA\n");
            } else if ((skor <= 70.99) && (skor > 66)) {
                printf("Harf notu: BA\n");
            } else if ((skor <= 65.99) && (skor > 61)) {
                printf("Harf notu: BB\n");
            } else if ((skor <= 60.99) && (skor > 56)) {
                printf("Harf notu: CB\n");
            } else if ((skor <= 55.99) && (skor > 51)) {
                printf("Harf notu: CC\n");
            } else if ((skor <= 50.99) && (skor > 46)) {
                printf("Harf notu: DC\n");
            } else if ((skor <= 45.99) && (skor > 41)) {
                printf("Harf notu: DD\n");
            } else if ((skor <= 40.99) && (skor > 36)) {
                printf("Harf notu: FD\n");
            } else {
                printf("Harf notu: FF\n");
            }
        } else if ((ortalama > 57.5) && (ortalama <= 62.5)) {
            if (skor >= 73) {
                printf("Harf notu: AA\n");
            } else if ((skor <= 72.99) && (skor > 68)) {
                printf("Harf notu: BA\n");
            } else if ((skor <= 67.99) && (skor > 63)) {
                printf("Harf notu: BB\n");
            } else if ((skor <= 62.99) && (skor > 58)) {
                printf("Harf notu: CB\n");
            } else if ((skor <= 57.99) && (skor > 53)) {
                printf("Harf notu: CC\n");
            } else if ((skor <= 52.99) && (skor > 48)) {
                printf("Harf notu: DC\n");
            } else if ((skor <= 47.99) && (skor > 43)) {
                printf("Harf notu: DD\n");
            } else if ((skor <= 42.99) && (skor > 38)) {
                printf("Harf notu: FD\n");
            } else {
                printf("Harf notu: FF\n");
            }
        } else if ((ortalama > 52.5) && (ortalama <= 57.5)) {
            if (skor >= 75) {
                printf("Harf notu: AA\n");
            } else if ((skor <= 74.99) && (skor > 70)) {
                printf("Harf notu: BA\n");
            } else if ((skor <= 69.99) && (skor > 65)) {
                printf("Harf notu: BB\n");
            } else if ((skor <= 64.99) && (skor > 60)) {
                printf("Harf notu: CB\n");
            } else if ((skor <= 59.99) && (skor > 55)) {
                printf("Harf notu: CC\n");
            } else if ((skor <= 54.99) && (skor > 50)) {
                printf("Harf notu: DC\n");
            } else if ((skor <= 49.99) && (skor > 45)) {
                printf("Harf notu: DD\n");
            } else if ((skor <= 44.99) && (skor > 40)) {
                printf("Harf notu: FD\n");
            } else {
                printf("Harf notu: FF\n");
            }
        } else if ((ortalama > 47.5) && (ortalama <= 52.5)) {
            if (skor >= 77) {
                printf("Harf Notu: AA\n");
            } else if ((skor <= 76.99) && (skor > 72)) {
                printf("Harf Notu: BA\n");
            } else if ((skor <= 71.99) && (skor > 67)) {
                printf("Harf Notu: BB\n");
            } else if ((skor <= 66.99) && (skor > 62)) {
                printf("Harf Notu: CB\n");
            } else if ((skor <= 61.99) && (skor > 57)) {
                printf("Harf Notu: CC\n");
            } else if ((skor <= 56.99) && (skor > 52)) {
                printf("Harf Notu: DC\n");
            } else if ((skor <= 51.99) && (skor > 47)) {
                printf("Harf Notu: DD\n");
            } else if ((skor <= 46.99) && (skor > 42)) {
                printf("Harf Notu: FD\n");
            } else {
                printf("Harf Notu: FF\n");
            }
        } else if ((ortalama > 42.5) && (ortalama <= 47.5)) {
            if (skor >= 79) {
                printf("Harf Notu: AA\n");
            } else if ((skor <= 78.99) && (skor > 74)) {
                printf("Harf Notu: BA\n");
            } else if ((skor <= 73.99) && (skor > 69)) {
                printf("Harf Notu: BB\n");
            } else if ((skor <= 68.99) && (skor > 64)) {
                printf("Harf Notu: CB\n");
            } else if ((skor <= 63.99) && (skor > 59)) {
                printf("Harf Notu: CC\n");
            } else if ((skor <= 58.99) && (skor > 54)) {
                printf("Harf Notu: DC\n");
            } else if ((skor <= 53.99) && (skor > 49)) {
                printf("Harf Notu: DD\n");
            } else if ((skor <= 48.99) && (skor > 44)) {
                printf("Harf Notu: FD\n");
            } else {
                printf("Harf Notu: FF\n");
            }
        }
        else{
            if(skor>=81){
                printf("harf notu: AA\n");
            }else if((skor<=80.99) && (skor>76)){
                printf("harf notu: BA\n");
            }else if((skor<=75.99) && (skor>71)){
                printf("harf notu: BB\n");
            }else if((skor<=70.99) && (skor>66)){
                printf("harf notu: CB\n");
            }else if((skor<=65.99) && (skor>61)){
                printf("harf notu: CC\n");
            }else if((skor<=60.99) && (skor>56)){
                printf("harf notu: DC\n");
            }else if((skor<=55.99) && (skor>51)){
                printf("harf notu: DD\n");
            }else if((skor<=50.99) && (skor>46)){
                printf("harf notu: FD\n");
            }else{
                printf("harf notu: FF\n");
            }
        }

    }
}

// Ana fonksiyon
int main() {
    srand(time(NULL)); // Rastgele sayý tohumunu ayarla

    printf("Ogrenci sayisini giriniz (max 100): ");
    scanf("%d", &N);

    printf("Soru sayisini giriniz (max 100): ");
    scanf("%d", &S);

    printf("Bos birakma ihtimalini giriniz (0.0 - 1.0): ");
    scanf("%lf", &B);

    printf("Dogru cevap verme ihtimalini giriniz (0.0 - 1.0): ");
    scanf("%lf", &D);

    cevap_anahtari_uret(cevap_anahtari, S);

    printf("Cevap Anahtari:\n");
    for (int i = 0; i < S; i++) {
        printf("%d = %c | ", i + 1, cevap_anahtari[i]);
    }
    printf("\n");

    sinavi_uygula(ogrenci_cevaplari, cevap_anahtari, N, S, B, D); // Öðrenci cevaplarýný üret

    printf("Ogrenci Cevaplari:\n");
    for (int i = 0; i < N; i++) {
        printf("Ogrenci %d: ", i + 1);
        for (int j = 0; j < S; j++) {
            printf("%d = %c | ", j + 1, ogrenci_cevaplari[i][j]);
        }
        printf("\n");
    }

    ogrencileri_puanla(ogrenci_cevaplari, cevap_anahtari, HBN, N, S);

    ortalama = sinif_ortalamasi_hesapla(HBN, N); // Sýnýf ortalamasý
    standart_sapma = standart_sapma_hesapla(ortalama, HBN, N); // Standart sapma

    printf("Sinif Ortalamasi: %.2f\n", ortalama);
    printf("Standart Sapma: %.2f\n", standart_sapma);

    T_skoru_hesapla(ortalama, HBN, N, standart_sapma, T_skoru); // Harf notlarýyla T-skorunu hesapla

    return 0;
}

