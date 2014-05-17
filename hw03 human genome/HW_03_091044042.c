/*
*   Ali Anil APAYDIN
*   Computer Science Engineering
*   091044042
*
*   Notes:Human Genome
*
*   Description:Bu program kullanıcıdan aldıgı insan DNA'sı
*   çeşitli işlemler yaparak onu klonlar,mutasyona ugratır,istenen
*   boyutta çaprazlama yapar,benzerlik oranı ölçer ve belirli
*   bir hastalıga yatkın olup olmadıgını ölçer.
*
*
*   References:GIT CSE 102 Summer Term HomeWork 03
*
*
*/

#include <stdio.h>                                                          /*scanf,printf*/
#include <time.h>                                                           /*wait*/
#include <math.h>                                                           /*fabs*/

#define MAX_LENGTH 33                                                       /*Maksimum DNA uzunlugu*/
#define WAIT_TIME 5                                                         /*Program bekletilme süresi*/

void initilizeDNA(char str[MAX_LENGTH],int *DNAlength)                      /*Kullanıcı yardımı ile DNA oluşturma fonksiyonu*/
{
    int i=0;
    char character,junk;

    for(i=0;i<MAX_LENGTH-1;i++)                                             /*Önce string içindeki bütün elemanlar boşluk ile doldurulur*/
    {
        str[i]=' ';
    }

    i=0;
    while(i<MAX_LENGTH-1)                                                   /*Sonra kullanıcı çıkış degeri girene ya da string dolana kadar*/
    {                                                                       /*elemanlar stringe atanır*/
        character='\n';
        printf("Enter the character like A or a to Adenine and Q or q to close\n");

        scanf("%c",&character);
        while(character=='\n')
        {
            scanf("%c",&character);
        }
        system("cls");

        switch(character)
        {
        case 'a':                                                           /*Kullanıcı nükleosidleri baş harflerini girerek belirler*/
        case 'A':
        str[i]='A';
        break;
        case 'g':
        case 'G':
        str[i]='G';
        break;
        case 'c':
        case 'C':
        str[i]='C';
        break;
        case 't':
        case 'T':
        str[i]='T';
        break;
        case 'q':
        case 'Q':
        *DNAlength=i;
        str[*DNAlength]='\0';
        i=MAX_LENGTH;
        break;
        }                                                                   /*Atama işlemi bittikten sonra string sonuna ve eleman bitimi*/
        i++;                                                                /*sonuna NULL karakteri atanır*/
        character='\n';
    }

    str[MAX_LENGTH-1]='\0';


}
void clonDNA(char str[MAX_LENGTH])                                          /*DNA klonlama fonksiyonu*/
{
    char tempstr[MAX_LENGTH];                                               /*İlk başta bir template stringi oluşturulur ve içi*/
    int num,i,copied,j=0,DNAlength;                                         /*kullanıcı tarafından doldurulur*/

    initilizeDNA(tempstr,&DNAlength);

    for(i=0;tempstr[i]!='\0';i++)
    copied=i+1;

    for(i=0;str[i]!='\0';i++)                                               /*Asıl stringin sonuna eklenmesi için son eleman bulunur*/
    num=i+1;


    copied=num+copied;

    if((num>=MAX_LENGTH)&&(copied<=MAX_LENGTH))                             /*Toplam boyut maximumdan büyükse ve eklencek kısım*/
    {                                                                       /*maksimumdan küçükse maximum boyuta gelen kadar ekleme yapılır*/
        for(i=copied;i<MAX_LENGTH-1;i++)
        {
            str[i]=tempstr[j];
        }
        str[i]='\0';
    }

    for(i=num;i<copied;i++)                                                 /*Normal boyutlu ekleme islemi gerçekleştirilir*/
    {
        str[i]=tempstr[j];
        j++;
    }
    str[i]='\0';
}
void mutation(char str[MAX_LENGTH])                                         /*Mutasyona ugratma fonksiyonu*/
{
    int i,temp;
    srand(time(NULL));

    for(i=MAX_LENGTH-1;str[i]!='A';i--)                                     /*DNA'daki son adenin yeri bulunur*/

    temp=rand()%3;                                                          /*Baska bir nükleosid ile zamana göre random degeri*/
                                                                            /*atılarak degisiklik yapılır*/
    if(temp==0)
    {
        str[i]='G';
    }
    else if(temp==1)
    {
        str[i]='T';
    }
    else
    {
        str[i]='C';
    }
}
int crossover(char str[MAX_LENGTH],char tempstr[MAX_LENGTH],int length)     /*Çaprazlama fonksiyonu*/
{
    int i,j=0,num1,num2;
    char temp;

    for(i=0;str[i]!='T';i++)                                                /*İlk DNA'daki ilk timinin yeri bulunur*/
    num1=i+1;

    for(i=0;tempstr[i]!='\0';i++)                                           /*İkinci DNA'nın sonuna gelinir*/
    num2=i+1;

    for(i=num2;tempstr[i]!='G';i--)                                         /*İkinci DNA'daki son guaninin yeri bulunur*/
    num2=i-1;

    if(length<=(int)fabs((double)(num1-num2)))                              /*Çaprazlama alanı iki nükleotid arasındaki uzaklıktan küçük*/
    {                                                                       /*eşitse yani alan yeterliyse çaprazlama yapılır*/
        if(num1>num2)
        {
            for(i=num2;i<num2+length;i++)                                   /*Çaprazlama yeri bulunan timin ve guaninin birbiri içindeki*/
            {                                                               /*konumlarına göre yapılır*/
                temp=tempstr[i];
                tempstr[i]=str[num1-j];
                str[num1-j]=temp;
                j++;
            }
        }
        else if(num2>num1)
        {
            for(i=num1;i<num1+length;i++)
            {
                temp=str[i];
                str[i]=tempstr[num2-j];
                tempstr[num2-j]=temp;
                j++;
            }
        }
        return 1;                                                       /*Çaprazlam gerçekleşince doğru deger döndürülür*/
    }
    else
    {
        return 0;                                                       /*Gerçekleşmezse yanlış deger döndürülür*/
    }
}
int tendencyDisease(char str[MAX_LENGTH],char tempstr[MAX_LENGTH],int *length)   /*Hastalıga yatkınlık fonksiyonu*/
{
    int i,j=0,temp,tempi;

    temp=*length;                                                           /*Hastalık geni uzunlugu template içinde saklanır*/
    for(i=0;str[i]!='\0';i++)
    {
        if(tempstr[j]==str[i])                                              /*Hastalık geni sıra sıra Normal DNA'da aranır*/
        {
            tempi=i;
            while((str[i]==tempstr[j])&&(*length>1))                        /*Sıra sıra eş bulnukça uzunluk azaltılır*/
            {
                *length--;
                i++;
                j++;
            }
            if(*length==0)                                                  /*Uzunluk sıfırlanırsa hastalık geni bulunmuş demektir*/
            {                                                               /*Aksi takdirde uzunluk tekrardan eski haliğne alınır ve*/
                return 1;                                                   /*İşlem tekrar edilir,hastalım geni bulunmuşsa 1 döndürülür*/
            }
            else
            {
                i=tempi;                                                    /*i ve length tekrardan eski degerine döndürülür*/
                *length=temp;                                               /*j 0'a döndürülür hastalık genine baştan bakılması için*/
                j=0;
            }
        }
    }
    return 0;                                                               /*Fonksiyonda çıkılmazsa hastalım geni bulmamış demektir*/
}                                                                           /*0 degeri döndürülür*/
double similarity(char DNA[MAX_LENGTH],char similarityDNA[MAX_LENGTH],int *DNAlength)  /*Benzerlik fonksiyonu*/
{
    int i,j,k;
    double max=0.0,temp=0.0;                                                /*max=en büyük benzer sıra,temp=program içinde max ile*/
                                                                            /*kontrol edilen benzerlik sırası uzunlugu*/
    for(i=0;DNA[i]!='\0';i++)
    {
        k=i;                                                                /*i degeri k'ya atanır*/
        for(j=0;similarityDNA[j]!='\0';j++)
        {
            if(DNA[k]==similarityDNA[j])                                    /*Benzer gen bulununca*/
            {
                temp+=1;                                                    /*Benzer gen sırası sayısı için temp attırılır*/
                k++;                                                        /*Devamlılık için k attırılır*/
                if(temp>=max)                                               /*Eger temp max degerinde büyükse temp max'a atanır*/
                {                                                           /*ve temp degeri sıfırlanır*/
                    max=temp;
                    temp=0.0;
                }
            }
        }
    }

    max = max / *DNAlength;                                                 /*Benzerlik oranı tespit edilir ve döndürülür*/

    return max;
}
void printDNA(char str[MAX_LENGTH])                                         /*DNA basılması fonksiyonu*/
{
    int i;

    for(i=0;str[i]!='\0';i++)                                               /*NULL karakterine kadar DNA ekrana basılır*/
    {
        printf("%c--",str[i]);
    }
    printf("\n");
}
void wait(double seconds)                                                   /*Program bekletme fonksiyonu*/
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait){}
}
int main()                                                                  /*Main fonksiyonu*/
{
    char DNA[MAX_LENGTH],                                                   /*DNA stringleri*/
         crossoverDNA[MAX_LENGTH],
         tendency[MAX_LENGTH],
         similarityDNA[MAX_LENGTH];

    int selection,                                                          /*Degişkenlerin imlementasyonları*/
        length,
        DNAlength,
        i;
    double similarityrate;

    initilizeDNA(DNA,&DNAlength);                                           /*Asıl olan DNA kullanıcıdan alınır ve ekrana basılır*/
    printf("Your DNA is:\n");
    printDNA(DNA);

    while(selection!=6)                                                     /*Menu*/
    {
        wait(WAIT_TIME);                                                    /*Program beklemesi*/
        system("cls");
        printf("Enter your selection:\n");                                  /*Menu*/
        printf("1.Cloning \n2.Mutation\n3.Crossover\n");
        printf("4.Similarity\n5.Tendency\n6.Exit\n");
        scanf("%d",&selection);

        switch(selection)                                                   /*Seçim degeri 6 olmadıkça menu tekrar eder*/
        {
        case 1:                                                             /*Klonlama*/
        clonDNA(DNA);
        printf("The clon DNA is:\n");
        printDNA(DNA);
        break;
        case 2:                                                             /*Mutasyon*/
        mutation(DNA);
        printf("After the mutution...\n");
        printDNA(DNA);
        break;
        case 3:                                                             /*Çaprazlama*/
        initilizeDNA(crossoverDNA,&DNAlength);                              /*Çaprazlanacak DNA oluşturulur*/
        printf("Enter the length to crossover this two DNAs:\n");
        scanf("%d",&length);
        if(!crossover(DNA,crossoverDNA,length))                             /*0 degeri için Error verir*/
        {
            printf("\nERROR in the crossover!!\n\n");
        }
        else                                                                /*1 degeri için çaprazlama işlemi olmuştur*/
        {                                                                   /*DNA'ların yeni halleri ekrana basılır*/
            printf("After the crossover your first DNA is:\n");
            printDNA(DNA);
            printf("After the crossover your second DNA is:\n");
            printDNA(crossoverDNA);
        }
        break;
        case 4:                                                             /*Benzerlik*/
        for(i=0;DNA[i]!='\0';i++)
        DNAlength=i+1;

        printf("Enter your similarity DNA nucleocid number %d\n",DNAlength);
        initilizeDNA(similarityDNA,&DNAlength);
        similarityrate=similarity(DNA,similarityDNA,&DNAlength);
        printf("This two DNA's similarity rate is %.2f per hundred\n",(similarityrate*100));
        break;
        case 5:                                                             /*Hastalık kontrolü*/
        printf("Your tendency length should be between 0 to 3\n");          /*Hastalık geni 0-3 aralıgında olması daha mantıklıdır*/
        initilizeDNA(tendency,&DNAlength);
        if(tendencyDisease(DNA,tendency,&DNAlength))                        /*1 degeri içn hastalık vardır*/
        {
            printf("\nThere is the tendency of that disease.I am sorry...\n");
        }
        else                                                                /*0 degerinde hastalık yoktur*/
        {
            printf("\nThere is not any tendency of that disease!!!\n");
        }
        break;
        case 6:                                                             /*Çıkış*/
        printf("Good Bye...");
        wait(WAIT_TIME);                                                    /*Yazı için program bekletilir ve çıkılır*/
        return 0;
        break;
        default:                                                            /*Yanlış girilen deger için error verilir ve menu tekrar açılır*/
        printf("\nERROR!!\n");
        printf("Please try again...\n");
        break;
        }
    }
    return 0;                                                               /*Program sonu*/
}

