/* 
 * File:   Lab7.c
 * Author: yiransunjunyi
 *
 * Created on November 3, 2014, 7:49 PM
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
    //check horizontal line
    int horiSum = 0;
    int e, f;
    for (e = 0; e <= n; e++)
        if (e == row) {
            for (f = col; f <= n; f++)//right side of the position
                if (board[e][f] == board[row][col])
                    horiSum++;
                else
                    break;
            for (f = col; f >= 0; f--)//left side of the position
                if (board[e][f] == board[row][col])
                    horiSum++;
                else
                    break;
        }
    horiSum = horiSum - 1;
    //check vertical line
    int vertiSum = 0;
    int c, d;
    for (d = 0; d <= n; d++)
        if (d == col) {
            for (c = row; c <= n; c++)//lower side of the position
                if (board[c][d] == board[row][col])
                    vertiSum++;
                else
                    break;
            for (c = row; c >= 0; c--)//upper side of the position
                if (board[c][d] == board[row][col])
                    vertiSum++;
                else
                    break;
        }
    vertiSum = vertiSum - 1;
    //diagonal form upper left to down right
    int diaSum1 = 0;
    int h;
    for (h = 1; h <= n; h++)
        if (board[row + h][col + h] == board[row][col])
            diaSum1++;
        else
            break;
    for (h = 1; h <= n; h++)
        if (board[row - h][col - h] == board[row][col])
            diaSum1++;
        else
            break;
    diaSum1 = diaSum1 + 1;
    //diagonal from upper right to down left
    int diaSum2 = 0;
    for (h = 1; h <= n; h++)
        if (board[row + h][col - h] == board[row][col])
            diaSum2++;
        else
            break;
    for (h = 1; h <= n; h++)
        if (board[row - h][col + h] == board[row][col])
            diaSum2++;
        else
            break;
    diaSum2 = diaSum2 + 1;
    int longest; //compare different sums and find the biggest one
    longest = iMax(horiSum, vertiSum);
    longest = iMax(longest, diaSum1);
    longest = iMax(longest, diaSum2);
    return longest;
}
//function to check who wins

void whoWin(int n, char board[n][n]) {
    int p, q;
    int mostB = 1, mostW = 1;
    for (p = 0; p <= n; p++)
        for (q = 0; q <= n; q++) {
            if (board[p][q] == 'B')
                if (findLongest(n, board, p, q) > mostB)
                    mostB = findLongest(n, board, p, q);
            if (board[p][q] == 'W')
                if (findLongest(n, board, p, q) > mostW)
                    mostW = findLongest(n, board, p, q);
        }
    if (mostB >= 6 && mostB > mostW)
        printf("Black wins\n");
    else if (mostW >= 6 && mostW > mostB)
        printf("White wins\n");
    else
        printf("No winner so far\n");
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
        else if ((x<-1 || x > n-1) && (y<-1 || y > n-1))
            printf("Out of range row or column\n");
        else {
            board[x][y] = 'R';
            printboard(n, board);
        }
    }
    //play the game in order
    int turn = 1;
    int a = 0, b = 0;
    bool end = false;
    while (a >= 0 && b >= 0 && end == false) {
        if (a >= 0 && b >= 0 && (turn % 2) != 0) { //when the turn is an odd number, black plays
            printf("Enter Black Move (ROW COL); (-1 -1) to finish: ");
            scanf("%d %d", &a, &b);
            if (a >= 0 && b >= 0 && board[a][b] != 'U')
                printf("That square is already occupied or blocked\n");
            else if (a == -1 && b == -1)
                end = true;
            else {
                board[a][b] = 'B';
                printboard(n, board);
                turn++;
            }
        } else { //when the turn is an even number, white plays
            printf("Enter White Move (ROW COL); (-1 -1) to finish: ");
            scanf("%d %d", &a, &b);
            if (a >= 0 && b >= 0 && board[a][b] != 'U')
                printf("That square is already occupied or blocked\n");
            else if (a == -1 && b == -1)
                end = true;
            else {
                board[a][b] = 'W';
                printboard(n, board);
                turn++;
            }
        }
    }
    printf("\n");
    int row = 0, col = 0;
    whoWin(n, board);
    bool finish = false;
    while (finish == false) { //find the longest line for the input point
        printf("Enter position (ROW COL) of square to measure; (-1 -1) to finish: ");
        scanf("%d %d", &row, &col);
        if (row == -1 && col == -1)
            finish = true;
        else if ((row<-1 || row > n-1) && (col<-1 || col > n-1))
                printf("Out of range row or column\n");
        else {
            if (board[row][col] == 'B' || board[row][col] == 'W')
                printf("Longest Run of %c at position (%d,%d) is %d\n", board[row][col], row, col, findLongest(n, board, row, col));
            else
                printf("That square is neither white nor black\n");
            }
    }
    printf("Goodbye");
    return (EXIT_SUCCESS);
}

