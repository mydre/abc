算法训练 简单加法(基本型)  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　首先给出简单加法算式的定义：
　　如果有一个算式(i)+(i+1)+(i+2),(i>=0)，在计算的过程中，没有任何一个数位出现了进位，则称其为简单的加法算式。
　　例如：i=3时，3+4+5=12，有一个进位，因此3+4+5不是一个简单的加法算式；又如i=112时，112+113+114=339，没有在任意数位上产生进位，故112+113+114是一个简单的加法算式。

　　问题：给定一个正整数n，问当i大于等于0且小于n时,有多少个算式(i)+(i+1)+(i+2)是简单加法算式。其中n<10000。
输入格式
　　一个整数，表示n
输出格式
　　一个整数,表示简单加法算式的个数
样例输入
4

样例输出


3

/*
 i+(i+1)+(i+2)相当有3*(i+1)，因此首先需要构造出i，然后进行加1，然后乘3
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int a[6];
int tot,cnt;
int jin(int m){
	memset(a,0,sizeof(a));
	tot=0;
	while(m/10){
		a[tot++]=m%10;
		m/=10;
	}
	a[tot++]=m;
//	for(int i=0;i<tot;i++){
//		cout<<a[i]<<" ";
//	}
	a[0]+=1;
	for(int i=0;i<tot;i++){
		a[i]*=3;
		if(a[i]>10){
			return 1;
		}
	} 
	return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		if(!jin(i)) cnt++;
	}
	cout<<cnt;
}
