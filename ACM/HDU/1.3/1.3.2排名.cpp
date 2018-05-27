#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct Student
{
	string ID;
	int score;
	Student(int _score = 0):score(_score) {};
	
};

//�ȽϺ�������a>b����ture 
bool cmp(Student a, Student b)
{
	if(a.score == b.score)
		return a.ID < b.ID;
	else
		return a.score > b.score;
}

int main()
{
	#ifdef LOCAL
		freopen("1-3-2.in", "r", stdin);
	#endif
	
	int n, m, std;
	
	while(scanf("%d %d %d",&n, &m, &std) != EOF)
	{
		int a[11];
		Student q[1001];
		
		if(!n)	break;
		
		//���������� 
		for(int i = 1; i <= m; i++)
			scanf("%d",&a[i]);
		
		//����ѧ��ѧ�ţ�kΪ��ɼ�����	
		for(int i = 1; i <= n; i++)
		{
			int k;
		//	scanf("%s",q[i].ID.c_str());//��srtingת����char���� 
			cin >> q[i].ID;
			scanf("%d",&k);
			
			//���������Щ�⣬�õ���Щѧ���ķ��� 
			while(k--)
			{
				int temp;
				scanf("%d",&temp);
				q[i].score = q[i].score + a[temp];
			}
				
		}
		
		//��ÿ���˵ĳɼ����� 
		sort(&q[1], &q[n+1], cmp);	
		
		//������������ 
		int sum;


		for(sum = 1; sum <= n; sum++)
		{
			if(q[sum].score < std)
				break;			
		}
		
		printf("%d\n",sum-1);//һ��sum-1�� 
		
		//������ߵ���Ա���� 
		for(int i = 1; i < sum; i++)
		{
			printf("%s ",q[i].ID.c_str());
			printf("%d\n",q[i].score);
		}
		
	}
	
	return 0;
}
