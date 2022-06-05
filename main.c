#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <sys/time.h>
#define HEIGHT 10 // table height
#define WIDTH 10 // table width
#define NB_PIECES 7 // number of pieces
#define HMP 4 // maximum height of pieces

#include "pieces.h"
#include "general_function.h"

typedef struct { // structure representing the pieces
    int haut;
    int larg;
    char *forme[4];
} pieces;


void genererPieces(pieces tabPiece[]){ // creation of pieces, according to their height, width and shape
    

    tabPiece[1].haut = 2;        /*/ Square piece /*/
    tabPiece[1].larg = 2;
    tabPiece[1].forme[1] = "@@";
    tabPiece[1].forme[0] = "@@";
    
    
    tabPiece[2].haut = 4;        /*/ Pieces "bar" first position /*/
    tabPiece[2].larg = 1;
    tabPiece[2].forme[3] = "@";
    tabPiece[2].forme[2] = "@";
    tabPiece[2].forme[1] = "@";
    tabPiece[2].forme[0] = "@";
    
    tabPiece[3].haut = 2;        /*/ Pieces "S" first position /*/
    tabPiece[3].larg = 3;
    tabPiece[3].forme[1] = " @@";
    tabPiece[3].forme[0] = "@@ ";
    
    tabPiece[4].haut = 2;        /*/ Pieces "Z" first position /*/
    tabPiece[4].larg = 3;
    tabPiece[4].forme[1] = "@@ ";
    tabPiece[4].forme[0] = " @@";
    
    tabPiece[5].haut = 3;        /*/ Pieces "L" first position /*/
    tabPiece[5].larg = 2;
    tabPiece[5].forme[2] = "@ ";
    tabPiece[5].forme[1] = "@ ";
    tabPiece[5].forme[0] = "@@";
    
    tabPiece[6].haut = 3;        /*/ Pieces "J" first position /*/
    tabPiece[6].larg = 2;
    tabPiece[6].forme[2] = " @";
    tabPiece[6].forme[1] = " @";
    tabPiece[6].forme[0] = "@@";
    
    tabPiece[7].haut = 2;        /*/ Pieces "T" first position /*/
    tabPiece[7].larg = 3;
    tabPiece[7].forme[1] = "@@@";
    tabPiece[7].forme[0] = " @ ";
    
    tabPiece[8].haut = 1;        /*/ Pieces "bar" second position /*/
    tabPiece[8].larg = 4;
    tabPiece[8].forme[0] = "@@@@";
    
    tabPiece[9].haut = 3;        /*/ Pieces "S" second position /*/
    tabPiece[9].larg = 2;
    tabPiece[9].forme[2] = "@ ";
    tabPiece[9].forme[1] = "@@";
    tabPiece[9].forme[0] = " @";

    tabPiece[10].haut = 3;        /*/ Pieces "Z" second position /*/
    tabPiece[10].larg = 2;
    tabPiece[10].forme[2] = " @";
    tabPiece[10].forme[1] = "@@";
    tabPiece[10].forme[0] = "@ ";
    
    tabPiece[11].haut = 2;        /*/ Pieces "L" second position /*/
    tabPiece[11].larg = 3;
    tabPiece[11].forme[1] = "  @";
    tabPiece[11].forme[0] = "@@@";

    tabPiece[12].haut = 3;        /*/ Pieces "L" third position /*/
    tabPiece[12].larg = 2;
    tabPiece[12].forme[2] = "@@";
    tabPiece[12].forme[1] = " @";
    tabPiece[12].forme[0] = " @";
    
    tabPiece[13].haut = 2;        /*/ Pieces "L" fourth position /*/
    tabPiece[13].larg = 3;
    tabPiece[13].forme[1] = "@@@";
    tabPiece[13].forme[0] = "@  ";
    
    tabPiece[14].haut = 2;        /*/ Pieces "J" second position /*/
    tabPiece[14].larg = 3;
    tabPiece[14].forme[1] = "@@@";
    tabPiece[14].forme[0] = "  @";
    
    tabPiece[15].haut = 3;        /*/ Pieces "J" third position /*/
    tabPiece[15].larg = 2;
    tabPiece[15].forme[2] = "@@";
    tabPiece[15].forme[1] = "@ ";
    tabPiece[15].forme[0] = "@ ";
    
    tabPiece[16].haut = 2;        /*/ Pieces "J" fourth position /*/
    tabPiece[16].larg = 3;
    tabPiece[16].forme[1] = "@  ";
    tabPiece[16].forme[0] = "@@@";
    
    tabPiece[17].haut = 3;        /*/ Pieces "T" second position /*/
    tabPiece[17].larg = 2;
    tabPiece[17].forme[2] = "@ ";
    tabPiece[17].forme[1] = "@@";
    tabPiece[17].forme[0] = "@ ";
    
    tabPiece[18].haut = 2;        /*/ Pieces "T" third position /*/
    tabPiece[18].larg = 3;
    tabPiece[18].forme[1] = " @ ";
    tabPiece[18].forme[0] = "@@@";
    
    tabPiece[19].haut = 3;        /*/ Pieces "T" fourth position /*/
    tabPiece[19].larg = 2;
    tabPiece[19].forme[2] = " @";
    tabPiece[19].forme[1] = "@@";
    tabPiece[19].forme[0] = " @ ";
}

