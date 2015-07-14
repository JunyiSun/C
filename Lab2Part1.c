/* 
 * File:   main.c
 * Author: yiransunjunyi
 *
 * Created on September 22, 2014, 2:13 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //declare variables
int numMonths;
int freeMonths;
double swipeFeeRatePercentage;
double applePayRatePercentage;
double monthlyRate;
double swipeFeeRate;
double applePayRate;
double totalCharge;
double swipeFee;
double applePay;
const double HST=0.13;
//get the monthly rate and service duration from users
printf("Enter the monthly rate: ");
scanf("%lf", &monthlyRate); 
printf("Enter the service duration(in months): ");
scanf("%d", &numMonths);    
//get the swipe fee rate in percentage and convert it
printf("Enter the swipe fee rate (in percentage): ");
scanf("%lf", &swipeFeeRatePercentage);
swipeFeeRate=swipeFeeRatePercentage/100;
//get the Apple Pay rate in percentage and convert it
printf("Enter the Apple Pay rate (in percentage): ");
scanf("%lf", &applePayRatePercentage);
applePayRate=applePayRatePercentage/100;
//calculate the free months and print it
freeMonths= numMonths/4; 
printf("Your total free month(s) using iBell's service is: %d\n", freeMonths);
//calculate the total charge and print it
totalCharge=(numMonths-freeMonths)*monthlyRate*(1+HST);
printf("Your total charge including taxes is: %.2lf\n", totalCharge);
//calculate the swipe fee and print it
swipeFee=totalCharge*swipeFeeRate;
printf("The swipe fee paid to Mastercard is: %.2lf\n", swipeFee);
//calculate the apple pay and print it
applePay=swipeFee*applePayRate;
printf("The fee paid to use Apple Pay is: %.2lf", applePay);
   return (EXIT_SUCCESS);
}

