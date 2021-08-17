/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Mohamed AbdelAzeem
 */

#include <stdio.h>
#include "check_winner.h"
#include <stdlib.h>

/**************************** Constansts ***************************************/
#define PLAYER_1 1
#define PLAYER_2 2


/**************************** Global Variables *********************************/

char Start_End ;
unsigned int current_player = 1;
unsigned int current_position  = 0;
unsigned int full_matrix = 0;
unsigned int positons_played[10] = {0};
int winner = -1  ;
char players_symbols[] = {0, 'X', 'O'};
/**********************************************************************************/



void print_matrix_empty()
{

	int pos = 1 ;
	printf("\n");
	for(unsigned int i = 0; i < 3 ; i++ )
	{
		for(unsigned int j = 0 ; j < 3; j++)
		{

			printf(" ");
			printf(" %d  ", pos);
			printf("|");
			pos++;
		}
		printf("\n");
		printf(" __    __    __ \n\n");

	}

}

void Welcome_func()
{
	printf("Welcome to X-O Game. \n");
	printf("Author: Mohamed AbdelAzeem. \n");
	printf("Created on Aug,2021.\n");
	printf("-----------------------------\n");
	printf("Player 1 : X ,  Player 2 : O\n\n" );
	printf("you have to choose the number which indicates the position you want.\n");
}


void Ask_for_Start_End()
{
	printf("To start now please Enter 'S'. To End now please Enter 'E'.\n");
	printf("To End at any time please Enter -1  \n");
	printf("Note: Letters should be capital. \n");

	do
	{
		scanf(" %c", &Start_End );
		if(Start_End == 'S')
		{
			printf("Game started .. \n");
		}
		else if(Start_End== 'E' || Start_End ==  -1 )
		{
			printf("Game Ended .. \n");
			Start_End = 'E';
			winner = 0;
			return ;
		}else
		{
			printf("Invalid character.. \n");
		}

	}while(Start_End != 'E' && Start_End != 'S');
}


int check_matrix_full()
{
	//Check if the matrix is full and all places are taken before
	int full_flag= 1 ;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i != 0 && positons_played[i] == 0)
		{
			full_flag = 0 ;
		}
	}
	return full_flag;
}
void player_move(char player)
{
	//Take input from player
	current_player = player;
	unsigned char full_flag = 1 ;
	printf("Enter Position Player %d : \n", player);
	do
	{
		scanf(" %d", &current_position);
		//terminate if the input = -1
		if(current_position == -1 )
		{
			Start_End = 'E';
			winner = 0;
			printf("Game Ended ... ");
			exit(0);
		}
		//check if the input is valid
		if(current_position < 1 || current_position > 9 )
		{
			//input is out of range : NOT VALID
			printf("Invalid positon \n");
		}
		else
		{
			//input is valid
			if(positons_played[current_position] == 0 )
			{
				//position is not taken before
				positons_played[current_position] = player;
			}
			else
			{
				//position is taken before
				//if the matrix is not full
				if(check_matrix_full() == 0)
				{
					printf("Invalid Position, Please choose another one. \n");
				}
				else
				{
					//matrix is full
					full_matrix = full_flag ;
					printf("Matrix is full");
					return;
				}
			}
		}

		//check if the matrix is full to prevent another input sequence
		if(check_matrix_full() == 1)
		{
			full_matrix = full_flag ;
		}

	}while(current_position < 1 || current_position > 9 );
}

void print_matrix()
{
	int pos = 1;
	printf("\n");
	for(unsigned int i = 0; i < 3 ; i++ )
	{
		for(unsigned int j = 0 ; j < 3; j++)
		{

			printf(" ");
			printf(" %c  ", players_symbols[positons_played[pos]]);
			printf("|");
			pos++;
		}
		printf("\n");
		printf(" __    __    __ \n\n");

	}

}

void check_counter(int* counter)
{
	if(*counter == 3 )
	{
		winner = PLAYER_1;
	}
	else if(*counter == -3)
	{
		winner = PLAYER_2 ;
	}
	else
	{
		*counter=0;
		return;
	}
		//no winners until now
}

void check_winner()
{
	//check all rows and cols and diagonals
	int counter = 0;
	counter = check_first_row(positons_played);
	check_counter(&counter);

	counter = check_second_row(positons_played);
	check_counter(&counter);

	counter = check_third_row(positons_played);
	check_counter(&counter);

	counter =check_first_col(positons_played);
	check_counter(&counter);

	counter =check_second_col(positons_played);
	check_counter(&counter);

	counter = check_third_col(positons_played);
	check_counter(&counter);

	counter =check_first_diagonal(positons_played);
	check_counter(&counter);

	counter = check_second_diagonal(positons_played);
	check_counter(&counter);
}


void print_winner()
{
	printf("Winner %d \n", winner);
	printf(" IS Matrix full %d \n", full_matrix);
	if(winner != -1 )
	{
		//there is a winner
		if(winner == PLAYER_1)
		{
			printf(" **************************  PLAYER 1 IS THE WINNER ************************* \n");
			exit(0);
		}
		else if(winner == PLAYER_2)
		{
			printf(" ************************** PLAYER 2 IS THE WINNER **************************\n");
			exit(0);
		}
		else
		{
			printf("%d", winner);
			exit(0);
		}
	}
	else
	{
		//there is no winner
		if(full_matrix == 1)
		{
			//End Game draw
			printf("******************** End Game : Draw *****************************\n");
			Start_End = 'E';
			winner = 0;
			exit(0);
		}
	}
}

int main()
{
	 setbuf(stdout, NULL); //Disable Buffer problems , comment when debugging

	Welcome_func();
	print_matrix_empty();
	Ask_for_Start_End();

	while(Start_End != 'E' || winner == -1 )
	{
		player_move( PLAYER_1 );
		print_matrix();
		check_winner(PLAYER_1 );
		print_winner();

		player_move( PLAYER_2 );
		print_matrix();
		check_winner(PLAYER_2 );
	    print_winner();
	}

	printf("Game Endded \n");



return 0;
}





