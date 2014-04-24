#include <stdio.h>
#include <limits.h>
int y=0;

void inputArray(int* a,int *c,int s) {
  int i=0, b;
  printf("Введите %d элементов для заполнения массива:\n",s);
  for(i=0;i<s;i++){scanf("%d",&b);a[i]=b;c[i]=b;}
}

void printArray(int* a,int s) {
  int i=0;
  printf("Массив:\n");
  for(i=0;i<s;i++) printf("[%d]\t",i);printf("\n");
  for(i=0;i<s;i++) printf(" %d\t",a[i]); // Пробел перед %d — идея Будниковой
  printf("\n\n");
}

void swap(int* a,int* b) {
  int c;
  c=*a;
  *a=*b;
  *b=c;
}

void q(int* a,int s,int fi,int la) {
  int p;
  int c;
  int l,r;
  l=fi; r=la;
  p=a[(l+r)/2];
  c=0;
  while(l<=r) {
    while(a[l]<p) l++;
    while(a[r]>p) r--;
    if(l<=r) {
      c++;
      swap(&a[l],&a[r]);
      l++;
      r--;
    }
  }
  y++;
  if(fi<r) q(a,s,fi,r);
  if(l<la) q(a,s,l,la);
}

void sort(int* m,int size) {
  int e=0;
  int min, mini, b;
  for(int i=0;i<size;i++) {
    min=INT_MAX;
    for(int j=i;j<size;j++) {
      if(m[j]<min){min=m[j];mini=j;e+=3;};
    }
    b=m[i];
    m[i]=min;
    m[mini]=b;
  }
  printf("\nПростая сортировка: %d шагов\n\n",e);
}

int main() {
  int n1;
  int* m1;
  int* m2;
  printf("=== Сейчас будет создан один массив ===\n\n");
  printf("Какой длины? "); scanf("%d",&n1);
  m1 = (int*) malloc(sizeof(int)*n1);
  m2 = (int*) malloc(sizeof(int)*n1);
  inputArray(m1,m2,n1);
  sort(m1,n1);
  q(m2,n1,0,n1-1);
  printf("Ну очень сложная сортировка: %d шагов\n\n",y);
  printArray(m1,n1);
  return 0;
}
