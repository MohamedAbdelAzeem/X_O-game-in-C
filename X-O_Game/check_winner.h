/*
 * check_winner.h
 *
 *  Created on: Aug 17, 2021
 *      Author: ZAMALA
 */

#ifndef CHECK_WINNER_H_
#define CHECK_WINNER_H_

	int check_first_row(unsigned int* positons_played);
	int check_second_row(unsigned int* positons_played);
	int check_third_row(unsigned int* positons_played);

	int check_first_col(unsigned int* positons_played);
	int check_second_col(unsigned int* positons_played);
	int check_third_col(unsigned int* positons_played);

	int check_first_diagonal(unsigned int* positons_played);
	int check_second_diagonal(unsigned int* positons_played);

#endif /* CHECK_WINNER_H_ */
