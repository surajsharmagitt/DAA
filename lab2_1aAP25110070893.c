#include <stdio.h>

int main() {
  int x, n;
  long long sum = 1;
  long long power = 1;

  printf("Enter value of X: ");
  scanf("%d", &x);

  printf("Enter number of terms: ");
  scanf("%d", &n);

  for (int i = 1; i < n; i++) {
    power = power * x;
    sum = sum + power;
  }

  printf("Sum of the series = %lld\n", sum);

  return 0;
}