/* 
 * File:   main.c
 * Author: yiransunjunyi 
 *
 * Created on October 6, 2014, 4:12 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables 
    //nuC=number of Cent,nuQ=number of Quarter,nuQ=number of dime,nuN=number of Nickel
    //reCeQ=remain cents after Quarter, reCeD=remain cents after Dime,remain cents after Nickel
    int nuC,nuQ,nuD,nuN,reCeQ,reCeD,reCeN; 
    do{     //do the statement when number of cents is between 1 and 99
        printf("Please give an amount in cents less than 100: "); //get the input cents from users 
        scanf("%d",&nuC);
    nuQ=nuC/25;  //calculate number of each coins and remain cents
    reCeQ=nuC%25;
    nuD=reCeQ/10;
    reCeD=reCeQ%10;
    nuN=reCeD/5;
    reCeN=reCeD%5;
    if (nuC<1 || nuC>99)  //if the input is out of range, print goodbye
    printf ("Goodbye");
    else {            //if the input is in the range, run the following  
    if (nuC==1)         // if the input is just 1 cent, print 1 cent
    printf ("1 cent: ");
    else                      
    printf("%d cents: ",nuC);  //or print the input of cents
    
    if (nuQ==1){        //if the quarter is just 1, print 1 quarter
    printf("1 quarter");
         if (nuD==1)         //after, if the Dime is just 1, print 1 dime
         printf(", 1 dime");
         else if (nuD>1)
         printf(", % dimes",nuD); //or print number of dimes
         
             if (nuN==1)    //after, if the Nickel is just 1, print 1 nickel
             printf(", 1 nickel");
             else if (nuN>1)     //or print number of nickels
             printf(", %d nickels",nuN);
             
                 if (reCeN==1)    //same as 1 cent and number of cents
                 printf(", 1 cent");
                 else if (reCeN>1)
                 printf(", %d cents",reCeN);
    }
    
    else if (nuQ>1){        //or print the number of quarters, and after, the following are the same
    printf("%d quarters",nuQ);
         if (nuD==1)
         printf(", 1 dime");
         else if (nuD>1)
         printf(", %d dimes",nuD);
         
             if (nuN==1)
             printf(", 1 nickel");
             else if (nuN>1)
             printf(", %d nickels",nuN);
             
                 if (reCeN==1)
                 printf(", 1 cent");
                 else if (reCeN>1)
                 printf(", %d cents",reCeN);
    }
    else if (nuQ==0){      // or no need to print quarters, just jump to the next type of coin
         if (nuD==1)
         printf("1 dime");
         else if(nuD>1)
         printf("% dimes",nuD);
         
             if (nuN==1)
             printf("1 nickel");
             else if (nuN>1)
             printf("%d nickels",nuN);
             
                 if (reCeN==1)
                 printf("1 cent");
                 else if (reCeN>1)
                 printf("%d cents",reCeN);
    }
        printf(".\n"); //print a period at the end of the each sentence
    } 
    }
    while ((nuC>1)&&(nuC<99));  //when the input number is not between 1 and 99, exit the do loop
         
    return (EXIT_SUCCESS);
}

