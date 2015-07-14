/* 
 * File:   main.c
 * Author: yiransunjunyi
 *
 * Created on September 22, 2014, 10:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int inputNumber;
    int outputNumber;
    printf("Enter an encrypted 3-digit code: ");
    scanf("%d",&inputNumber);
    outputNumber=inputNumber/100+(inputNumber%10)*100+(9-inputNumber/10%10)*10;
    printf("The real 3-digit code is: %d",outputNumber);
    return (EXIT_SUCCESS);
}

