#include <stdio.h>

int p(int x, int y) {
  int s=1;
  for(int i=0;i<y;i++) {
    s*=x;
  }
  return s;
}

int main() {
  int m,n=1,k=0;
  printf("Введите m: ");
  scanf("%d",&m);
  while(p(7,k)<m) {
    k++;
  }
  printf("Ответ: %d\n",k-1);
  printf("Таблица степеней числа 7:\n");
  for(int i=0;i<=10;i++) {
    printf("7^%d=%d\n",i,p(7,i));
  }
  return 0;
}