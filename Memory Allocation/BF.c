#include <stdio.h>
#define MAX 20

int main() {
    int bsize[MAX], fsize[MAX], nb, nf;
    int temp, low;
    int bflag[MAX] = {0}, fflag[MAX] = {0}; // Initialize flags to 0
    int i, j;

    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter the size of %d memory blocks:\n", nb);
    for (i = 0; i < nb; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &bsize[i]);
    }

    printf("\nEnter the number of files: ");
    scanf("%d", &nf);

    printf("Enter the size of %d files:\n", nf);
    for (i = 0; i < nf; i++) {
        printf("File %d size: ", i + 1);
        scanf("%d", &fsize[i]);
    }

    // Best Fit Algorithm
    for (i = 0; i < nf; i++) {
        low = 10000; // Reset low for each file
        int best_index = -1; // Store index of best block

        for (j = 0; j < nb; j++) {
            if (!bflag[j]) { // If block is not allocated
                temp = bsize[j] - fsize[i];

                if (temp >= 0 && temp < low) { // If it fits and is the smallest fit so far
                    best_index = j;
                    low = temp;
                }
            }
        }

        if (best_index != -1) {
            fflag[i] = best_index;
            bflag[best_index] = 1; // Mark block as allocated
        } else {
            fflag[i] = -1; // Indicate no suitable block found
        }
    }

    // Print Allocation Results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\n");
    for (i = 0; i < nf; i++) {
        if (fflag[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, fsize[i], fflag[i] + 1, bsize[fflag[i]]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, fsize[i]);
        }
    }

    return 0;
}