#include <stdio.h>
#include <math.h>
long double f(long double x);
long double solve(long double a, long double b, int i);

long double f(long double x) {
  return ((long double)x-(long double)cos(x));
}

long double solve(long double a, long double b, int i) {
  if(i>32) return a;
  long double c=(b+a)/2;
  //printf("%lf:%lf %lf:%lf\n",a,f(a),b,f(b)); Отладочка
  if(f(a)*f(c)<0) return solve(a,c,i+1);
  if(f(c)*f(b)<0) return solve(c,b,i+1);
}

int main() {
  printf("%.8llf\n",solve(-2,4,0));
  return 0;
}