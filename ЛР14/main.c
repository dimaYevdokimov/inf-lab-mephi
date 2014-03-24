#include <stdio.h>
#include <limits.h>

void show(int* m,int size) {
  printf("\nНаш массив:\n");
  for(int i=0;i<size;i++) {
    printf("%d\t",m[i]);
  }
  printf("\n");
}

void sort(int* m,int size) {
  int min, mini, b;
  for(int i=0;i<size;i++) {
    min=INT_MAX;
    for(int j=i;j<size;j++) {
      if(m[j]<min){min=m[j];mini=j;};
    }
    b=m[i];
    m[i]=min;
    m[mini]=b;
  }
}

int main() {
  int* a;
  int s;
  int b;
  printf("Сколько элементов в нашем массиве? "); scanf("%d",&s);
  a = (int*) malloc(s*sizeof(int)); 
  for(int i=0;i<s;i++) {
    printf("Введите элемент с индексом %d: ",i);
    scanf("%d",&b);
    a[i]=b;
  }
  show(a,s);
  sort(a,s);
  printf("\nПосле сортировки:\n");
  show(a,s);
  return 0;
}