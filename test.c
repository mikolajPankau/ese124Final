#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actions.h"
#include "stack.h"

FILE *f;

int numRows = 0, numCols = 0, curCol = 0;
char c;

char arr[50][50];


int main()
{
    f = fopen("Maze 4.txt", "r");
    if(f == NULL) {return 1;}

    while(1)
    {
        if(fscanf(f, "%c", &c) == EOF)
        {
            numRows++;
            break;
        }
        if(c == '\n')
        {
            numRows++;
            curCol = 0;
            continue;
        }
        arr[numRows][curCol] = c;
        //printf("%c %d, %d\n", c, numRows, curCol);
        curCol++;
        if(numRows == 0) {numCols++;}
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols-1; j++)
        {
            c = arr[i][j];
            //printf("%c at index (%d, %d)\n", arr[i][j], i, j);
            printf("%c", arr[i][j]);
            if(c != '*' && c != ' ' && c != '\n')
            {
                //printf("%c at index (%d, %d)\n", c, i+1, j+1);
            }
        }
        printf("\n");
    }


    return 0;
}
