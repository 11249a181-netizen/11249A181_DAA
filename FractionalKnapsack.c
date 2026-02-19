#include <stdio.h>

struct Item {
    int profit, weight;
    float ratio;
};
int main() {
int n, capacity ,i,j;
float totalProfit = 0;
printf("Enter number of items: ");
scanf("%d", &n);
struct Item items[n];
    for( i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }
printf("Enter capacity of knapsack: ");
scanf("%d", &capacity);
    for( i = 0; i < n-1; i++) {
        for( j = i+1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    for( i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].profit * ((float)capacity / items[i].weight);
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}

