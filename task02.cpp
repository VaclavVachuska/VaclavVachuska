#include <cstdio>
#define byte unsigned char

byte data[8];

byte flipBits(byte number){
	byte result = 0;
	for(int i=0; i<8; ++i) {
		bool bit = number & (1<<i);
		result |= bit<<(7-i);
	}
	return result;
}

void readDate(int* y, int* m, int* d, byte b1, byte b2) {
	*m = b2 & 0b1111;
  *d = b2>>4 | ((b1 & 0b1)<<4);
  *y = flipBits(b1>>1)>>1;
}

int main()
{
    FILE * fd = fopen("task02.dat", "rb");

    fread(data, 8, 1, fd);
   	int y, m, d;
   	readDate(&y, &m, &d, data[0], data[1]);
    printf ("John Doe se narodil: %d.%d.%d\n", d, m, y+1900);

    fread(data, 8, 1, fd);
    readDate(&y, &m, &d, data[0], data[1]);
    printf ("Sam Sepiol se narodil: %d.%d.%d\n", d, m, y+1900);
}
