#include<iostream> 

Result sumExist(int a[],int n, int sum)
{
	int i = 0, j = n - 1;
	Result result;
	while(i < j)
	{
		if(a[i] + a[j] < sum)
			i++;
		else if (a[i] + a[j] > sum)
			j--;
		else
			result.add(i);
			result.add(j);
			return result;	
	}
	return NULL;
}


int main()
{
	
	
	
	return 0;
}
