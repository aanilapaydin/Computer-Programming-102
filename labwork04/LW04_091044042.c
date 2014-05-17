/*
*   Created by Ali Anil APAYDİN
*
*   Date:16/03/2012
*
*   Description:This program prints upper,lower triangle anad diamond.
*
*   Notes: CSE 108 LW04_091044042_PART_1.c
*
*/


#include <stdio.h>
#include <stdlib.h>

int menu();
void upperTriangle();
void lowerTriangle();
void diamond();
void shapeOne();
void shapeTwo();
void shapeThree();
int printChar(char ,int );
int main()
{
 menu();

 return 0;

}
int menu()
{
 int selection=1;

 while(selection!=0)
 {
    printf("(1)Upper Triangle \n");
    printf("(2)Lower Triangle \n");
    printf("(3)Diamond \n");
    printf("(4)Shape One \n");
    printf("(5)Shape Two \n");
    printf("(6)Shape Three \n");
    printf("(0)Exit \n");
    printf("Enter your selection: \n");
    scanf("%d",&selection);
    system("cls");

    switch(selection)
    {
        case 1:
        upperTriangle();
        break;
        case 2:
        lowerTriangle();
        break;
        case 3:
        diamond();
        break;
        case 4:
        shapeOne();
        break;
        case 5:
        shapeTwo();
        break;
        case 6:
        shapeThree();
        break;
        case 0:
        printf("Goodbye! \n");
        return 0;
        break;
        default:
        printf("Wrong selection!! \n \n");
        break;
    }
 }
}
void upperTriangle()
{
 int height,
     i,
     j;

 printf("Enter the heigth \n");
 scanf("%d",&height);

 for(i=1;i<=height;++i)
 {
    printChar('*',i);
    printf("\n");
 }
}
void lowerTriangle()
{
 int height,
     i;

 printf("Enter the heigth \n");
 scanf("%d",&height);

 for(i=height;i>0;--i)
 {
    printChar('*',i);
    printf("\n");
 }
}
void diamond()
{
 int height,
     i;

 printf("Enter the heigth \n");
 scanf("%d",&height);

 if(height%2==0)
 {
    for(i=1;i<=height/2;++i)
    {
        printChar('*',i);
        printf("\n");
    }
    for(i=height/2;i>0;--i)
    {
        printChar('*',i);
        printf("\n");
    }
 }
 else
 {
    for(i=1;i<=(height/2)+1;++i)
    {
        printChar('*',i);
        printf("\n");
    }
    for(i=height/2;i>0;--i)
    {
        printChar('*',i);
        printf("\n");
    }
 }
}
void shapeOne()
{
 int height,
     i,j;

 printf("Enter the heigth \n");
 scanf("%d",&height);

 j=height-1;
 for(i=1;i<=(2*height)-1;i+=2)
 {
    printChar(' ',j);
    printChar('*',i);
    printf("\n");
    --j;
 }
}
void shapeTwo()
{
 int height,
     i,
     j;

 printf("Enter the heigth \n");
 scanf("%d",&height);

 j=0;
 for(i=(2*height)-1;i>0;i-=2)
 {
    printChar(' ',j);
    printChar('*',i);
    printf("\n");
    j++;
 }
}
void shapeThree()
{
 int height,
     i,
     j;

 printf("Enter the heigth \n");
 scanf("%d",&height);

 if(height%2==0)
 {
    j=(height/2)-1;
    height=height/2;
    for(i=1;i<=(2*height)-1;i+=2)
    {
        printChar(' ',j);
        printChar('*',i);
        printf("\n");
        j--;
    }
    j=0;
    for(i=(2*height)-1;i>0;i-=2)
    {
        printChar(' ',j);
        printChar('*',i);
        printf("\n");
        j++;
    }
 }
 else
 {
    j=(height/2);
    height=(height/2)+1;
    for(i=1;i<=(2*height)-1;i+=2)
    {
        printChar(' ',j);
        printChar('*',i);
        printf("\n");
        j--;
    }
    j=1;
    for(i=(2*height)-3;i>0;i-=2)
    {
        printChar(' ',j);
        printChar('*',i);
        printf("\n");
        j++;
    }
 }
}
int printChar(char a,int n)
{
 int i,count=0;
 if(n<0)
 {
    printf("Invalid number!");
    return -1;
 }
 else
 {
    for(i=0;i<n;++i)
    {
       count += printf("%c ",a);
    }
    return count;
 }
}
