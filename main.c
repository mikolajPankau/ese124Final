#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

FILE *f, *mapFile;
char c[15];
int repeatAmount, repeatNum;
char **repeatArray;
int temp;

Maze *maze;
AntMemory *memory;


void runCommand(char *command)
{
    //commands
    if(strcmp(command, "MARK"))
        mark(maze);
    else if(strcmp(command, "MOVE_F"))
        move_f(maze);
    else if(strcmp(command, "MOVE_B"))
        move_b(maze);
    else if(strcmp(command, "MOVE_L"))
        move_l(maze);
    else if(strcmp(command, "MOVE_R"))
        move_r(maze);
    else if(strcmp(command, "CWL"))
        cwl(maze);
    else if(strcmp(command, "CWR"))
        cwr(maze);
    else if(strcmp(command, "CWF"))
        cwf(maze);
    else if(strcmp(command, "CWB"))
        cwb(maze);
    else if(strcmp(command, "PUSH"))
        push((*maze).antPos, memory);
    else if(strcmp(command, "POP"))
        pop(memory);
    else if(strcmp(command, "PEEK"))
        clear(memory);
    else if(strcmp(command, "BJPI"))
        {
            scanf("%d", &temp);
            bjpi();
        }
    else if(strcmp(command, "CJPI"))
        {
            scanf("%d", &temp);
            cjpi();
        }
    else if(strcmp(command, "BACKTRACK"))
        backtrack();
    else if(strcmp(command, "RP"))
        {
            scanf("%d %d", &repeatNum, &repeatAmount);
            repeatArray = malloc(repeatNum * sizeof(char *));
            for(int i = 0; i < repeatNum; i++)
            {
                repeatArray[i] = malloc(15 * sizeof(char));
            }
            for(int i = 0; i < repeatNum; i++)
            {
                scanf("%s", &command);
                strcpy(repeatArray, command);
            }
            for(int i = 0; i < repeatAmount; i++)
            {
                for(int j = 0; j < repeatNum; j++)
                {
                    runCommand(repeatArray[j]);
                }
            }
        }
    else
        printf("Unknown instruction!\n");

    
}


int main()
{
    //open files
    if((f = fopen("intelligence.txt", "r")) == NULL)
    {
        printf("Error opening instruction file!\n");
        return 1;
    }
    if((mapFile = fopen("maze.txt", "r")) == NULL)
    {
        printf("Error opening maze file!\n");
        return 1;
    }
    //create maze and memory variable
    maze = malloc(sizeof(Maze));
    memory = malloc(sizeof(AntMemory));

    //create the actual maze in memory
    int numRows, numCols;
    printf("Enter size of maze(x, y): ");
    scanf("%d %d", &numRows, &numCols);

    printf("Enter start point(x, y): ");
    scanf("%d, %d", &((*maze).antPos.x), &((*maze).antPos.y));


    (*maze).map = malloc(numRows * sizeof(char *));
    for(int i = 0; i < numRows; i++)
    {
        (*maze).map[i] = malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; j++)
        {
            fscanf(mapFile, "%c", &((*maze).map[i][j].type));       //assign the char in the maze
            switch (((*maze).map[i][j]).type)                       //assign deed point values to each spot in the maze array
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    ((*maze).map[i][j]).deed = ((*maze).map[i][j]).type - '0';
                    break;
            default:
                ((*maze).map[i][j]).deed = 0;
                break;
            }
        }
        char a;
        if((a = fgetc(mapFile)) != '\n')
            ungetc(a, mapFile);
    }

    while(1)
    {
        if(fscanf(f, "%s", &c) == EOF) { break; }
        runCommand(c);
    }


} 
