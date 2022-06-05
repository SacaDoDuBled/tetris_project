#include<stdio.h>
#include<stdlib.h>

#define HEIGHT 10
#define WIDTH 10

#include "pieces.h"


void creer_Tab(char *grille[HEIGHT][WIDTH]){ // creation of the table and display
    int i, j;
    printf("\n ABCDEFGHIJ \n");
    for (i=1; i<HEIGHT; i++){
        printf("|");
        for (j=1; j<=WIDTH; j++){
            grille[i][j] = " ";
            printf("%s", grille[i][j]);
        }
        printf("|");
        printf("%d", i);
        printf("\n");
    }
    printf("------------\n\n");
}

void afficheTab(char *grille[HEIGHT][WIDTH]){ // table view only
    int i, j;
    printf("\n ABCDEFGHIJ \n");
    for (i=1; i<HEIGHT; i++){
        printf("|");
        for (j=1; j<=WIDTH; j++){
            printf("%s", grille[i][j]);
        }
        printf("|");
        printf("%d", i);
        printf("\n");
    }
    printf("------------\n\n");
}    


int hauteur_max(char *grille[HEIGHT][WIDTH], int a, int b){ // function allowing to know the row of the highest part between certain columns defined in parameter
    int i, j;
    j=a;
    i=1;
    while(grille[i][j]==" " && i<=9) {
        j++;
        if(j==b){
            i++;
            j=a;
        }
    }
    if(grille[i][j]=="@"){
        return i;
    }
    else {
        return -1;
    }
}

