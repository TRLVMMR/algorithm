#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int a[10];
	
	scanf("%d %d %d", &a[0], &a[1] ,&a[2]);
	
	sort(a, a+3);
	
	for(int i = 0; i < 2; i++)
		printf("%d->", a[i]);
	printf("%d\n",a[2]);
	
	
	return 0;
}
