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
	float gui;            //计算机导论成绩
	float mat;            //高等数学成绩
	float eng;            //英语成绩
	float Cla;            //C语言成绩
	float ave;            //平均成绩
} Score;
typedef struct
{
	int num; 
    char name[20];     
    char sex[3];	
	Date birthday;       //学生出生日期
	Score sco;           //成绩与平均成绩	         
} Student;

#define N 40                                         //限制学生人数
//全局{外部}变量声明
extern int Count;                                    //已录入的学生人数
extern Student StuInf[N];                            //学生信息结构体数组

void PrintAll(char *

s);
void SaveDate(char *s);//保留学生信息数据到文件，s为文件名字符串
void ReadDate(char *s); //读学生信息数据文件，s为文件名
void InputDate(char *s); // 输入数据，可通过输入1或2进行“新建”或“追加”数据库
void Browse(char *s); ////浏览全部、男、女、成绩及格、不及格等的学生信息
void Sort(char *s); // /按平均成绩由大到小排序
void Search( char *s); // 搜索查询
void ChangeInfo(char *s, int index);//用于修改对应学生的信息 
void SortPart(char *s);

void InfSta(char *s);//输入序号1、2、3分别按性别、出生年、平均成绩统计学生人数

void vote(char *s);//选举函数，每人投票给平均分最高的5人 

int Count;
Student StuInf[N]; 

