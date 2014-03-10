#include <stdio.h>
#include <time.h>

int r() {
  return rand()%26+5;
}

void printm(int* m, int size, short f) {
  for(int i=0;i<size;i++) {printf("%d\t",i); if(f==1){m[i]=r();};}; printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",m[i]); printf("\n");
}

void f1(int* m, int size, int i) {
  int b;
  b=m[i];
  m[i]=m[size-1];
  m[size-1]=b;
}

void f2(int *m,int *n,int a) {
  n[0]=a;
  for(int i=0;i<10;i++) n[i+1]=m[i];
}

int main() {
  int m[10]; int b;
  int n[11];
  srand(time(NULL));
  printm(m,10,1);
  printf("Какой элемент поменять с последним? "); scanf("%d",&b);
  f1(m,10,b);
  printm(m,10,0);
  printf("Какое число вставить первым? "); scanf("%d",&b);
  f2(m,n,b);
  printm(n,11,0);
  return 0;
}