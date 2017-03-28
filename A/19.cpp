算法训练 调和数列问题  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　输入一个实数x，求最小的n使得，1/2+1/3+1/4+...+1/(n+1)>=x。

　　输入的实数x保证大于等于0.01，小于等于5.20，并且恰好有两位小数。你的程序要能够处理多组数据，即不停地读入x，如果x不等于0.00，则计算答案，否则退出程序。

　　输出格式为对于一个x，输出一行n card(s)。其中n表示要计算的答案。
输入格式
　　分行输入x的具体数值
输出格式
　　分行输出n的数值，格式为n card(s)
样例输入
1.00
3.71
0.04
5.19
0.00

样例输出


3 card(s)
61 card(s)
1 card(s)
273 card(s)
/*
 第一步建表
 第二步进行判断
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000;
double A[maxn+5];
int main(){
	for(int i=1;i<=maxn;i++){
		A[i]=A[i-1]+1.0/(i+1);
		//cout<<"i="<<i<<" "<<A[i]<<endl;
	}
	double x;
	while(cin>>x&&x!=0){
		for(int i=1;i<=maxn;i++){
			if(A[i]>=x){
				cout<<i<<" card(s)"<<endl;break;
			}
		}
	}
}
