#include <stdio.h>

void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int low, int high) {
  int pivot;
  int i, j;

  pivot = a[high];

  i = low - 1;

  for (j = low; j < high; j++) {
    if (a[j] < pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[i + 1], &a[high]);

  return i + 1;
}

void quickSort(int a[], int low, int high) {
  int p;

  if (low < high) {
    p = partition(a, low, high);

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
  }
}

int main() {
  int a[100];
  int n, i;

  printf("Enter array size: ");
  scanf("%d", &n);

  printf("Enter array elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  quickSort(a, 0, n - 1);

  printf("Sorted array:\n");

  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}