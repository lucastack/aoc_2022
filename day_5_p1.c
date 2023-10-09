#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 100
#define MAX_LEN 500


int main() {
	FILE *file;
	char *filename = "input.txt";
	char line[MAX_LEN];
	char grid[MAX_COLUMNS][MAX_ROWS];
	char real_grid[MAX_COLUMNS][MAX_ROWS];
	int heights[MAX_COLUMNS] = {0};

	file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}
	int is_board_initialized = 0;
	while (fgets(line, sizeof(line), file) != NULL) {
		printf("%s", line);
		if (strncmp(line, "move", 4) != 0) {
			int i = 0;
			for (int j = 0; j < strlen(line); j++) {
				if ( ((j - 1) % 4 == 0) && (isdigit(line[j]) == 0)){
					if (isalpha(line[j]) ) {	
						int insert_pos = heights[i];
						grid[i][insert_pos] = line[j];
						heights[i]++;
					} 
					i++;
				}
			}
		} else {
			int cols_number = 9;
			if (is_board_initialized != 1){
				for(int j = 0; j < cols_number; j++){
					int col_height = heights[j];
					for(int i = col_height - 1; i > -1; i--) {
						real_grid[j][col_height - i - 1] = grid[j][i];
					}
				}
				is_board_initialized = 1;
			}  
			int amount, src_index, dst_index;
			if (sscanf(line, "move %d from %d to %d", &amount, &src_index, &dst_index) == 3) {
				printf("%s", line);
				src_index--;
				dst_index--;
				for(int i = 0; i < amount; i++){
					int src_height = heights[src_index];
					int dst_height = heights[dst_index];
					char char_to_move = real_grid[src_index][src_height - 1];			
					real_grid[dst_index][dst_height] = char_to_move; 
					real_grid[src_index][src_height - 1] = '\0';
					heights[src_index]--;
					heights[dst_index]++;
					for(int i = 0; i < 9; i++){
						int col_height = heights[i];
						for(int j=0; j < col_height; j++){
							printf("%c", real_grid[i][j]);
						}
						printf("\n");
					}
					printf("----------------------\n");
				}
    			} else {
        			printf("Failed to parse the instruction properly.\n");
    			}
			
		}
    	}
	for (int i = 0; i < 9; i++) {
		int col_index = heights[i] - 1;
		printf("%c", real_grid[i][col_index]);
	}
	printf("\n");
    	fclose(file);
    	return 0;
}

