/*
	����array��lenû��ֵ������������ 
*/
#include<cstdio>
#define MAXV 256

//���ַ����ҵ������� 
int binarySearch(int array[], int len, int key)
{
	int left = 0;
	int right = len - 1;
	
	while(right >= left)
	{
		int mid = (right - left) / 2 + left;
		
		if(array[mid] > key)
			right = mid - 1; 
			
		else if(array[mid] == key)
			return mid;
			
		else
			left = mid + 1;
		
	}
	return -1;
}

int main()
{
	
	int array[MAXV];
	int key;
	int len;
	
	scanf("%d", key);
	
	binarySearch(array, len, key);
	
	return 0;
}
