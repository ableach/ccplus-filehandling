#include <stdio.h>

int main () {
    FILE *p_file;

    p_file = fopen("testdata.txt", "r");

    if (p_file == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }

    return 0;
}