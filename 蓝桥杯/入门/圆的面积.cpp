#include<stdio.h>
#define PI 3.14159265358979323

int main()
{
	int r;
	
	scanf("%d", &r);
	
	double s = 1.0 * r * r * PI;// + 0.00000005;
	
	printf("%.7llf", s);
	
	return 0;
}
