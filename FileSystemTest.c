#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "FileSystem.h"

void displayOptions();
void commandChoice();

int main(){
	
	char str[20];
	char str1[20];
	printf("Enter the drive: (Drive2MB , Drive3MB ,Drive5MB , Drive10MB): \n");
	scanf("%s" , str1);
	setup(str1); // start up the filesystem
	while (1){		// display options until user exits
		displayOptions();
		printf("$ ");
		scanf("%s", str);
		commandChoice(str); // calls the appropriate filesystem method
	}
}


void displayOptions(){
	printf("Here are your options:\n");
	printf("\"create\"\t\"delete\" \n");
	printf("\"read\"  \t\"write\" \n");
	printf("\"mkdir\"  \t\"list\" \n");
	printf("\"open\"   \t\"exit\" \n");
	printf("\"close\"  \n");
}

void commandChoice(char str[]){

	char fileName[11];
	int firstBlock;

	if (strcmp(str, "create") == 0){ 
		printf("Enter the name of file: ");
		scanf("%s", fileName);
		create(fileName, 0);		// 0 flag means file
	}
	else if (strcmp(str, "delete") == 0){				// delete files
		printf("Enter the name of file: ");
		scanf("%12s", fileName);
		fs_delete(fileName);
	}
	else if (strcmp(str, "read") == 0){					// read data blocks of a file
		printf("Enter the name of file: ");
		scanf("%12s", fileName);
		fs_read(fileName);
	}
	else if (strcmp(str, "write") == 0){
		
		char *dataBlock = calloc(32768, sizeof(char));	// create an empty larger array

		printf("Enter the name of file: ");
		scanf("%12s", fileName);
		printf("--- Write --- \n");
		
		if(read(STDIN_FILENO, dataBlock, 32768) < 0){
		}
		fs_write(fileName, dataBlock);
		free(dataBlock);
	}
	else if (strcmp(str, "mkdir") == 0){  				// create a directory
		printf("Enter the name of directory: ");
		scanf("%s", fileName);
		create(fileName, 1); 						// 1 flag means directory
	}
	else if (strcmp(str, "list") == 0){					// exit program
			list();	
	}
	else if(strcmp(str , "open") == 0){
		printf("Enter the file name to open: ");
		scanf("%12s", fileName);
		firstBlock = fs_open(fileName);
		printf("First block of the file is: \n");
		printf("%d\n" , firstBlock);
	}
	else if(strcmp(str , "exit") == 0){
		fs_exit();
		exit(0);
	}
	else if (strcmp(str, "close") == 0){					
		fs_close();
		printf("Successfully close the file \n");
	}	
	else {
		printf("Invalid Command\n");
	}
} 
