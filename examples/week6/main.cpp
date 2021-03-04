#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#define X 10;

constexpr int factorial(int n) { return n <= 1 ? 1 : (n * factorial(n - 1)); }

constexpr int fib(int n) { return n <= 1 ? 1 : (n - 1) + (n - 2); }

template <int n> struct constN {
  constN() { std::cout << n << std::endl; }
};

constexpr auto x = 10;

std::string foo(int n) {
  if (n > 10) {
    return "foo";
  } else {
    return "bar";
  }
}

struct ChangeLineItem {
  int accountId;
  float amount;
};

template <class T> struct AuthzEnvelope {
  T data;
  int userId;
  std::string userRole;
};

struct LineItem {
  int accountId;
  float balance;
};

struct Bank {
  std::vector<LineItem> lineItems;

  void receive(AuthzEnvelope<ChangeLineItem> cl) {
    LineItem l;

    if (cl.userRole != "BankAdmin") {
      return;
    }
    for (auto li : lineItems) {
      if (li.accountId == cl.data.accountId) {
        l = li;
      }
    }

    l.balance += cl.data.amount;
  }
};

std::string foo2(int n) { return n > 10 ? "foo" : "bar"; }

int main() {
  // c++ 17 only
  //
  //
  std::cout << foo(19) << std::endl;
  std::cout << foo2(19) << std::endl;
}
