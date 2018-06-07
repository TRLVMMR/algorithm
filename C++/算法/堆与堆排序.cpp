/*
	最小堆：
			任意 父 <= 儿
				只需父 <= min儿  
					就留下   
		反义： 
			存在 父 > 儿 
				只需 父 > min儿
					就调整 
*/
#include<cstdio>
#include<algorithm>
#define MAXV 256

using namespace std;

int heap[MAXV], n;

//向下调整:适合建堆时用,【left， right】是heap的范围 
void downAdjust(int left, int right)
{
	int key = left, child = key * 2; //key为预调整节点,child为最小的孩子，先初始化为左孩子 
	
	//如果孩子存在，找到最小的孩子，然后调整 
	/*
		堆是完全二叉树，所以不到最后一个元素，肯定是堆中数据 
	*/
	while(child <= right)
	{
		//如果右孩子存在且右孩子小于左孩子，设置最小的孩子为右孩子 
		if(child + 1 <= right && heap[child + 1] < heap[child])
		{
			child = child + 1;
		}
		
		
		//如果key节点的值比最小的(任意的)儿子大，继续往下调整(反正不能待这了) 
		if(heap[key] > heap[child])
		{
		 	swap(heap[key], heap[child]);
			key = child;
			child = key * 2;
		}
		//如果节点的值比儿子小或者一样大，则到达位置，结束循环
		else
		{
		
			break;
		}
		
		
	} 
	
	
}

//建堆 
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

//堆顶出列：最后的元素放最前，然后调整 
void popHeap()
{
	heap[i] = heap[n--];
	downAdjust(1, n);
	
}

int topHeap()
{
	return heap[0];
}

//向上调整:适合插入 
void upAdjust(int left, int right)
{
	int key = right, father = key / 2; 

	//父亲最多到根节点 
	while(father >= left)
	{
		
		//如果key的值比father小，把key往上调整 
		if(heap[key] < heap[father])
		{
			swap(heap[key], heap[father]);
			key = father;
			father = key / 2; 
		}
		 
		//如果节点的值比儿子小或者一样大，则到达位置，结束循环 
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
