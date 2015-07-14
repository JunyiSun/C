/* 
 * File:   main.c
 * Author: yiransunjunyi
 *
 * Created on September 29, 2014, 10:32 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
int main(int argc, char** argv){
    //declare variables
    int P,D,n; //P=purchase price,D=down payment,n=finance term
    double r,rPercentage,M,x,y;//r=monthly interest rate, M=monthly payment
    //get the purchase price from users
    printf("Enter the purchase price: ");
    scanf("%d",&P);
    //get the down payment from users
    printf("Enter the amount of down payment: ");
    scanf("%d",&D);
    //get the finance term from users
    printf("Enter the finance term(in months): ");
    scanf("%d",&n);
    //get the monthly interest rate
    printf("Enter the monthly interest rate(in percentage): ");
    scanf("%lf",&rPercentage);
    r=rPercentage/100;
    //calculate the monthly payment
    M=((P-D)*r*pow(1+r,n))/(pow(1+r,n)-1);
    printf("The monthly payment is: %.2lf",M);
    return (EXIT_SUCCESS);
}

