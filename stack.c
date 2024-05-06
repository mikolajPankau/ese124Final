#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



void mark(Coordinates coordinates) {

}

void move_f(Coordinates coordinates) {

}

void move_b(Coordinates coordinates) {

}

void move_l(Coordinates coordinates) {

}

void move_r(Coordinates coordinates) {

}

int cwf(char arr[], Coordinates coordinates) {

}

int cwb(char arr[], Coordinates coordiantes) {
    int i;
    while (i = 0; arr[coordinates.coords[coordinates.top].x - i] != '*' || arr[coordinates.coords[coordinates.top].x - i] != '+' && coordinates.coords[coordinates.top].x - i != MAXSIZEOFMAZE; i++) {

    }
    return
}

int cwl(char arr[], Coordinates coordinates) {

}

int cwr(char arr[], Coordinates coordinates) {

}

void push(Coords coord, Coordinates coordinates) {
    coordinates.top += 1;
    coordinates.coords[coordinates.top] = coord;
}

Coords pop(Coordinates coordinates) {
    return coordinates.coords[coordinates.top];
    coordinates.top = coordinates.top - 1;
}

Coords peek(Coordinates coordinates) {
    return coordinates.coords[coordinates.top];
}

void clear(Coordinates coordinates) {
    coordinates.top = -1;
}

