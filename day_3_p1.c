#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char get_index(char c);

int main()
{
	FILE *fp;
	char *line = NULL;
	size_t len = 100;
	ssize_t read;	
	int priority, priorities_sum;

	fp = fopen("input.txt", "r");
	if (fp == NULL){
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1) {
		int total_items = read - 1;  
		int half = total_items / 2;
		int left_count_array[52] = {0};
		int right_count_array[52] = {0};

		for (int i= 0; i < half; i++){
			char left_char = line[i];
			char right_char = line[i + half];

			char left_index = get_index(left_char);
			char right_index = get_index(right_char);

			left_count_array[left_index]++;
			right_count_array[right_index]++;

			if(left_count_array[left_index] > 0 && right_count_array[left_index] > 0){
				priority = (int) left_index + 1; 
				break;
			}
			if(right_count_array[right_index] > 0 && left_count_array[right_index] > 0){
				priority = (int) right_index + 1;
				break;
			}

		}
		priorities_sum += priority;
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
