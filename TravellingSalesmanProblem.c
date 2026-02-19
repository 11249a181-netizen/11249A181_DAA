#include <stdio.h>

#define MAX 10

int matrix[MAX][MAX];
int visited[MAX];
int n;
int cost = 0;

void tsp(int start)
{
    int i, next_city;
   
    printf("%d ", start + 1);
    visited[start] = 1;

    next_city = -1;
    int min = 999;

    for(i = 0; i < n; i++)
    {
        if(matrix[start][i] != 0 && visited[i] == 0)
        {
            if(matrix[start][i] < min)
            {
                min = matrix[start][i];
                next_city = i;
            }
        }
    }

    if(next_city != -1)
    {
        cost += min;
        tsp(next_city);
    }
    else
    {
        cost += matrix[start][0];  // return to starting city
        printf("1");
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        visited[i] = 0;
    }

    printf("Path: ");
    tsp(0);

    printf("\nMinimum Cost: %d\n", cost);

    return 0;
}

