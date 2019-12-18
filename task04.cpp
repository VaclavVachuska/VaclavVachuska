#include <cstdio>
#include <cstring>

struct Animal {
  const char* name;
  virtual const char* whatDoesItSay(){
  sprintf(buffer, "%s says %s", Animal, whatDoesItSay());
  };
};

protected:
  char buffer[48];

struct Dog : Animal {
  
  
}

struct Fox : Animal {
  
}

int main() {
  Animal* animals[] = {
    new Dog("dog", "woof"),
    new Fox("fox", "ringidingidingidingiding")
  };
  for(Animal* animal : animals) {
    animal->whatDoesItSay();
  }
  // dog says woof
  // fox says ringidingidingidingiding
}
