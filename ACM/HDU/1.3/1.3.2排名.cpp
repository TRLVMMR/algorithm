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

//比较函数，若a>b返回ture 
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
		
		//输入各题分数 
		for(int i = 1; i <= m; i++)
			scanf("%d",&a[i]);
		
		//输入学生学号，k为完成几道题	
		for(int i = 1; i <= n; i++)
		{
			int k;
		//	scanf("%s",q[i].ID.c_str());//把srting转换成char数组 
			cin >> q[i].ID;
			scanf("%d",&k);
			
			//输入完成哪些题，得到这些学生的分数 
			while(k--)
			{
				int temp;
				scanf("%d",&temp);
				q[i].score = q[i].score + a[temp];
			}
				
		}
		
		//将每个人的成绩排序 
		sort(&q[1], &q[n+1], cmp);	
		
		//计算上线人数 
		int sum;


		for(sum = 1; sum <= n; sum++)
		{
			if(q[sum].score < std)
				break;			
		}
		
		printf("%d\n",sum-1);//一共sum-1人 
		
		//输出上线的人员名单 
		for(int i = 1; i < sum; i++)
		{
			printf("%s ",q[i].ID.c_str());
			printf("%d\n",q[i].score);
		}
		
	}
	
	return 0;
}
