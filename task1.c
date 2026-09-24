#include <stdio.h>

/*
The print combinations function determines all possible combinations of scoring plays in the NFL game when user inputed score is passed.
It uses brute force logic to iterate through every possible count for each scoring play.
*/
void print_combinations(int score) {
	printf("Possible combinations of scoring plays if a team's score is %d:\n", score); // Prefix message before combination is printed

	// First checks combinations starting from the highest point value down to the lowest
	// Loops check to make sure count * points are less than or equal to total score
	// Wjen the total sum of scoring plays matches the user inputed score, that combination is printed to user

	// Point values are as follows; TD + 2pt = 8; TD + FG = 7; TD = 6; 3pt FG = 3; Safety = 2
	for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
		for (int td_fg = 0; td_2pt * 8 + td_fg * 7 <= score; td_fg++) {
			for (int td = 0; td_2pt * 8 + td_fg * 7 + td * 6 <= score; td++) {
				for (int fg = 0; td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 <= score; fg++) {
					for (int safety = 0; td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 <= score; safety++) {
						if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
						}
					}
				}
			}
		}
	}
}

/*
The main function stores user inputed game score and passes this value to the print_combination function.
It also handles error checking for user input.
*/
int main() {
	int score;	// Initialize score int variable for user input

	// A while loop is used so program doesn't have to be run again after returning combinations for inputed score
	while (1) {
		printf("Enter the NFL score (Enter 1 to stop): ");	// Prompt user for game score

		/* User input error handling block
		   - If user inputed score is less than 1, including negative integers, the user is prompted with a program termination message then program is terminated.
		   - If user inputed score is not an interger greater than 1, the user is prompted with an invalid input message that restates valid input and user is prompted to enter game scoer again.
		*/

		if (scanf("%d", &score) != 1) {
			printf("Invalid input. Please enter an integer.\n");
			while (getchar() != '\n');	// If the user enters letters instead of numbers, the input buffer holds the unread keyboard input. This buffer needs to be cleared before new input is entered to prevent an infinite loop.
			continue;
		}

		if (score <= 1) {	// Prints program termination message and terminates program when integer less than 1 is entered
			printf("Program terminated.\n");
			break;
		}

		print_combinations(score);	// If error handling checks pass, user inputed game score is passed into print_combinations function.
	}

	return 0;
}
