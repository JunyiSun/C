/* 
 * File:   main.c
 * Author: yiransunjunyi
 *
 * Created on October 7, 2014, 4:24 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int row,col,n;  //declare variables
    printf("Enter the number of rows in the triangle: ");  //get input of rows as n
    scanf("%d",&n);
    for (int row=1; row<=(n-1); row++){  //for loop to control row,start with first row, when row number is less than n-1,do the next line, then increment 
        for (int col=1; col<=(2*n-1); col++) //nested for loop to control column
        
        if ((col==n-row+1)||(col==n+row-1)) //at the column of n-row+1 and n=row-1 on each row, print a star
        printf ("*");
        else 
        printf (" "); //just keep a blank in other positions
        printf ("\n");} //move to the next line
    
    for (int col=1; col<=(2*n-1); col++)//just print 2n-1 stars in the last line
        printf ("*");
        return (EXIT_SUCCESS);
}

