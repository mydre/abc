算法训练 反置数  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　一个整数的“反置数”指的是把该整数的每一位数字的顺序颠倒过来所得到的另一个整数。如果一个整数的末尾是以0结尾，那么在它的反置数当中，这些0就被省略掉了。比如说，1245的反置数是5421，而1200的反置数是21。请编写一个程序，输入两个整数，然后计算这两个整数的反置数之和sum，然后再把sum的反置数打印出来。要求：由于在本题中需要多次去计算一个整数的反置数，因此必须把这部分代码抽象为一个函数的形式。
　　输入格式：输入只有一行，包括两个整数，中间用空格隔开。
　　输出格式：输出只有一行，即相应的结果。
　　输入输出样例
样例输入
435 754
样例输出
199

/*有两个函数起主要作用，pp函数将一个整数存放在h数组中，oo函数根据一个数组求出一个整数*/
#include<cstdio>
#include<iostream> 
using namespace std;  
int a,b;
int h[100];
int pp(int q){//将一个数存在h数组中 
	int tot=0;
	while(q/10){
		h[tot++]=q%10;
		q/=10;
	}
	h[tot++]=q%10;
	return tot;
} 
int oo(int *a,int n){//根据数组求出一个数 
	int temp=0;
	int flag=0;
	for(int i=0;i<n;i++){
		if(flag==0&&a[i]==0) continue;
		flag=1;
		if(i!=n-1) temp=(temp+a[i])*10;
		else if(i==n-1) temp+=a[i];
	}
	return temp;
}
int main(){
	int a_len,b_len;
	cin>>a>>b;
	a_len=pp(a);
	a=oo(h,a_len);
	b_len=pp(b);
	b=oo(h,b_len);
	a=a+b;
	a_len=pp(a);
	a=oo(h,a_len);
	cout<<a;
}
