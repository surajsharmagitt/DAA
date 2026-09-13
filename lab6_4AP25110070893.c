#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {
    struct Item items[100];
    int n, capacity;
    int i, j;
    float totalProfit = 0;
    struct Item temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d",&items[i].profit,&items[i].weight);
        items[i].ratio =(float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("\nItems selected:\n");
    for (i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            capacity = capacity - items[i].weight;
            totalProfit =totalProfit + items[i].profit;
            printf("Item %d: 100%% taken\n", i + 1);
        }
        else {
            float fraction =(float)capacity / items[i].weight;
            totalProfit =totalProfit +
                items[i].profit * fraction;
            printf("Item %d: %.2f%% taken\n",i + 1, fraction * 100);
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n",
           totalProfit);

    return 0;
}
