/*
 * check_winner.c
 *
 *  Created on: Aug 17, 2021
 *      Author: ZAMALA
 */


int check_first_row(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 1 || i == 2 || i == 3)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}
int check_second_row(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 4 || i == 5 || i == 6)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}
int check_third_row(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 7 || i == 8 || i ==  9)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}

int check_first_col(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 1 || i == 4 || i ==  7)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}
int check_second_col(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 2 || i == 5 || i ==  8)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}




int check_third_col(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 3 || i == 6 || i ==  9)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}



int check_first_diagonal(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 1 || i == 5 || i ==  9)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}
int check_second_diagonal(unsigned int* positons_played)
{
	int counter = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(i == 3 || i == 5 || i ==  7)
		{
			if(positons_played[i] == 1 )
			{
				counter++;
			}
			else if(positons_played[i] == 2)
			{
				counter--;
			}
			else
			{
				counter = 0;
			}
		}
	}
	return counter;
}
