/*
 * functions.h
 *
 *  Created on: Jul 25, 2024
 *      Author: melika
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int check_letter(char letter,char *word, char *display_word){
	int found=0;
	for(int i=0; i<strlen(word); i++){
			if(word[i] == letter){
				display_word[i] = letter;// checking for any matches and replacing them on screen
				found++;
			}
		}
	return found;
}

int guess_complete(char *word, char *display_word){
		for(int i=0; i<strlen(word); i++){
				if(word[i]!= display_word[i]){
					return 0; //checks for any differences
				}
			}
		printf("\nCongratulations! you have found the word\n");
		return 1;
}

list* create_word_list(){
char *word;
int len;
list* myList= createList();

printf("How many words do you want to add: ");
scanf("%d",&len);
printf("Enter the words one by one. Maximum of 14 characters is allowed \n");

for(int i=1; i<=len; i++){
	word= (char*)malloc(sizeof(char)*15);
	printf("Entry %d: ",i);
	scanf("%s",word);
	getchar();
	addNode(myList, word);
}
printf("\n\n\t******List Created Successfully***********\n\n");
printf("Starting game...\n\n\t");
return myList;
}


int hangman_game_dll(list* myList, int level){
	     char guess;
	     int trial=0;
	     char word[15];
	     removeRandomNode(myList, word);// removes a randomly selected node from list
	     int length = strlen(word);// length of display
	     puts(word);
	     char display_word[length];
	    for(int i=0; i<strlen(word); i++){
	         display_word[i] = '_';
	         printf("%c ", display_word[i]); // sets the screen
	     }

	    while(trial<(length+level)){// checks if user have any trials left
	    	 printf("\n Guess a letter:");
	    	 scanf("%c",&guess); // user prompt
	    	 getchar();
	    	 if(check_letter(guess, word, display_word)> 0)// checks for any guessed letters
	    		 printf("you guessed correctly!!!\n\n\t");
	    	 else
	    		 printf("wrong letter!\n\n\t");
	    	 for(int i=0; i<strlen(word); i++){
	    	     printf("%c ", display_word[i]);// displays the current state of the word
	    	     }
	    	 printf("\n");
	    	 if(guess_complete(word, display_word))// checks if all letters have been guessed
	    		 return 1;
	    	 trial++;
	     }
	     if(trial>=level+length)
	    	 printf("you are out of guesses :( \n");// failure message
	     return 0;
}



#endif /* FUNCTIONS_H_ */
