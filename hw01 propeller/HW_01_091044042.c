/*
*
*  Ali Anil APAYDIN
*  Computer Science Engineering
*  091044042
*
*  Notes:PROPELLER-Bu program kullanicidan aldigi
*  Buyuk ya da kucuk bir harf karakterini ekranin boyutuna
*  gore belirlenen bir sayi araliginda pervane boyutu olarak
*  aldigi degere gore 8 farkli yonde ekranin tam ortasinda
*  pervane kolu olarak ve tur sayisini tutarak basar.
*  Her bastigi sekilden sonra kullanicinin hamlesini bekler.
*
*  References:GIT CSE 102 Summer Term Homework 1
*
*
*/

#include <stdio.h>                                                              /*printf,scanf*/
#include <stdlib.h>                                                             /*system*/

#define MIN 3                                                                   /*Minumum karakter sayisini tutan constant makro*/
#define MAX 12                                                                  /*Maximum karakter sayisini tutan constant makro*/
#define MAX_COUNT 100                                                           /*Maximum tur sayisini tutan constant makro*/
#define PROPELLER_WIDTH 39                                                      /*Ekranin enine ortasina gelmek icin tutulan constant makro*/

void propellerNorth(char *character,int *length);                               /*Pervane yonune gore fonksiyon declarasyonlari*/
void propellerNorthEast(char *character,int *length);
void propellerNorthWest(char *character,int *length);
void propellerEast(char *character,int *length);
void propellerWest(char *character,int *length);
void propellerSouth(char *character,int *length);
void propellerSouthEast(char *character,int *length);
void propellerSouthWest(char *character,int *length);
void gettingCenter(int *length);                                                /*Kuzey sekilleri icin ekranin ortasina gelme fonk.*/
void gettingSouthCenter(int *length);                                           /*Guney sekilleri icin ekranin ortasina gelme fonk.*/
int gettingInput();                                                             /*Karakter ve Buyukluk degiskenlerini alan fonksiyon*/

