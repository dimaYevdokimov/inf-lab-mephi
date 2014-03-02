#include <stdio.h>
#include <math.h>
long double sum(int n);
long int solve();

int main() {
  int n;
  scanf("%d",&n);
  printf("%.10Lf\n",sum(n));
  printf("Ответ: %ld\n",solve());
  return 0;
}
 
long double sum(int n) { // a very good solution
  return (double) n/ (double) (n+1);
}

long int solve() { // a very bad solution
  long int n=1;
  while(sum(n)<0.9999999999) {
    n++;
  }
}


