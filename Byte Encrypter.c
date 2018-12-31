#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE 256

FILE *fp;
char message[BYTE];

char *encrypt(FILE *fp);
char *decrypt(FILE *fp);


int main() {
	
	printf("\n\t\t\t- Byte Encrypter - \n");
	printf("This is a C program that modifies text from a file using Ceasar's cipher. \n");
	// loads file from user input 
	printf("Enter the path to your file: ");
	char fname[75]; 	
	scanf("%s", &fname);
	
    // opens text file for reading 
    fp = fopen(fname, "r");
    
    // checks that the text file exists
    if (fp == NULL) {
		printf("Unable to open file. \n");
		printf("Path example: C:\\Users\\You\\Desktop\\file.txt");
		return 1;
	}
	// displays menu
	int option = 0;
	char* new = malloc(BYTE);
	printf("\nYour file has been loaded and is ready to be modified.\n\n");	
	do {
	printf("1. Encrypt File \n");
	printf("2. Decrypt File  \n");
	printf("3. Exit Program \n");
	printf("Select an option: ");
	scanf("%d", &option);
	
	// handles all the options
	if (option == 1) new = encrypt(fp);
	if (option == 2) new = decrypt(fp);
	
    // write new message to file
	fp = fopen(fname, "w");
    fprintf(fp, "%s", new);

	} while(option != 3);
	
    fclose(fp);
	return 0;
}

char* encrypt(FILE *fp) {

    // reads the text file
	int ch = getc(fp);
	int i = 0;
    while(ch != EOF ) {
	    message[i++] = ch; 
		ch = getc(fp);
    }
	
	// encrypts the text file
	char* encrypted = message;
	char current;
    int mlen = (int)strlen(message);
	int key = mlen / 2 + 1; 
	
    for (i = 0; i < mlen; i++) {
		// does not modify these chars (punctuations)
		if (message[i] != ' ' && message[i] != ',' && message[i] != ':' && message[i] != ';' 
			&& message[i] != '.' && message[i] != '\'' && message[i] != '\"' 
			&& message[i] != '!' && message[i] != '?' && message[i] != '\n') {
			current = (message[i] + key);	    
		} else {
		   current = message[i];
		}
		encrypted[i] = current;
    }
	
    int elen = (int)strlen(encrypted);
    printf("\nYour file containing %d chars has been encrypted.\n\n", elen);
	return encrypted;
} 

char *decrypt(FILE *fp) {

    // reads the text file
	int ch = getc(fp);
	int i = 0;
    while(ch != EOF ) {
	    message[i++] = ch; 
		ch = getc(fp);
    }
	
	// decrypts the text file
	char *decrypted = message;
	char current;
    int mlen = (int)strlen(message);
	int key = mlen / 2 + 1; 
	
    for (i = 0; i < mlen; i++) {
		// does not modify these chars (punctuations)
		if (message[i] != ' ' && message[i] != ',' && message[i] != ':'
			&& message[i] != ';' && message[i] != '.' 
			&& message[i] != '\'' && message[i] != '\"' 
			&& message[i] != '!' && message[i] != '?' && message[i] != '\n') {
			current = (message[i] - key);	    
		} else {
		   current = message[i];
		}
		decrypted[i] = current;
    }
    int elen = (int)strlen(decrypted);
    printf("\nYour file containing %d chars has been decrypted.\n\n", elen);
	return decrypted;
} 


	