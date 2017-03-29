算法训练 邮票  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　给定一个信封，有N（1≤N≤100）个位置可以贴邮票，每个位置只能贴一张邮票。我们现在有M(M<=100)种不同邮资的邮票，面值为X1,X2….Xm分（Xi是整数，1≤Xi≤255），每种都有N张。

　　显然，信封上能贴的邮资最小值是min(X1, X2, …, Xm)，最大值是 N*max(X1, X2, …,　　Xm)。由所有贴法得到的邮资值可形成一个集合（集合中没有重复数值），要求求出这个集合中是否存在从1到某个值的连续邮资序列，输出这个序列的最大值。

　　例如，N=4，M=2，面值分别为4分，1分，于是形成1，2，3，4，5，6，7，8，9，10，12，13，16的序列，而从1开始的连续邮资序列为1，2，3，4，5，6，7，8，9，10，所以连续邮资序列的最大值为10分。
输入格式
　　第一行：最多允许粘贴的邮票张数N；第二行：邮票种数M；第三行：空格隔开的M个数字，表示邮票的面值Xi。注意：Xi序列不一定是大小有序的！
输出格式
　　从1开始的连续邮资序列的最大值MAX。若不存在从1分开始的序列（即输入的邮票中没有1分面额的邮票），则输出0.
样例输入
样例一：
4
2
4 1
样例二：
10
5
2 4 6 8 10

样例输出


样例一：
10
样例二：
0
/*
  本题可以看成是一个集合问题,即求在贴的邮票不多于n张的可满足条件的邮资集.集合问题的关键在于判定元素是否在集合中,对于本题而言,是判断某个邮资是否在贴不多于n张邮票可满足.这个判断问题可以用递归的方法解决.设当前考虑的邮资值为max,最多允许贴n张邮票,记为(max,n).如果首先贴一张面值为xi的邮票,那么剩下的问题是(max-xi,n-1)的问题.如果(max-xi,n-1)可解,那么(max,n)问题也可解.
       进一步, 这个递归的算法可以转化为递推的算法来解决.设piece[value]表示邮资为value时所需最少的邮票数, pieces[MAX]=min{pieces[MAX-x[i]]+1}.当pices[value]<=n时,问题(max,n)可解,否则无解.
递推算法可以描述为:
  for(i=1;i<=m;i++)  if( MAX-x[i]>=0)
     {
         if(pieces[MAX]==0)
               pieces[MAX]=pieces[MAX-x[i]]+1;
          if(pieces[MAX]>pieces[MAX-x[i]]+1)
                pieces[MAX]=pieces[MAX-x[i]]+1; 
      }
*/
/*
  本题非常经典，刚开始看着不像是动态规划，用了递归，可是通过60%后就超时了，因为枚举产生的树太深，
  可以转化为动态规划来处理
  dp[value]表示当邮资为value的时候需要的最小票的数目，显然最大为n，
  于是在j-*(val+i)>=0的时候可以分为两种情况，
  情况一：dp[j]==0，这时应该让dp[j]=dp[j-*(val+i)]+1来更新dp[j],虽然也是不太理解
  情况二：dp[j]!=0,这时让dp[j]=min(dp[j],dp[j-*(val+i)]+1)
*/

//动态规划，令dp[value]为邮资为value时需要的最小邮票数 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[25505];
int n,m;
int main(){
	cin>>n>>m;
	int *val=new int[m];
	for(int i=0;i<m;i++) cin>>*(val+i);
	sort(val,val+m);
	int tv=0;
	dp[tv]=0;
	int mv=n**(val+m-1);
	for(int i=0;i<m;i++){//对于每一个邮资 
		for(int j=0;j<=mv;j++){//对于每一个容量 
			if(j-*(val+i)>=0){
				if(dp[j]==0) dp[j]=dp[j-*(val+i)]+1;//只能说这一步非常重要 
				dp[j]=min(dp[j],dp[j-*(val+i)]+1); 
			}
		}
	}
	int i;
	for(i=1;i<=mv;i++){
		if(dp[i]>0&&dp[i]<=n) continue;
		else break;
	}	 
	cout<<i-1;
	
} 
