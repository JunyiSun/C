/* 
 * File:   Lab99999999999.c
 * Author: yiransunjunyi
 *
 * Created on November 19, 2014, 3:13 AM
 */
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//function to print the board

// Maximum depth to be below 1 second is 3 for 21 squares 
#define MAX_DEPTH 3

//#define DEBUGME 1

static int slotsLeft;
static int lastA;
static int lastB;

void printboard(int n, char board[n][n]) {
    int r, s;
    for (r = 0; r < n; r++) {
        for (s = 0; s < n; s++) {
            printf("%c", board[r][s]);
        }
        printf("\n");
    }
}

// Function to find the max number

int iMax(int firstN, int secoN) {
    if (firstN > secoN)
        return firstN;
    else
        return secoN;
}
// Function to find the min number
int iMin(int firstN, int secoN) {
    if (firstN > secoN)
        return secoN;
    else
        return firstN;
}
//function to find the longest

int findLongest(int n, char board[n][n], int a, int b) {
    //check horizontal line
    int horiSum = 0;
    int e, f;
    e = a;
    for (f = b; f < n; f++)//right side of the position
        if (board[e][f] == board[a][b])
            horiSum++;
        else
            break;
    for (f = b; f >= 0; f--)//left side of the position
        if (board[e][f] == board[a][b])
            horiSum++;
        else
            break;
    horiSum = horiSum - 1;
    //check vertical line
    int vertiSum = 0;
    int c, d;
    d = b;
    for (c = a; c < n; c++)//lower side of the position
        if (board[c][d] == board[a][b])
            vertiSum++;
        else
            break;
    for (c = a; c >= 0; c--)//upper side of the position
        if (board[c][d] == board[a][b])
            vertiSum++;
        else
            break;
    vertiSum = vertiSum - 1;
    //diagonal form upper left to down right
    int diaSum1 = 1;
    int h;
    for (h = 1; h < (n - a) && h < (n - b); h++)
        if (board[a + h][b + h] == board[a][b])
            diaSum1++;
        else
            break;
    for (h = 1; h <= a && h <= b; h++)
        if (board[a - h][b - h] == board[a][b])
            diaSum1++;
        else
            break;
    //diagonal from upper right to down left
    int diaSum2 = 1;
    for (h = 1; h < (n - a) && h <= b; h++)
        if (board[a + h][b - h] == board[a][b])
            diaSum2++;
        else
            break;
    for (h = 1; h <= a && h < (n - b); h++)
        if (board[a - h][b + h] == board[a][b])
            diaSum2++;
        else
            break;
    int longest; //compare different sums and find the biggest one
    longest = iMax(horiSum, vertiSum);
    longest = iMax(longest, diaSum1);
    longest = iMax(longest, diaSum2);
    return longest;
}

int findBiggest(int n, char board[n][n], int a, int b) {
    //check horizontal line
    int horiSum = 0;
    int e, f;
    e = a;
    for (f = b; f < n; f++)//right side of the position
        if (board[e][f] == board[a][b])
            horiSum++;
        else
            break;
    for (f = b; f >= 0; f--)//left side of the position
        if (board[e][f] == board[a][b])
            horiSum++;
        else
            break;
    horiSum = horiSum - 1;
    //check vertical line
    int vertiSum = 0;
    int c, d;
    d = b;
    for (c = a; c < n; c++)//lower side of the position
        if (board[c][d] == board[a][b])
            vertiSum++;
        else
            break;
    for (c = a; c >= 0; c--)//upper side of the position
        if (board[c][d] == board[a][b])
            vertiSum++;
        else
            break;
    vertiSum = vertiSum - 1;
    //diagonal form upper left to down right
    int diaSum1 = 1;
    int h;
    for (h = 1; h < (n - a) && h < (n - b); h++)
        if (board[a + h][b + h] == board[a][b])
            diaSum1++;
        else
            break;
    for (h = 1; h <= a && h <= b; h++)
        if (board[a - h][b - h] == board[a][b])
            diaSum1++;
        else
            break;
    //diagonal from upper right to down left
    int diaSum2 = 1;
    for (h = 1; h < (n - a) && h <= b; h++)
        if (board[a + h][b - h] == board[a][b])
            diaSum2++;
        else
            break;
    for (h = 1; h <= a && h < (n - b); h++)
        if (board[a - h][b + h] == board[a][b])
            diaSum2++;
        else
            break;
    int longest; //compare different sums and find the biggest one
    longest = horiSum + vertiSum + diaSum1 + diaSum2;
    return longest;
}
//whether it's draw or not

