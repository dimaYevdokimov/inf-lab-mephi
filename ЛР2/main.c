#include <stdio.h>

int main() {
  int a;
  scanf("%d",&a);
  if(a==0){printf("Не принадлежит"); return 0;};
  if(((a>=-20)&&(a<=15))||(a>=50)) {
    if(a%3==0){printf("Кратное\n");}else{printf("Не кратное\n");};
  } else {
    printf("Не принадлежит\n");
  }
  return 0;
}
