#include <stdio.h>
#include <math.h>
long double f(long double x);
long double solve(long double a, long double b, int i);
int p(int x,int n);

long double f(long double x) {
  return (-3/5+(long double)cos(x));
}

int p(int x,int n) {
  int b=1;
  for(int i=0;i<n;i++) {
    b*=x;
  }
  return b;
}

long double solve(long double a, long double b, int i) {
  if((i>9)||(b-a<0.0000001)) {printf("Ey=%.24llf\n",(b-a)/p(2,i));printf("cosx0=%.7llf\n",f(3/5+(a+b)/2));return ((a+b)/2);}; //TODO i
  long double c=(b+a)/2;
  //printf("%lf:%lf %lf:%lf\n",a,f(a),b,f(b)); Отладочка
  if(f(a)*f(c)<0) return solve(a,c,i+1);
  if(f(c)*f(b)<0) return solve(c,b,i+1);
}

int main() {
  printf("x=%.7llf\n",solve(6,8,0));
  return 0;
} 
