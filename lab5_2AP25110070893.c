#include <stdio.h>

void bucketSort(int a[], int n) {
  int bucket[10][100];
  int count[10] = {0};

  int i, j, k;
  int b, temp;
  for (i = 0; i < n; i++) {
    b = a[i] / 10;
    bucket[b][count[b]] = a[i];
    count[b]++;
  }

  for (i = 0; i < 10; i++) {
    for (j = 1; j < count[i]; j++) {
      temp = bucket[i][j];
      k = j - 1;

      while (k >= 0 && bucket[i][k] > temp) {
        bucket[i][k + 1] = bucket[i][k];
        k--;
      }

      bucket[i][k + 1] = temp;
    }
  }

  k = 0;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < count[i]; j++) {
      a[k] = bucket[i][j];
      k++;
    }
  }
}

int main() {
  int a[100];
  int n, i;

  printf("Enter array size: ");
  scanf("%d", &n);

  printf("Enter elements (0 to 99):\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  bucketSort(a, n);

  printf("Sorted array:\n");

  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}