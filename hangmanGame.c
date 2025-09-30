#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<Stdlib.h>
#include<time.h>

void Hangman(int chances){
	switch(chances){
		case 6:
			printf("\n +---+\n    |\n   |\n  ===\n");
			break;
			case 5:
				printf("\n +---+\n o |\n  |\n  |\n  ===\n");
				break;
				case 4:
					printf("\n +---+\n o |\n |  |\n  |\n   ===\n");
					break;
					case 3:
						printf("\n +---+\n o |\n/|  |\n  |\n===\n");
						break;
						case 2:
							printf("\n +---+\n o |\n/|\\  |\n  |\n  ===\n");
							break;
							case 1:
								printf("\n +---+\n o |\n/|\\  |\n/  |\n  ===\n");
								break;
								case 0:
									printf("\n +---+\n o |\n/|\\ |\n/\\  |\n  ===\n");
	}
}

int main(){
	const char *words[] = {"computer","programming","hangman","language","science","keyboard"};
	int totalWords = sizeof(words) / sizeof(words[0]);
	
	//pick randome word
	srand(time(0));
	const char *word = words[rand()%totalWords] ;
	
	char guessed[50];
	int wordLength = strlen(word);
	int chances = 6;   
	int correctGuesses = 0;
	char guess;
	int i, found;
	
	for(i=0; i<wordLength; i++){
		guessed[i] = '_';
		
	}
	guessed[wordLength] = '\0';
	
	printf("Welcome to Hangman!\n");
	
	  while (chances > 0 && correctGuesses < wordLength) {
		Hangman(chances);
		printf(" Word: %s\n",guessed);
		
		printf("Enter a letter: ");
		scanf("%c",&guess);
		guess = tolower(guess);
		
		found=0;
		for(i=0; i<wordLength; i++){
			if(word[i] == guess && guessed[i]=='_'){
				guessed[i] = guess;
				correctGuesses++;
				found=1;
			}
		}
		if(!found){
			chances--;
			printf("Wrong guess! Chances left: %d\n",chances);
			
		}else{
			printf("Good guess1\n");
		}
	}
	Hangman(chances);
	if(correctGuesses == wordLength){
		printf("\nCongratulation! you guessed the word '%s'.\n",word);
		
	}else{
		printf("\n Game over! the word was '%s'.\n",word);
	}
	return 0;
}
