#include<stdio.h>
#define MAXV 256

int getf(int father[], int key)
{
	if(key == father[key])
		return key;
	
	father[key] = getf(father, father[key]);
	
	return father[key];
	
}

//²¢²é¼¯ 
void merge(int father[], int a, int b)
{
	int faA = getf(a);
	int faB = getf(b);
	
	if(faA != faB)
		father[faA] = faB;
	
}


int main()
{
	int father[MAXV];
	
	for(int i = 0; i < MAXV; i++) 
		father[i] = i;
	
	while(scanf("%d %d", &a, &b) != EOF)
		merge(father, a, b);
	
	
	
	
	return 0;
}
