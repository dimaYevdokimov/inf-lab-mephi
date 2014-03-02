#include <stdio.h>
int gf=0;
int gf2=1000000;

int fib(int n,int f) {
  if((gf2>n)&&(f>0)) gf2=n;
  if((f==0)&&(gf<=gf2)) {
    printf("Текущий уровень рекурсии\t\tРекурсивный спуск\t\tРекурсивный подъем\n");
    printf("0\t\t\t\t\tВвод: %d fib(%d)\t\t\tВывод: fib(%d)=%d\n",n,n,n,fib(n,-10000000)); f++;
    printf("%d\t\t\t\t\tn=%d call fib(%d) call fib(%d)\treturn fib(%d)=%d\n",f,n,n-1,n-2,n,fib(n,-10000000));
    gf++;
  } else {
    if((n==2)&&(gf<gf2+2)&&(f>0)) {
      printf("%d\t\t\t\t\t\t\t  n=2 return 1 n=1 return 0\n",f,n);
      gf++;
    } else
    if((f>0)&&(gf<=gf2)) {
      printf("%d\t\t\t\t\tn=%d call fib(%d) call fib(%d)\treturn fib(%d)=%d\n",f,n,n-1,n-2,n,fib(n,-10000000));
      gf++;
    }
  };
  if((n==1)||(n==2)) {
    return 1;
  } else {
    return fib(n-1,f+1)+fib(n-2,f+1);
  }
}

int main() {
  printf("\nОтвет:%d\n",fib(5,0));
  return 0;
}