bool draw(int a, int b, int n, char board[n][n]) {

    if (slotsLeft > 0)
        return false;
    return true;
}

//function to check who wins

bool whoWin(int n, char board[n][n], int a, int b) {
#ifdef DEBUGME 
    printf("%d\n", findLongest(n, board, a, b));
        #endif 

    if (findLongest(n, board, a, b) >= 6) {
        if (board[a][b] == 'B') {
            printf("\nBlack player wins.");

        }
        else {
            printf("\nWhite player wins.");
        }
        return true;
    }
    return false;
    
}

// Score Function from Lab 8 
//calculating the sum of black score and white score

int mostSum(int n, char board[n][n], int a, int b) {
    int mostB;
    int mostW;
    board[a][b] = 'B';
    mostB = findLongest(n, board, a, b);
    board[a][b] = 'W';
    mostW = findLongest(n, board, a, b);
    board[a][b] = 'U'; // reset back to Unoccupied 
    return mostB + mostW;
}

// To prevent opponent from winning 

int goodness(int n, char board[n][n], int a, int b) {
    int mostB;
    int mostW;
    board[a][b] = 'B';
    mostB = findLongest(n, board, a, b);
    board[a][b] = 'W';
    mostW = findLongest(n, board, a, b);
    board[a][b] = 'U';
    int goodness = mostB + mostW; // same as score function 
    if (mostB == 6)
        goodness = goodness + 500;
    if (mostW == 6)
        goodness = goodness + 400;
    if (mostB == 5)
        goodness = goodness + 300;
    return goodness;
}

bool emergency1(int n, char board[n][n], int a, int b) {
    int mostB;
    board[a][b] = 'B';
    mostB = findLongest(n, board, a, b);
    board[a][b] = 'U';
    if (mostB == 6)
        return true;
    else return false;
}

bool emergency2(int n, char board[n][n], int a, int b) {
    int mostW;
    board[a][b] = 'W';
    mostW = findLongest(n, board, a, b);
    board[a][b] = 'U';
    if (mostW == 6)
        return true;
    else return false;
}
// To prevent opponent from winning

int recurseHelper(int n, char board[n][n], int a, int b) {
    int mostB;
    int mostW;
    char original = board[a][b];
    board[a][b] = 'B';
    mostB = findLongest(n, board, a, b);
    board[a][b] = 'W';
    mostW = findLongest(n, board, a, b);
    board[a][b] = 'U';
    int goodness = 3*mostB + mostW; // same as score function
    if (mostB == 6)
       goodness += 500;
   if (mostB == 5)
        goodness += 300;
    board[a][b] = original; // reset to original value 
    return goodness;
}

// Note: Can only call this function if you start first ('Black!')

