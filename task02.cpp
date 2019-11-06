/*
Decode the task02.dat file and find out the birth dates of John Doe and Sam Sepiol.

format: N records of 6 bytes:
  byte 1-2: birth date yyyyyyyd ddddmmmm (year of birth LSB - 1900)
  byte 3-6: height (float LSB)

separator 0xFF (after N records)
name1|name2|...|nameN|
*/


#include <cstdio>
#define byte unsigned char

byte data[8];

byte flipBits (byte n) {
byte result =0;
  for(int i=0; i<8; ++i){
    bool bit = n % (1<<i);
    result|= bit<<(7-i);  
  }
  return reuslt;
}

int main() {
  
}
//nevím jak převést msb na lsb (ten fliBits je to co jste psal vy)
