/*
*   Ali Anil APAYDIN
*   Computer Science Engineering
*   091044042
*
*   Notes:RECURSION
*
*   Description:Bu program string.h kütüphanesindeki
*   sting fonksiyonlarýnýn recursion hallerinden oluþur.
*
*   References:GIT CSE 102 Summer Term HomeWork 04
*/
#include <stdio.h>                                                          /*printf,scanf*/

#define MAX_LENGTH 80                                                       /*Maximum string uzunlugu*/
#define QUIT 10

char *strchr(const char *str,char c)                                        /*Verilen karakteri string içinde arar ve karakteri ilk buldugu*/
{                                                                           /*adresi geri döndürür*/
	if (c==*str)
	{
	    return str;
	}
	else if (*str == '\0')
	{
	    return NULL;
	}
	else
	{
	    return(strchr(str+1,c));
	}
}

char *strncpy(char *dest, char *src, size_t n)                              /*Ýkinci stringden verilen deger kadar elemaný*/
{                                                                           /*ilkinin üzerine kopyalama*/
	if ((n>0) && (*src != '\0'))
	{
		*dest=*src;
	    strncpy(dest+1,src+1,n-1);
	}
	return dest;
}

char *strcpy(char *dest,const char *src)                                    /*Ýkinci stringi birincisinin ilk elemamnýndan itibaren*/
{                                                                           /*üzerine kopyalama*/
	if (*src != '\0')
	{
	    *dest = *src;
		strcpy(dest+1, src+1);
	}
	return dest;
}

int strncmp(char *str1, char *str2, size_t n)                               /*Verilen iki stringin n kadar elemenýný ascii tablosu*/
{                                                                           /*degerlerine gore karsýlastýrma*/
	if ((n==0) || (*str1=='\0') || (*str1 != *str2))
    {
        if(*str1>*str2)
	    {
	        return 1;
	    }
	    else if(*str1<*str2)
	    {
	        return -1;
	    }
	    else
	    {
	        return 0;
	    }
    }
	else
	{
	    return(strncmp(str1+1, str2+1, n-1));
	}
}

int strcmp(const char *str1, char *str2)                                    /*Verilen iki stringin bütün elemenlarýný ascii tablosu*/
{                                                                           /*degerlerine gore karsýlastýrma*/
	if ((*str1 == '\0') || (*str1 != *str2))
	{
	    if(*str1>*str2)
	    {
	        return 1;
	    }
	    else if(*str1<*str2)
	    {
	        return -1;
	    }
	    else
	    {
	        return 0;
	    }
	}
	else
	{
	return(strcmp(str1+1, str2+1));
	}
}

size_t strlen(const char *str)                                              /*Verilen dizinin son karakteri NULL'a kadar uzunlugunu bulma*/
{
	if (*str=='\0')
	{
	    return 0;
	}
	else
	{
	    return(1 + strlen(str+1));
	}
}

void print(const char *str)                                                 /*Verilen dizi ekrana bastýrma*/
{
    if(*str=='\0'){}
    else
    {
        printf("%c",*str);
        print(str+1);
    }

}
void printVertical(const char *str)                                         /*Verilen diziyi ekrana dikey olarak bastýrma*/
{
    if(*str=='\0'){}
    else
    {
        printf("%c\n");
        printVertical(str+1);
    }
}
void printReverse(const char *str)                                          /*Verilen diziyi ekrana tersten bastýrma*/
{
  char *dest;

  if(*str != '\0')
  {
        *dest-- = *str++;
        printf("%c",*dest);
        printReverse(str);
  }

}
char *strchr_minus(const char *str,char c)                                  /*strrchr için terten recursive olarak karakter arýyan*/
{                                                                           /*yardýmcý fonksiyon*/
    if(c==*str)
    {
        return str;
    }
    else
    {
        strchr_minus(str-1,c);
    }
}
char *strrchr(const char *str,char c)                                       /*Verilen karakteri string içinde arar ve karakteri son buldugu*/
{                                                                           /*adresi döndürür*/
    if (c==*str)
	{
	    strrchr(str+1,c);
	}
	else if(str==NULL)
	{
	    strchr_minus(str-1,c);
	}
	else
	{
	    strrchr(str+1,c);
	}
}
char *add_str(char *dest,const char *src)                                   /*strcat fonksiyonu için ekleme yapan yardýmcý fonksiyon*/
{
    if(*src!=NULL)
    {
        *dest=*src;
        add_str(dest+1,src+1);
    }
    else
    {
        return dest;
    }
}
char *strcat(char *dest,const char *src)                                    /*Verilen iki diziden ikincisini birincisinin sonuna ekler*/
{
    if(*dest!=NULL)
    {
        strcat(dest+1,src);
    }
    else
    {
        add_str(dest,src);
        return dest;
    }
}
char *add_strn(char *dest,const char *src,size_t n)                         /*strncat için ekleme yapan yardýmcý fonksiyon*/
{
    if(n!=0)
    {
        *dest=*src;
        add_strn(dest+1,src+1,n-1);
    }
    else
    {
        return dest;
    }
}
char *strncat(char *dest,const char *src,size_t n)                          /*Ýkinci dizideki verieln n kadar elemaný ilk dizinin*/
{                                                                           /*sonuna ekleme*/
    if(*dest!=NULL)
    {
        strncat(dest+1,src,n);
    }
    else
    {
        add_strn(dest,src,n);
        return dest;
    }
}
int main(void)                                                              /*Main fonksiyonu*/
{
    char str1[MAX_LENGTH]="ali anil";
    char str2[MAX_LENGTH]=" onur";
    int selection=0;
    char c;
    size_t n;

    while(selection!=QUIT)                                                  /*Menu*/
    {
        printf("1.Strcat\n2.Strncat\n3.Strchr\n4.Strrchr\n");
        printf("5.Strcmp\n6.Strncmp\n7.Strcpy\n8.Strncpy\n");
        printf("9.Strlen\n10.Quit\n");
        printf("Enter your selection\n");
        scanf("%d",&selection);

        switch(selection)
        {
            case 1:
            strcat(str1,str2);
            printf("%s\n",str1);
            break;
            case 2:
            printf("Enter the number of character you want to add\n");
            scanf("%d",&n);
            strncat(str1,str2,n);
            printf("%s\n",str2);
            break;
            case 3:
            printf("Enter the char you want to search\n");
            scanf("%c",&c);
            strchr(str1,c);
            break;
            case 4:
            printf("Enter the char you want to search\n");
            scanf("%c",&c);
            strrchr(str1,c);
            break;
            case 5:
            printf("%d\n",strcmp(str1,str2));
            break;
            case 6:
            printf("Enter the number of character you want to compare\n");
            scanf("%d",&n);
            printf("%d\n",strncmp(str1,str2,n));
            break;
            case 7:
            strcpy(str1,str2);
            printf("%s\n",str1);
            break;
            case 8:
            printf("Enter the number of character you want to copy\n");
            scanf("%d",&n);
            strncpy(str1,str2,n);
            printf("%s\n",str1);
            break;
            case 9:
            printf("%d\n",strlen(str1));
            break;
            case 10:
            return 0;
            break;
        }
    }
    return 0;
}
