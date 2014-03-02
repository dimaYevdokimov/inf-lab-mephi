#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeT(int a, int b) {
  for(int i=a;i<=b;i++) {
    printf("%d\t ",i);
  }
}

int main() {
  double r;
  int d1,d2;
  int a[10];
  int n;
  int sum=0,v=0;
  double avg;
  int stime;
  long int ltime;
  ltime=time(NULL);
  stime=(unsigned) ltime/2;
  srand(stime);
  printf("Введите диапазон (два целых числа, второе больше первого): ");
  scanf("%d",&d1);
  scanf("%d",&d2);
  printf("Индекс: \t");
  writeT(0,10);
  printf("\n");
  printf("Элемент: \t");
  for(int i=0;i<=10;i++) {
    r = rand()/(RAND_MAX+1.0);
    a[i]= (r*(d2-d1)+d1);
    printf("%d\t ",a[i]);
  }
  printf("\nВведите какое-нибудь число: ");
  scanf("%d",&n);
  for(int i=0;i<=10;i++) {
    if(a[i]<n){sum+=a[i];v++;};
  }
  avg=(double)sum/(double)v;
  printf("Ср. арифм. = %.7lf\n",(double)sum/(double)v);
  sum=0;
  for(int i=0;i<=10;i++) {
    if(a[i]>avg) sum+=a[i];
  }
  printf("Сумма1=%d\n",sum);
  sum=0;
  for(int i=0;i<=10;i++) {
    if(a[i]>avg) sum+=*(a+i);
  }
  printf("Сумма2=%d\n",sum);
  return 0;
}
