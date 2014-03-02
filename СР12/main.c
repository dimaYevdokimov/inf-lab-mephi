#include <stdio.h>

int main() {
	int i,j,k=0,f=0,g=0;
	char mw[8]; char cw[8];
	int l[30];
	int li=0;
	int ln=0;
	int r=0;
	for(i=0;i<8;i++){mw[i]=0;cw[i]=1;}
	char c;
	FILE *fin = fopen("input.txt","r+");
	printf("\n");
	do {
		ln++;
		do {
			f=0;k=0;g=0;
			for(i=0;i<8;i++) {
				c=getc(fin);
				if(c==EOF||c=='\n'||c==' '){break;};
				if(c<mw[i]){f=1;}else{if(f==0) k++;};
				cw[i]=c;
			}
			if(k>=r) {
				r=k;
				for(j=0;j<i;j++){if(mw[j]!=cw[j]){g=1;};};
				if(g==0){if(l[li-1]!=ln){l[li]=ln;li++;};}else{l[0]=ln;li=1;};
				for(j=0;j<i;j++){mw[j]=cw[j];};
			}
		} while((c!='\n')&&(c!=EOF));
	} while(c!=EOF);
	printf("Последнее по алфавиту слово: ");
	for(i=0;i<8;i++) {
		printf("%c",mw[i]);
	}
	printf("\nНайдено в строках: ");
	for(i=0;i<li;i++) {
		printf("%d",l[i]);
		if(i!=li-1) printf(", ");
	}
	printf("\n\n");
	fclose(fin);
	return 0;
}
