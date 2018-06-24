#include <stdio.h>
#include <tchar.h>
#include <string.h>

#include <stdlib.h>

typedef struct
{
	   int year; 
	   int month; 
} Date;
typedef struct
{
	float gui;            //��������۳ɼ�
	float mat;            //�ߵ���ѧ�ɼ�
	float eng;            //Ӣ��ɼ�
	float Cla;            //C���Գɼ�
	float ave;            //ƽ���ɼ�
} Score;
typedef struct
{
	int num; 
    char name[20];     
    char sex[3];	
	Date birthday;       //ѧ����������
	Score sco;           //�ɼ���ƽ���ɼ�	         
} Student;

#define N 40                                         //����ѧ������
//ȫ��{�ⲿ}��������
extern int Count;                                    //��¼���ѧ������
extern Student StuInf[N];                            //ѧ����Ϣ�ṹ������

void PrintAll(char *

s);
void SaveDate(char *s);//����ѧ����Ϣ���ݵ��ļ���sΪ�ļ����ַ���
void ReadDate(char *s); //��ѧ����Ϣ�����ļ���sΪ�ļ���
void InputDate(char *s); // �������ݣ���ͨ������1��2���С��½�����׷�ӡ����ݿ�
void Browse(char *s); ////���ȫ�����С�Ů���ɼ����񡢲�����ȵ�ѧ����Ϣ
void Sort(char *s); // /��ƽ���ɼ��ɴ�С����
void Search( char *s); // ������ѯ
void ChangeInfo(char *s, int index);//�����޸Ķ�Ӧѧ������Ϣ 
void SortPart(char *s);

void InfSta(char *s);//�������1��2��3�ֱ��Ա𡢳����ꡢƽ���ɼ�ͳ��ѧ������

void vote(char *s);//ѡ�ٺ�����ÿ��ͶƱ��ƽ������ߵ�5�� 

int Count;
Student StuInf[N]; 

void SaveDate(char *s)//����ѧ����Ϣ���ݵ��ļ���sΪ�ļ����ַ���
{
	FILE *fp;
	int i;
	if((fp=fopen(s,"wb"))==NULL)      
	{
		printf("cannot open file\n");
		exit(0);
	}
	fwrite(&Count, sizeof(int),1,fp); //�ȱ���Count����Ϊ����ʱͳ�Ƶļ�¼�ĸ���
	for(i=0;i<Count;i++)              //�ٱ���ѧ����Ϣ��¼
		fwrite(&StuInf[i], sizeof(Student),1,fp);   
	fclose(fp);
}
void ReadDate(char *s)//��ѧ����Ϣ�����ļ���sΪ�ļ���
{
	FILE *fp;
	int i;
	if((fp=fopen(s,"rb"))==NULL)      
	{
		printf("cannot open file\n");
		exit(0);
	}
	fread(&Count, sizeof(int),1,fp);  //�ȶ���¼�ĸ���
	for(i=0;i<Count;i++)              //�ٶ�ѧ����Ϣ��¼
		fread(&StuInf[i], sizeof(Student),1,fp);  
	fclose(fp);
}
void InputDate(char *s) // �������ݣ���ͨ������1��2���С��½�����׷�ӡ����ݿ�
{
	int m;
	Student *p;
	printf("����1���½����ݿ�           ����2��׷�����ݿ�\n");
	scanf("%d",&m);
		while(m!=1 && m!=2){
		printf("��������ݲ���1��2������������\n");
		scanf("%d",&m);
	}
	switch(m)
	{
	case 1:
		Count=0;
		break;
	case 2:
		ReadDate(s);
		if(Count>=N){
			printf("��������������׷�ӣ�\n");
			return;
		}
		break;
	}
	for(p=StuInf+Count; p<StuInf+N; p++){   //�½���׷������
		printf("�������%d��ѧ����Ϣ: ѧ�š��������Ա𡢳����ꡢ������\n",Count+1);
		scanf("%d%s%s%d%d",&p->num,p->name,p->sex,&p->birthday.year,&p->birthday.month);
		printf("�������%d��ѧ����������ۡ��ߵ���ѧ��Ӣ�C���Գɼ�\n",Count+1);
		scanf("%f%f%f%f",&p->sco.gui,&p->sco.mat,&p->sco.eng,&p->sco.Cla);
		p->sco.ave=(p->sco.gui+p->sco.mat+p->sco.eng+p->sco.Cla)/4.0;	
		Count++;
		getchar();
		printf("���롰c������\n");	
		if(getchar()!='c')
			break;
	}
	char c;
	printf("�����ļ�����%s�����Ƿ������\n���롰y��������\t\t�����䰴��������\n",s);
	c=getchar();
	getchar();
	if(c=='y'){
		char *nfilename;
		puts("���������ļ���:");
		gets(nfilename);
		SaveDate(nfilename);
	}
	else
		SaveDate(s);
}
void Browse(char *s) //���ȫ�����С�Ů���ɼ����񡢲�����ȵ�ѧ����Ϣ
{
	printf("����    �Ա�    ���������    �ߵ���ѧ     Ӣ��     C����\n");
	ReadDate(s);
	
	for(int i = 0; i < Count; i++)
	{
		printf("%s", StuInf[i].name);
		printf("     %s", StuInf[i].sex);
		if(StuInf[i].sco.gui < 60)  printf("      ������"); else printf("         ����");
		if(StuInf[i].sco.mat < 60)  printf("      ������"); else printf("         ����");
		if(StuInf[i].sco.eng < 60)  printf("    ������"); else printf("      ����");
		if(StuInf[i].sco.Cla < 60)  printf("    ������"); else printf("      ����");
		printf("\n");
				 
		if(i % 10 == 0 && i != 0)
		{
			printf("����ո���ʾ��һҳ, ��������������������ʾ\n");
			if(' ' != getchar())
				break;	
		} 
	}


} 

