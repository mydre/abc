算法训练 阶乘  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　一个整数n的阶乘可以写成n!，它表示从1到n这n个整数的乘积。阶乘的增长速度非常快，例如，13!就已经比较大了，已经无法存放在一个整型变量中；而35!就更大了，它已经无法存放在一个浮点型变量中。因此，当n比较大时，去计算n!是非常困难的。幸运的是，在本题中，我们的任务不是去计算n!，而是去计算n!最右边的那个非0的数字是多少。例如，5! = 1*2*3*4*5 = 120，因此5!最右边的那个非0的数字是2。再如：7! = 5040，因此7!最右边的那个非0的数字是4。请编写一个程序，输入一个整数n(n<=100)，然后输出n! 最右边的那个非0的数字是多少。
　　输入格式：输入只有一个整数n。
　　输出格式：输出只有一个整数，即n! 最右边的那个非0的数字。
输入输出样例
样例输入
6
样例输出
2

/*关键是函数的理解，calculate函数中有四个参数，第一个参数a用于保存上一次计算的结果，len用于保存数组的长度，n用于表示要乘的数的
  数，b用于保存本次计算求得的结果。
*/
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=10000;
int s[maxn],e[maxn];
int calculate(int *a,int len,int n,int *b){
	int temp=0,i;
	for(i=0;i<len;i++){
		temp+=a[i]*n;
		b[i]=temp%10;
		temp/=10;
	}
	while(temp/10){
		b[i++]=temp%10;
		temp/=10;
	}
	b[i++]=temp%10;
	return i;
}
int main(){
	int n;
	cin>>n;
	s[0]=1;
	int p=1,q;
	for(int i=1;i<=n;i++){
		if(p>0){/*n为奇数的时候调用，上一次运算的结果s作为本次运算的条件，本次的运算结果e作为下一次运算的条件*/
			q=calculate(s,p,i,e);/*q保存e数组中元素的个数*/
			p=0;/*将p置为0*/
		}else if(q>0){/*n为偶数的时候调用，上一次运算的结果e作为本次运算的条件，本次运算的结果s作为下一次运算的条件*/
			p=calculate(e,q,i,s);/*p保存s数组中元素的个数*/
			q=0;
		}
	}
	if(n%2==0){
		for(int i=0;i<p;i++){
			if(s[i]==0) continue;
			else{
				cout<<s[i];break;
			}
		}
	}else{
		for(int i=0;i<q;i++){
			if(e[i]==0) continue;
			else{
				cout<<e[i];break;
			}
		}
	}
} 
