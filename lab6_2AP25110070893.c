#include <stdio.h>
#include <limits.h>

void findMaxCrossing(int a[], int low, int mid, int high, int *crossLow, int *crossHigh, int *crossSum) {
  int leftSum, rightSum, sum, i, j;

  leftSum = INT_MIN;
  sum = 0;
  *crossLow = mid;

  for (i = mid; i >= low; i--) {
    sum += a[i];
    if (sum > leftSum) {
      leftSum = sum;
      *crossLow = i;
    }
  }

  rightSum = INT_MIN;
  sum = 0;
  *crossHigh = mid + 1;

  for (j = mid + 1; j <= high; j++) {
    sum += a[j];
    if (sum > rightSum) {
      rightSum = sum;
      *crossHigh = j;
    }
  }

  *crossSum = leftSum + rightSum;
}

void findMaxSubarray(int a[], int low, int high, int *resLow, int *resHigh, int *resSum) {
  int mid;
  int lLow, lHigh, lSum;
  int rLow, rHigh, rSum;
  int cLow, cHigh, cSum;

  if (low == high) {
    *resLow = low;
    *resHigh = high;
    *resSum = a[low];
    return;
  }

  mid = low + (high - low) / 2;

  findMaxSubarray(a, low, mid, &lLow, &lHigh, &lSum);
  findMaxSubarray(a, mid + 1, high, &rLow, &rHigh, &rSum);
  findMaxCrossing(a, low, mid, high, &cLow, &cHigh, &cSum);

  if (lSum >= rSum && lSum >= cSum) {
    *resLow = lLow;
    *resHigh = lHigh;
    *resSum = lSum;
  } else if (rSum >= lSum && rSum >= cSum) {
    *resLow = rLow;
    *resHigh = rHigh;
    *resSum = rSum;
  } else {
    *resLow = cLow;
    *resHigh = cHigh;
    *resSum = cSum;
  }
}

int main() {
  int a[100];
  int n, i;
  int resLow, resHigh, resSum;

  printf("Enter array size: ");
  scanf("%d", &n);

  printf("Enter array elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  findMaxSubarray(a, 0, n - 1, &resLow, &resHigh, &resSum);

  printf("Start Index: %d\n", resLow);
  printf("End Index: %d\n", resHigh);
  printf("Maximum Sum: %d\n", resSum);

  return 0;
}
