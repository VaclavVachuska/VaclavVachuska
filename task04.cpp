#include <cstdio>
#include <cstring>

struct Animal {
  const char* name;
  Animal (char* getName) {
    name = getName;
  }
  virtual const char* whatDoesItSay() {
    sprintf(buffer, "%s says ", name);
    return buffer;
  };
protected:
  char buffer[255];
};

struct Dog : Animal {
  const char* sound;
  Dog(char* getName, char* getSound) : Animal (getName) {
    sound = getSound;
  }
  const char* whatDoesItSay() {
    Animal::whatDoesItSay();
    strcat(buffer, sound);
    return buffer;
  }
};

struct Fox : Animal {
  const char* sound;
  Fox(char* getName, char* getSound) : Animal (getName) {
    sound = getSound;
  }
  const char* whatDoesItSay() {
    Animal::whatDoesItSay();
    strcat(buffer, sound);  
    return buffer;
  }
};

int main() {
  Animal* animals[] = {
    new Dog((char*)"dog", (char*)"woof"),
    new Fox((char*)"fox", (char*)"ringidingidingidingiding")
  };
  for(Animal* animal : animals) {
    printf("%s\n",animal->whatDoesItSay());
  }
}
