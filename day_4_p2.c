#include <stdio.h>
#include <stdlib.h>


int are_tasks_contained(int x, int y, int a, int b) {
	return ((x <= a && b <= y) || (a <= x && y <= b));
}


int are_tasks_overlapped(int x, int y, int a, int b) {
	return are_tasks_contained(x, y, a, b) || (x <= a && a <= y) || (a <= x && x <= b);
}


int main()
{
	FILE *input_file;

	input_file = fopen("input.txt", "r");
	if (input_file == NULL){
		exit(EXIT_FAILURE);
	}
    
    	int x, y, a, b;
	int contained_tasks_num = 0;
	int overlapped_tasks_num = 0;

    	while(fscanf(input_file, "%d-%d,%d-%d", &x, &y, &a, &b) == 4) {
		contained_tasks_num += are_tasks_contained(x, y, a, b);
		overlapped_tasks_num += are_tasks_overlapped(x, y, a, b);
    	}

	printf("Contained tasks: %d\n", contained_tasks_num);
	printf("Overlapped tasks: %d\n", overlapped_tasks_num);

    	fclose(input_file);
    	return 0;
}

