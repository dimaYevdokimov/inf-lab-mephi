#include <stdio.h>

int main() {
  int x,y;
  scanf("%d%d",&x,&y);
  if(((x*x+y*y>=300*300)&&(x>=-300)&&(y>=-300)&&(x<=0)&&(y<=300))||((x*x<=300*300)&&((y>=0)&&(y>=300-x)||(y<=0)&&(y<=-300+x)))){printf("ДА!\n");}else{printf("НЕТ!\n");};
}