int main(void)
{
    gettingInput();                                                             /*Degiskenlerin alindigi fonksiyonun cagirilmasi*/

    return 0;                                                                   /*Programdan ana cikis (Program maximum tur sayisina kadar*/
}                                                                               /*basariyla uygulandiginda bu noktaya gelinir)*/
int gettingInput()                                                              /*Degiskenlerin alindigi fonksiyon*/
{
    char character,selection;                                                   /*Sirayla seklin basildigi ve enter key icin karakter*/
    int length,                                                                 /*Sirayla Seklin boyutu,pervane tur sayisi,sekil sirasi ve */
        count=1,                                                                /*enter key icin ascii tablosu kontrol degiskeni*/
        direction=8,
        temp;

    do{                                                                         /*Do-while dongusu ile pervane karakterinin alinmasi*/
    printf("Enter the character >");                                            /*Ayni zamanda temp integeri ile ascii tablosundan*/
    scanf("%c",&character);                                                     /*faydalanarak sadece buyuk ve kucuk harfler alinir*/
    temp=(int)character;
    system("cls");
    }while(((temp>=0)&&(temp<65)) || (((temp>=91)&&(temp<97)) || ((temp>=123)&&(temp<=127))));

    do{                                                                         /*Do-while dongusu ile pervane boyutunun alinmasi*/
    printf("Enter the length between 3 and 11 >");                              /*Boyut sadece pervanenin basildigi ekrana sigacak*/
    scanf("%d",&length);                                                        /*sekilde tutulmus manimum ve maximum degerler arasinda*/
    system("cls");                                                              /*olmalidir*/
    }while(length < MIN || length > MAX);

    scanf("%c",&selection);                                                     /*Pervena boyutu alindiginda ayni zamanda enter keye*/
                                                                                /*bastigimiz icin burda selection alinmasi lazim*/
    while(count<=MAX_COUNT)                                                     /*Pervane ana dongusu*/
    {
        printf("Cycle = %d\n",count);                                           /*Ekranin kosesine cycle yazilmasi*/
        direction=direction%8;                                                  /*Pervane sirasi degiskenin 8'e gore modunun alinmasi*/

        if(direction==0)
        {
            gettingCenter(&length);
            propellerNorth(&character,&length);
        }
        else if(direction==1)
        {
            gettingCenter(&length);                                             /*Modun degerine gore sekillerin fonksiyonlarinin*/
            propellerNorthEast(&character,&length);                             /*cagirilmasi*/
        }
        else if(direction==2)
        {
            gettingCenter(&length);
            gettingSouthCenter(&length);
            propellerEast(&character,&length);
        }
        else if(direction==3)
        {
            gettingCenter(&length);
            gettingSouthCenter(&length);
            propellerSouthEast(&character,&length);
        }
        else if(direction==4)
        {
            gettingCenter(&length);
            gettingSouthCenter(&length);
            propellerSouth(&character,&length);
        }
        else if(direction==5)
        {
            gettingCenter(&length);
            gettingSouthCenter(&length);
            propellerSouthWest(&character,&length);
        }
        else if(direction==6)
        {
            gettingCenter(&length);
            gettingSouthCenter(&length);
            propellerWest(&character,&length);
        }                                                                       /*Ilk 7 seklin basildiktan sonra devam sekli icin
                                                                                  enter keyin alinmasi*/
        if(direction!=7)                                                        /*Mod degeri degilse enter key degeri alinir.Enter key */
        {                                                                       /*degerine gore direciton arttirilir ya da fonksiyondan*/
            scanf("%c",&selection);                                             /*cikilir*/
            system("cls");
            temp=(int)selection;
            if(temp!='\n')
            {
                return 0;
            }
            direction++;
        }
        else                                                                    /*Mod degeri 7 ise son sekil basilir,enter key degerine gore*/
        {                                                                       /*count ve direction arttirilir ya da fonksiyondan cikilir*/
            gettingCenter(&length);
            propellerNorthWest(&character,&length);
            scanf("%c",&selection);
            system("cls");
            temp=(int)selection;
            if(temp!='\n')
            {
                return 0;
            }
            else
            {
                count++;
                direction++;
            }
        }
    }                                                                           /*Pervane ana dongusu max_count'a kadar basariyla*/
    return 0;                                                                   /*uygulanirsa whiledan cikilir return ile main'e donulur*/
}
void propellerNorth(char *character,int *length)                                /*Pervane'nin ilk sekli kuzeye bakan fonksiyonu*/
{
    int count,count2;

    for(count=0;count<*length;count++)                                          /*Pervane boyutu icin yukardan asagiya for dongusu ve her*/
    {                                                                           /*karakter icin enine ekranin ortasýna kadar bosluk basan for*/
        for(count2=0;count2<PROPELLER_WIDTH;count2++)                           /*dongusu*/
        printf(" ");

        printf("%c\n",*character);
    }
}
void propellerNorthEast(char *character,int *length)                            /*Ikinci sekil kuzeydogu fonksiyonu*/
{
    int count,count2,count3=1;

    for(count=0;count<*length;count++)                                          /*Boyu icin for dongusu*/
    {
        for(count2=count3;count2<PROPELLER_WIDTH+(*length);count2++)            /*Ikinci bir degisken ile enindeki caprazlik icin for*/
        printf(" ");                                                            /*dongusu*/

        count3++;
        printf("%c\n",*character);
    }
}
void propellerEast(char *character,int *length)                                 /*Ikýnci sekil dogu fonksiyonu*/
{
    int count;

    for(count=0;count<PROPELLER_WIDTH;count++)                                  /*Sekli ekranin enine ortasina kaydiran for dongusu*/
    printf(" ");
    for(count=0;count<(*length);count++)                                        /*Sekli yan yana basan for dongusu*/
    printf("%c",*character);
}
void propellerSouthEast(char *character,int *length)                            /*Dordunci sekil guneydogu fonksiyonu*/
{
    int count,count2,count3=(*length);

    for(count=0;count<(*length);count++)                                        /*Boyu icin for dongusu*/
    {
        for(count2=count3;count2<PROPELLER_WIDTH+(*length);count2++)            /*Ikinci bir count degiskeni ile sekli ekranin ortas na*/
        printf(" ");                                                            /*ve capraz olacak sekilde getiren for dongusu*/

        printf("%c\n",*character);
        count3--;
    }
}
void propellerSouth(char *character,int *length)                                /*Besinci sekil guney fonksiyonu*/
{
    int count,count2;

    for(count=0;count<(*length);count++)                                        /*Boyu icin For dongusu*/
    {
        for(count2=0;count2<PROPELLER_WIDTH;count2++)                           /*Ekrani enine ortasina getiren for dongusu*/
        printf(" ");

        printf("%c\n",*character);
    }
}
void propellerSouthWest(char *character,int *length)                            /*Altinci sekil guneybati fonksiyonu*/
{
    int count,count2,count3=0;

    for(count=0;count<(*length);count++)                                        /*Seklin boyu icin for dongusu*/
    {
        for(count2=count3;count2<PROPELLER_WIDTH;count2++)                      /*Ikinci bir count degiskeni ile sekli ekranin*/
        printf(" ");                                                            /*enine ortasina ve capraz olacak sekilde getiren for*/
                                                                                /*dongusu*/
        count3++;
        printf("%c\n",*character);
    }
}
void propellerWest(char *character,int *length)                                 /*Yedinci sekil bati fonksiyonu*/
{
    int count;

    for(count=0;count<=PROPELLER_WIDTH-(*length);count++)                       /*Sekli ekranin enine ortasina getiren for dongusu*/
    printf(" ");
    for(count=0;count<(*length);count++)                                        /*Sekli yan yana basan for dongusu*/
    printf("%c",*character);
}
void propellerNorthWest(char *character,int *length)                            /*Son sekil kuzeybati fonksiyonu*/
{
    int count,count2,count3=(*length);

    for(count=0;count<(*length);count++)                                        /*Seklin boyu icin for dongusu*/
    {
        for(count2=count3;count2<=PROPELLER_WIDTH;count2++)                     /*Ikinci bir count degiskeni ile sekli ekranin*/
        printf(" ");                                                            /*enine ortasina ve capraz olarak getiren for*/
                                                                                /*dongusu*/
        count3--;
        printf("%c\n",*character);
    }
}
void gettingCenter(int *length)                                                 /*Kuzey sekilllerini pervanenin boyutuna gore boyuna*/
{                                                                               /*ekranin ortasina getiren fonksiyon*/
    int count;

    for(count=1;count<(MAX-*length);count++)
    printf("\n");
}
void gettingSouthCenter(int *length)                                            /*Guney sekillerini pervanenin boyutuna gore ekranin*/
{                                                                               /*boyuna ortasina getiren fonksiyon*/
    int count;

    for(count=1;count<(*length);count++)
    printf("\n");
}