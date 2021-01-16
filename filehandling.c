/*
Author: A Bleach
Date: 16/01/2021
*/
#include <stdio.h>
#include <ctype.h>

#define SOURCEFILENAME "testdata.txt"
#define DESTINATIONFILENAME "edited.txt"

int describeFile();
int convertFileToLowerCase();
int getFileLength(FILE *p_file);
int printFile(FILE *p_file);
int reverseFile();

int main () {
    
    reverseFile();
    return 0;
    convertFileToLowerCase();
    describeFile();

    return 0;
}

int reverseFile() {
    FILE *p_sourceFile = NULL;
    int storeItem = 0, fileLength = 0;
    char currentChar;
    p_sourceFile = fopen(SOURCEFILENAME, "r");
    if (p_sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return -1;
    }

    fileLength = getFileLength(p_sourceFile);
    char fileBuffer[fileLength];
    
    while ( (currentChar = fgetc(p_sourceFile)) != EOF ) { // read source forwards
        fileBuffer[storeItem++] = currentChar;
    }

    for ( int i=fileLength; i>=0; i--) {
        printf("%c",fileBuffer[i]);
    }

    return 0;
}

int convertFileToLowerCase() {
    FILE *p_sourceFile = NULL;
    FILE *p_destinationFile = NULL;
    char currentChar;

    p_sourceFile = fopen(SOURCEFILENAME, "r");
    if (p_sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return -1;
    }

    p_destinationFile = fopen(DESTINATIONFILENAME, "w");
    if (p_destinationFile == NULL) {
        printf("Unable to open or create destination file.\n");
        return -1;
    }

    while ( (currentChar = fgetc(p_sourceFile)) != EOF ) {
        if ( islower(currentChar) ) {
            currentChar -= 32; 
        }
        fputc(currentChar,p_destinationFile);
    }

    fclose(p_sourceFile);
    p_sourceFile = NULL;

    fclose(p_destinationFile);
    p_destinationFile = NULL;

    p_destinationFile = fopen(DESTINATIONFILENAME, "r");
    if (p_destinationFile == NULL) {
        printf("Unable to open destination file for reading.\n");
        return -1;
    }
    printFile(p_destinationFile);

    fclose(p_destinationFile);
    p_destinationFile = NULL;

    remove(DESTINATIONFILENAME);

    return 0;
}

int printFile(FILE *p_file) {
    fseek(p_file, 0L, SEEK_SET);
    char currentLine[80];
    while ( fgets(currentLine, 81, p_file) != NULL ) {
        puts(currentLine);
    }

    return 0;
}

int describeFile() {
    FILE *p_file = NULL;
    char currentChar;
    int charCount = 0, lineCount = 0;

    p_file = fopen(SOURCEFILENAME, "r");

    if (p_file == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
     
    if ( getFileLength(p_file) > 1 ) {
        lineCount++;
        while ( (currentChar = fgetc(p_file)) != EOF ) {
            if ( currentChar == '\n' ) {
                lineCount++;
            } else {
                charCount++;
            }
        } 
    }

    fclose(p_file);
    p_file = NULL;

    printf("File has %i characters, excluding line endings\n", charCount);
    printf("File has %i lines\n", lineCount);

    return 0;  
}

int getFileLength(FILE *p_file) {
    int fileLength = 0;

    fseek(p_file, 0L, SEEK_END);
    fileLength = ftell(p_file);
    fseek(p_file, 0L, SEEK_SET);

    return fileLength;
}