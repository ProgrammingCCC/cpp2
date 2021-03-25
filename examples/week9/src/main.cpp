#include <iostream>
#include <memory>

#include "fib.hpp"

/*
 * struct Node {
  Node() {}
  ~Node() {}
  int value;
  std::unique_ptr<Node> next;

  void push(std::unique_ptr<Node> &&head, int value) {
    std::unique_ptr<Node> temp = std::make_unique<Node>(new Node());

    if (head) {
      temp->next = std::move(head);
    }
    head = std::move(temp);
  };

 * */

int main() {

  auto math = Math();

  auto result = math.fib(10);

  std::cout << result << std::endl;
  return 0;
}
