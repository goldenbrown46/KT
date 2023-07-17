#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) {
	if (strcmp(argv[1], "+") == 0) {
		printf("%d\n", atoi(argv[2])+atoi(argv[3]));
	}
	if (strcmp(argv[1], "-") == 0) {
		printf("%d\n", atoi(argv[2])-atoi(argv[3]));
	}
	if (strcmp(argv[1], "*") == 0) {
		printf("%d\n", atoi(argv[2])*atoi(argv[3]));
	}
	if (strcmp(argv[1], "/") == 0) {
		printf("%d\n", atoi(argv[2])/atoi(argv[3]));
	}
}
