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

int cwf(char arr[], Coordinates coordinates) { //checks if the next locations in the front are pheromone free
    Coords current = peek(coordinates);
    int i;
    for (i = 1; current.x + i < MAXSIZEOFMAZE; i++) {
        if (arr[current.x + i][current.y] == '*')
            return 0;
    }
    return 1;
}

int cwb(char arr[], Coordinates coordiantes) { //checks if the next locations in the back are pheromone free
    int i;
    while (i = 0; arr[coordinates.coords[coordinates.top].x - i] != '*' || arr[coordinates.coords[coordinates.top].x - i] != '+' && coordinates.coords[coordinates.top].x - i != MAXSIZEOFMAZE; i++) {

    }
    return
}

int cwl(char arr[], Coordinates coordinates) { //checks if the next locations to the left are pheromone free
    Coords current = peek(coordinates);
    int i;
    for (i = 1; current.y - i >= 0; i++) {
        if (arr[current.x][current.y - i] == '*')
            return 0;
    }
    return 1;
}

int cwr(char arr[], Coordinates coordinates) { //checks if the next locations to the right are pheromone free
    Coords current = peek(coordinates);
    int i;
    for (i = 1; current.y + i < MAXSIZEOFMAZE; i++) {
        if (arr[current.x][current.y + i] == '*')
            return 0;
    }
    return 1;
}

void push(Coords coord, Coordinates coordinates) {
    coordinates.top += 1;
    coordinates.coords[coordinates.top] = coord;
}

Coords pop(Coordinates coordinates) {
    Coords temp = coordinates.coords[coordinates.top];
    coordinates.top = coordinates.top - 1;
    return temp;
}

Coords peek(Coordinates coordinates) {
    return coordinates.coords[coordinates.top];
}

void clear(Coordinates coordinates) {
    coordinates.top = -1;
}