void SaveDate(char *s)//保留学生信息数据到文件，s为文件名字符串
{
	FILE *fp;
	int i;
	if((fp=fopen(s,"wb"))==NULL)      
	{
		printf("cannot open file\n");
		exit(0);
	}
	fwrite(&Count, sizeof(int),1,fp); //先保存Count，它为输入时统计的记录的个数
	for(i=0;i<Count;i++)              //再保存学生信息记录
		fwrite(&StuInf[i], sizeof(Student),1,fp);   
	fclose(fp);
}
void ReadDate(char *s)//读学生信息数据文件，s为文件名
{
	FILE *fp;
	int i;
	if((fp=fopen(s,"rb"))==NULL)      
	{
		printf("cannot open file\n");
		exit(0);
	}
	fread(&Count, sizeof(int),1,fp);  //先读记录的个数
	for(i=0;i<Count;i++)              //再读学生信息记录
		fread(&StuInf[i], sizeof(Student),1,fp);  
	fclose(fp);
}
void InputDate(char *s) // 输入数据，可通过输入1或2进行“新建”或“追加”数据库
{
	int m;
	Student *p;
	printf("输入1：新建数据库           输入2：追加数据库\n");
	scanf("%d",&m);
		while(m!=1 && m!=2){
		printf("输入的数据不是1或2，请重新输入\n");
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
			printf("数据已满，不能追加！\n");
			return;
		}
		break;
	}
	for(p=StuInf+Count; p<StuInf+N; p++){   //新建或追加数据
		printf("请输入第%d个学生信息: 学号、姓名、性别、出生年、出生月\n",Count+1);
		scanf("%d%s%s%d%d",&p->num,p->name,p->sex,&p->birthday.year,&p->birthday.month);
		printf("请输入第%d个学生计算机导论、高等数学、英语、C语言成绩\n",Count+1);
		scanf("%f%f%f%f",&p->sco.gui,&p->sco.mat,&p->sco.eng,&p->sco.Cla);
		p->sco.ave=(p->sco.gui+p->sco.mat+p->sco.eng+p->sco.Cla)/4.0;	
		Count++;
		getchar();
		printf("输入“c”继续\n");	
		if(getchar()!='c')
			break;
	}
	char c;
	printf("现有文件名”%s“，是否更名？\n输入“y”：更名\t\t否则输按其它键！\n",s);
	c=getchar();
	getchar();
	if(c=='y'){
		char *nfilename;
		puts("请输入新文件名:");
		gets(nfilename);
		SaveDate(nfilename);
	}
	else
		SaveDate(s);
}
void Browse(char *s) //浏览全部、男、女、成绩及格、不及格等的学生信息
{
	printf("姓名    性别    计算机导论    高等数学     英语     C语言\n");
	ReadDate(s);
	
	for(int i = 0; i < Count; i++)
	{
		printf("%s", StuInf[i].name);
		printf("     %s", StuInf[i].sex);
		if(StuInf[i].sco.gui < 60)  printf("      不及格"); else printf("         及格");
		if(StuInf[i].sco.mat < 60)  printf("      不及格"); else printf("         及格");
		if(StuInf[i].sco.eng < 60)  printf("    不及格"); else printf("      及格");
		if(StuInf[i].sco.Cla < 60)  printf("    不及格"); else printf("      及格");
		printf("\n");
				 
		if(i % 10 == 0 && i != 0)
		{
			printf("输入空格显示下一页, 键入其他建其他结束显示\n");
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

void Sort(char *s) // 用选择排序法按平均成绩由大到小排序
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
	printf("是否保存已排序的数据？ 输入1：保存到现有文件       输入2：另存为别的文件        输入3：否\n");	
	scanf("%d",&m);
	if(m==1)
		SaveDate(s);
	else if(m==2){
		char filename[20];
		printf("现有文件名是%s,请已输入新的文件名:",s);
		getchar();
		gets(filename);
		SaveDate(filename);
	}
	else
		return;
}


void ChangeInfo(char *s, int index)
{
	printf("请输入你要修改的内容对应编号\n");
	printf("1--学号， 2--名字， 3--生日， 4--性别, 5--成绩, 其他数字--无效\n");
	int oper;
	scanf("%d", &oper); 
	switch(oper)
	{
		case 1:
			printf("请输入学号\n");
			scanf("%d", &StuInf[index].num); 
			break;
		case 2:
			printf("请输入名字\n");
			scanf("%s", &StuInf[index].name); 
			break;
		case 3:
			printf("请输入生日的年月\n");
			scanf("%d %d", &StuInf[index].birthday.year, &StuInf[index].birthday.month); 
			break;
		case 4:
			printf("请输入性别\n"); 
			scanf("%s", &StuInf[index].sex);
			break;
		case 5:
			int soper, score;
			printf("请输入是哪科成绩, 1--导论， 2--高数， 3--英语， 4--C语言\n");
			scanf("%d ", &soper);
			printf("请输入成绩\n");
			scanf("%d", &score);
			
			if(soper == 1) StuInf[index].sco.gui = score;
			else if(soper == 2) StuInf[index].sco.mat = score;
			else if(soper == 3)	StuInf[index].sco.eng = score;
			else if(soper == 4)	StuInf[index].sco.Cla = score;
				
			break;
		
	}
	SaveDate(s);
}


void Search (char *s) // 搜索查询
{
	int num;
	printf("输入要搜索学生的学号\n");
	scanf("%d", &num);
	
	for(int i = 0; i < Count; i++)
	{
		if(num == StuInf[i].num)
		{
			ChangeInfo(s, i);
			return;	
		}		
	}
	printf("没有这个学号的学生\n");

}


void InfSta(char *s)// 输入序号1、2、3分别按性别、出生年、平均成绩统计学生人数
{
	SortPart(s);
	ReadDate(s);
	
	int oper;
	printf("统计数据：\n");
	printf("键入1：输出男女比例，2：出生年， 3：及格率\n");
	while(scanf("%d", &oper))
	{
		
		if(oper == 1)
		{
			int man = 0;
			for(int i = 0; i < Count; i++)
			{
				if(strcmp(StuInf[i].sex,"男") == 0)
					man++;
			}
			
			printf("男学生有%d人， 女学生有%d人\n", man, Count - man); 
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
					printf("%d年出生有%d人\n", year, num);
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
				printf("及格人数为%d, 及格率为100%%\n", Count);
			else
				printf("及格人数为%d, 及格率为%2.f%%\n", pass, (1.0 * pass / Count) * 100);
			break;
		}
		
		else
		{
			printf("请正确输入1,2,3来对应操作\n");
		}
	}	
	
}


void vote(char *s)
{
	//此函数的缺点是如果同名，输入的人可能分不清是谁。不想写了 
	SortPart(s);
	ReadDate(s);
	int result[5] = {0};
	
	for(int i = 0; i < 5; i++)
	{
		printf("%d号: %s\n", i, StuInf[i].name);
	} 
	
	for(int i = 5; i < Count; i++)
	{
		int num;
		printf("%s投给了: ", StuInf[i].name);
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
	
	printf("最终选举为学生会干部的是: %s", StuInf[maxi].name);
	
}

void fun(void (*f)(char *s))
{
	char name[N];
	
	printf("请输入数据库名称：");
	scanf("%s", name);
	
	return (*f)(name);
}

void MyMenu()
{
	do
	{
		printf("1---新建数据库    2------追加数据库     3---修改数据库\n");
		printf("4---浏览数据库    5------搜索数据       6---统计数据\n");
		printf("7---投票选举\n");
		int oper;
		scanf("%d", &oper);
		
		switch(oper)
		{
			//这里有个问题要重新输入一次，除非改老师的代码 
			case 1:
			case 2:
				fun(InputDate);
				break;
			case 3:
				printf("修改数据库\n");
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
				printf("请输入正确的数字\n");
				continue;	
		}
		printf("输出q退出\n");
		getchar();
	}while('q' != getchar());
	
}

void PrintAll(char *s)
{
	
	for(int i = 0; i < Count; i++)
	{
		printf("学号：%d\t", StuInf[i].num);
		printf("姓名：%s\t", StuInf[i].name);
		printf("性别：%s\t", StuInf[i].sex);
		printf("\n");
				 
		if(i % 10 == 0 && i != 0)
		{
			printf("输入空格显示下一页, 键入其他建其他结束显示\n");
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


