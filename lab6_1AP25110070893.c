#include <stdio.h>

void getMinMax(int a[], int low, int high, int *min, int *max) {
  int lmin, lmax, rmin, rmax, mid;

  if (low == high) {
    *min = a[low];
    *max = a[low];
    return;
  }

  if (high == low + 1) {
    if (a[low] < a[high]) {
      *min = a[low];
      *max = a[high];
    } else {
      *min = a[high];
      *max = a[low];
    }
    return;
  }

  mid = low + (high - low) / 2;

  getMinMax(a, low, mid, &lmin, &lmax);
  getMinMax(a, mid + 1, high, &rmin, &rmax);

  *min = (lmin < rmin) ? lmin : rmin;
  *max = (lmax > rmax) ? lmax : rmax;
}

int main() {
  int a[100];
  int n, i, min, max;

  printf("Enter array size: ");
  scanf("%d", &n);

  printf("Enter array elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  getMinMax(a, 0, n - 1, &min, &max);

  printf("Minimum element: %d\n", min);
  printf("Maximum element: %d\n", max);

  return 0;
}
