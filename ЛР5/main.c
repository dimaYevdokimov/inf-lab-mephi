#include <stdio.h>
#include <math.h>
double sum1(int n);
double sum2(int n);
double e=2.71828182846;

//Compile with gcc -std=c99 -lm

int main() {
  double s1,s2;
  printf("N\tСУМ1\t\t\tСУМ2\t\t\tРАЗН\n");
  s1=sum1(800); s2=sum2(800); printf("800\t%f\t%f\t%f\n",s1,s2,s2-s1);
  s1=sum1(900); s2=sum2(900); printf("900\t%f\t%f\t%f\n",s1,s2,s2-s1);
  s1=sum1(1000); s2=sum2(1000); printf("1000\t%f\t%f\t%f\n",s1,s2,s2-s1);
  return 0;
}

double sum1(int n) {
  double s=0;
  for(int i=0;i<n;i++) {
    s+=pow((double)e,sqrt((double) i));
  }
  return s;
}

double sum2(int n) {
  double s=0, scor=0, cor=0, fcor=0, f=0;
  for(int i=0;i<n;i++) {
    f=pow((double)e,sqrt((double) i));
    fcor=f-cor;
    scor=s+fcor;
    cor=(scor-s)-fcor;
    s=scor;
  }
  return s;
}
