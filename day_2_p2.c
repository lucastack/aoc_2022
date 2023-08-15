#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char *line = NULL;
	size_t len = 100;
	ssize_t read;
	char opp_choice, our_choice;
	int total_score;
	

	fp = fopen("input.txt", "r");
	if (fp == NULL){
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1) {
		opp_choice = line[0];
		our_choice = line[2];
		switch (opp_choice){
		case 'A':
			switch (our_choice) {
			case 'X':
				total_score += (3 + 0);
				break;
			case 'Y':
				total_score += (1 + 3);
				break;
			case 'Z':
				total_score += (2 + 6);
				break;
			}
			break;
		case 'B':
			switch (our_choice) {
			case 'X':
				total_score += (1 + 0);
				break;
			case 'Y':
				total_score += (2 + 3);
				break;
			case 'Z':
				total_score += (3 + 6);
				break;
			}
			break;
		case 'C':
			switch (our_choice) {
			case 'X':
				total_score += (2 + 0);
				break;
			case 'Y':
				total_score += (3 + 3);
				break;
			case 'Z':
				total_score += (1 + 6);
				break;
			}
			break;
		}
		printf("%c vs %c - score: %d\n", opp_choice, our_choice, total_score); 
	}
	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

