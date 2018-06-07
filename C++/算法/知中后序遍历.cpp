/*
	˼·�ܽ᣺
		*ʹ�÷��η�����--------�Ӵ����ֳ����������������ɴ��� 
		 	*ÿ�η��ζ��ñ�֤����������Ԫ��һ��------------ÿ�ζ���ĳ���������к������ 
		 	 
		 	������ָ�-----------�ֳ��������� 
		 		*�������lastԪ��Ϊroot 
	 			������� ��*֪��root��������������з���������
				������� ��
							*������len = ����������Ҷ��� - ����� - 1 
							*������len = ��ߵĵ������ 
*/						
#include<cstdio>
#include<iostream>
#include<queue> 
#define MAXV 256

using namespace std;

struct Node
{
	int date;	
	Node *rchild, *lchild;
	
	Node(int key)
	{
		date = key;
		lchild = rchild = NULL;
	}
	
	Node()
	{
		lchild = rchild = NULL;
	}
	
	
};


int post_order[MAXV], in_order[MAXV];


//������������ҵ����ڵ�λ�� 
int find_root(int root, int L, int R)
{
	for(int i = L; i <= R; i++)
	{
		if(in_order[i] == root)
		{
			return i;
		} 
	} 
		
}

//��post����ֶ�, ����post_inder���ҵ���һ��root��λ��(Ҳ������root�Ķ���) 
int cur_lchild(int Rp, int Li, int Ri)
{
	//���������� 
	int len = Ri - Li + 1;
	
	//������λ�� 
	return Rp - len;
	
}

//���εݹ齨�� ,�豣��in_order��post_order������Ľڵ���ͬ 
Node* create_tree(int Lp, int Rp, int Li, int Ri)
{
	//�ȷ��γ�һ�����Ľڵ㣬�ٺ��������� 
	if(Lp > Rp || Li > Ri)
		return NULL;
	
	//��post_order���һ���ڵ��root 
	Node *root = new Node(post_order[Rp]);
	
	/*
	 
		��in_order����ֶγ���������
		
		���ݸ��ڵ����ұ߷ּ��� 
	*/
	int inRoot = find_root(root->date, Li, Ri);
	
	/*
		��post_order���飬�ֶγ���������
		 
		�Ҷ���Ϊ�����ڵ� - 1 
		�����Ϊ���Ҷ��� - ���������� 
	*/ 
	
	int postLchild = cur_lchild(Rp, inRoot, Ri); 
	
	//post��Ҷ���Ϊroot - 1�������Ϊ�Ҷ��Ӽ����������� 
	root->lchild = create_tree(Lp, postLchild, Li, inRoot - 1); 
	
	root->rchild = create_tree(postLchild + 1, Rp - 1, inRoot + 1, Ri); 
	
	return root;
	
}

//��������
void bfs(Node* root)
{
	queue<Node*> q;
	
	q.push(root);
	cout << root->date;
	
	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		
		if(temp->lchild != NULL)
		{
			cout << " "  << temp->lchild->date;
			q.push(temp->lchild);
		}
		
		if(temp->rchild != NULL)
		{
			cout << " "  << temp->rchild->date;
			q.push(temp->rchild);
		}

	} 
	
	cout << endl;
}



int main()
{
	int n;
	
	freopen("���к������.in", "r", stdin);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{	
		cin >>	in_order[i];
	}
	
	for(int i = 0; i < n; i++)
	{	
		cin >>	post_order[i];
	}
	
	Node *root = create_tree(0, n-1, 0, n-1);
	
	bfs(root);
	//�˳���Ƚ϶̣���˾Ͳ�ɾ���ڵ��� 
	
	return 0;
}
