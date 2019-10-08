#include <stdio.h>

typedef struct{
	int xpos;
	int ypos;
} Point;

Point getScale2xPoint(const Point* p){
	Point P2;
	P2.xpos = p->xpos * 2;
	P2.ypos = p->ypos * 2;
	return P2;
}

void swapPoints(Point *p1, Point *p2){
	Point temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main(void){
	Point p, p2;
	scanf("%d %d", &p.xpos, &p.ypos);
	printf("Calling getScale2xPoint()\n");
	printf("P1 : %d %d\n", p.xpos, p.ypos);
	p2 = getScale2xPoint(&p);
	printf("P2 : %d %d\n", p2.xpos, p2.ypos);
	printf("Calling swapPoint()\n");
	swapPoints(&p, &p2);
	printf("P1 : %d %d\n", p.xpos, p.ypos);
	printf("P2 : %d %d\n", p2.xpos, p2.ypos);
	return 0;
}
