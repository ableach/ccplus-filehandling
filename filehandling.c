/*
Author: A Bleach
Date: 16/01/2021
*/
#include <stdio.h>

#define FILENAME "testdata.txt"

int describeFile();
int getFileLength(FILE *p_file);

int main () {
    
    describeFile();

    return 0;
}

int describeFile() {
    FILE *p_file = NULL;
    char currentChar;
    int charCount = 0, lineCount = 0;

    p_file = fopen(FILENAME, "r");

    if (p_file == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
     
    if ( getFileLength(p_file) > 1 ) {
        lineCount++;
        while ( (currentChar = fgetc(p_file)) != EOF ) {
            charCount++;
            if ( currentChar == '\n' ) {
                lineCount++;
            }
        } 
    }

    fclose(p_file);
    p_file = NULL;

    printf("File has %i characters\n", charCount);
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