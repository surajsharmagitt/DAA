#include <stdio.h>

int main() {
  int a[100];
  int hash[1000] = {0};
  int n, i;

  printf("Enter array size: ");
  scanf("%d", &n);

  printf("Enter array elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    hash[a[i]]++;
  }

  printf("\nFrequency of elements:\n");

  for (i = 0; i < 1000; i++) {
    if (hash[i] > 0) {
      printf("%d -> %d\n", i, hash[i]);
    }
  }

  return 0;
}