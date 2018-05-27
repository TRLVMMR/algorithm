#include<stdio.h>
#include<string.h>

typedef int State[9];//����״̬

const int maxstate  = 1000000;
State st[maxstate],goal;//st���·����״̬��goalΪĿ������
int dirt[maxstate];//dirtΪ��������

const int hashstate = 1000019;
int head_hash[hashstate],next_hash[maxstate];

//���巽������,	   ��,��,��, �ҡ�x��yΪ����
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void Init_hash()
{
	memset(head_hash, 0, sizeof(head_hash) ); 
	memset(next_hash, 0, sizeof(next_hash) );
	
}

//����״̬�� ����״̬�ĳ�9λ������������ͷ�ڵ�Ĺ�ϣֵ 
int change_hash(State& s)
{
	int sum = 0;
	for(int i = 0; i < 9; i++)
		sum = sum * 10 + s[i];
			
	return sum % hashstate;
}

//�����ϣ���������ͻ�ķ��������ǹ���������� + ��̬���� 
bool insert_hash(int s)
{
	int h, u;
	h = change_hash(st[s]);
	u = head_hash[h];
	
	while(u)
	{
		if(memcmp(st[u],st[s],sizeof(st[s]) ) == 0 )
			return false;
		u = next_hash[u];
	}
	
	next_hash[s] = head_hash[h];
	head_hash[h] = s;
	return true;
	//�����ͷû�в���� ,��s���� 
/*	if(!u)
	{	
		head_hash[h] = s;
		return true;
	}
	
	//�����ͷ������ˣ�˳�ű�ͷ��ָ��������������� 
	while(u)
	{
		//�Ƚ�s��u������ҵ���ͬ�ģ���ʾ��ϣ�������У�����ʧ�� 
		if (memcmp(st[s],st[u],sizeof(st[s]) ) == 0)
			return false;
		//���û�ҵ��������� 
		u = next_hash[u];		
	}
	//�����ϣ����û�����ֵ ������ɹ� 
	 head_hash[u] = s;	
	return true;*/
}

int bfs()
{
	int head,tail;



	Init_hash();//��ʼ����ϣ�� 
	head = 1;
	tail = 2;
	
	while(head < tail)
	{
		State& s = st[head];
		//����ҵ�Ŀ��״̬������
		if ( memcmp(goal, s, sizeof(s) ) == 0)
			return head;
		//���û���ҵ�Ŀ��״̬����ö�ٸ����߷�
		//�ҵ��ո��λ�ã����ո�Ϊ0��
		int x, y, z;
		for(z = 0; z < 9; z++)	if(!s[z]) break;
		x = z / 3;
		y = z % 3;
		
		//ö�ٸ�������߷�
		for(int d = 0; d < 4; d++)
		{
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			//����߷����ϸ�����
			if(newx >= 3 || newx < 0 || newy >= 3 || newy < 0)
					continue;
			
				State& t = st[tail];
				//����߷��ϸ񣬴��������ϸ��״̬�ռ�
				memcpy(&t, &s, sizeof(s));
	
				//���ո������ߵĸ��ӽ�����ʾ����һ��
				t[newz] = s[z];
				t[z] = s[newz];
	
				dirt[tail] = dirt[head] + 1;
				if( insert_hash(tail) )
					tail++;
			
		}
		head++;
	}
	
	return 0;
}


int main()
{
	freopen("������.in","r",stdin);
	//�����ʼ��״̬ 
	for(int i = 0; i < 9; i++)
		scanf("%d",&st[1][i]);
		
	
	
	for(int i = 0; i < 9; i++)
		scanf("%d",&goal[i]);
		
	
	int ans = bfs();
	
	if(ans > 0)
		printf("%d\n",dirt[ans]);
	else
		printf("-1\n");
		
	return 0;
}
