#include <stdio.h>

int main() {
  int a,b,c,d;
  scanf("%d%d%d",&a,&b,&c);
  if((a==b)||(a==c)||(b==c)){printf("Нет такого числа\n");return 0;};
  if(((a>b)&&(b>c))||((c>b)&&(b>a))) printf("%d\n",b);
  if(((c>a)&&(a>b))||((b>a)&&(a>c))) printf("%d\n",a);
  if(((b>c)&&(c>a))||((a>c)&&(c>a))) printf("%d\n",c);  
  return 0;
}