#include <stdio.h>
#include <stdlib.h>

// FIFO Page Replacement Algorithm
int fifo(int pageFrames, int referenceString[], int n) {
    int pageFaults = 0;
    int pageTable[pageFrames];
    for (int i = 0; i < pageFrames; i++) {
        pageTable[i] = -1;
    }
    int pageTableIndex = 0;

    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;
        for (int j = 0; j < pageFrames; j++) {
            if (pageTable[j] == page) {
                pageFound = 1;
                break;
            }
        }
        if (!pageFound) {
            pageTable[pageTableIndex] = page;
            pageFaults++;
            pageTableIndex = (pageTableIndex + 1) % pageFrames;
        }
    }

    return pageFaults;
}

// LRU Page Replacement Algorithm
int lru(int pageFrames, int referenceString[], int n) {
    int pageFaults = 0;
    int pageTable[pageFrames];
    for (int i = 0; i < pageFrames; i++) {
        pageTable[i] = -1;
    }
    int lruTable[pageFrames];
    for (int i = 0; i < pageFrames; i++) {
        lruTable[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;
        for (int j = 0; j < pageFrames; j++) {
            if (pageTable[j] == page) {
                pageFound = 1;
                lruTable[j] = i;
                break;
            }
        }
        if (!pageFound) {
            int minLru = 1000000;
            int pageTableIndex = 0;
            for (int j = 0; j < pageFrames; j++) {
                if (lruTable[j] < minLru) {
                    minLru = lruTable[j];
                    pageTableIndex = j;
                }
            }
            pageTable[pageTableIndex] = page;
            pageFaults++;
            lruTable[pageTableIndex] = i;
        }
    }

    return pageFaults;
}

int main() {
    int referenceString[] = {0, 1, 7, 2, 3, 2, 7, 1, 0, 3};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int pageFrames = 4;

    printf("FIFO Page Replacement: %d\n", fifo(pageFrames, referenceString, n));
    printf("LRU Page Replacement: %d\n", lru(pageFrames, referenceString, n));

    return 0;
}

