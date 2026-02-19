#include <stdio.h>

int matrix[25][25], visited[25];
int n, totalCost = 0;

int findNearest(int city) {
    int i;
    int min = 999;
    int nearest = -1;

    for(i = 0; i < n; i++) {
        if(matrix[city][i] != 0 && visited[i] == 0) {
            if(matrix[city][i] < min) {
                min = matrix[city][i];
                nearest = i;
            }
        }
    }

    if(nearest != -1) {
        totalCost += min;
    }

    return nearest;
}

void tsp(int city) {
    visited[city] = 1;
    printf("%d ", city + 1);

    int next = findNearest(city);

    if(next == -1) {
        printf("%d ", 1);  // Return to starting city
        totalCost += matrix[city][0];
        return;
    }

    tsp(next);
}

int main() {
    int i, j;

    printf("Enter Total Number of Cities: ");
    scanf("%d", &n);

    printf("Enter Cost Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nPath: ");
    tsp(0);

    printf("\nMinimum Cost: %d\n", totalCost);

    return 0;
}

