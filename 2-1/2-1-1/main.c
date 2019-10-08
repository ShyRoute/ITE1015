#include <stdio.h>

typedef struct Person{
	char name[11];
	int age;
} person;

int main(void){
	person p[3];
	for(int i=0; i<3; i++){
		scanf("%s %d", p[i].name, &p[i].age);
	}
	for(int i=0; i<3; i++){
		printf("Name : %s, Age : %d\n", p[i].name, p[i].age);
	}
	return 0;
}
