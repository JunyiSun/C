/* 
 * File:   main.c
 * Author: yiransunjunyi
 *
 * Created on September 15, 2014, 9:29 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //declare the variable
    int inputNumber1;
    int inputNumber2;
    int Sum;
    int Difference;
    int Product;
    int Division;
    //get the first number from users
    printf("Enter First Number: ");
    scanf("%d",&inputNumber1);
    //get the second number from users
    printf("Enter Second Number: ");
    scanf("%d",&inputNumber2);
    //get the sum&print
    Sum=inputNumber1+inputNumber2;
    printf("Sum: %d\n",Sum);
    //get the difference&print
    Difference=inputNumber1-inputNumber2;
    printf("Difference: %d\n",Difference);
    //get the product&print
    Product=inputNumber1*inputNumber2;
    printf("Product: %d\n",Product);
    //get the division&print
    Division=inputNumber1/inputNumber2;
    printf("Division: %d\n",Division);
    return (EXIT_SUCCESS);
}

