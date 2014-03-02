#include <stdio.h>
#include <math.h>

double V(double r,double h) {
  return (3.1415926*r*r*h)/3;
}

double S(double r,double h) {
  return (3.1415926*r*(r+sqrt(r*r+h*h)));
}

double Et(double s) {
  return sqrt(s/sqrt(3));
}

int main() {
  double r,h;
  double j=100000;
  double ra, ha;
  printf("Введите радиус основания и высоту конуса: ");
  scanf("%lf %lf",&r,&h);
  printf("S=%lf\n",S(r,h));
  printf("V=%lf\n",V(r,h));
  for(int ir=1;ir<51;ir++) {
    for(int ih=1;ih<51;ih++) {
      if(fabs(1-(V((double)ir,(double)ih)/S((double)ir,(double)ih)))<j){j=fabs(1-(V((double)ir,(double)ih)/S((double)ir,(double)ih)));ra=ir;ha=ih;}
    }
  }
  printf("Ответом на вопрос 2 является конус с r=%lf и h=%lf\n",ra,ha);
  printf("Ответ на вопрос 3: %lf\n",Et(S(r,h)));
  return 0;
}