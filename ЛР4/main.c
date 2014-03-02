#include <stdio.h>

int main() {
  int divs[200][200];
  int divc[200];
  short divf[200];
  int divsum[200];
  int smax = 0;
  int dmax;
  int b;
  for(int i=0;i<100;i++) {divc[i]=0;divsum[i]=0;};
  for(int i=0;i<=20;i++) {
    for(int t=2;t<i+179;t++) {
      if((i+180)%t==0) {
	b = divc[i];
	divs[i][b]=t;
	divc[i]++;
	divf[i]=1;
	divsum[i]+=t;
	if(divsum[i]>smax){smax=divsum[i];dmax=i+180;}
      }
    }
  }
  printf("\nЧисло\t\tДелители\t\t\t  Сум. дел.\n\n");
  for(int i=0;i<=20;i++) {
    if(i!=0) printf("\n\n");
    printf("%d\t\t",i+180);
    int m = 0;
    if(divc[i]==0) printf("\t\t\t\t  0");
    while(divc[i]>m) {
      printf("%d",divs[i][m]); m++;
      if(m!=divc[i]) printf(",\t");
      if(m==4){printf("  %d\t",divsum[i]);};
      if((m==divc[i])&&(m<4)){for(int l=0;l<=3-divc[i];l++){printf("\t");};if(divc[i]==2){printf("\t  ");};printf("%d",divsum[i]);}
      if(m%4==0) printf("\n\t\t");
    }
  }
  printf("\n\n");
  printf("Наибольшая сумма делителей (%d) наблюдается у числа %d\n\n\n",smax,dmax);
  return 0;
}
