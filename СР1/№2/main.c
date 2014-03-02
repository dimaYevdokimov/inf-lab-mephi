#include <stdio.h>

int main() {
  int x1,x2,x3,x4;
  int a1,a2,a3,a4,a5;
  scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
  a1=-(x1+x2+x3+x4);
  a2=(x1*x2+x1*x3+x1*x4+x2*x3+x2*x4+x3*x4);
  a3=-(x1*x2*x3+x1*x2*x4+x2*x3*x4+x1*x3*x4);
  a4=(x1*x2*x3*x4);
  printf("4\t3\t2\t1\t0\n");
  printf("%d\t%d\t%d\t%d\t%d\t",1,a1,a2,a3,a4);
  return 0;
}