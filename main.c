#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actions.h"

FILE *f;
char c[15];
int repeatAmount, repeatNum;
char **repeatArray;
int temp;

Maze *maze;
AntMemory *memory;

void runCommand(char *command)
{
    
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
        push(memory);
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
}


int main()
{
    if((f = fopen("instructions.txt", "r")) == NULL)
    {
        printf("Error opening instruction file!\n");
        return 1;
    }

    maze = malloc(sizeof(Maze));
    memory = malloc(sizeof(AntMemory));

    //still have to add a way to add start point, and define the map

    while(1)
    {
        if(scanf("%s", &c) == EOF) { break; }
        runCommand(c);
    }


} 