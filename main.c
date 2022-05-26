#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct{
   int skor;
   char ad[50];
   char soyad[50];
}oyuncu;

oyuncu oyuncu1;
oyuncu oyuncu2;
char kazananOyuncu;

int siraSayaci=0, i, j;
int kazanmaSayaci=0;
char siradakiOyuncu;
char tablo[4][4]={{' ', '1', '2', '3'},{'1', '.', '.', '.'},{'2', '.', '.', '.'},{'3', '.', '.', '.'}};
int kazananKontrol(char siradakiOyuncu);


void oyuncuBilgisiYaz(FILE *fbilgi)
{

    fbilgi=fopen("bilgi.txt","w");

        printf("1. oyuncu adi:");
        scanf("%s",oyuncu1.ad);

        printf("1. oyuncu soyadi:");
        scanf("%s",oyuncu1.soyad);

        oyuncu1.skor=0;

        printf("\n");

        printf("2. oyuncu adi:");
        scanf("%s",oyuncu2.ad);

        printf("2. oyuncu soyadi:");
        scanf("%s",oyuncu2.soyad);

        printf("\n");

        oyuncu2.skor=0;

        fprintf(fbilgi,"%s ",oyuncu1.ad);
        fprintf(fbilgi,"%s\n",oyuncu1.soyad);
        fprintf(fbilgi,"%d\n",oyuncu1.skor);
        fprintf(fbilgi,"%s ",oyuncu2.ad);
        fprintf(fbilgi,"%s\n",oyuncu2.soyad);
        fprintf(fbilgi,"%d\n",oyuncu2.skor);


    fclose(fbilgi);
}

