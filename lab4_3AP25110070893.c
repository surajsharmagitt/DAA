#include <stdio.h>

int main() {
  int a[100];
  int n, target;
  int hash[1000] = {0};
  int i, needed;
  int found = 0;

  printf("Enter array size: ");
  scanf("%d", &n);

  printf("Enter array elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("Enter target value: ");
  scanf("%d", &target);

  for (i = 0; i < n; i++) {
    needed = target - a[i];

    if (needed >= 0 && needed < 1000 && hash[needed] == 1) {
      printf("Pair found: %d + %d = %d\n", needed, a[i], target);
      found = 1;
      break;
    }

    if (a[i] >= 0 && a[i] < 1000) {
      hash[a[i]] = 1;
    }
  }

  if (found == 0) {
    printf("No pair found\n");
  }

  return 0;
}