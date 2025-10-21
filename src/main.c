#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

static struct option long_options[] = {
	{"lower_bound", 1, 0, 'l'},
	{"upper_bound", 1, 0, 'u'},
	{0,0,0,0}
};
 

int main(int argc, char **argv) {
	char c;
	int lower_bound = -1, upper_bound = -1;
	while (1) {
		if ((c = getopt_long(argc, argv, "l:u:", long_options, 0)) == -1) {
			break;
		}
		switch (c) {
			case 'l':
				lower_bound = atoi(optarg);
				break;
			case 'u':
				upper_bound = atoi(optarg);
				break;
		}
	}
	if (lower_bound == -1) {
		fprintf(stderr, "Flag lower_bound is missing.\n");
		return 1;
	}
	if (upper_bound == -1) {
		fprintf(stderr, "Flag upper_bound is missing.\n");
		return 1;
	}
	if (lower_bound > upper_bound) {
		fprintf(stderr, "The lower bound is greater than the upper bound.\n");
		return 1;
	}
	for (int i = lower_bound; i <= upper_bound; ++i) {
		printf("%d ", i);
	}
}