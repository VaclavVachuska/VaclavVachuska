#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   char s[] = "hello world";
   int i;

   for(i=0;i<=strlen(s);i++) { 
      if(s[i]>=97 && s[i]<=122)
      {
		s[i]=s[i]-32;
      }
   }
   cout<<s;
   return 0;
}
