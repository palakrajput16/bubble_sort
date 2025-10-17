#include <stdio.h>
#include <stdlib.h>

#define MAXNUMS 1000
int inp_nums[MAXNUMS];
int out_nums[MAXNUMS];

/* Bubble Sort */
void bubble_sort(int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (out_nums[j] > out_nums[j + 1]) {
                temp = out_nums[j];
                out_nums[j] = out_nums[j + 1];
                out_nums[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <num1> <num2> <num3> ...\n", argv[0]);
        return 1;
    }

    int num_nums = argc - 1;
    int i;

    /* Store input */
    printf("INP: ");
    for (i = 0; i < num_nums; i++) {
        inp_nums[i] = atoi(argv[i + 1]);
        out_nums[i] = inp_nums[i];
        printf("%d ", inp_nums[i]);
    }
    printf("\n");

    /* Bubble Sort */
    bubble_sort(num_nums);

    printf("BUB: ");
    for (i = 0; i < num_nums; i++) {
        printf("%d ", out_nums[i]);
    }
    printf("\n");

    return 0;
}

