#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int skor;
   char ad[50];
}oyuncu;

oyuncu oyuncu1;
oyuncu oyuncu2;

/*
void oyuncubilgisi;
void tabloyaz;
int sira;
int secimkoordinat;
int kazanankontrol;
*/


void oyuncubilgisiyaz(FILE *fbilgi)
{

    fbilgi=fopen("bilgi.txt","w");

        printf("1. oyuncu adi:");
        scanf("%s",&oyuncu1.ad);

        oyuncu1.skor=0;

        printf("2. oyuncu adi:");
        scanf("%s",&oyuncu2.ad);

        oyuncu2.skor=0;

        fprintf(fbilgi,"1.nin adi: %s\n skoru%d\n",oyuncu1.ad,oyuncu1.skor);
        fprintf(fbilgi,"2.nin adi: %s\n skoru%d\n",oyuncu2.ad,oyuncu2.skor);


    fclose(fbilgi);
}



int main()
{
    FILE *fp;
    oyuncubilgisiyaz(fp);

    return 0;
}

