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

int main() {
  long int n;
  long int m;
  printf("Введите какое-нибудь число в семиричной системе: ");
  scanf("%ld",&n);
  switch(heptToDec(n,&m)) {
    case 1:
      printf("Переполнение!\n");
      break;
    case 2:
      printf("Посторонние символы!\n");
      break;
    default:
      printf("Если перевести %ld из семиричной в десятичную, будет %ld!\n",n,m);
      break;
  };
  printf("А теперь наоборот, введите число в десятичной системе: ");
  scanf("%ld",&n);
  if(decToHept(n,&m)==0) {
    printf("Если перевести %ld из десятичной в семиричную, будет %ld!\n",n,m);
  } else {
    printf("Переполнение!\n");
  };  
  return 0;
}
