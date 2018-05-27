#include<stdio.h>
#include<stdlib.h>

typedef struct Note
{
	int height,date;
	Note *lchild,*rchild;

}BFtree,*pBFtree;

void updateHeight(pBFtree root);
int getBalanceFactor(pBFtree p);
void L(pBFtree &root);
void R(pBFtree &root);

int max(int x ,int y)
{
	if(x > y)
		return x;
	else
		return y;

}

//创建新节点
pBFtree NewNote(int key)
{
	pBFtree p;

	p = (pBFtree)malloc(sizeof(BFtree));
	p->date  = key;
	p->height = 1;
	p->lchild = p->rchild = NULL;

		return p;
}

//插入结点到平衡二叉树
void insert(pBFtree &p,int key)
{
	if(!p)//如果p为空
	{
		p = NewNote(key);
		return;
	}
	if(key < p->date)
	{
		insert(p->lchild,key);
		updateHeight(p);
		if(2 == getBalanceFactor(p))//平衡因子为2（大于1的绝对值），则进行旋转，使平衡因子变为0
		{
			//左旋左增高，右旋右增高
			if(1 == getBalanceFactor(p->lchild))//LL型
				R(p);
			else if(-1 == getBalanceFactor(p->lchild))//LR型
			{
				L(p->lchild);
				R(p);
			}
		
		}



	}
	else
	{
		insert(p->rchild,key);
		updateHeight(p);
		if(-2 == getBalanceFactor(p))//平衡因子为-2，则进行旋转，使平衡因子变为0
		{
			if(-1 == getBalanceFactor(p->rchild))//RR型
				L(p);
			else if(1 == getBalanceFactor(p->rchild))//RL型
			{
				R(p->rchild);
				L(p);
			}
		
		}
		
	
	
	
	}
		

	return;
}

//获取节点高度
int getHeight(pBFtree p)
{
	if(!p)
		return 0;
	else
		return p->height;

}

//获取平衡因子
int getBalanceFactor(pBFtree p)
{
	
	return getHeight(p->lchild)-getHeight(p->rchild);
}

//更新树高度:比最大的儿子高1
void updateHeight(pBFtree root)
{
	root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
	
}

//创建平衡二叉树
pBFtree Create(int *date,int n)
{
	int i;
	pBFtree p = NULL;
	
	for(i=0; i < n; i++)
		insert(p,date[i]);
	
	return p;
}

//搜索
pBFtree Tsearch(pBFtree p,int key)
{
	
	if(!p)
		return NULL;

	if(key == p->date)
		return p;
	
	else if(key > p->date)
		p = Tsearch(p->rchild,key);
	else
		p = Tsearch(p->lchild,key);

		return p;
}


/*
一开始B为A的右子树
左旋操作:
1.让B的左子树成为A的右子树
2.让A成为B的左子树
3.将根节点设置为B
主要结果：右儿子变成根节点（即右边深度-1，左边深度再+1，差距少了2）
*/

void L(pBFtree &root)//根节点为A，由root指向
{
	pBFtree temp = root->rchild;//temp指向B
	root->rchild = temp->lchild;//步骤1

	temp->lchild = root;//步骤2
	//更新高度
	updateHeight(root);
	updateHeight(temp);

	root = temp;//步骤3

}

/*
	一开始A为B的左子树
	右旋操作：
	1.让A的右子树成为B的左子树
	2.让B成为A的右子树
	3.将根节点设置为A
主要结果：左儿子变成根节点（即左边深度-1，右边深度再+1，差距少了2）
 */
void R(pBFtree &root)
{
	pBFtree temp = root->lchild;//root指向B，temp指向A
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	
	root = temp;

}

void inorder(pBFtree root)
{
	if(!root)//达到空树递归返回
		return;
	inorder(root->lchild);
		printf("%d	",root->date);
	inorder(root->rchild);
	//	printf("%d	",root->date);

}

int main()
{
	int date[256] = {0};
	int i = 0,n = -1,key;
	pBFtree T,q;

	printf("请输入你想插入到二叉查找树中的数\n");
	do
	{
		scanf("%d",&date[i]);
		i++;
		n++;
	}while('p' != getchar());

	q = Create(date,n);	

	inorder(q);

	printf("请输入要查找的节点的值\n");
	scanf("%d",&key);
	T = Tsearch(q,key);
	if(!T)
		printf("%d\n",T->date);

	return 0;
}