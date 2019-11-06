#include <cstdio>

char* toUpper(char* input) {
  for(int i=0; input[i] != 0; i++){
    if(input[i] <= 'z' && input[i] >= 'a'){
      input[i] -= 32;
    }
  }
  return input;
}

int main() {
	char input[] = "Hello, World!"; // žádné háčky ani čárky
	puts(toUpper(input));
}
