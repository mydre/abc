 算法训练 新生舞会  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　新生舞会开始了。n名新生每人有三个属性：姓名、学号、性别。其中，姓名用长度不超过20的仅由大小写字母构成的字符串表示，学号用长度不超过10的仅由数字构成的字符串表示，性别用一个大写字符‘F’或‘M’表示。任意两人的姓名、学号均互不相同。换言之，每个人可被其姓名或学号唯一确定。给出m对两人的信息（姓名或学号），判断他们是否能共舞。两人能共舞的充要条件为两人性别相异。

输入
　　第一行一个整数n（2<=n<=1000），表示学生人数。接下来的n行每行依次包含一名新生的姓名、学号、性别，分别用一个空格隔开。
　　之后的一行是一个整数m(1<=m<=1000)，表示询问的数目。接着的m行每行包含两个信息（姓名或学号），保证两个信息不属于同一人，中间用一个空格隔开。

输出
　　对于每个询问输出一行，如果两人可以共舞，输出一个大写字母‘Y’，否则输出一个大写字母‘N’。


样例输入
　　4
　　John 10 M
　　Jack 11 M
　　Kate 20 F
　　Jim 21 M
　　3
　　John 11
　　20 Jack
　　Jim Jack


样例输出
　　N
　　Y
　　N
  
/*当使用map的时候，要定义为map<ElemType1,vector<ElemType2> >ma;的形式，以后插入数据的时候，
  应把下标当做key，可以直接push_back，比如mp[elem1].push_back(elem2);
*/  
#include<cstdio>
#include<iostream> 
#include<cstring>
#include<map>
#include<vector> 
using namespace std;  
map<string,vector<char> >ma;
struct Node{
	string name;
	string num;
	char sex;
	Node(){}
	Node(string na,string nu):name(na),num(nu){}
};
int pipei(char a,char b){
	if(a=='F'&&b=='M'||a=='M'&&b=='F') return 1;
	return 0;
}
int main(){
	int n,m;
	cin>>n;
	Node *node=new Node[n];
	for(int i=0;i<n;i++){
		cin>>node[i].name>>node[i].num>>node[i].sex;
		ma[node[i].name]=vector<char>();
		ma[node[i].name].push_back(node[i].sex);
		ma[node[i].num].push_back(node[i].sex);
	}
	cin>>m;
	string str1,str2;
	for(int i=0;i<m;i++){
		cin>>str1>>str2;
		if(pipei(ma[str1][0],ma[str2][0])){
			cout<<'Y'<<endl;
		}else{
			cout<<'N'<<endl;
		}
	}
}
