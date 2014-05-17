/*
*   Ali Anil Apaydin
*   091044042
*
*   Notes=Battleship Game
*
*   Description=Bu program bilgisayar ile kullanıcı arasında
*   geçen amiralbattı oyunudur.Bilgisayar gemilerini belli bir
*   algoritmaya göre random şekilde yarleştirir ve belli bir
*   algoritmaya göre kullanıcının gemilerini batırmaya      *   çalışır.
*   Diger tarafın bütün gemilerini batırmayı başaran oyunu *   kazanır.
*   Oyun bittiğinde kullanıcı yeniden oyuna başlayabilir.
*
*   References=GIT CSE 102 Summer Term Homework 2
*
*
*/

#include <stdio.h>                                          /*printf,scanf*/
#include <stdlib.h>                                         /*rand*/
#include <time.h>                                           /*srand*/

#define MAX 10                                              /*Tablo büyüklüğü*/
#define TOTAL_SHIP_PART 18                                  /*Herbir oyuncunun toplamdaki gemi sayısı*/
#define WAIT_TIME 1.5                                       /*Bekletme fonksiyonu için double constant macro*/


void randomState(int [][MAX],int );                         /*Bilgisayarın random gemi yerleştirme fonksiyonu*/
void Intro();                                               /*Oyuna giriş*/
int printTablesWithoutShips(int [][MAX],int ,int );         /*Oyun esnasında bakılan yerin controlü ve oyun alanlarının ekrana basılması*/
void printTableWithShips(int [][MAX]);                      /*Kullanıcı için gemilerini yerleştirirken gemiler ile oyun alanının basılması*/
void printTablePlayer(int [][MAX]);                         /*Kullanıcı için oyun esnasında gördügü oyun alanı*/
void computerStateShips(int [][MAX],int [][MAX]);           /*Bilgisayarın gemilerini yerleştirmesi*/
void playerStateShips(int [][MAX]);                         /*Kullanıcının gemilerini yerleştirmesi*/
void playerStating(int [][MAX],int ,int ,int ,int );        /*Kullanıcının gemilerini yerleştirmesi*/
void theGame(int [][MAX],int [][MAX]);                      /*Oyun esnasının çalışan fonksiyon*/
void lastMove(int ,int ,int );                              /*Bilgisayarın son hareketini basan fonksiyon*/
void getLastMove(int *,int *,int *,int ,int ,int );         /*Bilgisayarın son hareketini tutan fonksiyon*/
void getPlayerLastMove(int *,int *,int *,int ,int ,int );   /*Kullanıcının son hareketini tutan fonksiyon*/
void playerLastMove(int ,int ,int );                        /*Kullanıcının son hareketini basan fonksiyon*/
void wait(double );

