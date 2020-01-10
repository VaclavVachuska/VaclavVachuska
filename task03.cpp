#include <cstdio>
#include <cstring>
#include <cstdlib>

#define byte unsigned char

void interactive(bool verbose) {
  char str[255];
  int bufferNumber;
  bool isNumber = 1;
  int inputCount = 0;
  int sum = 0;
  if (verbose) printf("Waiting for numbers, leave blank to end\n"); 
  while (true) {
    printf("Number: ");
    fgets(str, 255, stdin);      
    sscanf(str, "%d", &bufferNumber);
    if (strlen(str) == 1) break;    
    sum += bufferNumber;
    ++inputCount;
  }
  
  if (verbose) {
    printf("Sum of %i numbers is %i.\n", inputCount, sum);
  
  } else {
    printf("Sum: %i\n", sum);    
  }
}

void fileHandling(char** fileName, bool verbose) {
  char data[255];
  char str[255];
  char buffer;
  int bufferNumber;
  int index = 0;
  int type = 0;
  int sum = 0;
  FILE* fd = fopen(*fileName, "rb");
  fread(data, sizeof(data), 1, fd);
  fclose(fd);
  for (int i = 0; i < 255; ++i) {
    buffer = data[i];
    switch (buffer) {
      case 0x0:
        type = 1;
        break;
      case 0xD:
        type = 2;
        break;
      case 0xA:
        type = 3;
        break;
      default:
        type = 4;
        break;
    }
    
    if (type == 2 || type == 1) {
      index = 0;
      sscanf(str, "%d", &bufferNumber);
      sum += bufferNumber;
      if (type == 1) break;
      else continue;
    }
    else if (type == 3) continue;
    str[index] = buffer;
    index++;
  }
  if (verbose) {
    printf("Sum of numbers in %s is %d\n", *fileName, sum);
  } else {
    printf("Sum: %d\n", sum);    
  }
}

void sumOfArguments(int sum, bool verbose) {
  if (sum == 0) {
    printf("You ned to add some numbers in order for this program to be useful. Have a nice day\n");
  } else {
    verbose ? printf("Sum of given numbers is %i\n", sum) : printf("Sum: %i\n", sum);
  }
}

void help() {
  printf("task03 adds numbers. Use parameters: \n");
  printf("-f <name>....to get sum of numbers from txt file\n");
  printf("-i...........write numbers in seqence and get sum if them\n");
  printf("-v...........for verbose mode\n");
  printf("or write numbers to get simple sum of them\n");
}

int main(int argc, char* argv[]) {
  bool arguments[3] = {0, 0, 0}; 
  int sum = 0; 
  int num = 0; 
  bool isNumber = 0;
  char* fileName;
  for (int j = 1; j < argc; j++) {
    if (!strcmp(argv[j], "-f")) arguments[0] = 1;
    else if (!strcmp(argv[j], "-i")) arguments[1] = 1;
    else if (!strcmp(argv[j], "-v")) arguments[2] = 1;
    
    else {
      isNumber = sscanf(argv[j], "%d", &num);
      if (isNumber) {
        sum += num;
        isNumber = 0;
      } else if (!strcmp(argv[j], "help")) {
        help(); 
      } else {
        fileName = argv[j];
      }
    }
  }

  if (arguments[0] == 1 && arguments[1] == 1) {
    printf("Can not read from file and from input, please choose only one\n");
  }
  else if (argc == 1) {
    help();
  }
  else if (arguments[0] == 1) {
    fileHandling(&fileName, arguments[2]);
  }
  else if (arguments[1] == 1) {
    interactive(arguments[2]);
  }
  else {
    sumOfArguments(sum, arguments[2]);
  }
    
  system("@cmd /k");
  
  return 0;
}
