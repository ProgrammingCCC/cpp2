#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <new>
#include <vector>

template <class T> bool isLessThan(T a, T b) { return a < b; }

std::string format(bool b) {
  if (b) {
    return "true";
  }
  return "false";
}

struct Temp {
  int x;

  Temp(const int x) { this->x = x; }
}

int main() {
  auto lambda = [](auto a, auto b) { return a < b; };

  auto isLessThan = lambda(10, 15);

  std::cout << format(isLessThan) << std::endl;

  std::vector<Temp> vect = std::vector<Temp>();
  vect.push_back(Temp(10));
  vect.push_back(Temp(15));
  vect.push_back(Temp(2));

  std::sort(vect.begin(), vect.end(),
            [](Temp a, Temp b) -> bool { return a.x <= b.x; });
}
