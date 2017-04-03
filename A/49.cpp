算法训练 5-2求指数  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　已知n和m，打印n^1，n^2，...，n^m。要求用静态变量实现。n^m表示n的m次方。已知n和m，打印n^1，n^2，...，n^m。要求用静态变量实现。n^m表示n的m次方。（每行显示5个数，每个数宽为12，右对齐）
样例输入
一个满足题目要求的输入范例。
例：
3 8
样例输出
与上面的样例输入对应的输出。
例：

数据规模和约定
　　输入数据中每一个数的范围。
　　例：n^m小于int 的表示范围。

/*
  可以利用递归+建表的方式，避免多次使用的时候造成超时
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int ci[1000];
int fang[1000];
int cifang(int n,int m){//递归加建表的过程 
	if(m==1){
		fang[m]=n;
		return n;
	}else{
		fang[m]=n*cifang(n,m-1);
		return n*cifang(n,m-1);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	cifang(n,m);
	for(int i=1;i<=m;i++){
		printf("%12d",fang[i]);
		if(i%5==0) cout<<endl;
	}
	return 0;
}
