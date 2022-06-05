#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <sys/time.h>

#define HEIGHT 10
#define WIDTH 10

#include "general_function.h"

int piece_aleatoire(){ // choose one of the 7 base pieces randomly
    int alea;
    srand(time(NULL));
    alea=rand()%7+1;
    return alea;
}

void pause(){ // procedure that structures the game using pauses
    getchar();
} 

unsigned long getTimeMicroSec(){ // function used to time how long the player takes to play
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (1000000 * tv.tv_sec) + tv.tv_usec;
}


void red () {  //function used to create color in the printf (red here)
  printf("\033[1;31m");
}
void yellow(){
    printf("\033[0;33m");
}
void green(){
    printf("\033[0;32m");
}
void reset () {
  printf("\033[0m");
}
