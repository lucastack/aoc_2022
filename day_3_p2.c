#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define LINE_MAX_LEN 100

char get_index(char c);

int main()
{
	FILE *fp;
	char *line = NULL;
	size_t len = LINE_MAX_LEN;
	ssize_t read;	
	int priorities_sum;

	fp = fopen("input.txt", "r");
	if (fp == NULL){
		exit(EXIT_FAILURE);
	}
	

	int delimiter_index = 0;
	int count_array[3][52] = {0};
	while ((read = getline(&line, &len, fp)) != -1) {  
		for (int i = 0; i < strlen(line) - 1; i++) {
			char char_at_i = line[i];
			char char_index = get_index(char_at_i);
			count_array[delimiter_index][char_index]++;
		}
		delimiter_index = (delimiter_index + 1) % 3;
		printf("%s", line);
		if (delimiter_index == 0){
			
			for(int i = 0; i < 52; i++){
				if (count_array[0][i] > 0 && count_array[1][i] > 0 && count_array[2][i] > 0){
					priorities_sum += i + 1;
				}

			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 52; j++){
					count_array[i][j] = 0; 
				}
			}
		}
	}
	printf("Sum of priorities: %d\n", priorities_sum);
	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

char get_index(char c){
	if (isupper(c)){
		return c - 'A' + 26;
	} else {
		return c - 'a';
	}
}
