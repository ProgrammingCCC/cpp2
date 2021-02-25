#include <iostream>
#include <string>
#include <vector>

#include "result.hpp"

template <class T> T max(T lhs, T rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

template <> std::string max(std::string lhs, std::string rhs) {
  if (lhs.length() > rhs.length()) {
    return lhs;
  }
  return rhs;
}

template <class T> std::vector<T> max(std::vector<T> lhs, std::vector<T> rhs) {
  if (lhs.size() > rhs.size()) {
    return lhs;
  }
  return rhs;
}

template <class T1, class T2> void foo(T1 a, T2 b) {
  // do something with a and b
}

template <class T2> void foo(int a, T2 b) {}

int main() {
  int maxInt = max<int>(10, 15);
  std::cout << maxInt << std::endl;

  long maxLong = max<long>(6592201396162128450, 7294196891785469671);
  std::cout << maxLong << std::endl;

  std::vector<int> rhs = {1, 2, 3, 4};
  std::vector<int> lhs = {1, 2, 3};

  std::vector<int> maxVector = max(lhs, rhs);
  std::cout << maxVector.size() << std::endl;

  std::string larger = max<std::string>("hello", "world");
  std::cout << larger << std::endl;

  foo<std::string>(10, "hello");

  Result<Account> result = save_account("some dumb account");

  if (result.isSuccess()) {
    std::cout << "Account Created " << result.getResult().name << std::endl;
  } else {
    std::cout << result.getErrorMessage() << std::endl;
  }
}
