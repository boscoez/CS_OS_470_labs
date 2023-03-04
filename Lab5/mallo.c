#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 500

int main() {
    char* name = (char*) malloc(MAX_NAME_LENGTH * sizeof(char)); // allocate memory for name
    char* address = (char*) malloc(MAX_ADDRESS_LENGTH * sizeof(char)); // allocate memory for address

    if (name == NULL || address == NULL) { // check if allocation was successful
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin); // read name from console

    printf("Enter your address: ");
    fgets(address, MAX_ADDRESS_LENGTH, stdin); // read address from console

    // remove newline character from input
    name[strcspn(name, "\n")] = '\0';
    address[strcspn(address, "\n")] = '\0';

    // print name and address to console
    printf("Name: %s\n", name);
    printf("Address: %s\n", address);

    free(name); // free memory allocated for name
    free(address); // free memory allocated for address

    return 0;
}

