#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

typedef struct coord {  //not all 4 values will always be used
    int x;              //x coordinate
    int y;              //y coordinate
    int deed;           //deed value
    char type;          //char that reperesents spot: * + # ' '
} Coord;

typedef struct memory {
    Coord coords[MAX_SIZE];         //stack with all remembered coords
    int top;                        //top of stack index
} AntMemory;

typedef struct maze {
    int xSize, ySize;               //represents the size of the maze in x and y directions
    Coord map[10][10];              //2d array representing the maze, will work on dynamic size later
    Coord antPos;                   //current position of ant
} Maze;

//i made the move functions return an int, they return the number of good deed points you got with that move

void mark(Maze *maze);
int move_f(Maze *maze);
int move_b(Maze *maze);
int move_l(Maze *maze);
int move_r(Maze *maze);
int cwf(Maze *maze);
int cwb(Maze *maze);
int cwl(Maze *maze);
int cwr(Maze *maze);
void push(Coord coord, AntMemory *coordinates);
Coord pop(AntMemory *coordinates);
Coord peek(AntMemory *coordinates);
void clear(AntMemory *coordinates);
void BJPI(int x, Coordinates *coordinates);
void CJPI(Coordinates *coordinates);

#endif
