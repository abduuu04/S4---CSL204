#include <stdio.h>

struct process {
    int ps;
    int flag;
} p[50];

struct sizes {
    int size;
    int alloc;
} s[50];

int main() {
    int i = 0, np = 0, n = 0, j = 0;

    printf("\nFirst Fit Memory Allocation\n");
    
    // Get number of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    
    // Get sizes of blocks
    printf("Enter the size for %d blocks:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter the size for block %d: ", i);
        scanf("%d", &s[i].size);
        s[i].alloc = 0; // Initialize allocation flag to 0
    }

    // Get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    
    // Get sizes of processes
    printf("Enter the size of %d processes:\n", np);
    for (i = 0; i < np; i++) {
        printf("Enter the size of process %d: ", i);
        scanf("%d", &p[i].ps);
        p[i].flag = 0; // Initialize allocation flag to 0
    }

    // First Fit Allocation
    printf("\nAllocation of blocks using First Fit:\n");
    printf("Process\tProcess Size\tBlock Size\n");

    for (i = 0; i < np; i++) {
        for (j = 0; j < n; j++) {
            if (p[i].flag == 0 && s[j].alloc == 0 && p[i].ps <= s[j].size) {
                p[i].flag = 1;
                s[j].alloc = 1;
                printf("%d\t\t%d\t\t%d\n", i, p[i].ps, s[j].size);
                break; // Stop searching for this process
            }
        }
    }

    // Check for unallocated processes
    for (i = 0; i < np; i++) {
        if (p[i].flag == 0) {
            printf("Sorry! Process %d must wait as there is no sufficient memory.\n", i);
        }
    }

    return 0;
}