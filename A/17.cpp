算法训练 数组排序去重  
时间限制：1.0s   内存限制：512.0MB
提交此题   锦囊1   锦囊2
问题描述
　　输入10个整数组成的序列，要求对其进行升序排序，并去掉重复元素。
输入格式
　　10个整数。
输出格式
　　多行输出，每行一个元素。
样例输入
2 2 3 3 1 1 5 5 5 5
样例输出
1
2
3
5

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int fla[10];
int main(){
	int *a=new int[10];
	for(int i=0;i<10;i++) cin>>*(a+i);
	sort(a,a+10);
	for(int i=0;i<10;i++){
		if(!fla[*(a+i)]) cout<<*(a+i)<<endl;
		fla[*(a+i)]=1;
	}
} 
