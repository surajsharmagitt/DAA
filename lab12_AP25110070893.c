#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int n;

int isSafe(int row, int col)
{
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

int solve(int row)
{
    if (row == n)
        return 1;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solve(row + 1))
                return 1;

            board[row][col] = 0;  // Backtracking
        }
    }

    return 0;
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    if (solve(0))
    {
        printf("Solution:\n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists\n");
    }

    return 0;
}
