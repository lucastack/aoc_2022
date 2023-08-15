#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ON 1
#define OFF 0

int main()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 100;
    ssize_t read;
    int status = ON;
	int max_sum = 0;
	int partial_sum = 0;
    int num;

    fp = fopen("input.txt", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
		if (strcmp(line, "\n") == 0){
            if (status == ON){
		        status = OFF;
				if (partial_sum > max_sum){
				    max_sum = partial_sum;
				}
			}
		} else {
		    if (status == OFF){
		        status = ON;
				partial_sum = 0;
			}
		}
		
		if (status == ON){
		    num = atoi(line);
			partial_sum += num;
		}

    }
	printf("Solution: %d\n", max_sum);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

