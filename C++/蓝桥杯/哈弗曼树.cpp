#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

//开玩笑开玩笑，就计算 
int tree_build()
{
	int sum = 0;
	while(q.size() > 1)
	{
		int top1 = q.top();
		q.pop();
		int top2 = q.top();
		q.pop();
		
		q.push(top1+ top2);
		
		sum = top1 + top2 + sum;
	}
	
	return sum;
}

int main()
{
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int temp;
		
		cin >> temp;
		q.push(temp);
		
	}
	
	cout << tree_build() << endl;
	
	return 0;
}
