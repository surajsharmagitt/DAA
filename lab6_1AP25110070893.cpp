#include <iostream>
#include <vector>

struct MinMax {
  int min;
  int max;
};

MinMax getMinMax(const std::vector<int>& arr, int low, int high) {
  MinMax result;

  if (low == high) {
    result.min = arr[low];
    result.max = arr[low];
    return result;
  }

  if (high == low + 1) {
    if (arr[low] < arr[high]) {
      result.min = arr[low];
      result.max = arr[high];
    } else {
      result.min = arr[high];
      result.max = arr[low];
    }
    return result;
  }

  int mid = low + (high - low) / 2;
  MinMax left = getMinMax(arr, low, mid);
  MinMax right = getMinMax(arr, mid + 1, high);

  result.min = (left.min < right.min) ? left.min : right.min;
  result.max = (left.max > right.max) ? left.max : right.max;

  return result;
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11, 90, 88, 45, 13, 79, 53, 31, 99, 5, 42, 70};
  MinMax res = getMinMax(arr, 0, arr.size() - 1);

  std::cout << "Minimum element: " << res.min << std::endl;
  std::cout << "Maximum element: " << res.max << std::endl;
  return 0;
}
