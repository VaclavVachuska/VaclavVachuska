# VaclavVachuska

## task01

Zatím neodpovídá zadání: úkolem bylo doplnit tělo funkce char* toUpper(char* input), tělo funkce main ponechte tak, jak je

## task02

- lsb -> msb
- byte data: 0110010 -> 01001100

- Procházení bit po bitu od nejméně významného: `for(int i=0; i<7; ++i) bool bit = data & (1<<i);`
- Zápis bit po bitu od nejvýznamnějšího:

```
byte output = 0;
for(int i=0; i<7; ++i) {
  bool bit = data & (1<<i);
  output|= (1<<(6-i)) & bit;
}
```