void SortPart(char *s)
{
	ReadDate(s);
	Student temp;   
	int i,j,k;
	for(i=0;i<Count-1;i++)
	{ 
		k=i;
		for(j=i+1;j<Count;j++)
			if(StuInf[j].sco.ave>StuInf[k].sco.ave) 
				k=j;
		temp=StuInf[k];
		StuInf[k]=StuInf[i];  
		StuInf[i]=temp;   
   }
}

void Sort(char *s) // ��ѡ�����򷨰�ƽ���ɼ��ɴ�С����
{
	ReadDate(s);
	Student temp;   
	int i,j,k;
	for(i=0;i<Count-1;i++)
	{ 
		k=i;
		for(j=i+1;j<Count;j++)
			if(StuInf[j].sco.ave>StuInf[k].sco.ave) 
				k=j;
		temp=StuInf[k];
		StuInf[k]=StuInf[i];  
		StuInf[i]=temp;   
   }
	PrintAll(s);
	int m;
	printf("�Ƿ񱣴�����������ݣ� ����1�����浽�����ļ�       ����2�����Ϊ����ļ�        ����3����\n");	
	scanf("%d",&m);
	if(m==1)
		SaveDate(s);
	else if(m==2){
		char filename[20];
		printf("�����ļ�����%s,���������µ��ļ���:",s);
		getchar();
		gets(filename);
		SaveDate(filename);
	}
	else
		return;
}


void ChangeInfo(char *s, int index)
{
	printf("��������Ҫ�޸ĵ����ݶ�Ӧ���\n");
	printf("1--ѧ�ţ� 2--���֣� 3--���գ� 4--�Ա�, 5--�ɼ�, ��������--��Ч\n");
	int oper;
	scanf("%d", &oper); 
	switch(oper)
	{
		case 1:
			printf("������ѧ��\n");
			scanf("%d", &StuInf[index].num); 
			break;
		case 2:
			printf("����������\n");
			scanf("%s", &StuInf[index].name); 
			break;
		case 3:
			printf("���������յ�����\n");
			scanf("%d %d", &StuInf[index].birthday.year, &StuInf[index].birthday.month); 
			break;
		case 4:
			printf("�������Ա�\n"); 
			scanf("%s", &StuInf[index].sex);
			break;
		case 5:
			int soper, score;
			printf("���������ĿƳɼ�, 1--���ۣ� 2--������ 3--Ӣ� 4--C����\n");
			scanf("%d ", &soper);
			printf("������ɼ�\n");
			scanf("%d", &score);
			
			if(soper == 1) StuInf[index].sco.gui = score;
			else if(soper == 2) StuInf[index].sco.mat = score;
			else if(soper == 3)	StuInf[index].sco.eng = score;
			else if(soper == 4)	StuInf[index].sco.Cla = score;
				
			break;
		
	}
	SaveDate(s);
}


void Search (char *s) // ������ѯ
{
	int num;
	printf("����Ҫ����ѧ����ѧ��\n");
	scanf("%d", &num);
	
	for(int i = 0; i < Count; i++)
	{
		if(num == StuInf[i].num)
		{
			ChangeInfo(s, i);
			return;	
		}		
	}
	printf("û�����ѧ�ŵ�ѧ��\n");

}


