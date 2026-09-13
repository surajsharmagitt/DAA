#include <iostream>
#include <vector>
#include <limits>

struct SubarrayResult {
  int lowIndex;
  int highIndex;
  int sum;
};

SubarrayResult findMaxCrossingSubarray(const std::vector<int>& arr, int low, int mid, int high) {
  int leftSum = std::numeric_limits<int>::min();
  int sum = 0;
  int maxLeft = mid;

  for (int i = mid; i >= low; --i) {
    sum += arr[i];
    if (sum > leftSum) {
      leftSum = sum;
      maxLeft = i;
    }
  }

  int rightSum = std::numeric_limits<int>::min();
  sum = 0;
  int maxRight = mid + 1;

  for (int j = mid + 1; j <= high; ++j) {
    sum += arr[j];
    if (sum > rightSum) {
      rightSum = sum;
      maxRight = j;
    }
  }

  return {maxLeft, maxRight, leftSum + rightSum};
}

SubarrayResult findMaximumSubarray(const std::vector<int>& arr, int low, int high) {
  if (low == high) {
    return {low, high, arr[low]};
  }

  int mid = low + (high - low) / 2;

  SubarrayResult left = findMaximumSubarray(arr, low, mid);
  SubarrayResult right = findMaximumSubarray(arr, mid + 1, high);
  SubarrayResult cross = findMaxCrossingSubarray(arr, low, mid, high);

  if (left.sum >= right.sum && left.sum >= cross.sum)
    return left;
  else if (right.sum >= left.sum && right.sum >= cross.sum)
    return right;
  else
    return cross;
}

int main() {
  std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  SubarrayResult res = findMaximumSubarray(arr, 0, arr.size() - 1);

  std::cout << "Start Index: " << res.lowIndex << std::endl;
  std::cout << "End Index: " << res.highIndex << std::endl;
  std::cout << "Maximum Sum: " << res.sum << std::endl;
  return 0;
}
