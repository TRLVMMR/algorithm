/*
	输出排名
		成绩第一是第一名，第二是第二名。如果第一名并列两个，就不存在第二名（平常的排名。但不按学号） 

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
		int n = 0;//放在外面可以记录多少个数 
		while(scanf("%d %d", &snum, &score ) != EOF)
		{
			if(!snum && !score)	break;
			s[n].snum = snum;
			s[n].score = score;
			n++;
		}
		
		//按分数从大到小排序s 
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
