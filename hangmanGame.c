#include<stdio.h>
#include<string.h>

int main(){
	char word[]="hangman";
	char guess[20];
	int tries=6;
	int correct=0;
	int len=strlen(word);
	char display[20];
	
	for(int i=0;i<len;i++){
		display[i]=' ';
	}
	
	display[len]='\0';
	printf("Welcome to Hangman!\n");
	
	while(tries>0&&correct<len){
		printf("\nWord: %s\n", display);
		printf("Tries left: %d\n",tries);
		printf("Enter a letter: ");
		char ch;
	}
}