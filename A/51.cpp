算法训练 区间k大数查询  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。

输入格式
第一行包含一个数n，表示序列长度。

第二行包含n个正整数，表示给定的序列。

第三个包含一个正整数m，表示询问个数。

接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K大的数是哪个。序列元素从1开始标号。

输出格式
总共输出m行，每行一个数，表示询问的答案。
样例输入
5
1 2 3 4 5
2
1 5 2
2 3 2
样例输出
4
2
数据规模与约定
对于30%的数据，n,m<=100；

对于100%的数据，n,m<=1000；

保证k<=(r-l+1)，序列中的数<=106。

/*
  使用指针来操作整型数组，效率更高。
  第一次输入的是原始数据，不需要进行排序
  后来进行查询的时候要把原始数据赋值给B，进行特定区间的排序，再根据输入的k的值确定取出哪一个元素
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int B[110];
void cp(int *B,int *A,int be,int en){
	for(int i=be;i<=en;i++){
		*(B+i)=*(A+i); 
	} 
}
int main(){
	int n,m;
	cin>>n;
	int *A=new int[n+1];
	int *B=new int[n+1];
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	cin>>m;
	int be,en,k;
	for(int i=0;i<m;i++){
		cin>>be>>en>>k;
		cp(B,A,be,en);
		sort(B+be,B+en+1);
		cout<<*(B+en-k+1)<<endl;
	}
}
