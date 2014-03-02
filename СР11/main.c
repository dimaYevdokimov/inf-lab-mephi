#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int s[7]; //Внешние массивы зло!

void nullArray(int* m,int size) {
  for(int i=0;i<size;i++) m[i]=0;
}

void printArray(int* m,int size) {
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",i);
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",m[i]);
  printf("\n\n");
}

void rndArray(int* m,int size,int from,int to) {
  int r; short flags[7];
  for(int i=0;i<7;i++) flags[i]=0;
  for(int i=0;i<size;i++) {
    r=from + rand()%(to-from+1);
    m[i]=r;
    if(flags[r-14]==0) {
      s[r-14]++;
      flags[r-14]=1;
    }
  }
}

int maxArray(int* m,int size) {
  int mx=0;
  for(int i=0;i<size;i++) {
    if(m[i]>mx) mx=m[i];
  }
  return mx;
}

int maxArrayInd(int* m,int size) {
  int mi=0;
  for(int i=0;i<size;i++) {
    if(m[i]>mi) mi=i;
  }
  return mi;  
}

int main() {
  int m[9];
  int n[7];
  int l[6];
  srand (time(NULL));
  for(int i=0;i<7;i++) s[i]=0;
  printf("Ну, мы создали три массива:\n");
  rndArray(&m,9,14,20);
  rndArray(&n,7,14,20);
  rndArray(&l,6,14,20);
  printArray(&m,9);printArray(&n,7);printArray(&l,6);
  for(int i=0;i<7;i++) {
    if(s[i]==3) printf("Число %d содержится во всех массивах!\n",i+14);
  }
  printf("\n");
  return 0;
}
