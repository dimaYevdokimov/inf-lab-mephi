#include <stdio.h>
#include <math.h>

int f(double a, double b, double c, double* rp, double* rs) {
  double p;
  p=(a+b+c)/2;
  if((a<=0)||(b<=0)||(c<=0)){printf("Неположительные длины сторон!\n");return 1;};
  if(p==0){printf("Треугольник вырожден в точку!\n");return 2;};
  if((a+b<c)||(a+c<b)||(b+c<a)){printf("Треугольник не существует!\n");return 3;};
  if((a+b==c)||(a+c==b)||(b+c==a)){printf("Треугольник вырожден в отрезок!\n");return 4;};
  double s=sqrt(p*(p-a)*(p-b)*(p-c));
  *rp=2*p;
  *rs=s;
  return 0;
}

int main() {
  double a,b,c;
  double r,s;
  printf("Введите длины сторон треугольника (3 шт.): ");
  scanf("%lf%lf%lf",&a,&b,&c);
  if(f(a,b,c,&r,&s)==0) {
    printf("Периметр треугольника: %lf\n",r);
    printf("Площадь треугольника: %lf\n",s);  
  }
  return 0;
}
