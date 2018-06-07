/*
	各种算法实现从小到大排序 
	创建时间：2018年3月4日22:56:28 
*/


#include<cstdio>
#include<algorithm>
#define MAXV 256
#define INF 0x3fffffff

class MySort
{
	private:
		void merge_sort_dac(int array[], const int left, const int right);
		void merge_sort_part(int array[], const int left, int mid, const int right);
		void create_heap(int array[], const int n);
		void insert_heap(int heap[], int size, int key);
		void heap_pop(int array[], const int n);
		void quick_part(int array[], const int left, const int right);
	
	public:
		void bubble_sort(int array[], const int n);	
		void select_sort(int array[], const int n);
		void insert_sort(int array[], const int n);
		void merge_sort(int array[], const int n);
		void quick_sort(int array[], const int n);
		void heap_sort(int array[], const int n);

};

//冒泡排序:从左到右依次比较交换，找到最大值放最右 时间复杂度为O (n^2)
void MySort::bubble_sort(int array[], const int n)
{
	/*
		i比较次数，j是数组位置，减1是因为j+1 
	*/
	
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-i-1; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
			
		}
	
}

//选择排序:每次选出最小的放最前面 ,时间复杂度为0（n^2） 
void MySort::select_sort(int array[], const int n)
{

	for(int i = 0; i < n; i++)
	{	
		/*
			i代表最前面 
			这里的min也可以初始化为array[i]，因为每次min必然先跟array[j=i]比较，而min是INF，所有数都比它小 	
		*/
		int min = INF, minv = INF;

		for(int j = i; j < n; j++)
		{
			if(array[j] < min)
			{
				min = array[j];
				minv = j;
			} 
		}
		
		/*
			讨论这里要不要flag判断if语句是否执行过，答案：不用，if一定执行过，因为min一开始为INF 
		*/
		
		int temp = array[minv];
		array[minv] = array[i];
		array[i] = temp;
		
	}
	
	
} 

//插入排序：把没排序的插入到排序好的，时间复杂度为0（n^2） 
void MySort::insert_sort(int array[], const int n)
{
	/*
		默认i左边是排序好的，其他是没排序的 
		第一个数默认排序好 
	*/
	for(int i = 1; i < n; i++)
	{
		int temp = array[i];
		for(int j = 0; j < i; j++)
		{
			//找到插入位置j，将后面的数往后移
			if(array[j] > temp)
			{ 
				//k必须倒序，顺序的话会产生错误：样会让后面的数都变成array[k] ，即指针移动方向不能与数字移动方向相同，否则会出错，为什么自己画图想想。 
				for(int k = i; k > j; k--)
				{
					array[k] = array[k-1];
				}
				
				array[j] = temp;
				break;
			}
		}
	
		
	}
	
}

//归并排序分治部分 
void MySort::merge_sort_dac(int array[], const int left, const int right)
{
	if(left < right)
	{
		int mid = (right - left) / 2 + left;
		
		merge_sort_dac(array, left, mid);
		merge_sort_dac(array, mid+1, right);
		/*
			若使用左开右闭区间，这样分治会出问题，left = 0，right = 1,时会进入无限递归 
			merge_sort_dac(array, left, mid);
			merge_sort_dac(array, mid, right); 
		*/
		merge_sort_part(array, left, mid, right);
		
	}	
	
}

//归并排序合并部分 
void MySort::merge_sort_part(int array[], const int left, int mid, const int right)
{
	int i = left;
	
	int j = mid + 1;
	
	int k = 0;
	int temparray[MAXV] = {0};
	
	//主要操作 
	while(i <= mid && j <= right)
	{
		if(array[i] < array[j])
		{
			temparray[k++] = array[i++]; 	
		}
		else
		{
			temparray[k++] = array[j++];
		}
	}
	
	//把剩余的数字放到数组里 
	while(i <= mid)
	{
		temparray[k++] = array[i++];
	}
	while(j <= right)
	{
		temparray[k++] = array[j++];
	}
	
	i = left;
	k = 0;
	

	while(i <= right)
	{
		array[i++] = temparray[k++];
	}
}


//归并排序：
void MySort::merge_sort(int array[], const int n)
{
	int mid = n / 2 - 1;
	
	merge_sort_dac(array, 0, mid);
	merge_sort_dac(array, mid+1, n-1);
	
	merge_sort_part(array, 0, mid, n-1);	

	
} 

//基准位左边全比较小，右边全比较大 
void MySort::quick_part(int array[], const int left, const int right)
{
	if(left > right)
		return;
	
	int i = left, j = right;
	int standard = array[left];
	
	while(i != j)
	{
		//必须右边先走，不然类似6,1,2,7,9的话，6的位置会换在第四个，而实际上是第三个 
		//必须有等号， 否则，只有两个元素时，如5,6时，执行交换语句，变成6,5这不是想要的结果 
		while(i < j && array[j] >= standard)
			j--;
		while(i < j && array[i] <= standard)
			i++;
		
		if(i < j)
			std::swap(array[i], array[j]);	
				
	}
	
	//基准位归位 
	std::swap(array[left], array[i]);
	
	//分治法找到全部数基准位 
	quick_part(array, left, i - 1);
	quick_part(array, i + 1, right);
	
	
}


//快速排序 
void MySort::quick_sort(int array[], const int n)
{
	
	quick_part(array, 0, n-1);
	
}



int main()
{
	int num, n = 0;
	int array[MAXV] = {0};
	
	freopen("排序的数字.txt", "r", stdin);
	
	//读取文件的n个数字，放入array数组 
	while(scanf("%d", &num) != EOF)
	{	
		array[n] = num;
		n++;
	}
	
	MySort sort;
	
	sort.quick_sort(array, n);

		
	for(int i = 0; i < n-1; i++)
	{
		printf("%d < ", array[i]);
	}
	printf("%d\n", array[n-1] );
		
	return 0;
}
