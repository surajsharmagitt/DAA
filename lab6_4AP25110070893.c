#include <stdio.h>

int main() {
  double weight[100], value[100], ratio[100];
  double capacity, totalValue, remaining, temp;
  int n, i, j, tempId;
  int id[100];

  printf("Enter number of items: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    id[i] = i + 1;
    printf("Enter weight and value of item %d: ", i + 1);
    scanf("%lf %lf", &weight[i], &value[i]);
    ratio[i] = value[i] / weight[i];
  }

  printf("Enter knapsack capacity: ");
  scanf("%lf", &capacity);

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (ratio[j] < ratio[j + 1]) {
        temp = ratio[j]; ratio[j] = ratio[j + 1]; ratio[j + 1] = temp;
        temp = weight[j]; weight[j] = weight[j + 1]; weight[j + 1] = temp;
        temp = value[j]; value[j] = value[j + 1]; value[j + 1] = temp;
        tempId = id[j]; id[j] = id[j + 1]; id[j + 1] = tempId;
      }
    }
  }

  totalValue = 0.0;
  remaining = capacity;

  for (i = 0; i < n; i++) {
    if (remaining <= 0.0) break;

    if (weight[i] <= remaining) {
      remaining -= weight[i];
      totalValue += value[i];
    } else {
      totalValue += value[i] * (remaining / weight[i]);
      remaining = 0.0;
    }
  }

  printf("Maximum Profit: %.0lf\n", totalValue);

  return 0;
}
