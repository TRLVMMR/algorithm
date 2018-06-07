/*
	思路总结：
		*使用分治法建树--------从大树分成子树，从子树建成大树 
		 	*每次分治都得保证两个数组里元素一样------------每次都是某颗子树的中后序遍历 
		 	 
		 	将数组分割-----------分出左右子树 
		 		*后序遍历last元素为root 
	 			中序分治 ：*知道root，就在中序遍历中分左右子树
				后序分治 ：
							*右子树len = 后序遍历中右儿子 - 左儿子 - 1 
							*左子树len = 左边的到左儿子 
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


//在中序遍历中找到根节点位置 
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

//将post数组分段, 即在post_inder中找到下一个root的位置(也即现在root的儿子) 
int cur_lchild(int Rp, int Li, int Ri)
{
	//右子树长度 
	int len = Ri - Li + 1;
	
	//左子树位置 
	return Rp - len;
	
}

//分治递归建树 ,需保持in_order与post_order数组里的节点相同 
Node* create_tree(int Lp, int Rp, int Li, int Ri)
{
	//先分治成一个个的节点，再合起来建树 
	if(Lp > Rp || Li > Ri)
		return NULL;
	
	//把post_order最后一个节点给root 
	Node *root = new Node(post_order[Rp]);
	
	/*
	 
		将in_order数组分段成左右子树
		
		根据根节点左右边分即可 
	*/
	int inRoot = find_root(root->date, Li, Ri);
	
	/*
		将post_order数组，分段成左右子树
		 
		右儿子为：根节点 - 1 
		左儿子为：右儿子 - 右子树长度 
	*/ 
	
	int postLchild = cur_lchild(Rp, inRoot, Ri); 
	
	//post里，右儿子为root - 1，左儿子为右儿子减右子树长度 
	root->lchild = create_tree(Lp, postLchild, Li, inRoot - 1); 
	
	root->rchild = create_tree(postLchild + 1, Rp - 1, inRoot + 1, Ri); 
	
	return root;
	
}

//层续遍历
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
	
	freopen("树中后序遍历.in", "r", stdin);
	
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
	//此程序比较短，因此就不删除节点了 
	
	return 0;
}
