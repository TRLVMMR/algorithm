#include<stdio.h>
#include<stdlib.h>



typedef struct TreeNote
{
	int date;
	TreeNote *lchild,*rchild;

}BITNote,*BITTree;

void DeleteNote(BITTree &T);

void insert(BITTree &T,int date)//找到合适的位置插入，&为引用符号，可直接修改T原变量即child的值
{

	if(!T)//如果结点是空的,则插入结点
	{
		T = (BITTree)malloc(sizeof(BITNote));
		T->date = date;
		T->lchild = T->rchild = NULL;

		return;
	}
	if(date == T->date)
		return;

	else if(date < T->date)//如果数据比结点小，插在左子树合适且空的位置
		insert(T->lchild,date);
	else
		insert(T->rchild,date);
//相等不进行任何操作
	return;
}

//二叉查找树的建立,返回树顶
BITTree Create(int *date,int n)
{
	int i;
	BITTree q;
	
	q = (BITTree)malloc(sizeof(BITNote));
	q->date = date[0];
	q->lchild = q->rchild = NULL;

	for(i =1; i < n; i++)
		insert(q,date[i]);
	
	return q;
}

//二叉查找树的查找
BITTree search(BITTree root,int key)
{
	static BITTree p = NULL;
		 

	if(!root)//若树(结点)是空的
		return NULL;
	
	if(key == root->date)//找到则返回结点指针
		return root;

	else if(key < root->date)
		root = search(root->lchild,key);
		
	else
		root = search(root->rchild,key);
		
	return root;
}

void BSTdelete(BITTree &p,int key)
{
	if(!p)//空结点则返回
		return;

	if(key == p->date)
		DeleteNote(p);

	else if (key > p->date)
		BSTdelete(p->rchild,key);
	else
		BSTdelete(p->lchild,key);

	return;
}


//二叉树的删除
void DeleteNote(BITTree &T)
{
	BITTree q,s;

	if(!T->lchild)//如果是叶子结点且左子树为空,把右节点接上去
	{
		q = T;
		T = T->rchild;
		free(q);
	}
	else if(!T->rchild)
	{
		q = T;
		T = T->lchild;
		free(q);
		
	}
	else//如果左右子树都有，找到前驱（左子树最大的）,插入到删除位置
	{
		q = T;
		s = T->lchild;

		while(NULL != s->rchild)
		{
			q = s;
			s = s->rchild;
		
		}

		T->date = s->date;
		
		if(q != T)//有可能T只有一个左儿子，此时q跟T从头到尾指向的都是同一个
		{
			q->rchild = s->lchild;//删除结点的左边接到父亲的右边（自己的位置）
		}
		else
			q->lchild = s->lchild;

		free(s);
	}
	
}

void inorder(BITTree root)
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
	BITTree T,q,*p;

	printf("请输入你想插入到二叉查找树中的数\n");
	do
	{
		scanf("%d",&date[i]);
		i++;
		n++;
	}while('p' != getchar());

	q = Create(date,n);	
	
	

	printf("请输入你要删除结点的权值\n");
	scanf("%d",&key);
	
	
	if(NULL != search(q,key))
		BSTdelete(q,key);

	else
		printf("没有这个数\n");

	if(NULL != q)
		inorder(q);
	
	printf("\n");
	getchar();
	getchar();
	return 0;
}
