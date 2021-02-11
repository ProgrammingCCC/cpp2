#include <iostream>
#include <string>
class Animal {
protected:
  int age;
  int legs;
  std::string name;

public:
  virtual void makeNoise() = 0;
  void info() {
    std::cout << "I Have " << this->legs << "and I am " << this->age
              << " years old" << std::endl;
  }
};

class Dog : public Animal {
public:
  Dog(int age) {
    this->age = age;
    this->legs = 4;
  }
  void makeNoise() { std::cout << "Bark" << std::endl; }
};

class Duck : public Animal {
public:
  Duck(int age) {
    this->age = age;
    this->legs = 2;
  }

  void makeNoise() { std::cout << "Quack" << std::endl; }
};

class AnimalManager {
private:
  Animal *m_animal;

public:
  AnimalManager(Animal *animal) { this->m_animal = animal; }

  void info() { this->m_animal->info(); }

  void tellMakeNoise() { this->m_animal->makeNoise(); }
};

class Object {
protected:
public:
  virtual std::string toString() { return "Object"; }
};

class CanMakeNoise {
public:
  virtual void makeNoise() = 0;
};

class HasLegs : Object {

protected:
  int m_legCount;

public:
  std::string toString() { return "Bumble"; }
};

class HasAge : Object {
protected:
  int m_age;

public:
  std::string toString() { return "Duck"; }
};

class TraitsAnimal : CanMakeNoise, HasLegs, HasAge {};

class TraitsDog : TraitsAnimal {
public:
  void makeNoise() { std::cout << "Bark" << std::endl; }
};

int main() {}
