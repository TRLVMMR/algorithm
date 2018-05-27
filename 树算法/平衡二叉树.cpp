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

//�����½ڵ�
pBFtree NewNote(int key)
{
	pBFtree p;

	p = (pBFtree)malloc(sizeof(BFtree));
	p->date  = key;
	p->height = 1;
	p->lchild = p->rchild = NULL;

		return p;
}

//�����㵽ƽ�������
void insert(pBFtree &p,int key)
{
	if(!p)//���pΪ��
	{
		p = NewNote(key);
		return;
	}
	if(key < p->date)
	{
		insert(p->lchild,key);
		updateHeight(p);
		if(2 == getBalanceFactor(p))//ƽ������Ϊ2������1�ľ���ֵ�����������ת��ʹƽ�����ӱ�Ϊ0
		{
			//���������ߣ�����������
			if(1 == getBalanceFactor(p->lchild))//LL��
				R(p);
			else if(-1 == getBalanceFactor(p->lchild))//LR��
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
		if(-2 == getBalanceFactor(p))//ƽ������Ϊ-2���������ת��ʹƽ�����ӱ�Ϊ0
		{
			if(-1 == getBalanceFactor(p->rchild))//RR��
				L(p);
			else if(1 == getBalanceFactor(p->rchild))//RL��
			{
				R(p->rchild);
				L(p);
			}
		
		}
		
	
	
	
	}
		

	return;
}

//��ȡ�ڵ�߶�
int getHeight(pBFtree p)
{
	if(!p)
		return 0;
	else
		return p->height;

}

//��ȡƽ������
int getBalanceFactor(pBFtree p)
{
	
	return getHeight(p->lchild)-getHeight(p->rchild);
}

//�������߶�:�����Ķ��Ӹ�1
void updateHeight(pBFtree root)
{
	root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
	
}

//����ƽ�������
pBFtree Create(int *date,int n)
{
	int i;
	pBFtree p = NULL;
	
	for(i=0; i < n; i++)
		insert(p,date[i]);
	
	return p;
}

//����
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
һ��ʼBΪA��������
��������:
1.��B����������ΪA��������
2.��A��ΪB��������
3.�����ڵ�����ΪB
��Ҫ������Ҷ��ӱ�ɸ��ڵ㣨���ұ����-1����������+1���������2��
*/

void L(pBFtree &root)//���ڵ�ΪA����rootָ��
{
	pBFtree temp = root->rchild;//tempָ��B
	root->rchild = temp->lchild;//����1

	temp->lchild = root;//����2
	//���¸߶�
	updateHeight(root);
	updateHeight(temp);

	root = temp;//����3

}

/*
	һ��ʼAΪB��������
	����������
	1.��A����������ΪB��������
	2.��B��ΪA��������
	3.�����ڵ�����ΪA
��Ҫ���������ӱ�ɸ��ڵ㣨��������-1���ұ������+1���������2��
 */
void R(pBFtree &root)
{
	pBFtree temp = root->lchild;//rootָ��B��tempָ��A
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	
	root = temp;

}

void inorder(pBFtree root)
{
	if(!root)//�ﵽ�����ݹ鷵��
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

	printf("������������뵽����������е���\n");
	do
	{
		scanf("%d",&date[i]);
		i++;
		n++;
	}while('p' != getchar());

	q = Create(date,n);	

	inorder(q);

	printf("������Ҫ���ҵĽڵ��ֵ\n");
	scanf("%d",&key);
	T = Tsearch(q,key);
	if(!T)
		printf("%d\n",T->date);

	return 0;
}