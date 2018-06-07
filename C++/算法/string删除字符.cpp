/*
	string对象可以像char数组那样使用
	甚至可以，将char赋值给string对象，但是不能是初始化，因为没有字符的构造函数
	 
	 插入用insert(pos, string) 
	 （不重要）一般写代码时，不需要定义构造器iterato，只需用begin跟end加减就行
	 上面一行不用看，其实用到构造器的，只需要用数字传入就行 
	 find（str，pos）函数查找子串，失败时返回string:npos 值为 -1
	 
	 替换用replace(pos, len, str)； 
	 删除用erase(pos, len) 

*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1;
	string str2;
	
	getline(cin, str1);
	getline(cin, str2);
	
	
	int len = str2.size();
	for(int i = 0; i < len; i++)
	{
		string temp;
		temp = str2[i];
		
		str1.erase(str1.find(temp), 1);
	}
	
	
	
	cout << str1 << endl;
	
	
	return 0;
}
