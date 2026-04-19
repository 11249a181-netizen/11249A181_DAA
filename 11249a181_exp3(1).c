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

    for (int i = 0; i < n; i++) {
        int placed = 0;

        for ( j = 0; j < binsUsed; j++) {
            if (bin[j] >= weight[i]) {
                bin[j] -= weight[i];
                placed = 1;
                break;
            }
        }

        if (!placed) {
            bin[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printf("First Fit: Total bins used = %d\n", binsUsed);
    return 0;
}

