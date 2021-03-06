算法训练 数列  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
　　给定一个正整数k(3≤k≤15),把所有k的方幂及所有有限个互不相等的k的方幂之和构成一个递增的序列，例如，当k=3时，这个序列是：
　　1，3，4，9，10，12，13，…
　　（该序列实际上就是：30，31，30+31，32，30+32，31+32，30+31+32，…）
　　请你求出这个序列的第N项的值（用10进制数表示）。
　　例如，对于k=3，N=100，正确答案应该是981。
输入格式
　　只有1行，为2个正整数，用一个空格隔开：
　　k N
　　（k、N的含义与上述的问题描述一致，且3≤k≤15，10≤N≤1000）。
输出格式
　　计算结果，是一个正整数（在所有的测试数据中，结果均不超过2.1*109）。（整数前不要有空格和其他符号）。
样例输入
3 100
样例输出
981

/*
 翻阅网上的资料才知道，本题关键在于对数学公式的转化上，当一个新的单独的k的方幂出现后，它会与前面的各项分别加一次，构成其往后的
 各项，因此，用tmp变量保存单独的方幂出现的位置，now保存当前方幂的值，当执行完一次循环后，要让now*k来更新now
*/
#include<cstdio>
#include<iostream>
using namespace std;
int k,N,A[1010];
int main(){
	cin>>k>>N;
	int len=0,tmp=0,now=1;
	while(len<N){
		tmp=len;
		A[len++]=now;
		for(int i=0;i<tmp;i++){
			A[len++]=now+A[i]; 
		}
		now*=k;
	}
	cout<<A[N-1];
}