void displayPieces(pieces tabPiece[], int i){ // display of pieces according to their height (they will not appear in the table)
    if (tabPiece[i].haut == 1){
        printf("%s\n↑\n", tabPiece[i].forme[0]);
    }
    else if (tabPiece[i].haut == 2){
        printf("%s", tabPiece[i].forme[1]);
        printf("\n%s\n↑\n", tabPiece[i].forme[0]);
    }
    else if (tabPiece[i].haut == 3){
        printf("%s", tabPiece[i].forme[2]);
        printf("\n%s\n", tabPiece[i].forme[1]);
        printf("%s\n↑\n", tabPiece[i].forme[0]);
    }
    else if (tabPiece[i].haut == 4){
        printf("%s", tabPiece[i].forme[3]);
        printf("\n%s\n", tabPiece[i].forme[2]);
        printf("%s\n", tabPiece[i].forme[1]);
        printf("%s\n↑\n", tabPiece[i].forme[0]);
    }
}


int main(){
    int alea, r ,c ,e ,a, R1, R2, C, s, S=0 ; 
    long int t1, t2; 
    pieces tabPiece[20];
    char *grille[HEIGHT][WIDTH] = {" "};
    creer_Tab(grille);
    while(hauteur_max(grille,1,10)!=1){ // the game ends once the first line is reached
        pause();
        alea=piece_aleatoire();
        printf("Voici la pièce que vous devez jouer: \n\n");
        genererPieces(tabPiece); 
        displayPieces(tabPiece, alea);
        t1=getTimeMicroSec(); // increment time at time t1
        pause();
        if(alea==2 || alea==3 || alea==4){ // categorization of pieces according to the number of their rotation (here they have 2)
            printf("\nQuel rotation choisissez-vous ?\n\n1/\n");
            displayPieces(tabPiece, alea);
            printf("\n2/\n");
            displayPieces(tabPiece, alea+6); // display of pieces according to their according to the base part
            scanf("%d", &r);
        }
  
      else if(alea==5){
            printf("\nQuel rotation choisissez-vous ?\n\n1/\n");
            displayPieces(tabPiece, alea);
            printf("\n2/\n");
            displayPieces(tabPiece, alea+6);
            printf("\n3/\n");
            displayPieces(tabPiece, alea+7);
            printf("\n4/\n");
            displayPieces(tabPiece, alea+8);
            scanf("%d", &r);
        }
        else if(alea==6){
            printf("\nQuel rotation choisissez-vous ?\n\n1/\n");
            displayPieces(tabPiece, alea);
            printf("\n2/\n");
            displayPieces(tabPiece, alea+8);
            printf("\n3/\n");
            displayPieces(tabPiece, alea+9);
            printf("\n4/\n");
            displayPieces(tabPiece, alea+10);
            scanf("%d", &r);
        }
        else if(alea==7){
            printf("\nQuel rotation choisissez-vous ?\n\n1/\n");
            displayPieces(tabPiece, alea);
            printf("\n2/\n");
            displayPieces(tabPiece, alea+10);
            printf("\n3/\n");
            displayPieces(tabPiece, alea+11);
            printf("\n4/\n");
            displayPieces(tabPiece, alea+12);
            scanf("%d", &r);
        }
        t2=getTimeMicroSec(); // increment the time at instant t2
        if((t2-t1)/1000000>15){ // time's up
            R1=rand()%2+1; // otation chosen randomly for two-rotation pieces
            R2=rand()%4+1; // rotation chosen randomly for pieces with four rotations
            C=rand()%7+1;  // randomly chosen column
            if(r==1){       // display of pieces randomly
            ecrire_piece(grille,alea,C,hauteur_max(grille,C,C+tabPiece[alea].larg));
            }
            else if(alea==2 || alea==3 || alea==4 || alea==5){
            ecrire_piece(grille,alea+4+R1,C,hauteur_max(grille,C,C+tabPiece[alea+4+R1].larg));
            }
            else if(alea==6){
            ecrire_piece(grille,alea+6+R2,C,hauteur_max(grille,C,C+tabPiece[alea+6+R2].larg));
            }
            else if(alea==7){
            ecrire_piece(grille,alea+8+R2,C,hauteur_max(grille,C,C+tabPiece[alea+8+R2].larg));
            }
            else {
                ecrire_piece(grille,alea,C,hauteur_max(grille,C,C+tabPiece[alea].larg));
            }
            s=supprime_ligne(grille); // number of rows completed per turn
            afficheTab(grille); 
            S=S+s;  // score increment then display
            printf("Votre score est de %d\n", S);
        }
        else if((t2-t1)/1000000<=15){ // the time is not up and the player can place his piece
            if(r==1){
                do{
                    printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                    scanf("%d", &c);
                }while(c<1 || c>9);     // loop to avoid collisions on the sides of the array
                ecrire_piece(grille,alea,c,hauteur_max(grille,c,c+tabPiece[alea].larg)); // this varies depending on the width of the pieces
            }
            else if(alea==2){
                if(r==1){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>10);
                    ecrire_piece(grille,alea+4+r,c,hauteur_max(grille,c,c+tabPiece[alea+4+r].larg));
                }
                else if(r==2){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>7);
                    ecrire_piece(grille,alea+4+r,c,hauteur_max(grille,c,c+tabPiece[alea+4+r].larg));
                }
            }
            else if(alea==3 || alea==4){
                if(r==1){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>8);
                    ecrire_piece(grille,alea+4+r,c,hauteur_max(grille,c,c+tabPiece[alea+4+r].larg));
                }
                else if(r==2){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>9);
                    ecrire_piece(grille,alea+4+r,c,hauteur_max(grille,c,c+tabPiece[alea+4+r].larg));
                }
            }
            else if(alea==5){
                if(r==1 || r==3){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>9);
                    ecrire_piece(grille,alea+4+r,c,hauteur_max(grille,c,c+tabPiece[alea+4+r].larg));
                }
                else if(r==2 || r==4){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>8);
                    ecrire_piece(grille,alea+4+r,c,hauteur_max(grille,c,c+tabPiece[alea+4+r].larg));
                }
            }
            else if(alea==6){
                if(r==1 || r==3){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>9);
                    ecrire_piece(grille,alea+6+r,c,hauteur_max(grille,c,c+tabPiece[alea+6+r].larg));
                }
                else if(r==2 || r==4){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>8);
                    ecrire_piece(grille,alea+6+r,c,hauteur_max(grille,c,c+tabPiece[alea+6+r].larg));
                }
            }
            else if(alea==7){
                if(r==1 || r==3){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>8);
                    ecrire_piece(grille,alea+8+r,c,hauteur_max(grille,c,c+tabPiece[alea+8+r].larg));
                }
                else if(r==2 || r==4){
                    do{
                        printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                        scanf("%d", &c);
                    }while(c<1 || c>9);
                    ecrire_piece(grille,alea+8+r,c,hauteur_max(grille,c,c+tabPiece[alea+8+r].larg));
                }
            }
            else {
                do{
                    printf("\nDans quel colonne souhaitez-vous mettre la piece ?\n");
                    scanf("%d", &c);
                }while(c<1 || c>9);
                ecrire_piece(grille,alea,c,hauteur_max(grille,c,c+tabPiece[alea].larg));
            }
            s=supprime_ligne(grille); // number of rows completed per turn
            afficheTab(grille);
            S=S+s; // score increment then display
            printf("Votre score est de %d\n", S);
        }
    }
    if (S==0){
        red();
        printf("Dommage, vous n'avez aucun points");
        reset();
    }
    else if (S<5){
        yellow();
        printf("Bravo, vous avez obtenue un score honorable de %d points", S);
        reset();
    }
    else if (S>=5){
        green();
        printf("Excellent, votre score est de %d points ! Bravo !!", S);
        reset();
    }
    return 0;
}