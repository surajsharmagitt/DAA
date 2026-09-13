#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
  int id;
  double weight;
  double value;
  double ratio;

  Item(int id, double weight, double value)
    : id(id), weight(weight), value(value), ratio(value / weight) {}
};

double solveFractionalKnapsack(double capacity, std::vector<Item>& items) {
  std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
    return a.ratio > b.ratio;
  });

  double totalValue = 0.0;
  double remainingCapacity = capacity;

  for (const auto& item : items) {
    if (remainingCapacity <= 0.0) break;

    if (item.weight <= remainingCapacity) {
      remainingCapacity -= item.weight;
      totalValue += item.value;
    } else {
      totalValue += item.value * (remainingCapacity / item.weight);
      remainingCapacity = 0.0;
    }
  }

  return totalValue;
}

int main() {
  double capacity = 50.0;
  std::vector<Item> items = {
    Item(1, 10.0, 60.0),
    Item(2, 20.0, 100.0),
    Item(3, 30.0, 120.0),
    Item(4, 5.0,  40.0),
    Item(5, 15.0, 45.0)
  };

  double maxProfit = solveFractionalKnapsack(capacity, items);
  std::cout << "Maximum Profit: " << maxProfit << std::endl;
  return 0;
}