int recurseDepth(int n, char board[n][n], int a, int b, int depth, int* finalA, int* finalB) {
    // Initialize to no position
    *finalA = -1;
    *finalB = -1;
#ifdef DEBUGME
    printf("lalala\n");
#endif 
    if (depth < 0) return 0; 
    int tempUseless;
    if (draw(tempUseless, tempUseless, n, board) == true) {
#ifdef DEBUGME
    printf("IT IS DRAW\n");
#endif 
        // This is the only move left
        *finalA = a;
        *finalB = b;
        return 0;
    }
    int condition = -1; // start with smallest possible value
    int newA, newB;
    int temp;
    for (newA = a - 1; newA <= a + 1; newA++) {
        for (newB = b - 1; newB <= b + 1; newB++) {
            if (newA >= 0 && newA < n && newB >= 0 && newB < n && board[newA][newB] == 'U') {
                // Mark position as filled
                board[newA][newB] = 'B';
                // If it is a draw, don't bother doing anything else
                if (draw(newA, newB, n, board) == true) {
                    // This is the only move left
             //       *finalA = newA;
               //     *finalB = newB;
                    return 0;
                } else {
                    // Guess what move white is going to make and make it, assuming white is being defensive
                    int mostScore = -1;
                    int maxRow, maxCol;
                    int a1;
                    int b1;
                    for (a1 = 0; a1 < n; a1++) {
                        for (b1 = 0; b1 < n; b1++)
                            if (board[a1][b1] == 'U') {
            
                                int temp2 = goodness(n, board, a1, b1);
                                if (temp2 > mostScore) {
                                    mostScore = temp2;
                                    maxRow = a1;
                                    maxCol = b1;
                                }
                            }
                    }
                    // Set the move guessed for white
                    board[maxRow][maxCol] = 'W';
                    int tempA = 0;
                    int tempB = 0;
                    // if it causes a draw, this will return temp as 0
                    int tempC = recurseDepth(n, board, newA, newB, depth - 1, &tempA, &tempB);

                    if (condition < tempC) {
                           #ifdef DEBUGME
    printf("condition is %d and tempC is %d \n", condition, tempC);
#endif              
                        condition = tempC;
                        *finalA = newA;
                        *finalB = newB;
                    }

                    // Unmark the position from White
                    board[maxRow][maxCol] = 'U';
                }
                // Unmark the position made by Black 
                board[newA][newB] = 'U';
            }
        }
    }
    // recurseHelper for being here, and condition for going else where.
    return condition + recurseHelper(n, board, a, b);
    // Thus, if finalA and finalB returns -1 , need find some other way of getting next position
}

