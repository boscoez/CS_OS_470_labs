#include <stdio.h>
#include <pthread.h>

#define ROWS 4
#define COLS 4

int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result_add[ROWS][COLS], result_subtract[ROWS][COLS], result_multiply[ROWS][COLS];

void *addition(void *arg) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result_add[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Addition result:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result_add[i][j]);
        }
        printf("\n");
    }
    return NULL;
}

void *subtraction(void *arg) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result_subtract[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("Subtraction result:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result_subtract[i][j]);
        }
        printf("\n");
    }
    return NULL;
}

void *multiplication(void *arg) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result_multiply[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                result_multiply[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("Multiplication result:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result_multiply[i][j]);
        }
        printf("\n");
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    int i, j;
    printf("Enter matrix 1 (%d x %d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter matrix 2 (%d x %d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    pthread_create(&thread1, NULL, addition, NULL);
    pthread_create(&thread2, NULL, subtraction, NULL);
    pthread_create(&thread3, NULL, multiplication, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}

