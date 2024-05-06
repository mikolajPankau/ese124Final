#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

typedef struct coord {
    int x;
    int y;
    int deed;
} Coords;

typedef struct coordinates {
    Coords coords[MAX_SIZE];
    int top;
} Coordinates;

void mark(Coordinates coordinates);
void move_f(Coordinates coordinates);
void move_b(Coordinates coordinates);
void move_l(Coordinates coordinates);
void move_r(Coordinates coordinates);
int cwf(char arr[], Coordinates coordinates);
int cwb(char arr[], Coordinates coordiantes);
int cwl(char arr[], Coordinates coordinates);
int cwr(char arr[], Coordinates coordinates);
void push(Coords coord, Coordinates coordinates);
Coords pop(Coordinates coordinates);
Coords peek(Coordinates coordinates);
void clear(Coordinates coordinates);

#endif