#include<stdio.h>
int main(){
	int a, b, m, d;
	printf("enter  no:");
	scanf("%d, %d", &a, &b);
	m=a*b;
	d=a/b;
	printf("multiplication: %d\n", m);
	printf("division:%d", d);
	return 0;
}
