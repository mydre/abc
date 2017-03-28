算法训练 矩阵加法  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　给定两个N×M的矩阵，计算其和。其中：
　　N和M大于等于1且小于等于100，矩阵元素的绝对值不超过1000。
输入格式
　　输入数据的第一行包含两个整数N、M，表示需要相加的两个矩阵的行数和列数。接下来2*N行每行包含M个数，其中前N行表示第一个矩阵，后N行表示第二个矩阵。
输出格式
　　你的程序需要输出一个N*M的矩阵，表示两个矩阵相加的结果。注意，输出中每行的最后不应有多余的空格，否则你的程序有可能被系统认为是Presentation　　Error
样例输入
2 2
1 2
3 4
5 6
7 8

样例输出


6 8
10 12

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int A[100][100];
int main(){
	cin>>n>>m;
	int a;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a;
			A[i][j]+=a;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j!=m-1) cout<<A[i][j]<<" ";
			else cout<<A[i][j];
		}
		cout<<endl;
	}
}
