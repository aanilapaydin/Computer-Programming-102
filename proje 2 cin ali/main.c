

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Postures.h"


#define WAITING_TIME 0.2    /* Wait time between postures */
#define START_POSITION 30   /* Initial Position of the character */
#define MIN_AVAILABLE_POSITION 0   /* Initial Position of the character */
#define MAX_AVAILABLE_POSITION 60   /* Initial Position of the character */


/* Directions that the character can turn or move */
typedef enum
{
    LEFT=-1,FRONT,RIGHT
} courses;

/* for possible error reasons */
typedef enum
{
    incorrectInput
} errors;


/* Display and initialization functions */
char menu();
void initialize(int ,int* , char [][WIDTH]);

/* Turning functions */
void turnLeft(int, int* , char [][WIDTH]);
void turnRight(int, int* , char [][WIDTH]);
void turnFront(int, int* , char [][WIDTH]);

/* Movement functions */
void walk(int, courses, int*, char [][WIDTH]);
void walkToRight(int, int* , char [][WIDTH]);
void walkToLeft(int, int* , char [][WIDTH]);
void move(int, char [][WIDTH], void (char [][WIDTH]));

/* Accessory functions */
void deleteCinAli(char [][WIDTH]);
void printCinAli(int , char [][WIDTH]);
void setStepNumber(int *step);
int increment(int* );
int decrement(int* );
void error(errors i);
void gameOver();
void flushInputBuffer();
void wait ( double );


int main()
{
    courses direction=FRONT;    /* Direction of the character */
    int     currentPosition=START_POSITION, /* Position of the character */
            step;   /* The step number that athe character moves in a direction */

    char    cinAli[HEIGHT][WIDTH], /* the Character of the Game*/
            action;    /* Type of action that user enters */

    /* Initialize Cin Ali */
    initialize(currentPosition, &direction, cinAli);

    /* Play game until user exits */
    do
    {
        /* Display menu and read the order user gave*/
        action=menu();
        /* Do the action */
        switch (action)
        {
            case '>': /* Move Right */
                setStepNumber(&step); /* Read and set the step number */
                turnRight(currentPosition, &direction, cinAli);
                walk(step, direction, &currentPosition, cinAli);
                break;
            case '<': /* Move left */
                setStepNumber(&step);
                turnLeft(currentPosition, &direction, cinAli);
                walk(step, direction, &currentPosition, cinAli);
                break;
            case '=': /* Turn Front */
                turnFront(currentPosition, &direction, cinAli);
                break;
            case 'r': /* Turn Right */
                turnRight(currentPosition, &direction, cinAli);
                break;
            case 'l': /* Turn Left */
                turnLeft(currentPosition, &direction, cinAli);
                break;
            case 'x': /* Exit */
                gameOver();
                break;
            default:
                error(incorrectInput); /* Incorrect input from the user */
                break;
        }
        flushInputBuffer(); /* Clean the input buffer */

    }while(action!='x');

    return 0;
}


/*
 *  Displays options for the user to select an available action
 *  Pre:  database accesses a binary file of product_t records that has
 *        been opened as an input file, and params is defined
 *  Post: It returns the chosen action
 */
char menu()
{
    char select;
    printf("\n\nEnter '>' for Cin Ali to walk right\n");
    printf("Enter '<' for Cin Ali to walk left\n");
    printf("Enter '=' for Cin Ali to turn front\n");
    printf("Enter 'r' for Cin Ali to turn right\n");
    printf("Enter 'l' for Cin Ali to turn left\n");
    printf("Enter 'x' to exit\n");
    scanf("%c",&select);
    return select;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void initialize(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=FRONT;
    move(currentPosition, character, frontPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void setStepNumber(int *step)
{
    printf("Step Number: ");
    scanf("%d", step);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void deleteCinAli(char character[][WIDTH])
{
    int i, j;
    for(i=0; i<HEIGHT; ++i)
    {
        for(j=0; j<WIDTH; ++j)
        {
            character[i][j]=' ';
        }
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void printCinAli(int currentPosition, char character[][WIDTH])
{
    int i, j;
    for(i=0; i<HEIGHT; ++i)
    {
        for(j=0; j<currentPosition; ++j)
        {
            printf(" ");
        }
        for(j=0; j<WIDTH; ++j)
        {
            printf("%c", character[i][j]);
        }
        printf("\n");
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void move(int currentPosition, char character[][WIDTH], void posture(char [][WIDTH]))
{
    system("clear");
    deleteCinAli(character);
    posture(character);
    printCinAli(currentPosition, character);
    wait(WAITING_TIME);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void turnLeft(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=LEFT;
    move(currentPosition, character, leftPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void turnRight(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=RIGHT;
    move(currentPosition, character, rightPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void turnFront(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=FRONT;
    move(currentPosition, character, frontPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void walk(int step, courses direction, int *currentPosition, char character[][WIDTH])
{
    switch (direction)
    {
        case LEFT:
            walkToLeft(step, currentPosition, character);
            break;
        case RIGHT:
            walkToRight(step, currentPosition, character);
            break;
        default:
            break;
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void walkToRight(int step, int* currentPosition, char character[][WIDTH])
{
    int i;
    for(i=0; i<step; ++i)
    {
        move(increment(currentPosition), character, toRightFootsDown);
        move(increment(currentPosition), character, toRightBeckFootUp);
        move(increment(currentPosition), character, toRightCenteral);
        move(increment(currentPosition), character, toRightFrontFootUp);
    }
    move(*currentPosition, character, rightPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void walkToLeft(int step, int* currentPosition, char character[][WIDTH])
{
    int i;
    for(i=0; i<step; ++i)
    {
        move(decrement(currentPosition), character, toLeftFootsDown);
        move(decrement(currentPosition), character, toLeftBeckFootUp);
        move(decrement(currentPosition), character, toLeftCenteral);
        move(decrement(currentPosition), character, toLeftRightFootUp);
    }
    move(*currentPosition, character, leftPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
int increment(int* position)
{
    if((*position)<MAX_AVAILABLE_POSITION)
        ++(*position);
    return *position;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
int decrement(int* position)
{
    if((*position)>MIN_AVAILABLE_POSITION)
        --(*position);
    return *position;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void error(errors i)
{
    switch(i)
    {
        case incorrectInput:
            printf("Please, enter the right input\n");
            break;
        default:
            break;
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void gameOver()
{
    printf("Game Over!");
    wait(1);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void wait ( double seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}



/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void flushInputBuffer()
{
    char junk;
    /* A loop that cleans the input buffer till '\n' character being entered*/
    do
    {
        scanf("%c",&junk);
    }while(junk!='\n');
}
