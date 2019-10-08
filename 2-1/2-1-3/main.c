#include <stdio.h>

void rotateLeft(int *pa, int *pb, int *pc){
	int temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
}

void rotateRight(int *pa, int *pb, int *pc){
	int temp = *pc;
	*pc = *pb;
	*pb = *pa;
	*pa = temp;
}

int main(void){
	int a=10, b=20, c=30;
	int work;
	printf("%d:%d:%d\n", a, b, c);
	while(1){
		scanf("%d", &work);
		if(work!=1 && work!=2){
			break;
		}
		if(work==1){
			rotateLeft(&a, &b, &c);
		}
		if(work==2){
			rotateRight(&a, &b, &c);
		}
		printf("%d:%d:%d\n", a, b, c);
	}
	return 0;
}

