#include<stdio.h>
#include<stdlib.h>



typedef struct TreeNote
{
	int date;
	TreeNote *lchild,*rchild;

}BITNote,*BITTree;

void DeleteNote(BITTree &T);

void insert(BITTree &T,int date)//�ҵ����ʵ�λ�ò��룬&Ϊ���÷��ţ���ֱ���޸�Tԭ������child��ֵ
{

	if(!T)//�������ǿյ�,�������
	{
		T = (BITTree)malloc(sizeof(BITNote));
		T->date = date;
		T->lchild = T->rchild = NULL;

		return;
	}
	if(date == T->date)
		return;

	else if(date < T->date)//������ݱȽ��С�����������������ҿյ�λ��
		insert(T->lchild,date);
	else
		insert(T->rchild,date);
//��Ȳ������κβ���
	return;
}

//����������Ľ���,��������
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

//����������Ĳ���
BITTree search(BITTree root,int key)
{
	static BITTree p = NULL;
		 

	if(!root)//����(���)�ǿյ�
		return NULL;
	
	if(key == root->date)//�ҵ��򷵻ؽ��ָ��
		return root;

	else if(key < root->date)
		root = search(root->lchild,key);
		
	else
		root = search(root->rchild,key);
		
	return root;
}

void BSTdelete(BITTree &p,int key)
{
	if(!p)//�ս���򷵻�
		return;

	if(key == p->date)
		DeleteNote(p);

	else if (key > p->date)
		BSTdelete(p->rchild,key);
	else
		BSTdelete(p->lchild,key);

	return;
}


//��������ɾ��
void DeleteNote(BITTree &T)
{
	BITTree q,s;

	if(!T->lchild)//�����Ҷ�ӽ����������Ϊ��,���ҽڵ����ȥ
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
	else//��������������У��ҵ�ǰ�������������ģ�,���뵽ɾ��λ��
	{
		q = T;
		s = T->lchild;

		while(NULL != s->rchild)
		{
			q = s;
			s = s->rchild;
		
		}

		T->date = s->date;
		
		if(q != T)//�п���Tֻ��һ������ӣ���ʱq��T��ͷ��βָ��Ķ���ͬһ��
		{
			q->rchild = s->lchild;//ɾ��������߽ӵ����׵��ұߣ��Լ���λ�ã�
		}
		else
			q->lchild = s->lchild;

		free(s);
	}
	
}

void inorder(BITTree root)
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
	BITTree T,q,*p;

	printf("������������뵽����������е���\n");
	do
	{
		scanf("%d",&date[i]);
		i++;
		n++;
	}while('p' != getchar());

	q = Create(date,n);	
	
	

	printf("��������Ҫɾ������Ȩֵ\n");
	scanf("%d",&key);
	
	
	if(NULL != search(q,key))
		BSTdelete(q,key);

	else
		printf("û�������\n");

	if(NULL != q)
		inorder(q);
	
	printf("\n");
	getchar();
	getchar();
	return 0;
}
