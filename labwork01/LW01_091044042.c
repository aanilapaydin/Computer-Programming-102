/*
*	Created by Ali Anıl APAYDIN
*	Number:091044042
*	File:LW_01_091044042.c
*	
*	Date:24/02/2012
*	
*	Description:This Program converts a 
* 		    Celcius value to Fahrenheit
*/
#include <stdio.h>								/*fprintf,fscanf,fopen,fclose*/

int main()									/*Main function*/
{
 int celcius;									/*Celcius and Fahrenheit variables*/
 double fahrenheit;
 
 FILE *inputFilePtr,								/*Input and output file pointers*/
      *outputFilePtr;

 inputFilePtr=fopen("input.txt","r");						/*Opening input file*/

 fscanf(inputFilePtr,"%d",&celcius);						/*Scaning celcius value from input file*/

 fclose(inputFilePtr);								/*Closing input file pointer*/

 fahrenheit = (celcius * 1.8) + 32;						/*Converting celcius to fahrenheit*/

 outputFilePtr=fopen("output.txt","w");						/*Opening output file*/

 fprintf(outputFilePtr,"Input file scanning...\n"); 
 fprintf(outputFilePtr,"Celcius:%d to Fahrenheit:%.2f",celcius,fahrenheit);	/*Printing values in output file*/
	
 fclose(outputFilePtr);								/*Closing output file pointer*/
 
 return 0;									/*Program ending*/
}
