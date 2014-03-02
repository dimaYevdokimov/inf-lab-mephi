#include <stdio.h>
#include <limits.h>

int main() {
  long int n; long int a=1; long int b=1; long int c=0; int n4; int n3; int n2; int n1; long int s=2;
  printf("Введите n:");
  scanf("%d",&n);
  switch(n) {
    case 1:
      s=1;
      break;
    case 2:
      s=2;
      break;
    default:
      for(int i=1;i<=n-2;i++) {
	c=a+b;
	a=b;
	b=c;
	s+=c;
      }
  }
  printf("%ld\n",s);
  a=1; b=1; s=2; n=2;
  while(s<INT_MAX) {
    c=a+b;
    a=b;
    b=c;
    s+=c;
    n++;
    n1=n2;
    n2=n3;
    n3=n4;
    n4=s;
  }
  printf("\n%d\t\t%d\t\t%d\n",n-3,n-2,n-1);
  printf("%ld\t%ld\t%ld\n",n1,n2,n3); 
  return 0;
}