/*
Author: A Bleach
Date: 16/01/2021
*/
#include <stdio.h>

int main () {
    FILE *p_file;
    char str[80];
    int lineCount = 0;

    p_file = fopen("testdata.txt", "r");

    if (p_file == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }

    while ( fgets(str,81,p_file)!=NULL ) {
        lineCount++;
    } 

    printf("File has %i lines\n", lineCount);

    fclose(p_file);

    return 0;
}