/*
Author: A Bleach
Date: 16/01/2021
*/
#include <stdio.h>

#define FILENAME "testdata.txt"

int describeFile();

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

    while ( (currentChar = fgetc(p_file)) != EOF ) {
        charCount++;
        if ( currentChar == '\n' ) {
            lineCount++;
        }
    } 

    printf("File has %i characters\n", charCount);
    printf("File has %i lines\n", lineCount);

    fclose(p_file);

    return 0;  
}