#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n,m,i,j,x,y;
	vector<int> a[50];

	scanf("%d %d",&n,&m);

	for(i = 0; i < m; i++)
	{
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < a[i].size(); j++)
		{
			printf("%d ",*(a[i].begin()+j));	
		
		}
	
	}
	
	getchar();

	return 0;
}