void ecrire_piece(char *grille[HEIGHT][WIDTH], int p, int c, int h){ // procedure that displays the 19 pieces in the grid
    if(p==1){                                                      // h takes as value the return of the function hauteur_max
            if(h==-1){ // there are no pieces in the table yet
                grille[9][c]="@";
                grille[9][c+1]="@";
                grille[8][c]="@";
                grille[8][c+1]="@";
            }
            else if(h!=-1){ // displays the pieces in the table according to the other pieces already present (collisions)
            grille[h-1][c]="@";
                grille[h-1][c+1]="@";
                grille[h-2][c]="@";
                grille[h-2][c+1]="@";
                } 
        }
        else if(p==2){
            if(h==-1){
                grille[9][c]="@";
                grille[8][c]="@";
                grille[7][c]="@";
                grille[6][c]="@";
            }
            else if(h!=-1){
            grille[h-1][c]="@";
                grille[h-2][c]="@";
                grille[h-3][c]="@";
                grille[h-4][c]="@";
                } 
        }
        else if(p==8){
            if(h==-1){
                grille[9][c]="@";
                grille[9][c+1]="@";
                grille[9][c+2]="@";
                grille[9][c+3]="@";
            }
            else if(h!=-1){
            grille[h-1][c]="@";
                grille[h-1][c+1]="@";
                grille[h-1][c+2]="@";
                grille[h-1][c+3]="@";
                } 
        }
        else if(p==3){
            if(h==-1){
                grille[8][c+2]="@";
                grille[8][c+1]="@";
                grille[9][c+1]="@";
                grille[9][c]="@";
            }
            else if(h!=-1){
                if(grille[h][c]=="@" || grille[h][c+1]=="@"){ // check surrounding pieces for collisions
                    grille[h-2][c+2]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                        grille[h-1][c]="@";
                    }
                    else {
                        grille[h-1][c+2]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c+1]="@";
                        grille[h][c]="@";
                    }
                } 
        }
        else if(p==9){
            if(h==-1){
                grille[7][c]="@";
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[9][c+1]="@";
            }
            else if(h!=-1){
                if(grille[h][c+1]=="@"){
                    grille[h-3][c]="@";
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                    }
                    else {
                        grille[h-2][c]="@";
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c+1]="@";
                    }
                }
        }
        else if(p==4){
            if(h==-1){
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[9][c+1]="@";
                grille[9][c+2]="@";
            }
            else if(h!=-1){
                if(grille[h][c+1]=="@" || grille[h][c+2]=="@"){
                    grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                        grille[h-1][c+2]="@";
                    }
                    else {
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c+1]="@";
                        grille[h][c+2]="@";
                    }
                }
        }
        else if(p==10){
            if(h==-1){
                grille[7][c+1]="@";
                grille[8][c+1]="@";
                grille[8][c]="@";
                grille[9][c]="@";
            }
            else if(h!=-1){
                if(grille[h][c]!="@"){
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                        grille[h-1][c]="@";
                        grille[h][c]="@";
                    }
                    else {
                        grille[h-3][c+1]="@";
                        grille[h-2][c+1]="@";
                        grille[h-2][c]="@";
                        grille[h-1][c]="@";
                    }
                }
        }
        if(p==5){
            if(h==-1){
        
        grille[7][c]="@";
                grille[8][c]="@";
                grille[9][c]="@";
                grille[9][c+1]="@";
            }
            else if(h!=-1){
            grille[h-3][c]="@";
                grille[h-2][c]="@";
                grille[h-1][c]="@";
                grille[h-1][c+1]="@";
                } 
        }
        if(p==11){
            if(h==-1){
                grille[8][c+2]="@";
                grille[9][c]="@";
                grille[9][c+1]="@";
 
            grille[9][c+2]="@";
            }
            else if(h!=-1){
            grille[h-2][c+2]="@";
                grille[h-1][c]="@";
                grille[h-1][c+1]="@";
                grille[h-1][c+2]="@";
                } 
        }
        else if(p==12){
            if(h==-1){
                grille[7][c]="@";

                grille[7][c+1]="@";



                grille[8][c+1]="@";
                grille[9][c+1]="@";
            }
            else if(h!=-1){
                if(grille[h][c+1]!="@" && grille[h+1][c+1]=="@"){
                    grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c+1]="@";
                    }
                    else if(grille[h][c+1]!="@" && grille[h+1][c+1]!="@"){
                    grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c+1]="@";
                        grille[h+1][c+1]="@";
                    }
                    else {
                        grille[h-3][c]="@";
                        grille[h-3][c+1]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                    }
                }
        }
        else if(p==13){
            if(h==-1){
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[8][c+2]="@";
                grille[9][c]="@";
            }
            else if(h!=-1){
                if(grille[h][c]!="@" && grille[h-1][c+1]!="@" && grille[h-1][c+2]!="@"){
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h-1][c+2]="@";
                        grille[h][c]="@";
                }
                else {
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-2][c+2]="@";
                        grille[h-1][c]="@";
                }
            } 
        }
        if(p==6){
            if(h==-1){
                grille[7][c+1]="@";
                grille[8][c+1]="@";
                grille[9][c+1]="@";
                grille[9][c]="@";
            }
            else if(h!=-1){
            grille[h-3][c+1]="@";
                grille[h-2][c+1]="@";
                grille[h-1][c+1]="@";
                grille[h-1][c]="@";
                } 
        }
        else if(p==14){
            if(h==-1){
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[8][c+2]="@";
                grille[9][c+2]="@";
            }
            else if(h!=-1){
                if(grille[h][c+2]!="@" && grille[h-1][c+1]!="@" && grille[h-1][c]!="@"){
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h-1][c+2]="@";
                        grille[h][c+2]="@";
                }
                else {
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-2][c+2]="@";
                        grille[h-1][c+2]="@";
                }
            } 
        }
        else if(p==15){
            if(h==-1){
                grille[7][c]="@";
                grille[7][c+1]="@";
                grille[8][c]="@";
                grille[9][c]="@";
            }
            else if(h!=-1){
                    if(grille[h][c]!="@" && grille[h+1][c]=="@"){
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c]="@";
                        grille[h][c]="@";
                    }
                    else if(grille[h][c]!="@" && grille[h+1][c]!="@"){
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c]="@";
                        grille[h+1][c]="@";
                    }
                    else {
                        grille[h-3][c]="@";
                        grille[h-3][c+1]="@";
                        grille[h-2][c]="@";
                        grille[h-1][c]="@";
                    }
                }
        }
        else if(p==16){
            if(h==-1){
                    grille[8][c]="@";
                    grille[9][c]="@";
                    grille[9][c+1]="@";
                    grille[9][c+2]="@";
            }
            else if(h!=-1){
                grille[h-2][c]="@";
                    grille[h-1][c]="@";
                    grille[h-1][c+1]="@";
                    grille[h-1][c+2]="@";
                } 
        }
        else if(p==7){
            if(h==-1){
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[8][c+2]="@";
                grille[9][c+1]="@";
            }
            else if(h!=-1){
                if(grille[h][c+1]=="@"){
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-2][c+2]="@";
                        grille[h-1][c+1]="@";
                    }
                    else {
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h-1][c+2]="@";
                        grille[h][c+1]="@";
                    }
                }
           
        }
        else if(p==17){
            if(h==-1){
                grille[7][c]="@";
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[9][c]="@";
            }
            else if(h!=-1){
                if(grille[h][c]!="@" && grille[h-1][c+1]!="@"){
                        grille[h-2][c]="@";
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c]="@";
                    }
                else {
                        grille[h-3][c]="@";
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c]="@";
                }
            }
           
        }
        else if(p==18){
            if(h==-1){
                grille[8][c+1]="@";
                grille[9][c]="@";
                grille[9][c+1]="@";
                grille[9][c+2]="@";
            }
            else if(h!=-1){
                grille[h-2][c+1]="@";
                grille[h-1][c]="@";
                    grille[h-1][c+1]="@";
                    grille[h-1][c+2]="@";
            }
           
        }
        else if(p==19){
            if(h==-1){
                grille[7][c+1]="@";
                grille[8][c]="@";
                grille[8][c+1]="@";
                grille[9][c+1]="@";
            }
            else if(h!=-1){
                if(grille[h][c+1]!="@"){
                    grille[h-2][c+1]="@";
                        grille[h-1][c]="@";
                        grille[h-1][c+1]="@";
                        grille[h][c+1]="@";
                    }
                    else {
                        grille[h-3][c+1]="@";
                        grille[h-2][c]="@";
                        grille[h-2][c+1]="@";
                        grille[h-1][c+1]="@";
                    }
                }
           
        }
} 


