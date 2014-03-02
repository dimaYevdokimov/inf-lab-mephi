#include <stdio.h>

int F(m,n) {
  if((m==0)||(n==0)) {
    return n+1;
  } else {
    return F(m-1,F(m,n-1));
  }
}

int main() {
  int m,n;
  printf("Введите натуральные числа m и n: ");
  scanf("%d",&m);
  scanf("%d",&n);
  printf("F(m,n): %d\n",F(m,n));
  return 0;
}
