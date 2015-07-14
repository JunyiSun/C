/* 
 * File:   Lab6.c
 * Author: yiransunjunyi
 *
 * Created on October 27, 2014, 8:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int DNA[] = {1, 2, 4, 2, 2, 2, 1, 4, 4, 2, 3, 4, 4, 4, 2, 1, 4, 1,
    3, 3, 2, 1, 3, 2, 1, 1, 2, 2, 2, 3, 4, 1, 3, 1, 2, 1,
    4, 4, 4, 1, 1, 3, 1, 4, 2, 4, 4, 1, 4, 4, 1, 4, 4, 4,
    4, 1, 1, 2, 3, 3, 3, 3, 4, 4, 3, 2, 3, 2, 3, 4, 3, 3,
    4, 4, 1, 3, 3, 2, 1, 2, 3, 1, 2, 1, 3, 3, 2, 1, 4, 1,
    4, 3, 4, 4, 4, 1, 2, 1, 3, 2, 0};

void match(int i, int length, int *sequence) {
    for (i = 0; DNA[i] != 0; i++) {//search every element in DNA array until meet 0
        bool isDNA = false;
        if (DNA[i] == sequence[0] || sequence[0] == 5) {
            isDNA = true;//when the first input number is 5 or the same as one DNA element, keep comparing the next number 
            int j;
            for (j = 1; j <= length - 1 && isDNA; j++)
                if (DNA[i + j] != sequence[j] && sequence[j] != 5)//if the next number is not 5 or not matching with DNA,leave the for loop
                    isDNA = false;
        }
        if (isDNA == true)
            printf("Match of search sequence found at element: %d\n", i);
    }
}

bool judge(int i, int length, int *sequence) {
    bool toMatch = true, returnNum;
    for (i = 0; i <= length - 1; i++)
        if (sequence[i] < 1 || sequence[i] > 5) {
            printf("Erroneous character input ’%d’ exiting\n", sequence[i]);
            toMatch = false;
            returnNum = true;//if there are illegal inputs,return true to leave the while loop
        }
    if (toMatch==true) {
        match(i, length, sequence);//if there is no illegal inputs, call the function match
        returnNum = false;
    }
    return returnNum;
}

int main(int argc, char** argv) {
    int length;
    int *sequence;//declare a pointer pointing to the array
    int i;
    bool done = false;
    while (done == false) { //into the while loop
        printf("Enter length of DNA sequence to match: ");  
        scanf("%d", &length);
        if (length > 0) {  
            printf("Enter %d characters (one of 12345) as a search sequence: ", length);
            sequence = (int*) malloc(length * sizeof (int));  //request memory from the operating system to the dynamic array
            for (i = 0; i <= length - 1; i++)
                scanf("%1d", &sequence[i]);//scan one number that users input into several one digit numbers
            done = judge(i, length, sequence);//call the function judge 
        } else
            done = true;//if the length is negative, leave the while loop
    }
    printf("Goodbye");
    free(sequence);//release unused memory
    return (EXIT_SUCCESS);
}
