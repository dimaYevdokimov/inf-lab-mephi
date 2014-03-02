#include <stdio.h>

void f1(int* m,int size,int a,int b) {
  for(int i=0;i<size;i++){
    m[i]=a+b*i;
  };
}

void f2(int* m,int size) {
  for(int i=0;i<size;i++) {
    printf("%d\t",i);
  }
  printf("\n");
  for(int i=0;i<size;i++) {
    printf("%d\t",m[i]);
  }
  printf("\n\n");
}

int main() {
  int hai[8];
  int moi[12];
  int a1,a2,b1,b2;
  printf("\n a1: ");scanf("%d",&a1);
  printf("\n b1: ");scanf("%d",&b1);
  printf("\n a2: ");scanf("%d",&a2);
  printf("\n b2: ");scanf("%d",&b2);
  printf("\n");
  f1(&hai,8,a1,b1);f2(&hai,8);
  f1(&moi,12,a2,b2);f2(&moi,12);
  return 0;
}
