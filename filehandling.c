/*
Author: A Bleach
Date: 16/01/2021
*/
#include <stdio.h>

int main () {
    FILE *p_file;
    char currentChar;
    int charCount = 0, lineCount = 0;

    p_file = fopen("testdata.txt", "r");

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