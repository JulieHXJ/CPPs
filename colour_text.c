#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int main(void) {
	// First Number 38 foreground, 48 background
	// second Number 5 -> indicator color code follow after ;
	// third Number 0 <-> 255 Color Code

	system("printf '\\033[2J\\033[3J\\033[H'");
	for (int i = 1; i < 256; ++i) {
		if (i > 0 && i < 201 && i % 50 == 0) {
			char *input;
			printf("\n\n\n");
			input = readline("\033[0;30;47m> Press Enter to continue <\033[0m");
			if (input != NULL)
				free(input);
			system("printf '\\033[2J\\033[3J\\033[H'");
		}
		printf("\033[38;5;%dmThis i 38;5;%d\033[0m\n", i, i);
		if(i == 255) {
			char *input;
			printf("\n\n\n");
			input = readline("\033[0;30;47m> Press Enter to continue <\033[0m");
			if (input != NULL)
				free(input);
			system("printf '\\033[2J\\033[3J\\033[H'");
		}
	}
	for (int i = 1; i < 256; ++i) {
		printf("\033[38;5;%dmThis i 38;5;%d\033[0m\n", i, i);
	}
	return (0);
}
