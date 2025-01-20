#include <stdio.h>

#define COUNT  9
int sudoku[9][9];
int input_function();
int display_function();
int solve_function(int, int);
int check_valid(int, int, int);

int main()
{
    int r = 0, c = 0;
    input_function();
    if (solve_function(r, c)) {
        printf("Sudoku solved successfully!\n");
    } else {
        printf("No solution exists.\n");
    }
    display_function();
    return 0;
}

int input_function()
{
    int i, j;
    for (i = 0; i < COUNT; i++)
    {
        for (j = 0; j < COUNT; j++)
        {
            printf("Enter the Position %d %d \t:", i + 1, j + 1);
            scanf("%d", &sudoku[i][j]);
        }
    }
}

int display_function()
{
    int i, j;
    for (i = 0; i < COUNT; i++)
    {
        for (j = 0; j < COUNT; j++)
        {
            printf("|");
            printf("\t%d\t", sudoku[i][j]);
        }
        printf("|\n");
    }
}

int solve_function(int r, int c)
{
    //  Reached the 9th row the Sudoku is solved
    if (r == 9)
    {
        return 1;
    }

    //Reached the 9th column move to the next row
    if (c == 9)
    {
        return solve_function(r + 1, 0);
    }

    // Skip filled cells
    if (sudoku[r][c] != 0)
    {
        return solve_function(r, c + 1);
    }

    // Try digits from 1 to 9
    for (int k = 1; k <= 9; k++)
    {
        if (check_valid(r, c, k)) // Check if K is valid
        {
            sudoku[r][c] = k; // Assign value
            if (solve_function(r, c + 1)) // Move to the next cell
            {
                return 1; // Solution found
            }
            sudoku[r][c] = 0; // Backtrack
        }
    }

    return 0; // No solution found
}

int check_valid(int r, int c, int k)
{
    // Check if k is in the same row
    for (int i = 0; i < COUNT; i++)
    {
        if (sudoku[r][i] == k)
        {
            return 0; // K is in the row
        }
    }

    // Check if K is in the same column
    for (int i = 0; i < COUNT; i++)
    {
        if (sudoku[i][c] == k)
        {
            return 0; // k is in the column
        }
    }

    // Check if k is in the 3x3 subgrid
    for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
    {
        for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
        {
            if (sudoku[i][j] == k)
            {
                return 0; // K is in the subgrid
            }
        }
    }

    // If no conflicts K is valid
    return 1;
}
