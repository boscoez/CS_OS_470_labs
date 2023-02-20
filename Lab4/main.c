#include <pthread.h>
#include <stdio.h>

//Declaring Global variables
int avg = 0;
int minValue = 0, maxValue = 0;

//Set length of array to 7 as the given input is of length 7 [ 90 81 78 95 79 72 85 ]
int len = 7;

/* Function to calculates average of the values in the given array */
void *calcAvg(void *arg) {
    int i = 0, sum = 0;
    int *values;

//Fetching array
    values = (int *) arg;

//Iterating over array
    for (i = 0; i < len; i++) {
//Accumulating sum
        sum = sum + values[i];
    }
    return NULL;
}

/* Function that calculates minimum value in from the given array */
void *calcMin(void *arg) {
    int i = 0;
    int *values;

//Fetching array
    values = (int *) arg;

//Initializing minimum value as starting element
    minValue = values[0];

//Iterating over array
    for (i = 0; i < len; i++) {
//Comparing value
        if (values[i] < minValue) {
//Updating minimum value
            minValue = values[i];
        }}
    return NULL;
}

/* Function that calculate minimum value in from the given array */
void *calcMax(void *arg) {
    int i = 0;
    int *values;

//Fetching array
    values = (int *) arg;

//Initializing maximum value as starting element
    maxValue = values[0];

//Iterating over array
    for (i = 0; i < len; i++) {
//Comparing value
        if (values[i] > maxValue) {
//Updating maximum value
            maxValue = values[i];
        }}
    return NULL;
}

/* Main function */
int main(void) {
//Thread identifiers
    pthread_t minPth, maxPth;
    int i = 0;

//Array declaration
    int values[] = {90, 70, 2, 5, 20, 98, 25};

//Creating threads one for each operation
    pthread_create(&minPth, NULL, calcMin, values);
    pthread_create(&maxPth, NULL, calcMax, values);

//Waiting till all threads finish their work
    pthread_join(minPth, NULL);
    pthread_join(maxPth, NULL);

//Printing results
    printf("\n The Minimum value is: %d \n", minValue);
    printf("\n The Maximum value is: %d \n", maxValue);

    return 0;
}
