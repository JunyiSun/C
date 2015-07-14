/* 
 * File:   main.c
 * Author: yiransunjunyi
 *
 * Created on September 29, 2014, 11:40 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
int main(int argc, char** argv) {
    int threshold; 
    int obserBoilPoint;
    const int waterB=100;
    const int mercuryB=357;
    const int copperB=1187;
    const int silverB=2193;
    const int goldB=2660;
    printf("Enter the threshold in celsius: ");
    scanf("%d",& threshold);
    printf("Enter the observed boiling point in celsius: ");
    scanf("%d",& obserBoilPoint);
    if(fabs(obserBoilPoint-waterB)<=threshold)
    printf("The substance you tested is: Water");
    else 
        if(fabs(obserBoilPoint-mercuryB)<=threshold)
    printf("The substance you tested is: Mercury");
    else 
        if(fabs(obserBoilPoint-copperB)<=threshold)
    printf("The substance you tested is: Copper");
    else
        if(fabs(obserBoilPoint-silverB)<=threshold)
    printf("The substance you tested is: Silver");
    else
        if(fabs(obserBoilPoint-goldB)<=threshold)
    printf("The substance you tested is: Gold");
    else
        printf("Substance unknown.");
    return (EXIT_SUCCESS);
}

