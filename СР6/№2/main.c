#include <stdio.h>
#include <math.h>

long double p(long double x,long double n) {
  long double b=1;
  for(int i=0;i<n;i++) {
    b*=x;
  }
  return b;
}

long double fac(n) {
  long double r=1;
  long double m=1;
  for(long double i=0;i<n;i++) {
    r*=m; m++;
  }
  return r;
}

long double f(long double x,int n) {
  long double s = 0;
  for(int i=0;i<=n;i++) {
    s+=(p(-1,i)*p(x,2*i))/fac(2*i);
  }
  return s;
}

int main() {
  int o;
  long double x0=7.8544922;
  long double cosx0=-0.000511;
  printf("Old cosx0=%.7llf\n",cosx0);
  for(int n=1;n<16;n++) {
    o = (int)floor(1000000*f(x0,n));
    printf("New cos (n=%d) x0=%.6llf\n",n,f(x0,n));
  }
  return 0;
}
