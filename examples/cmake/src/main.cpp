#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(v.begin(), v.end(), g);
  for (auto i : v) {
    std::cout << i << std::endl;
  }
  return 0;
}
