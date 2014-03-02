#include <stdio.h>
#include <math.h>

int main() {
  double Y[71]; double b; double min=1000; double avgm=0;
  for(int i=0;i<71;i++) {
    b=4*cos((double)0.2*3*i-7);
    Y[i]=b;
    if((b<min)&&(i%2==0)) min=b;
    if(b<0) avgm+=b;
    printf("4cos(%1.1f)=%lf\n",0.2*3*i-7,b);
  }
  avgm/=70;
  printf("min=%lf\n",min);
  printf("avgm=%lf\n",avgm);
  return 0;
}
