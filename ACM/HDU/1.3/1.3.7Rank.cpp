/*
	�������
		�ɼ���һ�ǵ�һ�����ڶ��ǵڶ����������һ�������������Ͳ����ڵڶ�����ƽ����������������ѧ�ţ� 

*/

#include<stdio.h>
#include<algorithm>

using namespace std;

struct Student
{
	int snum;
	int score;
	int rank;
};

bool cmp(Student a, Student b)
{
	return a.score > b.score;
	
}

int main()
{
	int jan, snum, score;
	
	while (scanf("%d",&jan) != EOF)
	{
		Student s[1000];
		int n = 0;//����������Լ�¼���ٸ��� 
		while(scanf("%d %d", &snum, &score ) != EOF)
		{
			if(!snum && !score)	break;
			s[n].snum = snum;
			s[n].score = score;
			n++;
		}
		
		//�������Ӵ�С����s 
		sort(s, s+n, cmp);
		
		s[0].rank = 1;
		for(int i = 1; i < n; i++)
		{
			if(s[i].score == s[i-1].score)
				s[i].rank = s[i-1].rank; 
			else
				s[i].rank = i+1;
			
		}
		
		for(int i = 0; i < n; i++)
		{
			if(s[i].snum == jan)
			{
				printf("%d\n",s[i].rank);
				break;
			}
		}
	}
	
	return 0;
} 
