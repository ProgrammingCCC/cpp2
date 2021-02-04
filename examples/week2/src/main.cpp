#include <cstdio>
#include <iostream>
#include <istream>
#include <stdio.h>

class Foo {
private:
  int m_int;

public:
  void set_int(const int n);
  int get_int();
};

void Foo::set_int(const int n) { this->m_int = n; }

int Foo::get_int() { return this->m_int; }

int main() {}

// in class assignment
bool is_palindrom(int n) {

  int original = n;

  if (n < 0) {
    return false;
  }
  if (n < 10) {
    return false;
  }
  int rev = 0, remainder;

  while (n != 0) {
    remainder = n % 10;
    rev = rev * 10 + remainder;
    n /= 10;
  }

  std::cout << rev << std::endl;

  return rev == original;
}