int supprime_ligne(char *grille[HEIGHT][WIDTH]){ // function that deletes a complete line and moves the rest of the pieces down
    int i, h, r=0, a=0, H;
    for(h=1; h<11 ;h++){ // loop to delete the complete line
        for(i=1; i<11 ;i++){
            if(grille[h][i]=="@"){
                r++;
            }
        }  
        if(r==10){ 
            for(i=1; i<11; i++){
                grille[h][i]=" ";
            }
        a++; // a is the number of rows completed in a single round
        H=h;
        }
    r=0;
    }
    if(a==1){
    for(h=H; h>1 ;h--){
        for(i=1; i<11 ;i++){
            grille[h][i]=grille[h-1][i]; // each box of the table takes the value of the one above
            grille[1][i]=" ";
        }
    }
    return a;
    }
    if(a==2){
    for(h=H; h>2 ;h--){
        for(i=1; i<11 ;i++){
            grille[h][i]=grille[h-2][i]; // each cell of the grid takes the value of cell 2 above
            grille[1][i]=" ";
            grille[2][i]=" ";
        }
    }
    return a; // returns the number of rows to complete for score management
    }
    if(a==3){
    for(h=H; h>3 ;h--){
        for(i=1; i<11 ;i++){
            grille[h][i]=grille[h-3][i]; // each box of the grid takes the value of box 3 above
            grille[1][i]=" ";
            grille[2][i]=" ";
            grille[3][i]=" ";
        }
    }
    return a;
    }
    if(a==4){
    for(h=H; h>3 ;h--){
        for(i=1; i<11 ;i++){
            grille[h][i]=grille[h-4][i]; // each box of the grid takes the value of box 4 above
            grille[1][i]=" ";
            grille[2][i]=" ";
            grille[3][i]=" ";
            grille[4][i]=" ";
        }
    }
    return a;
    }
    return a;
}