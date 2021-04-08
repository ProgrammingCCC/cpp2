#include <iostream>
#include <optional>

template <class T> T add(T t1, T t2) { return t1 + t2; }

//+ - / * == > <
//[] ()
//

const std::string s = "1, \"Test, Happy\", Test@test.com, abc123";

struct Temp {
  int foo;
  Temp operator+(const Temp &temp) {
    Temp t;
    t.foo = this->foo + temp.foo;
    return t;
  }
  bool operator==(const Temp &temp) { return temp.foo == this->foo; }
};

Temp *doAThing(int blah) {
  std::cout << blah << std::endl;
  return new Temp();
}

Temp doAThing(float blah) {
  std::cout << blah << std::endl;
  return Temp();
}

void fo(Temp *t) {
  // do something with t
  std::cout << t->foo << std::endl;
}

int main() {
  auto intSum = add<int>(1, 5);
  auto floatSum = add<float>(1.0, 199.9);
  auto tempSum = add<Temp>(Temp(), Temp());

  fo(doAThing(10));
}
