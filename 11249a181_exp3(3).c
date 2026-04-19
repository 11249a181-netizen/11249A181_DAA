#include <stdio.h>
#define MAX 100

int main() {
    int n,i,j, capacity, weight[MAX];
    int bin[MAX], binsUsed = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item weights:\n");
    for ( i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    for ( i = 0; i < n; i++) {
        int bestIndex = -1;

        for ( j = 0; j < binsUsed; j++) {
            if (bin[j] >= weight[i]) {
                if (bestIndex == -1 || bin[j] < bin[bestIndex])
                    bestIndex = j;
            }
        }

        if (bestIndex != -1)
            bin[bestIndex] -= weight[i];
        else {
            bin[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printf("Best Fit: Total bins used = %d\n", binsUsed);
    return 0;
}

