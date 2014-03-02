#include <stdio.h>

int p(long int x, long int y) {
  long int r=1;
  for(long int i=0;i<y;i++) {
    r*=x;
  }
  return r;
}

int wrsmb(long int h) {
  while(h>0) {
    if(h%10>6) return 1;
    h/=10;
  }
  return 0;
}

int decToHept(long int x, long int* y) {
  long int r=0;
  long int i=0;
  long int s=0;
  int m=1;
  if(x<0) {x*=-1;m=-1;};
  while(x!=0) {
    s+=x%7*p(10,i); i++;
    if((s<-2146666666)||(s>2146666666)) return 1;
    x/=7;
  }
  *y = s*m;
  return 0;
}

int heptToDec(long int x, long int* y) {
  long int r=0;
  long int i=0;
  int m=1;
  int e = wrsmb(x); if(e!=0) return 2;
  if((x<-2146666666)||(x>2146666666)) return 1;
  if(x<0) {x*=-1;m=-1;};
  while(x>0) {
    r+=x%10*p(7,i); i++;
    x/=10;
  };
  *y = r*m;
  return 0;
}

int hp(long int x,long int y, long int* z) {
  long int xd, yd, zd, r;
  if(heptToDec(x,&xd)!=0) return 1;
  if(heptToDec(y,&yd)!=0) return 1;
  zd=xd+yd;
  if(decToHept(zd,&r)!=0) return 1;
  *z = r;
  return 0;
}

int hm(long int x,long int y, long int* z) {
  long int xd, yd, zd, r;
  if(heptToDec(x,&xd)!=0) return 1;
  if(heptToDec(y,&yd)!=0) return 1;
  zd=xd-yd;
  if(decToHept(zd,&r)!=0) return 1;
  *z = r;
  return 0;
}

int hmul(long int x,long int y, long int* z) {
  long int xd, yd, zd, r;
  if(heptToDec(x,&xd)!=0) return 1;
  if(heptToDec(y,&yd)!=0) return 1;
  zd=xd*yd;
  if(decToHept(zd,&r)!=0) return 1;
  *z = r;
  return 0;
}

int hpow(long int x,long int y, long int* z) {
  long int xd, yd, zd, r;
  if(heptToDec(x,&xd)!=0) return 1;
  if(heptToDec(y,&yd)!=0) return 1;
  zd=p(xd,yd);
  if(decToHept(zd,&r)!=0) return 1;
  *z = r;
  return 0;
}

int main() {
  long int a;
  long int b;
  long int bb;
  long int c;
  long int d;
  int e=0;
  printf("Введите a и b: ");
  scanf("%ld%ld",&a,&b);
  e+=hpow(b,2,&bb);
  e+=hm(bb,a,&c);
  e+=hmul(a,c,&bb);
  e+=hm(a,bb,&c);
  e+=hp(c,b,&bb);
  if(e==0) {
    printf("Ответ: %ld\n",bb);
  } else {
    printf("Случилось переполнение!\n");
  }
  return 0;
}
 
