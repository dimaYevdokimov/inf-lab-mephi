#include <stdio.h>
#include <limits.h>

long long pow(long long int a) {
  long long int c = 1;
  for(long long int i=1;i<=a;i++) {
    c*=a;
  }
  return c;
}

int main() {
  long long int t[22];
  long int n; long int i = 1;
  long long int r = 0;
  int k = 0;
  scanf("%ld",&n);
  do {
    r+=pow(i);
    if(i==n) printf("%llu\n\n",r);
    t[i-1]=r;
    i++;
  } while(r<2147483647);
  for(long int y=0;y<i-1;y++) {
      printf("%llu ", t[k]); k++;
       long long int b = t[k-1];
      int m = 0;
      while(b>0) {
	m++;
	b/=10;
      }
      for(int j=0;j<10-m;j++) printf(" ");
      if((y+1)%2==0) printf("\n");
  }
  return 0;
}
