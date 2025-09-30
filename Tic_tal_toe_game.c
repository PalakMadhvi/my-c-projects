#include<stdio.h>
#include<conio.h>

char board[3][3];  //Gamer board

//function to initialize the board
void initializeBoard(){
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	board[i][j]=' ';
}

//Function to print the board
void printBoard(){
	printf("\n");
	printf("%c|%c|%c\n",board[0][0],board[0][1],board[0][2]);
	printf("--+--+--\n");
	printf("%c|%c|%c\n",board[1][0],board[1][1],board[1][2]);
	printf("--+--+--\n");
	printf("%c|%c|%C\n",board[2][0],board[2][1],board[2][2]);
	printf("\n");
}
//Function to check is a player has won
int checkWin(){
	// check row
	for(int i=0;i<3;i++)
	if(board[i][0]==board[1][i]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
	return 1;
	
	//Check column
	for (int i=0;i<3;i++)
	if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!=' ')
	return 1;
	
	//check diagonals
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]==board[0][0]!=' ')
	return 1;
	
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' ')
	return 1;
	
	return 0;
}

//function to check if the board is full(draw
int isDraw(){
	for(int i=0;i<3;i++)
	for(int j=0;i<3;j++)
	if(board[i][j]==' ')
	return 0;
 return 1;
}

int main(){
	int row,col;
	char currentPlayer='X';
	initializeBoard();
	while(1){
		system("cls");  //clear screen for window	
		
		printf("TIC TAC TOE GAME\n\n");
		printBoard();
		printf("Player  %c,enter row and column(1-3 1-3);",currentPlayer);
		scanf("%d%d",&row,&col);
		
		//Adjust for array index(0-2 instead of 1-3)
		row--;
		col--;
		
		//check the move is valid
		if(row>=0&&row<3&&col>=0&&col<3&&board[row][col]==' '){
			board[row][col]=currentPlayer;
			
			//check for win
			if(checkWin()){
				system("cls");
				printBoard();
				printf("?? Player  %c win!\n",currentPlayer);
				break;
			}
			
			//check for draw
			if(isDraw()){
				system("cls");
				printBoard();
				printf("it's a draw!\n");
				break;
			}
			
			//Switch player
			currentPlayer=(currentPlayer=='X')?'0':'X';
					}
					else{
						printf(" Invalid move! Press any key to try again...");
						getch();
					}
}
return 0;
}