void InfSta(char *s)// �������1��2��3�ֱ��Ա𡢳����ꡢƽ���ɼ�ͳ��ѧ������
{
	SortPart(s);
	ReadDate(s);
	
	int oper;
	printf("ͳ�����ݣ�\n");
	printf("����1�������Ů������2�������꣬ 3��������\n");
	while(scanf("%d", &oper))
	{
		
		if(oper == 1)
		{
			int man = 0;
			for(int i = 0; i < Count; i++)
			{
				if(strcmp(StuInf[i].sex,"��") == 0)
					man++;
			}
			
			printf("��ѧ����%d�ˣ� Ůѧ����%d��\n", man, Count - man); 
			break;
		}
		
		else if(oper == 2)
		{
			int max = -1, min = 0xffffff;
			for(int i = 0; i < Count; i++)
			{
				int temp = StuInf[i].birthday.year;
				if(temp > max)	max = temp;
				if(temp < min)	min = temp;
			}
			
			for(int year = min; year <= max; year++)
			{
				int num = 0;
				for(int i = 0; i < Count; i++)
				{
					if(StuInf[i].birthday.year == year)
						num++;
				}
				
				if(num != 0)
					printf("%d�������%d��\n", year, num);
			}
			
			break;
		}
		
		else if(oper == 3)
		{
			int pass = -1;
			for(int i = 0; i < Count; i++)
			{
				if(StuInf[i].sco.ave < 60)
					pass = i;
			}
			
			if(pass == -1)
				printf("��������Ϊ%d, ������Ϊ100%%\n", Count);
			else
				printf("��������Ϊ%d, ������Ϊ%2.f%%\n", pass, (1.0 * pass / Count) * 100);
			break;
		}
		
		else
		{
			printf("����ȷ����1,2,3����Ӧ����\n");
		}
	}	
	
}


void vote(char *s)
{
	//�˺�����ȱ�������ͬ����������˿��ֲܷ�����˭������д�� 
	SortPart(s);
	ReadDate(s);
	int result[5] = {0};
	
	for(int i = 0; i < 5; i++)
	{
		printf("%d��: %s\n", i, StuInf[i].name);
	} 
	
	for(int i = 5; i < Count; i++)
	{
		int num;
		printf("%sͶ����: ", StuInf[i].name);
		scanf("%d", num); 
		result[num]++; 
	}
	
	int max = -1;
	int maxi = -1;
	
	for(int i = 0; i < 5; i++)
	{
		if(result[i] > max)
		{
			max = result[i];
			maxi = i;
		}
	}
	
	printf("����ѡ��Ϊѧ����ɲ�����: %s", StuInf[maxi].name);
	
}

void fun(void (*f)(char *s))
{
	char name[N];
	
	printf("���������ݿ����ƣ�");
	scanf("%s", name);
	
	return (*f)(name);
}

void MyMenu()
{
	do
	{
		printf("1---�½����ݿ�    2------׷�����ݿ�     3---�޸����ݿ�\n");
		printf("4---������ݿ�    5------��������       6---ͳ������\n");
		printf("7---ͶƱѡ��\n");
		int oper;
		scanf("%d", &oper);
		
		switch(oper)
		{
			//�����и�����Ҫ��������һ�Σ����Ǹ���ʦ�Ĵ��� 
			case 1:
			case 2:
				fun(InputDate);
				break;
			case 3:
				printf("�޸����ݿ�\n");
				fun(Search); 
			case 4:
				fun(Browse);
				break;
			case 5:
				fun(Search); 
				break;
			case 6:
				fun(InfSta);
				break;
			case 7:
				fun(vote);
				break;
			default: 
				printf("��������ȷ������\n");
				continue;	
		}
		printf("���q�˳�\n");
		getchar();
	}while('q' != getchar());
	
}

void PrintAll(char *s)
{
	
	for(int i = 0; i < Count; i++)
	{
		printf("ѧ�ţ�%d\t", StuInf[i].num);
		printf("������%s\t", StuInf[i].name);
		printf("�Ա�%s\t", StuInf[i].sex);
		printf("\n");
				 
		if(i % 10 == 0 && i != 0)
		{
			printf("����ո���ʾ��һҳ, ��������������������ʾ\n");
			if(' ' != getchar())
				break;	
		} 
	}
	
}

int main()
{
	int i=0;
	char filename[N] = "StuInf.dat";


	Sort(filename);
	MyMenu(); 
	

	return 0;
}


