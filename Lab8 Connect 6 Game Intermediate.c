/* File:   Lab8.c
 * Author: sunjunyi
 *
 * Created on November 12, 2014, 12:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//function to print the board

void printboard(int n, char board[n][n]) {
    int r, s;
    for (r = 0; r < n; r++) {
        for (s = 0; s < n; s++) {
            printf("%c", board[r][s]);
        }
        printf("\n");
    }
}
//function to find the max number

int iMax(int firstN, int secoN) {
    if (firstN > secoN)
        return firstN;
    else
        return secoN;
}
//function to find the longest

int findLongest(int n, char board[n][n], int row, int col) {
       bool test1=true,test2=true; 
       int i;
    //check horizontal line
int NorthtoSouth=1,WesttoEast=1,NorthWesttoSouthEast=1,NorthEasttoSouthWest=1,maxNumber=1;
    // calculate the right diagonal Number    
    for (i=1; test1 || test2; i++)
    {
        if (board[row][col] == board[row-i][col+i])
                NorthEasttoSouthWest++;
        else 
            test1=false;
        if (board[row][col] == board[row+i][col-i])
                NorthEasttoSouthWest++;
        else 
            test2=false;
    }
    
    //reset test1 and test2  
    test1=true;                                                      
    test2=true;
    
     // calculate the left diagonal Number 
    for (i=1; test1 || test2; i++)
    {
        if (board[row][col] == board[row-i][col-i])
                NorthWesttoSouthEast++;
        else 
            test1=false;
        if (board[row][col] == board[row+i][col+i])
                NorthWesttoSouthEast++;
        else 
            test2=false;
    }
    
    //reset test1 and test2 so that it can enter the for loop;
    test1=true;                        
    test2=true; 
    
     // calculate the left horizontal number
    for (i=1; test1 || test2; i++)
    {
        if (board[row][col] == board[row][col-i])
                WesttoEast++;
        else 
            test1=false;
        if (board[row][col] == board[row][col+i])
                WesttoEast++;
        else 
            test2=false;
    }
    
    // calculate the left horizontal number
    test1=true;                       
    test2=true; 
   
    //calculate the vertical number
    for (i=1; test1 || test2; i++)
    {
        if (board[row][col] == board[row - i][col])
                NorthtoSouth++;
        else 
            test1=false;
        if (board[row][col] == board[row + i][col])
                NorthtoSouth++;
        else 
            test2=false;
    }
    //printf("%d, %d, %d, %d\n",WesttoEast,NorthtoSouth,NorthWesttoSouthEast,NorthEasttoSouthWest);
    int longest; //compare different sums and find the biggest one
    longest = iMax(WesttoEast, NorthtoSouth);
    longest = iMax(longest, NorthWesttoSouthEast);
    longest = iMax(longest, NorthEasttoSouthWest);
    return longest;
}
//whether it's draw or not

bool draw(int a, int b, int n, char board[n][n]) {
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++)
            if (board[a][b] == 'U')
                return false;
    }
    return true;
}
//function to check who wins

bool whoWin(int n, char board[n][n], int a, int b) {
    bool whiteWin = false;
    bool blackWin = false;
    if (findLongest(n, board, a, b) >= 6) {
        if (board[a][b] == 'B')
            blackWin = true;
        else if (board[a][b] == 'W') {
            whiteWin = true;
        } else
            return false;
    } else
        return false;

    if (blackWin) {
        printf("\nBlack player wins.");
        return true;
    } else if (whiteWin) {
        printf("\nWhite player wins.");
        return true;
    } else
        return false;
}
//calculating the sum of black score and white score

int mostSum(int n, char board[n][n], int a, int b) {
    int mostB;
    int mostW;
    board[a][b] = 'B';
    mostB = findLongest(n, board, a, b);
    board[a][b] = 'W';
    mostW = findLongest(n, board, a, b);
    board[a][b] = 'U';
    //printf("%d, %d\n",mostB,mostW);
    return mostB + mostW;
}
//calculating score and computer makes decision

void computerPlay(int a, int b, int n, char computer, char board[n][n]) {
    int mostScore = 0;
    int maxRow, maxCol;
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++)
            if (board[a][b] == 'U') {
                if (mostSum(n, board, a, b) > mostScore) {
                    mostScore = mostSum(n, board, a, b);
                    maxRow = a;
                    maxCol = b;
                }
            }
    }
    printf("Computer moves %c at %d %d\n", computer, maxRow, maxCol);
    board[maxRow][maxCol] = computer;
    printboard(n, board);

}
//black moves

void blackPlay(int a, int b, bool end, int n, char board[n][n]) {
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
            printboard(n, board);
            validB = true;
        }
    }
    return;
}
//white moves

void whitePlay(int a, int b, bool end, int n, char board[n][n]) {
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
            printboard(n, board);
            validW = true;
        }
    }
    return;
}

int main(int argc, char** argv) {
    //print the original board
    int n;
    printf("Enter board dimensions (n), n>=6 and n<=21: ");
    scanf("%d", &n);
    int i, j;
    char board[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("U");
            board[i][j] = 'U';
        }
        printf("\n");
    }
    //ask which color the computer will play
    char inFirstPlayer[2];
    printf("Computer playing B or W?: ");
    scanf("%s", inFirstPlayer);
    char computer;
    for (i = 0; inFirstPlayer[i] != '\0'; i++)
        computer = inFirstPlayer[i];

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
            printboard(n, board);
        }
    }
    //play the game in order
    int a = 0, b = 0;
    bool end = false;
    if (computer == 'B') {
        while (end == false) {
            if (draw(a, b, n, board) == true) {
                printf("Draw!");
                end = true;
            } else {
                int mostScore = 0;
                int maxRow, maxCol;
                for (a = 0; a < n; a++) {
                    for (b = 0; b < n; b++)
                        if (board[a][b] == 'U') {
                            if (mostSum(n, board, a, b) > mostScore) {
                                mostScore = mostSum(n, board, a, b);
                                maxRow = a;
                                maxCol = b;
                            }
                        }
                }
                printf("Computer moves %c at %d %d\n", computer, maxRow, maxCol);
                board[maxRow][maxCol] = computer;
                printboard(n, board);
                if (whoWin(n, board, maxRow, maxCol) == true)
                    end = true;
                else {
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
                            printboard(n, board);
                            validW = true;
                        }
                    }
                    if (whoWin(n, board, a, b) == true)
                        end = true;
                }
            }
        }
    } else {
        while (end == false) {
            if (draw(a, b, n, board) == true) {
                printf("Draw!");
                end = true;
            } else {
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
                        printboard(n, board);
                        validB = true;
                    }
                }
                if (whoWin(n, board, a, b) == true) {
                    end = true;
                } else {
                    int mostScore = 0;
                    int maxRow, maxCol;
                    for (a = 0; a < n; a++) {
                        for (b = 0; b < n; b++)
                            if (board[a][b] == 'U') {
                                if (mostSum(n, board, a, b) > mostScore) {
                                    mostScore = mostSum(n, board, a, b);
                                    maxRow = a;
                                    maxCol = b;
                                }
                            }
                    }
                    printf("Computer moves %c at %d %d\n", computer, maxRow, maxCol);
                    board[maxRow][maxCol] = computer;
                    printboard(n, board);
                    if (whoWin(n, board, maxRow, maxCol) == true)
                        end = true;
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}


