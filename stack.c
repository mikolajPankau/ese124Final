#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define MAXSIZEOFMAZE 100


void mark(Coordinates coordinates) {

}

void move_f(Coordinates coordinates) { //move forward one
    coordinates.coords[coordinates.top].x++; //increment x
    push(coordinates.coords[coordinates.top], coordinates);  //push updated position onto stack
}

void move_b(Coordinates coordinates) { //move backward one
    coordinates.coords[coordinates.top].x--; //decrement x
    push(coordinates.coords[coordinates.top], coordinates);  //push updated position onto stack
}

void move_l(Coordinates coordinates) { //move left one
    coordinates.coords[coordinates.top].y--; //decrement y
    push(coordinates.coords[coordinates.top], coordinates); //push updated position onto stack
}
void move_r(Coordinates coordinates) { //move right one
    coordinates.coords[coordinates.top].y++; //increment y
    push(coordinates.coords[coordinates.top], coordinates); //push updated position onto stack    
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

