#include <stdio.h>
#include <stdlib.h>


#define LINE_MAX_LEN 100


int main()
{
	FILE *input_file;

	input_file = fopen("input.txt", "r");
	if (input_file == NULL){
		exit(EXIT_FAILURE);
	}
    
    	int x, y, a, b;
	int contained_tasks = 0;

    	while(fscanf(input_file, "%d-%d,%d-%d", &x, &y, &a, &b) == 4) {
		if ((x <= a && b <= y) || (a <= x && y <= b)) {
			contained_tasks++;
		}
		
    	}

	printf("Contained tasks: %d\n", contained_tasks);

    	fclose(input_file);
    	return 0;
}

