/* 
 * File:   Lab5.c
 * Author: yiransunjunyi 
 * Student Number:1001350183\9 
 *
 * Created on October 21, 2014, 8:27 PM
 */

#include <stdio.h>

int factorial(int n) {      //function to calculate the factorial of input n
    int i;
    int result = 1;
    for (i = 1; i <= n; i++)
        result *= i;
    return result;
}

int choose(int a, int b) {  //function to calculate aCb
    int value;
    value = factorial(a) / (factorial(b) * factorial(a - b));
    return value;
}

void triangle(int row) {   //function to print the triangle
    int a, b;
    for (a = 0; a < row; a++) {
        for (b = 0; b < 3*row - 3*a - 3; b++)
            printf(" ");          //print spaces when the column# when b < 3*row - 3*a - 3
        for (b = 0; b <= a; b++)
            printf("%-6d", choose(a, b));  //print the value of aCb at b<=a, have 6 positions in total and spaces are after each number
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int row;
    do {
        printf("What is the number of the row in the Pascal's triangle? ");//get the row number from users
        scanf("%d", &row);
        if (row <= 13) {
            triangle(row);  //run the function triangle
            printf("\n");
        }
    } while (row >= 0 && row <= 13);
    return 0;
}


