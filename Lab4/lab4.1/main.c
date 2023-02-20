#include <stdio.h>

int main() {
    FILE *fp;
    char phrase[] = "This is a test for opening, writing, and closing a file!";

    fp = fopen("outputLab4.txt", "a"); // Open the file for appending

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fp, "%s", phrase); // Write the phrase to the file

    fclose(fp); // Close the file

    return 0;
}

