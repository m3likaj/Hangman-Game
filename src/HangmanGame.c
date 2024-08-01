/*
 ============================================================================
 Name        : HangmanGame.c
 Author      : Melika Jibril Seid
 Version     : 2.0
 Copyright   : MIT license
 Description : Hangman game in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedList.h"
#include "functions.h"

enum level {H=5,M=7,E=9};
int gameLevel;

int main(){
    srand(time(NULL));
    int len=0, score=0;
    char confirm, level;
    list* myList;
    printf("*********Welcome to the Hangman Game*********\n\n");
    printf("Please choose a level: Enter 'E' for easy 'M' for medium or 'H' for hard: ");
    scanf("%c",&level);
    getchar();

    switch(level){
    case 'e':
    case 'E':
    	gameLevel=E;
    	break;
    case 'M':
    case 'm':
    	gameLevel=M;
    	break;
    case 'h':
    case 'H':
    	gameLevel=H;
    	break;
    default:
    	printf("Invalid entry. Setting level to easy....\n");
    	gameLevel=E;
    }

    printf("Do you want to create your own list for the game?\n enter 'Y' for Yes or 'N' for No: ");
    scanf("%c", &confirm);
    getchar();
    switch(confirm){
    case 'y':
    case 'Y':
    	myList= create_word_list();
    	break;
    default:
    	printf("Using pre-created list.....\n\n\t");
    	 char word_list[][15] = {"act", "eat","sassy", "sit", "kilt"};
    	 len=5;
    	 myList= createList();
    	 for(int i=0; i<len; i++){ //adding words to linked list
    	     addNode(myList, word_list[i]);
    	     }
    }
    while(1){
    score += hangman_game_dll(myList, gameLevel);//calling game function

    if(myList->count > 0)
    	 printf("next word coming up...\n\n\t");
    else{//if linked list is empty
    	printf("\n\nyou have completed the game\n\n");
    	printf("Your score is: %d\n\n", score);
    	printf("***********Game over!************");
    	break;
    	}
    }
    return 0;
}






