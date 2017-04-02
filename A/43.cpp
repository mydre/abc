  算法训练 寂寞的数  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　道德经曰：一生二，二生三，三生万物。
　　对于任意正整数n，我们定义d(n)的值为为n加上组成n的各个数字的和。例如，d(23)=23+2+3=28, d(1481)=1481+1+4+8+1=1495。
　　因此，给定了任意一个n作为起点，你可以构造如下一个递增序列：n,d(n),d(d(n)),d(d(d(n)))....例如，从33开始的递增序列为：
　　33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
　　我们把n叫做d(n)的生成元，在上面的数列中，33是39的生成元，39是51的生成元，等等。有一些数字甚至可以有两个生成元，比如101，可以由91和100生成。但也有一些数字没有任何生成元，如42。我们把这样的数字称为寂寞的数字。
输入格式
　　一行，一个正整数n。
输出格式
　　按照升序输出小于n的所有寂寞的数字，每行一个。
样例输入
40
样例输出
1
3
5
7
9
20
31
数据规模和约定
　　n<=10000


/*
  刚开始因为生成元只有1到9，后来发现任何数都可以被当做生成元，
  然后1到n之间的数都可以当做生成元，然后就可以建表了
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int sheng[10010];
int qiu(int n){//求n的各位数字之和 
	int s=0;
	while(n/10){
		s+=n%10;
		n/=10;
	}
	s+=n%10;
	return s;
}
void build(int i){/*i和i的各位数字之和*/
	sheng[i+qiu(i)]=1;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		build(i);/*对于生成元i进行建表*/
	}
	for(int i=1;i<n;i++){
		if(sheng[i]==0) cout<<i<<endl; 
	}
}