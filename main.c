/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**************************************************************************/
/* Macro Defines
 **************************************************************************/

/**************************************************************************/
/* Function prototypes
 **************************************************************************/
void display();
int dice();
void win(int,int);
int rando();

/**************************************************************************/
/* Global variables
 **************************************************************************/


/**************************************************************************
 * Main
 *    Reads a number in between MIN and MAX from the keyboard
 *    Reports errors encountered 
 *    Returns 0 on success
 *            1 on failure
 **************************************************************************/
int main( void ) {
    int loop = 0;
    char cont;

    srand((unsigned int) time(NULL));
    while (loop == 0) {
        fflush(stdin);
        printf("ROLL THE DICE WITH [ENTER]\n");
        getchar();
        display();
        dice();
        printf("Continue (y/n)?\n");
        scanf("%c", &cont);
        if (cont == 'n') {
            loop = 1;
        }
    }

    return EXIT_SUCCESS;
}


//displays header for dice
void display(){
    printf("--------------------------------------------------------------\n");
    printf("ROLL NUM     DIE #1     DIE #2     TOTAL ROLL     POINT MATCH\n");
    printf("--------------------------------------------------------------\n");
}

//handles the dice rolling
int dice(){
    int die1,die2,point,total;
    point = 0;
    for(int i = 1;i < 4;i++){
        die1 = rando();
        die2 = rando();
        total = die1 + die2;


        if(i == 1){
            //if its the first roll
            point = total;
            printf("1     %d     %d     %d     %d\n",die1,die2,total,point);
            if(total == 7){
                //win on 7
                win(total,0);
                return 0;
            }else if(total == 11){
                //win on 11
                win(total,0);
                return 0;
            }else if(total == 2){
                //lose on 2
                win(total,1);
                return 1;
            }else if(total == 3){
                //lose on 3
                win(total,1);
                return 1;
            }else if(total == 12){
                //lose on 12
                win(total,1);
                return 1;
            }
        }else{
            printf("%d     %d     %d     %d     %d\n",i,die1,die2,total,point);
            if(total == 7){
                //lost if 7 is rolled second or third
                win(total,1);
                return 1;
            }else if(total == point){
                //win if total matches point
                win(total,0);
                return 0;
            }

    }}
        printf("Did not meet winning conditions\n");
        return 1;

}

//returns random number for dice roll
int rando(){
    return (rand() % 6) + 1 ;
}

//win/lose message
void win(int num,int res){
    if(res == 0){
        printf("You rolled: %d and won\n",num);
    }else{
        printf("You rolled: %d and lost\n",num);
    }
}