void tabloYaz(int siraSayaci)
{
    int i=0, j=0;

    printf("----------------------------\n");

    if((siraSayaci % 2) == 0)
        printf("\tSira : O\n");
    else
        printf("\tSira : X\n");

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%c", tablo[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}


char siraBelirle(int siraSayaci)
{
    if(siraSayaci%2==0)
        return 'O';
    else
        return 'X';
}


int main()
{
    FILE* fbilgi;
    FILE*fYenioyun;
    system("color b0");
    printf("Eski oyuna devam etmek ister misiniz?\nEVET->E/e\tHAYIR->H/h ");

    char karar;
    scanf("%c",&karar);

    if(karar=='h' || karar=='H')
    {
    FILE *fp;
    oyuncuBilgisiYaz(fp);
    }
   else if(karar=='e' || karar=='E')
    {
    yeniOyun();
    }

    siraSayaci=0;
    while(siraSayaci<9)
    {
        siradakiOyuncu=siraBelirle(siraSayaci);
        tabloYaz(siraSayaci);
        if(koordinatSecme(siraSayaci)==2)
            {
                if(kazananKontrol(siradakiOyuncu)==2)
               {
                   break;
               }
            }
    }
skorYenile();
yeniOyun();


}

int koordinatSecme(int siraSayaci)
{
    int satir,sutun;

        printf("Satir giriniz");
        scanf("%d",&satir);
        printf("Sutun giriniz");
        scanf("%d",&sutun);

         if(satir==1 && sutun==1 && tablo[1][1] == '.')
        {
            tablo[1][1] = siradakiOyuncu;
            return 2;
        }
        else if (satir==1 && sutun==2 && tablo[1][2]=='.')
        {
            tablo[1][2] = siradakiOyuncu;
            return 2;
        }
        else if(satir==1 && sutun==3 && tablo[1][3]=='.')
        {
            tablo[1][3] = siradakiOyuncu;
            return 2;
        }
        else if(satir==2 && sutun==1 && tablo[2][1]=='.' )
        {
            tablo[2][1] = siradakiOyuncu;
            return 2;
        }
        else if(satir==2 && sutun==2 && tablo[2][2] == '.')
        {
            tablo[2][2] = siradakiOyuncu;
            return 2;
        }

        else if(satir==2 && sutun==3 && tablo[2][3] == '.')
        {
            tablo[2][3] = siradakiOyuncu;
            return 2;
        }

        else if(satir==3 && sutun==1 && tablo[3][1] == '.')
        {
            tablo[3][1] = siradakiOyuncu;
            return 2;
        }

        else if(satir==3 && sutun==2 && tablo[3][2] == '.')
        {
            tablo[3][2] = siradakiOyuncu;
            return 2;

        }
        else if(satir==3 && sutun==3 && tablo[3][3] == '.')
        {
            tablo[3][3] = siradakiOyuncu;
            return 2;
        }
        else
            {printf("gecerli koordinat giriniz");
            getch();
            return 1;
            }
}


int kazananKontrol(char siradakiOyuncu)
{
    if( (tablo[1][1] == siradakiOyuncu && tablo[1][2] == siradakiOyuncu && tablo[1][3] == siradakiOyuncu) ||
        (tablo[2][1] == siradakiOyuncu && tablo[2][2] == siradakiOyuncu && tablo[2][3] == siradakiOyuncu) ||
        (tablo[3][1] == siradakiOyuncu && tablo[3][2] == siradakiOyuncu && tablo[3][3] == siradakiOyuncu) ||
        (tablo[1][1] == siradakiOyuncu && tablo[2][1] == siradakiOyuncu && tablo[3][1] == siradakiOyuncu) ||
        (tablo[1][2] == siradakiOyuncu && tablo[2][2] == siradakiOyuncu && tablo[3][2] == siradakiOyuncu) ||
        (tablo[1][3] == siradakiOyuncu && tablo[2][3] == siradakiOyuncu && tablo[3][3] == siradakiOyuncu) ||
        (tablo[1][1] == siradakiOyuncu && tablo[2][2] == siradakiOyuncu && tablo[3][3] == siradakiOyuncu) ||
        (tablo[1][3] == siradakiOyuncu && tablo[2][2] == siradakiOyuncu && tablo[3][1] == siradakiOyuncu))
    {kazananOyuncu=siradakiOyuncu;}

        if(kazananOyuncu=='O')
        {
            printf("kazanan oyuncu %s", oyuncu1.ad);
            oyuncu1.skor++;
            return 2;
        }
        else if (kazananOyuncu=='X')
        {
            printf("kazanan oyuncu %s", oyuncu2.ad);
            oyuncu2.skor++;
            return 2;
        }
        else
        {
            siraSayaci++;
                if (siraSayaci==9)
                {
                    printf("Berabere");
                    return 2;
                }
                else
                {
                    return 1;
                }
        }
}
void skorYenile()
{
    FILE* fbilgi;
    fbilgi=fopen("bilgi.txt","w");


        fprintf(fbilgi,"%s ",oyuncu1.ad);
        fprintf(fbilgi,"%s\n",oyuncu1.soyad);
        fprintf(fbilgi,"%d\n",oyuncu1.skor);
        fprintf(fbilgi,"%s ",oyuncu2.ad);
        fprintf(fbilgi,"%s\n",oyuncu2.soyad);
        fprintf(fbilgi,"%d\n",oyuncu2.skor);

    fclose(fbilgi);

}

void yeniOyun()
{

    FILE* fbilgi;
    fbilgi=fopen("bilgi.txt","r");

    fscanf(fbilgi,"%s%s%d%s%s%d",oyuncu1.ad, oyuncu1.soyad, &oyuncu1.skor, oyuncu2.ad, oyuncu2.soyad, &oyuncu2.skor);


    FILE* fYeniOyun;
    fYeniOyun=fopen("yenioyun.txt","w");
    fprintf(fYeniOyun,"1. oyuncu: %s %s\n skoru:%d\n",oyuncu1.ad, oyuncu1.soyad, oyuncu1.skor);
    fprintf(fYeniOyun,"2. oyuncu: %s %s\n skoru:%d\n",oyuncu2.ad, oyuncu2.soyad, oyuncu2.skor);


    fclose(fbilgi);
    fclose(fYeniOyun);

}
