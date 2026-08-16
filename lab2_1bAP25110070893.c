#include <stdio.h>

double power(double x, int n) {
  if (n == 0)
    return 1.0;

  double half = power(x, n / 2);

  if (n % 2 == 0)
    return half * half;
  else
    return x * half * half;
}

int main() {
  double x, sum;
  int n;

  printf("Enter value of X: ");
  scanf("%lf", &x);

  printf("Enter number of terms: ");
  scanf("%d", &n);

  if (x == 1) {
    sum = n;
  } else {
    sum = (power(x, n) - 1) / (x - 1);
  }

  printf("Sum of the series = %.2lf\n", sum);

  return 0;
}