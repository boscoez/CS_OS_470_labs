\
#include <stdio.h>


// FIFO Page Replacement Algorithm
int fifo(int pageFrames, int referenceString[], int referenceLength) {
    int pageFaults = 0;
    int pageTable[pageFrames];
    for (int i = 0; i < pageFrames; i++) {
        pageTable[i] = -1;
    }
    int pageTableIndex = 0;

    for (int i = 0; i < referenceLength; i++) {
        int page = referenceString[i];
        int pageFound = 0;
        for (int j = 0; j < pageFrames; j++) {
            if (pageTable[j] == page) {
                pageFound = 1;

#include <pthread.h>


#define NUM_FRAMES 4

#define NUM_THREADS 2



int ref_string[] = {0, 1, 7, 2, 3, 2, 7, 1, 0, 3};

int faults_fifo = 0, faults_lru = 0;



pthread_mutex_t fifo_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t lru_mutex = PTHREAD_MUTEX_INITIALIZER;



int fifo[NUM_FRAMES], lru[NUM_FRAMES], lru_count[NUM_FRAMES];



void *fifo_replace(void *arg) {

    int i, j, k, page, found;

    for (i = 0; i < 10; i++) {

        page = ref_string[i];

        found = 0;

        pthread_mutex_lock(&fifo_mutex);

        for (j = 0; j < NUM_FRAMES; j++) {

            if (fifo[j] == page) {

                found = 1;


                break;

            }

        }

        if (!found) {

            faults_fifo++;

            for (j = 0; j < NUM_FRAMES - 1; j++) {

                fifo[j] = fifo[j+1];

            }

            fifo[NUM_FRAMES-1] = page;

        }

        pthread_mutex_unlock(&fifo_mutex);

    }

    return NULL;

}

// LRU Page Replacement Algorithm
int lru(int pageFrames, int referenceString[], int referenceLength) {
    int pageFaults = 0;
    int pageTable[pageFrames];
    for (int i = 0; i < pageFrames; i++) {
        pageTable[i] = -1;
    }
    int lruTable[pageFrames];
    for (int i = 0; i < pageFrames; i++) {
        lruTable[i] = 0;
    }

    for (int i = 0; i < referenceLength; i++) {
        int page = referenceString[i];
        int pageFound = 0;
        for (int j = 0; j < pageFrames; j++) {
            if (pageTable[j] == page) {
                pageFound = 1;
                lruTable[j] = i;



void *lru_replace(void *arg) {

    int i, j, k, page, found, min;

    for (i = 0; i < 10; i++) {

        page = ref_string[i];

        found = 0;

        pthread_mutex_lock(&lru_mutex);

        for (j = 0; j < NUM_FRAMES; j++) {

            if (lru[j] == page) {

                found = 1;

                lru_count[j] = i;


                break;

            }

        }

        if (!pageFound) {
            int minLru = 2147483647;
            int pageTableIndex = 0;
            for (int j = 0; j < pageFrames; j++) {
                if (lruTable[j] < minLru) {
                    minLru = lruTable[j];
                    pageTableIndex = j;


        if (!found) {

            faults_lru++;

            min = lru_count[0];

            k = 0;

            for (j = 1; j < NUM_FRAMES; j++) {

                if (lru_count[j] < min) {

                    min = lru_count[j];

                    k = j;


                }

            }

            lru[k] = page;

            lru_count[k] = i;

        }

        pthread_mutex_unlock(&lru_mutex);

    }

    return NULL;

}



int main() {

    int referenceString[] = {0, 1, 7, 2, 3, 2, 7, 1, 0, 3};
    int referenceLength = sizeof(referenceString) / sizeof(referenceString[0]);
    int pageFrames = 4;

    printf("FIFO Page Replacement: %d\n", fifo(pageFrames, referenceString, referenceLength));
    printf("LRU Page Replacement: %d\n", lru(pageFrames, referenceString, referenceLength));


    pthread_t threads[NUM_THREADS];

    pthread_create(&threads[0], NULL, fifo_replace, NULL);

    pthread_create(&threads[1], NULL, lru_replace, NULL);



    int i;

    for (i = 0; i < NUM_THREADS; i++) {

        pthread_join(threads[i], NULL);

    }



    printf("FIFO faults: %d\n", faults_fifo);

    printf("LRU faults: %d\n", faults_lru);




    return 0;

}
