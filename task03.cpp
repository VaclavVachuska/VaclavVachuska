#include <stdio.h>
#include <cstring>
#include <fstream>
using namespace std;



int main (int argc, char *argv[]) {
    int sum = 0, counter;
    bool polearg[3] = {0,0,0}; //-f,-i,-v
    int num;
    char* filename;
for (int i=1;i < argc;i++) {
  if (!strcmp(argv[i],"-f")){polearg[0]= 1;}
 else if (!strcmp(argv[i],"-i")){polearg[1]= 1;}
 else if (!strcmp(argv[i],"-v")){polearg[2]= 1;}
else if(sscanf(argv[i],"%d",&num)){
 sum += num;
}else {
  filename = argv[i];
}
}
if (polearg[0]){
    int sum = 0;
    int x;
    ifstream inFile;
    inFile.open("fhodnoty.txt");
    
    while (inFile >> x) {
        sum = sum + x;
    }
    
    inFile.close();
    printf("suma je:%d", sum);
    return 0;
}

}
