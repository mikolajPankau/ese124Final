#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack.h>

void mark(Maze *maze) {
    (*maze).map[(*maze).antPos.x][(*maze).antPos.y].type = '+';
}

int move_f(Maze *maze) {
    int returnVal = 0;
    if((*maze).map[(*maze).antPos.x+1][(*maze).antPos.y].type != '*' && (*maze).antPos.x+1 < (*maze).xSize)
    {
        (*maze).antPos.x += 1;
        returnVal = (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed;
        if(returnVal != 0)
        { 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed = 0; 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].type = ' ';
        }
    }
    return returnVal;
}

int move_b(Maze *maze) {
    int returnVal = 0;
    if((*maze).map[(*maze).antPos.x-1][(*maze).antPos.y].type != '*' && (*maze).antPos.x-1 >= 0)
    {
        (*maze).antPos.x -= 1;
        returnVal = (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed;
        if(returnVal != 0)
        { 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed = 0; 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].type = ' ';
        }
    }
    return returnVal;
}

int move_l(Maze *maze) {
    int returnVal = 0;
    if((*maze).map[(*maze).antPos.x][(*maze).antPos.y-1].type != '*' && (*maze).antPos.y-1 >= 0)
    {
        (*maze).antPos.y -= 1;
        returnVal = (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed;
        if(returnVal != 0)
        { 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed = 0; 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].type = ' ';
        }
    }
    return returnVal;
}

int move_r(Maze *maze) {
    int returnVal = 0;
    if((*maze).map[(*maze).antPos.x][(*maze).antPos.y+1].type != '*' && (*maze).antPos.y+1 < (*maze).ySize)
    {
        (*maze).antPos.y += 1;
        returnVal = (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed;
        if(returnVal != 0)
        { 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].deed = 0; 
            (*maze).map[(*maze).antPos.x][(*maze).antPos.y].type = ' ';
        }
    }
    return returnVal;
}

int cwf(Maze *maze) {
    int freeSpots = 0;
    Coord c = (*maze).map[(*maze).antPos.x+1][(*maze).antPos.y];
    while(c.type != '*' && c.type != '+')
    {
        if(c.x >= (*maze).xSize) {break;}
        freeSpots++;
        c =(*maze).map[c.x+1][c.y];
    }
    (*maze).antPos.deed = 0;
    return freeSpots;
}

int cwb(Maze *maze) {
    int freeSpots = 0;
    Coord c = (*maze).map[(*maze).antPos.x-1][(*maze).antPos.y];
    while(c.type != '*' && c.type != '+')
    {
        if(c.x < 0) {break;}
        freeSpots++;
        c =(*maze).map[c.x-1][c.y];
    }
    (*maze).antPos.deed = 1;
    return freeSpots;
}

int cwl(Maze *maze) {
    int freeSpots = 0;
    Coord c = (*maze).map[(*maze).antPos.x][(*maze).antPos.y-1];
    while(c.type != '*' && c.type != '+')
    {
        if(c.y < 0) {break;}
        freeSpots++;
        c =(*maze).map[c.x][c.y-1];
    }
    (*maze).antPos.deed = 2;
    return freeSpots;
}

int cwr(Maze *maze) {
    int freeSpots = 0;
    Coord c = (*maze).map[(*maze).antPos.x][(*maze).antPos.y+1];
    while(c.type != '*' && c.type != '+')
    {
        if(c.y >= (*maze).ySize) {break;}
        freeSpots++;
        c =(*maze).map[c.x][c.y+1];
    }
    (*maze).antPos.deed = 3;
    return freeSpots;
}

void push(Coord coord, AntMemory *coordinates) {
    (*coordinates).top += 1;
    (*coordinates).coords[(*coordinates).top] = coord;
}

Coord pop(AntMemory *coordinates) {
    (*coordinates).top = (*coordinates).top - 1;
    return (*coordinates).coords[(*coordinates).top + 1];
}

Coord peek(AntMemory *coordinates) {
    return (*coordinates).coords[(*coordinates).top];
}

void clear(AntMemory *coordinates) {
    (*coordinates).top = -1;
}

void bjpi(Maze *maze, int x) { 
    if (x > 0) {
        Coord current = (*maze).antPos;
        switch (current.deed) {
            case 0: 
                current.x += x;
                break;
            case 1: 
                current.x -= x;
                break;
            case 2: 
                current.y -= x;
                break;
            case 3: 
                current.y += x;
                break;
            default:
                break;
        }
        (*maze).antPos = current;
    }
}

void cjpi(Maze *maze) { 
    Coord current = (*maze).antPos;
    switch (current.deed) {
        case 0:
            current.x++;
            break;
        case 1: 
            current.x--;
            break;
        case 2:
            current.y--;
            break;
        case 3:
            current.y++;
            break;
        default:
            break;
    }
    (*maze).antPos = current;
}

void backtrack(Maze *maze, AntMemory *memory) {
    Coord target = pop(memory);
    (*maze).antPos = target;
}