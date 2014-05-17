#include <stdio.h>
#include <stdlib.h>

#define TOTAL_TL_MONEY 10000
#define BUFFER_SIZE 255
#define MAX_DAY 13


void readExchangeRates();
int executionPart();
double takeAdviceFromA(double ,double ,double ,double ,double ,double );
double takeAdviceFromB(double ,double ,double ,double ,double ,double );
double takeAdviceFromC(double ,double ,double ,double ,double ,double );
double calculateCapital();
int checkPossibility(int possibility);
void generateReport();
int main()
{
    srand(time(NULL));

    double euro,
            dollar,
            pound;


    return executionPart();
}
int executionPart()
{

    FILE *inp;

    int day=1;
    char firstChoice;

    int secondChoice;
    int currentDay = 1,
        nextDay = 1;

    char c;
    double currentEuro,currentDollar,currentPound,
            nextEuro,nextDollar,nextPound;

    inp = fopen("ExchangeRates.txt","r");

    if(inp == NULL)
    {
        printf("Cannot open the file..\n");
        return 1;
    }

    do{
        fscanf(inp,"%c",&c);
    }while(c!='\n');

    while(day<=MAX_DAY)
    {

        if(day==1)
        {
            fscanf(inp,"%d %lf %lf %lf",&currentDay,&currentEuro,&currentDollar,&currentPound);
            fscanf(inp,"%d %lf %lf %lf",&nextDay ,&nextEuro ,&nextDollar ,&nextPound);
        }
        else if(day==MAX_DAY)
        {
            printf("Today is last day... \n");
            printf("Program calculates your fortune in TL...\n");
            //serveti tl cinsinden hesapla ve bas ve cýk
        }
        else
        {
           fscanf(inp,"%d %lf %lf %lf",&nextDay,&nextEuro,&nextDollar,&nextPound);
        }


        printf("Today:%d Euro:%.3f Dollar:%.3f Pound:%.3f\n",currentDay,currentEuro,currentDollar,currentPound);
        printf("If you want to take some advice press (Y)\nIf not press any key:\n");
        scanf(" %c" ,&firstChoice);

        if((firstChoice == 'Y') || (firstChoice == 'y'))
        {

            printf("Take advice to A Advisor enter : 1\n");
            printf("Take advice to B Advisor enter : 2\n");
            printf("Take advice to C Advisor enter : 3\n");

            scanf("%d" ,&secondChoice);

            switch(secondChoice)
            {
                case 1:
                takeAdviceFromA(currentDollar,currentEuro,currentPound,nextDollar,nextEuro,nextPound);
                break;
                case 2:
                takeAdviceFromB(currentDollar,currentEuro,currentPound,nextDollar,nextEuro,nextPound);
                break;
                case 3:
                takeAdviceFromC(currentDollar,currentEuro,currentPound,nextDollar,nextEuro,nextPound);
                break;
                default :
                printf("Illegal choice !\nProgram will be terminated..\n");
            }
        }
        else
        {
            //calculateCapital();
        }


        currentDay=nextDay;
        currentDollar=nextDollar;
        currentEuro=nextEuro;
        currentPound=nextPound;
        day++;
    }

}
int checkPossibility(int possibility)
{
    int randomNumber;

    randomNumber = (rand() % 100) + 1;

    if(randomNumber <= possibility)
    {
        return 1;
    }
    return 0;
}

double takeAdviceFromA(double currentDollar,double currentEuro,double currentPound,
                        double nextDollar,double nextEuro,double nextPound)
{
    double rate_a,rate_b,rate_c,rate_max;

    srand(time(NULL));

    rate_a = ((nextEuro - currentEuro)/currentEuro)*100;
    rate_b = ((nextDollar - currentDollar)/currentDollar)*100;
    rate_c = ((nextPound - currentPound)/currentPound)*100;

    if(rate_a<=rate_b)
        rate_max=rate_b;
    else
        rate_max=rate_a;
    if(rate_max<=rate_c)
        rate_max=rate_c;

    switch(rand()%4)
    {
        case 0:
        case 1:
        case 2:
            if(rate_max==rate_a)
                printf("You must buy euro I think \n");
            else if(rate_max==rate_b)
                printf("You must buy dollar I think \n");
            else
                printf("You must buy pound I think \n");
        break;
        default:
            if(rate_max==rate_a)
            {
                if(rand()%2==0)
                    printf("You must buy dollar I think \n");
                else
                    printf("You must buy pound I think \n");
            }
            if(rate_max==rate_b)
            {
                if(rand()%2==0)
                    printf("You must buy euro I think \n");
                else
                    printf("You must buy pound I think \n");
            }
            else
            {
                if(rand()%2==0)
                    printf("You must buy euro I think \n");
                else
                    printf("You must buy dollar I think \n");
            }
        break;
    }

    return 0;
}

