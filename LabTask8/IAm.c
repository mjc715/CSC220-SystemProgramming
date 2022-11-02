#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[1024];

int main(void) {

	String Input;
	String Qualities = "The qualities are ";
	String Trait;
	FILE *Output;

	if ((Output = fopen("MyQualities.txt", "a")) == NULL) {
		printf("Couldnt open file\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter sentences, . to end \n");
	do {
		fgets(Input, 1024, stdin);
		if (strstr(Input, "I am") && strlen(Input) > 4) {
			strcpy(Trait, &(Input[5]));
			if (Trait[strlen(Trait) - 1] == '\n') {
				Trait[strlen(Trait) - 1] = '\0';
			}
			strncat(Qualities, Trait, strlen(Trait));
			fputs(Trait, Output);
			fputs("\n", Output);
			strncat(Qualities, ", ", 2);
			
		}
	} while (strcmp(Input,".\n"));

	int Length = strlen(Qualities);
	if (Qualities[Length-2] == ',') {
		Qualities[Length-2] = '.';
	}
	printf("%s\n", Qualities);
	
	fclose(Output);
	if ((Output = fopen("MyQualities.txt", "r")) == NULL) {
		printf("Error opening for reading\n");
		exit(EXIT_FAILURE);
	}
	String S1;
	printf("Confirming the saved qualities...\n");
	while (fgets(S1, 1024, Output)) {
		printf("    %s",S1);
	}
	fclose(Output);
	remove("MyQualities.txt");

}

		
