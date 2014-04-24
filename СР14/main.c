#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int s[7]; //Внешние массивы зло! Да и вообще, код перегружен.
// Если бы я был лаборантом, за такой код я бы насиловал

void nullArray(int* m,int size) {
  for(int i=0;i<size;i++) m[i]=0;
}

void printArray(int* m,int size) {
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",i);
  printf("\n");
  for(int i=0;i<size;i++) printf("%d\t",m[i]);
  printf("\n\n");
}

void rndArray(int* m,int size,int from,int to) {
  int r; short flags[7];
  for(int i=0;i<7;i++) flags[i]=0;
  for(int i=0;i<size;i++) {
    r=from + rand()%(to-from+1);
    m[i]=r;
    if(flags[r-14]==0) {
      s[r-14]++;
      flags[r-14]=1;
    }
  }
}

int maxArray(int* m,int size) {
  int mx=0;
  for(int i=0;i<size;i++) {
    if(m[i]>mx) mx=m[i];
  }
  return mx;
}

int maxArrayInd(int* m,int size) {
  int mi=0;
  for(int i=0;i<size;i++) {
    if(m[i]>mi) mi=i;
  }
  return mi;  
}

void revArray(int *m,int size) {
  int b;
  switch(size) {
    case 1:
    case 2:
      break;
    default:
      for(int i=1;i<size/2+(1-size%2);i+=2) {
	b=m[i];
	m[i]=m[size-i-size%2];
	m[size-i-size%2]=b;
      }
  }
}

void save(int *m, int size) {
  FILE *fout = fopen("./savedArray.txt","w+");
  for(int i=0;i<size;i++) fprintf(fout,"%d\n",m[i]);
}

void load(int *m, int size) {
  int b;
  FILE *fin = fopen("./arrayToLoad.txt","r+");
  for(int i=0;i<size;i++) {
    fscanf(fin,"%d",&b);
    m[i]=b;
  }
}

int* insert(int *m, int size1, int *n, int size2, int fi) {
  int* rm;
  int size3;
  if(fi<size1) {
    size3=size1+size2;
    rm = (int*) malloc(size3*sizeof(int));
    for(int i=0;i<size3;i++) {
      if(i<fi) rm[i]=m[i];
      if((i>=fi)&&(i<fi+size2)) rm[i]=n[i-fi];
      if(i>=fi+size2) rm[i]=m[i-size2];
    }
  }
  return rm;
}

void rem(int *m, int size,int fi,int n) {
  for(int i=0;i<size;i++) {
    if(i>=fi) {
      m[i]=m[i+n];
    }
  }
}

void sort(int* m,int size) {
  int e1=0,e2=0;
  int min, mini, b;
  for(int i=0;i<size;i++) {
    min=INT_MAX;
    for(int j=i;j<size;j++) {
      if(m[j]<min){min=m[j];mini=j;e2+=3;};
      e1++;
    }
    b=m[i];
    m[i]=min;
    m[mini]=b;
  }
  printf("Сортировка A: %d сравнений, %d присваиваний\n\n",e1,e2);
}

void sort2(int* m,int size) { // Игра "найди костыль"
  int e1=0,e2=0;
  int min, mini, b;
  for(int i=0;i<size;i++) {
    min=INT_MAX;
    for(int j=i;j<size;j++) {
      if((i>0)&&(m[j]==m[i-1])){m[i]=m[j];e2++;}else{(m[j]==m[i-1]);if(m[j]<min){min=m[j];mini=j;e2+=3;}};
      e1++;
    }
    b=m[i];
    m[i]=min;
    m[mini]=b;
  }
  printf("Сортировка B: %d сравнений, %d присваиваний\n\n",e1,e2);
}

int main() {
  int* ra; int rb[5];
  int sa[3]; int a,b,c,ind;
  int m[9];
  int n[7];
  int l[6];
  srand (time(NULL));
  for(int i=0;i<7;i++) s[i]=0;
  printf("Ну, мы создали три массива:\n");
  rndArray(&m,9,14,20);
  rndArray(&n,7,14,20);
  rndArray(&l,6,14,20);
  printArray(&m,9);printArray(&n,7);printArray(&l,6);
  for(int i=0;i<7;i++) {
    if(s[i]==3) printf("Число %d содержится во всех массивах!\n",i+14);
  }
  printf("\n\n\n ===== Это была одиннадцатая СР, теперь тринадцатая. =====\n\n\n(Используем тот же массив)");
  printf("Вот у нас есть массив:\n");
  printArray(&m,9);
  printf("Мы взяли его элементы, стоящие на четных местах, и поменяли их порядок на обратный:\n");
  revArray(&m,9);
  printArray(&m,9);
  printf("Теперь мы сохранили этот массив в файл, а потом загрузили другой:\n");
  save(&m,9);
  load(&m,5);
  printArray(&m,5);  
  printf("Давайте вставим в наш массив другой массив из трех чисел. Каких? \n");
  printf("Число 1: "); scanf("%d",&a);
  printf("Число 2: "); scanf("%d",&b);
  printf("Число 3: "); scanf("%d",&c);
  sa[0]=a; sa[1]=b; sa[2]=c;
  printf("С какого индекса начать? "); scanf("%d",&ind);
  ra = insert(&m,5,&sa,3,ind);
  printf("\nВот что получилось: \n");
  printArray(ra,8);
  rem(ra,8,ind,3);
  printf("А теперь мы убрали добавленные элементы: \n");  
  printArray(ra,5);
  printf("\n\n\n ===== Это была тринадцатая СР, теперь четырнадцатая. =====\n\n\n(Используем тот же массив)");
  printArray(ra,5);
  for(int i=0;i<5;i++) rb[i]=ra[i]; // Игра "найди костыль" продолжается!
  sort(ra,5);
  printf("После сортировки A: \n");
  printArray(ra,5);
  sort2(rb,5);
  printf("После сортировки B: \n");
  printArray(ra,5);
 
  return 0;
}