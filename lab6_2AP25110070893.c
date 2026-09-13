#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int i;

    for (i = mid; i >= low; i--) {
        sum = sum + arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    for (i = mid + 1; i <= high; i++) {
        sum = sum + arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int arr[], int low, int high) {
    int mid;
    int leftMax, rightMax, crossMax;

    if (low == high)
        return arr[low];

    mid = (low + high) / 2;
    leftMax = maxSubarray(arr, low, mid);
    rightMax = maxSubarray(arr, mid + 1, high);
    crossMax = maxCrossingSum(arr, low, mid, high);

    return max(leftMax, max(rightMax, crossMax));
}

int main() {
    int arr[100], n, i;
    int result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    result = maxSubarray(arr, 0, n - 1);

    printf("Maximum subarray sum = %d\n", result);

    return 0;
}
