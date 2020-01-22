#include <cstdio>
#include <conio.h>

struct Button {
  virtual bool waitForButton() = 0;
  virtual void hello() = 0;
  virtual void loopHello() {
    while (true) {
      if (waitForButton()) {
        hello();
      }
    }
  }

};

struct ButtonPC : Button {
  bool waitForButton() {
    char keycode = getch();
    if (keycode == 13) {
      return true;
    } else {
      return false;
    }
  }
  
  void hello() {
    printf("hello\n");
  }
  void loopHello() {
    Button::loopHello();
  }
};


int main() {
  ButtonPC b;
  b.loopHello();

return 0;
}
