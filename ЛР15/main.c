#include <stdio.h>
int y=0;

void inputArray(int* a,int s,int n) {
  int i=0, b;
  printf("Введите %d элементов для заполнения массива №%d: ",s,n);
  for(i=0;i<s;i++){scanf("%d",&b);a[i]=b;}
}

void printArray(int* a,int s,int n) {
  int i=0;
  printf("№%d:\n",n);
  for(i=0;i<s;i++) printf("[%d]\t",i);printf("\n");
  for(i=0;i<s;i++) printf("%d\t",a[i]);
  printf("\n\n");
}

void swap(int* a,int* b) {
  int c;
  c=*a;
  *a=*b;
  *b=c;
}

void q(int* a,int s,int n,int fi,int la) {
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
  printf("\n(Шаг %d, перестановок в массиве №%d: %d)\n",y,n,c);
  printArray(a,s,n);
  if(fi<r) q(a,s,n,fi,r);
  if(l<la) q(a,s,n,l,la);
}

int main() {
  int n1,n2,n3;
  int* m1;
  int* m2;
  int* m3;
  printf("=== Сейчас будут созданы три массива ===\n\n");
  printf("Какая длина первого? "); scanf("%d",&n1);
  printf("А второго? "); scanf("%d",&n2);
  printf("А третьего? "); scanf("%d",&n3);
  m1 = (int*) malloc(sizeof(int)*n1);
  m2 = (int*) malloc(sizeof(int)*n2);
  m3 = (int*) malloc(sizeof(int)*n3);
  inputArray(m1,n1,1);
  inputArray(m2,n2,2);
  inputArray(m3,n3,3);
  printf("\nМассивы заполнены:\n\n");
  printArray(m1,n1,1);
  printArray(m2,n2,2);
  printArray(m3,n3,3);
  printf("\n\nПроизводится сортировка первого массива:\n");
  y=0; q(m1,n1,1,0,n1-1);
  printf("\n\nПервый массив отсортирован:\n");
  printArray(m1,n1,1);
  printf("\n\nПроизводится сортировка второго массива:\n");
  y=0; q(m2,n2,2,0,n2-1);
  printf("\n\nВторой массив отсортирован:\n");
  printArray(m2,n2,2);
  y=0; q(m3,n3,3,0,n3-1);
  printf("\n\nТретий массив отсортирован:\n");
  printArray(m3,n3,3);
  printf("\n");
  return 0;
}
