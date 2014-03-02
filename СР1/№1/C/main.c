#include <stdio.h>

int main() {
  int a; int b;
  scanf("%d",&a);
  b = (a%10)*1000+((a/10)%10)*100+((a/100)%10)*10+((a/1000)%10);
  printf("%d\n",b);
  return 0;
}