#include <stdio.h>

int main() { 
  int* a;
  int* b;
  int* *c;
  int n;
  printf("Какой длины создавать массивы? ");
  scanf("%d",&n);
  a = (int*) calloc(sizeof(int),n);
  b = (int*) calloc(sizeof(int),n);
  c = (int**) calloc(sizeof(int*),n*2);
  rndArray(a,n); rndArray(b,n);
  printf("Массив [a] заполнен случайно:\n"); printArray(a,n);
  printf("Массив [b] заполнен случайно:\n"); printArray(b,n);
  bubbleSortF(a,n); bubbleSortFBack(b,n);
  printf("Массив [a] отсортирован по неубыванию:\n"); printArray(a,n);
  printf("Массив [b] отсортирован по невозрастанию:\n"); printArray(b,n);
  printf("Формируется массив указателей...\n");
  for(int i=0;i<n;i++) c[i]=&a[i];
  printAddrArray(c,n);
 /* badSearch(c,n,&b[4]); Здесь тесты. По непонятным причинам (TODO) если передавать значение, а не указатель, (и соотв. образом изменить соотв. функции), 
  указатели странно связываются и фейлят все.*/
 // badSearch(c,n+1,&b[1]);
 // insert(c,n,&b[1],n-1);
  for(int i=0;i<n;i++) badSearch(c,n+i,&b[i]);
  printf("Получилась какая-то хрень (и она верная!):\n"); printAddrArray(c,2*n);
  printf("\n");
  return 0;
}

/* Бинарный поиск напишете сами! :)

void binaryInsert(int** m,int s,int x) {
  int it=s/2;
  while() {
    
  }
} */

void printAddrArray(int** m,int size) {
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",i);
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",*m[i]);
  printf("\n\n");
}

int badSearch(int** m,int s,int* n) { // Плохой, плохой поиск O(n)
  if(*n<=*m[0]){insert(m,s,n,0);return 0;};
  if(*n>=*m[s-1]){insert(m,s,n,s);return 0;};
  for(int i=1;i<s-1;i++) {
    if((*m[i-1]<=*n)&&(*m[i]>*n)){insert(m,s,n,i);printf("TEST\n");return 0;};
  }
}

void insert(int** m,int s,int* x,int n) { // Вставляет со сдвигом
  for(int i=s-1;i>=n;i--){m[i+1]=m[i];printf("SUBTEST\n");};
  m[n]=x;
  printAddrArray(m,s+1);
}

void rndArray(int* m,int size) {
  for(int i=0;i<size;i++) m[i]=rand()%1000-499;
}

void printArray(int* m,int size) {
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",i);
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",m[i]);
  printf("\n\n");
}

void bubbleSortF(int* m, int size) {
  int b;
  char f;
  for(int j=0;j<size-1;j++) {
    f='N';
    for(int i=0;i<size-j-1;i++) {
      if(m[i]>m[i+1]) {
	b=m[i+1];
	m[i+1]=m[i];
	m[i]=b;
	f='Y';
      }
    }
    if(f=='N') break;
  }
}

void bubbleSortFBack(int* m, int size) {
  int b;
  char f;
  for(int j=0;j<size-1;j++) {
    f='N';
    for(int i=0;i<size-j-1;i++) {
      if(m[i]<m[i+1]) {
	b=m[i+1];
	m[i+1]=m[i];
	m[i]=b;
	f='Y';
      }
    }
    if(f=='N') break;
  }
}
