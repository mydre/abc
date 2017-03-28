 算法训练 数组查找及替换  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　给定某整数数组和某一整数b。要求删除数组中可以被b整除的所有元素，同时将该数组各元素按从小到大排序。如果数组元素数值在A到Z的ASCII之间，替换为对应字母。元素个数不超过100，b在1至100之间。
输入格式
　　第一行为数组元素个数和整数b
　　第二行为数组各个元素
输出格式
　　按照要求输出
样例输入
7 2
77 11 66 22 44 33 55

样例输出


11 33  55 M

/*
 首先进行建表p
 然后输入的处理
 在进行排序
 最后进行输出
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int m,b;
int p[100];
int main(){
	for(int i='A';i<='Z';i++) p[i]=1;
	cin>>m>>b;
	int *a=new int[m];
	int tot=0,c;
	for(int i=0;i<m;i++){
		cin>>c;
		if(c%b==0) continue;
		else{
			*(a+tot++)=c;
		}
	} 
	sort(a,a+tot);
	for(int i=0;i<tot;i++){
		if(p[*(a+i)]){//在A到Z之间 
			printf("%c ",*(a+i));
		}else cout<<*(a+i)<<" ";
	}
}
