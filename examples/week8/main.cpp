#include <iostream>
#include <memory>
struct A {
public:
  A() { std::cout << "hello" << std::endl; }
  A(const A &a) { std::cout << "copied" << std::endl; }
  ~A() { std::cout << "bye bye" << std::endl; }

  void foo() { std::cout << "foo" << std::endl; }
};

struct MemManager {
private:
  A *m_a;

public:
  MemManager() { this->m_a = new A(); }

  ~MemManager() { delete this->m_a; }

  A *getA() { return this->m_a; }
};

void aWrapper(A &&a_copy) { a_copy.foo(); }

void aWrapper(A *aPtr) { aPtr->foo(); }

A createA() {
  A a = A();
  std::move(a);
  return a;
}

A *createAPtr() {
  A *a = new A();
  return a;
}

int main() {

  A a = createA();

  aWrapper(&a);

  /*
      * std::shared_ptr<A> a = std::make_shared<A>();

{
  std::shared_ptr<A> b = a;
  std::cout << a.use_count() << std::endl;
}
std::cout << a.use_count() << std::endl;

aWrapper(a.get());
      * */
}