int main()
{
 int table[MAX][MAX],                                       /*Kullanıcı ve bilgisayar oyun alanları*/
     comtable[MAX][MAX];
 int count=0,selection;

 while(count==0)
 {
    Intro();                                                /*Sırasıyla program girisi,bilgisayarın gemilerini yerleştirmesi,*/
    computerStateShips(table,comtable);                     /*kullanıcının gemilerini yerleştirmesi ve oyunun başlaması*/
    playerStateShips(table);
    theGame(table,comtable);
    count++;
    if(count==1)                                            /*Oyun sonlanınca kullanıcıya tekrar oynayıp oynamamasının soruldugu kısım*/
    {
        printf("\n\nPlay Again? (Yes=1/No=2)\n");
        scanf("%d",&selection);
        if(selection==1)
        {
            count=0;
        }
        else
        {
            return 0;
        }
    }
 }
 return 0;
}
void computerStateShips(int table[][MAX],int comtable[][MAX])   /*Bilgisarın gemilerini yerleştirmesi*/
{
 int count=0,size;
 int i,j;

 for(i=0;i<MAX;i++)                                             /*İlk başta oyun alanları 0 ile doldurulur.*/
 {
    for(j=0;j<MAX;j++)
    {
        table[i][j]=0;
        comtable[i][j]=0;
    }
 }

 size=5;                                                        /*Gemi büyüklüğü sısıyla gemiler bilgisayarın oyun alanına*/
 randomState(comtable,size);                                    /*yerleştirilir*/
 size=4;
 randomState(comtable,size);
 size=3;
 randomState(comtable,size);
 size=2;
 randomState(comtable,size);
 randomState(comtable,size);
 size=1;
 randomState(comtable,size);
 randomState(comtable,size);
}
void Intro()                                                    /*Program girişi ve tanıtımı*/
{
 printf("////////////Welcome\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
 printf("********BATTLESHIP GAME********\n");
 printf("******by Ali Anil Apaydin******\n");
 printf("                *\n");
 printf("      ***      ***      ***\n");
 printf("      ***     *****     ***\n");
 printf(" *******************************\n");
 printf("   ***************************\n");
 printf("Entering the Game...\n");
}
void randomState(int array[][MAX],int size)                     /*Bilgisayarın gemileri için random fonksiyonu*/
{
 int i,j,a,count,count2=0,count3=0;
 while(count3==0)
 {
    srand(time(NULL));                                          /*Zamana göre random atılır,sonra doldurulacak yer boşmu*/
    i=rand()%MAX;                                               /* ve oyun alanından çıkıldımı kontrol edilir*/
    j=rand()%MAX;                                               /*Koşullar uyuyorsa geminin boyutuna göre gemi yerleştirilir*/
    count=rand()%MAX;

    if(count==0)
    {
        for(a=size-1;a>=0;a--)
        {
            if(j+a<MAX)
            {
                if(array[i][j+a]==0)
                {count2++;}
            }
        }
        if(count2==size)
        {
            for(a=size-1;a>=0;a--)
            array[i][j+a]=1;

            count3=1;
        }
        else
        {
            count++;
            count2=0;
        }
    }
    if(count==1)
    {
        for(a=size-1;a>=0;a--)
        {
            if(j-a>0)
            {
                if(array[i][j-a]==0)
                {count2++;}
            }
        }
        if(count2==size)
        {
            for(a=size-1;a>=0;a--)
            array[i][j-a]=1;

            count3=1;
        }
        else
        {
            count++;
            count2=0;
        }
    }
    if(count==2)
    {
        for(a=size-1;a>=0;a--)
        {
            if(i+a<MAX)
            {
                if(array[i+a][j]==0)
                {count2++;}
            }
        }
        if(count2==size)
        {
            for(a=size-1;a>=0;a--)
            array[i+a][j]=1;

            count3=1;
        }
        else
        {
            count++;
            count2=0;
        }
    }
    if(count==3)
    {
        if(i-a>0)
        {
            for(a=size-1;a>=0;a--)
            {
                if(array[i-a][j]==0)
                {count2++;}
            }
        }
        if(count2==size)
        {
            for(a=size-1;a>=0;a--)
            array[i-a][j]=1;

            count3=1;
        }
        else
        {
            count++;
            count=count%4;
            count2=0;
        }
    }
 }
}
void playerStateShips(int table[][MAX])                         /*Kullanıcının gemileri yerleştirilmesi*/
{
 int count=0,size=0,location=0,temp=0,direction=0;
 char character,tempcharacter;
 int x,y;

 size=5;                                                        /*Gemi boyutuna göre degerler istenir*/
 system("cls");
 printTableWithShips(table);
 printf("Please enter the location of your Aircraft Carrier first part like A 5,C 3 etc.\n");
 printf("And the direction of your ship 1.North 2.East etc.\n");
 scanf("%c%d %d",&character,&location,&direction);
 scanf("%c",&tempcharacter);
 temp=(int)character - 65;                                      /*Gemi başının koordinantı ve nereye yöneleceği istenir*/
 playerStating(table,temp,location,direction,size);

 size=4;
 system("cls");
 printTableWithShips(table);
 printf("Please enter the location of your Battleship first part like A 5,C 3 etc.\n");
 printf("And the direction of your ship 1.North 2.East etc.\n");
 scanf("%c%d %d",&character,&location,&direction);
 scanf("%c",&tempcharacter);
 temp=(int)character - 65;
 playerStating(table,temp,location,direction,size);

 size=3;
 system("cls");
 printTableWithShips(table);
 printf("Please enter the location of your Cruiser first part like A 5,C 3 etc.\n");
 printf("And the direction of your ship 1.North 2.East etc.\n");
 scanf("%c%d %d",&character,&location,&direction);
 scanf("%c",&tempcharacter);
 temp=(int)character - 65;
 playerStating(table,temp,location,direction,size);

 for(y=0;y<2;y++)                                           /*İki adet Destroyer ve Submarine gemileri için for döngüleri*/
 {
    size=2;
    system("cls");
    printTableWithShips(table);
    printf("Please enter the location of your Destroyer first part like A 5,C 3 etc.\n");
    printf("And the direction of your ship 1.North 2.East etc.\n");
    scanf("%c%d %d",&character,&location,&direction);
    scanf("%c",&tempcharacter);
    temp=(int)character - 65;
    playerStating(table,temp,location,direction,size);
 }

 for(x=0;x<2;x++)
 {
    size=1;
    system("cls");
    printTableWithShips(table);
    printf("Please enter the location of your Submarine first part like A 5,C 3 etc.\n");
    printf("And the direction of your ship 1.North 2.East etc.\n");
    scanf("%c%d %d",&character,&location,&direction);
    scanf("%c",&tempcharacter);
    temp=(int)character - 65;
    playerStating(table,temp,location,direction,size);
 }
}
void printTableWithShips(int array[][MAX])                      /*Kullanıcı gemilerini yerleştirirken dogrulugunu görmek için */
{                                                               /*oyun alanını gemilerle basan fonksiyon*/
  int i,j;

  printf("//////PLAYER STATING SHIPS\\\\\\\\\\\\ \n");
  printf(" A B C D E F G H I J\n");

  for(i=0;i<MAX;i++)
  {
    printf("%d",i);
    for(j=0;j<MAX;j++)
    {
        if(array[i][j]==0)
        {
            printf("  ");
        }
        else if(array[i][j]==1)
        {
            printf("* ");
        }
    }
    printf("\n");
  }
}
void playerStating(int array[][MAX],int i,int j,int direction,int size)         /*Kullanıcın gemilerini yerleştirmesi için girilen degerlere*/
{                                                                               /*oyun alanını degistiren fonksiyon*/
   int a;

   if(direction==1)
   {
      for(a=(size-1);a>=0;--a)
      {
          array[j-a][i]=1;
      }
   }
   else if(direction==2)
   {
      for(a=(size-1);a>=0;--a)
      {
          array[j][i+a]=1;
      }
   }
   else if(direction==3)
   {
      for(a=(size-1);a>=0;--a)
      {
          array[j+a][i]=1;
      }
   }
   else if(direction==4)
   {
      for(a=(size-1);a>=0;--a)
      {
          array[j][i-a]=1;
      }
   }
}
int printTablesWithoutShips(int array[][MAX],int a,int b)       /*Oyun esnasında hem bilgisayar hem de kullanıcı için atışların kontrol*/
{                                                               /*edildiği ve oyun alanlarının basıldığı fonksiyon*/
  int i,j;
  int situation=0;
  system("clear");
  printf("//////CONTROLLING\\\\\\\\\\\\ \n");
  printf(" A B C D E F G H I J\n");

  for(i=0;i<MAX;i++)
  {
    printf("%d",i);
    for(j=0;j<MAX;j++)
    {
        if(array[i][j]==(-1))
        {
            printf("X ");
        }
        else if(array[i][j]==0)
        {
            printf("  ");
        }
        else if(array[i][j]==2)
        {
            printf("* ");
        }

        if((j==a)&&(i==b))
        {
            if(array[b][a]==1)
            {
                printf("* ");
                array[b][a]=2;
                situation=1;
            }
            else if(array[b][a]==0)
            {
                array[b][a]=(-1);
                printf("X ");
            }
        }
    }
    printf("\n");
  }
 wait(WAIT_TIME);
 return situation;
}
void theGame(int table[][MAX],int comtable[][MAX])              /*Oyun sırası fonksiyonu*/
{                                                               /*Bilgisayarın turu ve ya oyuncunun turuna,atışlarının isabetinin*/
  int count1=0,count2=0,count=0,count4=0,count5,count6;         /*gösterildiği fonksiyon*/
  int a,b;                                                      /*Son hamlelerin bulunması ve gösterilmesi için son hamle fonksiyonları da*/
  int c;                                                        /*bu fonksiyonun içinde çağırılır*/
  int k=0,l=0,m=0;
  int w=0,x=0,z=0;
  char character;

  srand(time(NULL));

  while((count1<=TOTAL_SHIP_PART) && (count2<=TOTAL_SHIP_PART))
  {
    count=0;
    if(count==0)
    {
        system("cls");
        printf("COMPUTER TURN\n\n");
        if(count4==0)
        {
            a=rand()%MAX;
            b=rand()%MAX;
            count5=printTablesWithoutShips(table,a,b);
            lastMove(k,l,m);
            if(count5==0)
            {
                count=1;
                printf("\n\nMISS   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a,b,2);
            }
            else
            {
                count4=1;
                count1++;
                printf("\n\nHIT   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a,b,1);
            }
        }
    while(count4==1)
    {
        system("cls");
        c=rand()%4;
        if(c==0)
        {
            if((a+1)<MAX)
            {
                count5=printTablesWithoutShips(table,a+1,b);
                lastMove(k,l,m);
            }

            if(count5==0)
            {
                count4=0;
                count=1;
                printf("\n\nMISS   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a+1,b,2);
            }
            else
            {
                count1++;
                printf("\n\nHIT   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a+1,b,1);
            }
        }
        if(c==1)
        {
            if((a-1)>0)
            {
                count5=printTablesWithoutShips(table,a-1,b);
                lastMove(k,l,m);
            }

            if(count5==0)
            {
                count4=0;
                count=1;
                printf("\n\nMISS   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a-1,b,2);
            }
            else
            {
                count1++;
                printf("\n\nHIT   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a-1,b,1);
            }
        }
        if(c==2)
        {
            if((b+1)<MAX)
            {
                count5=printTablesWithoutShips(table,a,b+1);
                lastMove(k,l,m);
            }

            if(count5==0)
            {
                count4=0;
                count=1;
                printf("\n\nMISS   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a,b+1,2);
            }
            else
            {
                count1++;
                printf("\n\nHIT   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a,b+1,1);
            }
        }
        if(c==3)
        {
            if((b-1)>0)
            {
                count5=printTablesWithoutShips(table,a,b-1);
                lastMove(k,l,m);
            }

            if(count5==0)
            {
                count4=0;
                count=1;
                printf("\n\nMISS   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a,b-1,2);
            }
            else
            {
                count1++;
                printf("\n\nHIT   ");
                wait(WAIT_TIME);
                lastMove(k,l,m);
                getLastMove(&k,&l,&m,a,b-1,1);
            }
        }
    }
    }

    while(count==1)
    {
        system("cls");
        printTablePlayer(comtable);
        printf("Enter your selection like A5 C3\n");
        scanf("%c%d",&character,&b);
        a=(int)character - 65;
        count6=printTablesWithoutShips(comtable,a,b);
        playerLastMove(w,x,z);
        if(count6=0)
        {
            printf("\n\nMISS   ");
            wait(WAIT_TIME);
            playerLastMove(w,x,z);
            getPlayerLastMove(&w,&x,&z,a,b,2);
            count=0;
        }
        else
        {
            printf("\n\nHIT   ");
            wait(WAIT_TIME);
            playerLastMove(w,x,z);
            getPlayerLastMove(&w,&x,&z,a,b,1);
            count2++;
        }
      }
    }

    if(count1>count2)
    {
        printf("Computer Wins!!!\n\n");
    }
    else
    {
        printf("Player Wins!!!\n\n");
    }
}
void printTablePlayer(int array[][MAX])                         /*Kullanıcının turunda ekrana kullanıcının takip etmesi için*/
{                                                               /*bilgisayarın oyun alanının basıldıgı fonksiyon*/
    int i,j;

    printf("\n\n//////PLAYER TURN\\\\\\\\\\\\ \n");
    printf(" A B C D E F G H I J\n");

    for(i=0;i<MAX;i++)
    {
        printf("%d",i);
        for(j=0;j<MAX;j++)
        {
            if(array[i][j]==(-1))
            {
                printf("X ");
            }
            else if(array[i][j]==2)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
void lastMove(int a,int b,int c)                                /*Bilgisayarın son hamlesinin ekrana basıldıgı fonksiyon*/
{
    switch(a)
    {
        case 0:
        printf("\n\n Computer Last Move = A%d ",b);
        break;
        case 1:
        printf("\n\n Computer Last Move = B%d ",b);
        break;
        case 2:
        printf("\n\n Computer Last Move = C%d ",b);
        break;
        case 3:
        printf("\n\n Computer Last Move = D%d ",b);
        break;
        case 4:
        printf("\n\n Computer Last Move = E%d ",b);
        break;
        case 5:
        printf("\n\n Computer Last Move = F%d ",b);
        break;
        case 6:
        printf("\n\n Computer Last Move = G%d ",b);
        break;
        case 7:
        printf("\n\n Computer Last Move = H%d ",b);
        break;
        case 8:
        printf("\n\n Computer Last Move = I%d ",b);
        break;
        case 9:
        printf("\n\n Computer Last Move = J%d ",b);
        break;
    }

    if(c==1)
    {
        printf("   HIT");
    }
    else if(c==2)
    {
        printf("   MISS");
    }
    else
    {
        printf("   %d",c);
    }
}
void getLastMove(int *k,int *l,int *m,int a,int b,int c)        /*Bilgisayarın son hamlesinin oluşturuldugu fonksiyon*/
{
    *k=a;
    *l=b;
    *m=c;
}
void getPlayerLastMove(int *k,int *l,int *m,int a,int b,int c)  /*Kullanıcının son hamlesinin bulundugu fonksiyon*/
{
    *k=a;
    *l=b;
    *m=c;
}
void playerLastMove(int a,int b,int c)                          /*Kullanıcının son hamlesinin ekrana basıldıgı fonksiyon*/
{
    switch(a)
    {
        case 0:
        printf("\n\n Player Last Move = A%d ",b);
        break;
        case 1:
        printf("\n\n Player Last Move = B%d ",b);
        break;
        case 2:
        printf("\n\n Player Last Move = C%d ",b);
        break;
        case 3:
        printf("\n\n Player Last Move = D%d ",b);
        break;
        case 4:
        printf("\n\n Player Last Move = E%d ",b);
        break;
        case 5:
        printf("\n\n Player Last Move = F%d ",b);
        break;
        case 6:
        printf("\n\n Player Last Move = G%d ",b);
        break;
        case 7:
        printf("\n\n Player Last Move = H%d ",b);
        break;
        case 8:
        printf("\n\n Player Last Move = I%d ",b);
        break;
        case 9:
        printf("\n\n Player Last Move = J%d ",b);
        break;
    }

    if(c==1)
    {
        printf("   HIT");
    }
    else if(c==2)
    {
        printf("   MISS");
    }
    else
    {
        printf("   %d",c);
    }
}
void wait(double seconds)                                       /*Geçişlerde ve kontrollerde programı bekletme fonksiyonu*/
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait){}
}
