//--- Put fgets inside the child process not outside
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_STRING 1024
typedef char String[MAX_STRING];

int main(int argc, char * argv[]) {
	FILE *ReadFile;
	String Line;
	char *MyArgV[100];
	int ChildPID, MyArgC, Status, i, j;
	ReadFile = fopen(argv[1], "r");
	String MyCommands[100];

	if (argc != 2) {
		printf("Enter 1 command line argument only\n");
		exit(EXIT_FAILURE);
	}
	if (ReadFile == NULL) {
		printf("File not opened\n");
		exit(EXIT_FAILURE);
	}
	printf("Commands:\n");
	while (fgets(MyCommands[i], MAX_STRING, ReadFile)) {
		printf("%s",MyCommands[i]);
		++i;
	}
	printf("\n");
	fclose(ReadFile);
	j = 0;
	while (j < i) {
		strcpy(Line, MyCommands[j]);
		ChildPID = fork();
		if ((ChildPID == -1)) {
			perror("Could not fork");
			exit(EXIT_FAILURE);
		}
		if (ChildPID == 0) {

				Line[strlen(Line)-1] = '\0';
				MyArgC = 0;
				MyArgV[MyArgC] = strtok(Line," ");
				while (MyArgV[MyArgC++] != NULL) {
					MyArgV[MyArgC] = strtok(NULL," ");
				}
				MyArgV[++MyArgC] = "&";
				execvp(MyArgV[0],MyArgV);
				perror("Error in exec");
				exit(EXIT_FAILURE);
			
		} 
	++j;
	}
	ChildPID = waitpid(ChildPID,&Status,0);
	exit(EXIT_SUCCESS);
}
			
		
		
		
	
