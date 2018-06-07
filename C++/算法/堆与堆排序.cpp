/*
	��С�ѣ�
			���� �� <= ��
				ֻ�踸 <= min��  
					������   
		���壺 
			���� �� > �� 
				ֻ�� �� > min��
					�͵��� 
*/
#include<cstdio>
#include<algorithm>
#define MAXV 256

using namespace std;

int heap[MAXV], n;

//���µ���:�ʺϽ���ʱ��,��left�� right����heap�ķ�Χ 
void downAdjust(int left, int right)
{
	int key = left, child = key * 2; //keyΪԤ�����ڵ�,childΪ��С�ĺ��ӣ��ȳ�ʼ��Ϊ���� 
	
	//������Ӵ��ڣ��ҵ���С�ĺ��ӣ�Ȼ����� 
	/*
		������ȫ�����������Բ������һ��Ԫ�أ��϶��Ƕ������� 
	*/
	while(child <= right)
	{
		//����Һ��Ӵ������Һ���С�����ӣ�������С�ĺ���Ϊ�Һ��� 
		if(child + 1 <= right && heap[child + 1] < heap[child])
		{
			child = child + 1;
		}
		
		
		//���key�ڵ��ֵ����С��(�����)���Ӵ󣬼������µ���(�������ܴ�����) 
		if(heap[key] > heap[child])
		{
		 	swap(heap[key], heap[child]);
			key = child;
			child = key * 2;
		}
		//����ڵ��ֵ�ȶ���С����һ�����򵽴�λ�ã�����ѭ��
		else
		{
		
			break;
		}
		
		
	} 
	
	
}

//���� 
void createHeap(int n)
{
	for(int i = n / 2; i >= 1; i--)
	{
		downAdjust(i, n);
	}
	
}

void pushHeap(int key)
{
	heap[n++] = key;
	upAdjust(1, n);
}

//�Ѷ����У�����Ԫ�ط���ǰ��Ȼ����� 
void popHeap()
{
	heap[i] = heap[n--];
	downAdjust(1, n);
	
}

int topHeap()
{
	return heap[0];
}

//���ϵ���:�ʺϲ��� 
void upAdjust(int left, int right)
{
	int key = right, father = key / 2; 

	//������ൽ���ڵ� 
	while(father >= left)
	{
		
		//���key��ֵ��fatherС����key���ϵ��� 
		if(heap[key] < heap[father])
		{
			swap(heap[key], heap[father]);
			key = father;
			father = key / 2; 
		}
		 
		//����ڵ��ֵ�ȶ���С����һ�����򵽴�λ�ã�����ѭ�� 
		else
		{
			break;
		}
		
		
	} 
	
	
} 

int main()
{
	
	
	return 0;
}
