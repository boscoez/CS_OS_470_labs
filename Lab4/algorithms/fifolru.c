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
    int referenceLength = sizeof(referenceString) / sizeof(referenceString[0]);
    int pageFrames = 4;

    printf("FIFO Page Replacement: %d\n", fifo(pageFrames, referenceString, referenceLength));
    printf("LRU Page Replacement: %d\n", lru(pageFrames, referenceString, referenceLength));

    return 0;
}