double takeAdviceFromB(double currentDollar,double currentEuro,double currentPound,
                        double nextDollar,double nextEuro,double nextPound)
{
    double rate_a,rate_b,rate_c,rate_max;

    srand(time(NULL));

    rate_a = ((nextEuro - currentEuro)/currentEuro)*100;
    rate_b = ((nextDollar - currentDollar)/currentDollar)*100;
    rate_c = ((nextPound - currentPound)/currentPound)*100;

    if(rate_a<=rate_b)
        rate_max=rate_b;
    else
        rate_max=rate_a;
    if(rate_max<=rate_c)
        rate_max=rate_c;

    switch(rand()%4)
    {
        case 0:
        case 1:
            if(rate_max==rate_a)
                printf("You must buy euro I think \n");
            else if(rate_max==rate_b)
                printf("You must buy dollar I think \n");
            else
                printf("You must buy pound I think \n");
        break;
        default:
            if(rate_max==rate_a)
            {
                if(rand()%2==0)
                    printf("You must buy dollar I think \n");
                else
                    printf("You must buy pound I think \n");
            }
            if(rate_max==rate_b)
            {
                if(rand()%2==0)
                    printf("You must buy euro I think \n");
                else
                    printf("You must buy pound I think \n");
            }
            else
            {
                if(rand()%2==0)
                    printf("You must buy euro I think \n");
                else
                    printf("You must buy dollar I think \n");
            }
        break;
    }

    return 0;
}

double takeAdviceFromC(double currentDollar,double currentEuro,double currentPound,
                        double nextDollar,double nextEuro,double nextPound)
{
    double rate_a,rate_b,rate_c,rate_max;

    srand(time(NULL));

    rate_a = ((nextEuro - currentEuro)/currentEuro)*100;
    rate_b = ((nextDollar - currentDollar)/currentDollar)*100;
    rate_c = ((nextPound - currentPound)/currentPound)*100;

    if(rate_a<=rate_b)
        rate_max=rate_b;
    else
        rate_max=rate_a;
    if(rate_max<=rate_c)
        rate_max=rate_c;

    switch(rand()%10)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            if(rate_max==rate_a)
                printf("You must buy euro I think \n");
            else if(rate_max==rate_b)
                printf("You must buy dollar I think \n");
            else
                printf("You must buy pound I think \n");
        break;
        default:
            if(rate_max==rate_a)
            {
                if(rand()%2==0)
                    printf("You must buy dollar I think \n");
                else
                    printf("You must buy pound I think \n");
            }
            if(rate_max==rate_b)
            {
                if(rand()%2==0)
                    printf("You must buy euro I think \n");
                else
                    printf("You must buy pound I think \n");
            }
            else
            {
                if(rand()%2==0)
                    printf("You must buy euro I think \n");
                else
                    printf("You must buy dollar I think \n");
            }
        break;
    }

    return 0;
}

double calculateCapital()
{
    char currencyToPay;

    printf("Enter the currency (E)uro , (D)ollar , (P)ound to pay in :\n");
    scanf(" %c" ,&currencyToPay);

    switch(currencyToPay)
    {
        case 'E':
        case 'e':



        break;
        case 'D':
        case 'd':


        break;
        case 'P':
        case 'p':


        break;
        default:
            printf("Illegal choice ! Program will be terminated ...\n");
            return 0;

    }
}



void generateReport()
{

}
