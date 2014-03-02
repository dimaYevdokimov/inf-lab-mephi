#include <stdio.h> 
#include <limits.h>

char checkChar(char d) {
  if(((d>='!')&&(d<='/'))||((d>=':')&&(d<='@'))||((d>='[')&&(d<='`'))||((d>='{')&&(d<='~'))||(d=='\n')||(d==' ')||(d=='	')) return 1;
  if((d>='0')&&(d<='9')) return -1;
  return 0;
}

int main() {
  char b[100];
  short it=0;
  short f=0;
  int min=INT_MAX;
  char c;
  printf("\n");
  do {
    c = getchar();
    switch(checkChar(c)) {
      case 0:
	if(f==0) {
	  b[it]=c;
	  it++;
	};
	break;
      case 1:
	f=0;
	if(it!=0) {
	  if(it<min) min=it;
	  for(int i=0;i<it;i++){printf("%c",b[i]);b[i]='\0';};it=0;printf("\n");
	}
	break;
      case -1:
	f=1;
	if(it!=0) {
	  for(int i=0;i<it;i++) b[i]='\0';
	  it=0;
	}
	break;
    }
  } while(c!='\n');
  if(min==INT_MAX) {
    printf("\nВ вашей строке нет ни одного слова. Что, фантазии не хватило?!\n\n");
  } else {
    printf("\nВ самом маленьком слове %d бук",min);
    if(min%10==1) printf("ва");
    if((min%10==0)||(min%10>4)) printf("в");
    if((min%10>1)&&(min%10<5)) printf("вы");
    printf("!\n\n");
  }
  return 0;
}