int main(int argc, char** argv) {
    
    // Set up timer
    struct rusage usage; // a structure to hold "resource usage" (including time
    struct timeval start, end; // will hold the start and end times

    //print the original board
    int n;
    printf("Enter board dimensions (n), n>=6 and n<=21: ");
    scanf("%d", &n);
    int i, j;
    char board[n][n];
    slotsLeft = n*n; // initialize number of slots left 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("U");
            board[i][j] = 'U';
        }
        printf("\n");
    }
    //ask which color the computer will play
    char computer;
    printf("Computer playing B or W?: ");
    scanf(" %c", &computer);

    //block the space,change the U to R
    int x = 0, y = 0;
    bool done = false;
    while (done == false) {
        printf("Enter position (ROW COL) of blocked square; (-1 -1) to finish: ");
        scanf("%d %d", &x, &y);
        if (x>-1 && x < n && y> -1 && y < n && board[x][y] != 'U')
            printf("Position already occupied, try again\n");
        else if (x == -1 && y == -1)
            done = true;
        else if (x<-1 || x > n - 1 || y<-1 || y > n - 1)
            printf("Out of range row or column\n");
        else {
            board[x][y] = 'R';
            slotsLeft--;
            printboard(n, board);
        }
    }
    //play the game in order
    int a = 0, b = 0;
    bool endBool = false;
    bool startBool = true;
    bool super = false;
    int maxRowDefault;
    int maxColDefault;
    int maxRow, maxCol; // index for maximum score 

    // Computer starts if it is black 
    if (computer == 'B') {
        while (endBool == false) {
        /*getrusage(RUSAGE_SELF, &usage);
        start = usage.ru_utime;
        double time_start = start.tv_sec + start.tv_usec/1000000.0;*/ // in seconds
            if (draw(a, b, n, board) == true) {
                printf("Draw!\n");
                endBool = true;
            } else {
                //calculating score and computer makes decision
                int mostScore = 0;
                int bestStart = 0;
                super = false;
                for (a = 0; a < n; a++) {
                    for (b = 0; b < n; b++)
                        if (board[a][b] == 'U') {
                            if (startBool == true) { //find the largest available space to place the first index
                                int temp3 = findBiggest(n, board, a, b);
                                if (temp3 > bestStart) {
                                    bestStart = temp3;
                                    maxRow = a;
                                    maxCol = b;
                                }
                            } else {
                                if (emergency1(n, board, a, b) == true) {
                                    maxRow = a;
                                    maxCol = b;
                                    super = true;
                                } else if (emergency2(n, board, a, b) == true) {
                                    maxRow = a;
                                    maxCol = b;
                                    super = true;
                                } else {
                                    int temp = mostSum(n, board, a, b);
                                    if (temp > mostScore) {
                                        mostScore = temp;
                                        maxRowDefault = a;
                                        maxColDefault = b;
                                    }
                                }
                            }
                        }
                }

                if (startBool == false && super == false) {
                    int depth = MAX_DEPTH;
                    int finalA, finalB;
                    int score;
                    score=recurseDepth(n, board, lastA, lastB, depth, &finalA, &finalB);
                    maxRow = finalA;
                    maxCol = finalB;
  #ifdef DEBUGME
                    printf("finalA is %d and finalB is %d \n", maxRow, maxCol);
#endif 

                    if (maxRow == -1 || maxCol == -1) {
                        maxRow = maxRowDefault;
                        maxCol = maxColDefault;
                    }
                }
                startBool = false;
                
        printf("Computer moves %c at %d %d\n", computer, maxRow, maxCol);
                lastA = maxRow;
                lastB = maxCol;
                board[maxRow][maxCol] = computer;
                slotsLeft--;
                printboard(n, board);
                if (whoWin(n, board, maxRow, maxCol) == true)
                { 
                    endBool = true;
                }
                else {
               /* getrusage(RUSAGE_SELF, &usage);
                end = usage.ru_utime;
                double time_end = end.tv_sec + end.tv_usec/1000000.0; // in seconds
                double total_time = time_end - time_start;  
                printf("Time taken for this round is %f\n", total_time); 
                if (total_time > 1.0)
                {
                    printf("Taken more than 1 second"); 
                    exit(0); 
                }*/
                    //white moves
                    bool validW = false;
                    while (validW == false) {
                        printf("Enter White Move (ROW COL): ");
                        scanf("%d %d", &a, &b);
                        if (a>-1 && a < n && b> -1 && b < n && board[a][b] != 'U') {
                            printf("That square is already occupied or blocked\n");
                        } else if ((a < 0) || (a > n - 1) || (b < 0) || (b > n - 1)) {
                            printf("Out of range row or column\n");
                        } else {
                            board[a][b] = 'W';
                            slotsLeft--;
                            printboard(n, board);
                            validW = true;
                        }
                    }
                    if (whoWin(n, board, a, b) == true)
                        endBool = true;
                }
            }
        }
    } else { // computer is white, computer start next 
        while (endBool == false) {
            if (draw(a, b, n, board) == true) {
                printf("Draw!");
                endBool = true;
            } else {
                //black moves
                bool validB = false;
                while (validB == false) {
                    printf("Enter Black Move (ROW COL): ");
                    scanf("%d %d", &a, &b);
                    if (a>-1 && a < n && b> -1 && b < n && board[a][b] != 'U') {
                        printf("That square is already occupied or blocked\n");
                    } else if ((a < 0) || (a > n - 1) || (b < 0) || (b > n - 1)) {
                        printf("Out of range row or column\n");
                    } else {
                        board[a][b] = 'B';
                        slotsLeft--;
                        printboard(n, board);
                        validB = true;
                    }
                }
                if (whoWin(n, board, a, b) == true) {
                    endBool = true;
                } else {
                    //calculating score and computer makes decision
                    int mostScore = 0;
                    int maxRow, maxCol;
                    for (a = 0; a < n; a++) {
                        for (b = 0; b < n; b++)
                            if (board[a][b] == 'U') {
                                int temp2 = goodness(n, board, a, b);
                                if (temp2 > mostScore) {
                                    mostScore = temp2;
                                    maxRow = a;
                                    maxCol = b;
                                }
                            }
                    }
                    printf("Computer moves %c at %d %d\n", computer, maxRow, maxCol);
                    board[maxRow][maxCol] = computer;
                    slotsLeft--;
                    printboard(n, board);
                    if (whoWin(n, board, maxRow, maxCol) == true)
                        endBool = true;
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}

