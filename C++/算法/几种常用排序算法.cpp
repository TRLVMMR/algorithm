/*
	�����㷨ʵ�ִ�С�������� 
	����ʱ�䣺2018��3��4��22:56:28 
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

//ð������:���������αȽϽ������ҵ����ֵ������ ʱ�临�Ӷ�ΪO (n^2)
void MySort::bubble_sort(int array[], const int n)
{
	/*
		i�Ƚϴ�����j������λ�ã���1����Ϊj+1 
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

//ѡ������:ÿ��ѡ����С�ķ���ǰ�� ,ʱ�临�Ӷ�Ϊ0��n^2�� 
void MySort::select_sort(int array[], const int n)
{

	for(int i = 0; i < n; i++)
	{	
		/*
			i������ǰ�� 
			�����minҲ���Գ�ʼ��Ϊarray[i]����Ϊÿ��min��Ȼ�ȸ�array[j=i]�Ƚϣ���min��INF��������������С 	
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
			��������Ҫ��Ҫflag�ж�if����Ƿ�ִ�й����𰸣����ã�ifһ��ִ�й�����Ϊminһ��ʼΪINF 
		*/
		
		int temp = array[minv];
		array[minv] = array[i];
		array[i] = temp;
		
	}
	
	
} 

//�������򣺰�û����Ĳ��뵽����õģ�ʱ�临�Ӷ�Ϊ0��n^2�� 
void MySort::insert_sort(int array[], const int n)
{
	/*
		Ĭ��i���������õģ�������û����� 
		��һ����Ĭ������� 
	*/
	for(int i = 1; i < n; i++)
	{
		int temp = array[i];
		for(int j = 0; j < i; j++)
		{
			//�ҵ�����λ��j�����������������
			if(array[j] > temp)
			{ 
				//k���뵹��˳��Ļ���������������ú�����������array[k] ����ָ���ƶ��������������ƶ�������ͬ����������Ϊʲô�Լ���ͼ���롣 
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

//�鲢������β��� 
void MySort::merge_sort_dac(int array[], const int left, const int right)
{
	if(left < right)
	{
		int mid = (right - left) / 2 + left;
		
		merge_sort_dac(array, left, mid);
		merge_sort_dac(array, mid+1, right);
		/*
			��ʹ�����ұ����䣬�������λ�����⣬left = 0��right = 1,ʱ��������޵ݹ� 
			merge_sort_dac(array, left, mid);
			merge_sort_dac(array, mid, right); 
		*/
		merge_sort_part(array, left, mid, right);
		
	}	
	
}

//�鲢����ϲ����� 
void MySort::merge_sort_part(int array[], const int left, int mid, const int right)
{
	int i = left;
	
	int j = mid + 1;
	
	int k = 0;
	int temparray[MAXV] = {0};
	
	//��Ҫ���� 
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
	
	//��ʣ������ַŵ������� 
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


//�鲢����
void MySort::merge_sort(int array[], const int n)
{
	int mid = n / 2 - 1;
	
	merge_sort_dac(array, 0, mid);
	merge_sort_dac(array, mid+1, n-1);
	
	merge_sort_part(array, 0, mid, n-1);	

	
} 

//��׼λ���ȫ�Ƚ�С���ұ�ȫ�Ƚϴ� 
void MySort::quick_part(int array[], const int left, const int right)
{
	if(left > right)
		return;
	
	int i = left, j = right;
	int standard = array[left];
	
	while(i != j)
	{
		//�����ұ����ߣ���Ȼ����6,1,2,7,9�Ļ���6��λ�ûỻ�ڵ��ĸ�����ʵ�����ǵ����� 
		//�����еȺţ� ����ֻ������Ԫ��ʱ����5,6ʱ��ִ�н�����䣬���6,5�ⲻ����Ҫ�Ľ�� 
		while(i < j && array[j] >= standard)
			j--;
		while(i < j && array[i] <= standard)
			i++;
		
		if(i < j)
			std::swap(array[i], array[j]);	
				
	}
	
	//��׼λ��λ 
	std::swap(array[left], array[i]);
	
	//���η��ҵ�ȫ������׼λ 
	quick_part(array, left, i - 1);
	quick_part(array, i + 1, right);
	
	
}


//�������� 
void MySort::quick_sort(int array[], const int n)
{
	
	quick_part(array, 0, n-1);
	
}



int main()
{
	int num, n = 0;
	int array[MAXV] = {0};
	
	freopen("���������.txt", "r", stdin);
	
	//��ȡ�ļ���n�����֣�����array���� 
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
