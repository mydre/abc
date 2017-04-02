算法训练 和为T  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　从一个大小为n的整数集中选取一些元素，使得它们的和等于给定的值T。每个元素限选一次，不能一个都不选。
输入格式
　　第一行一个正整数n，表示整数集内元素的个数。
　　第二行n个整数，用空格隔开。
　　第三行一个整数T，表示要达到的和。
输出格式
　　输出有若干行，每行输出一组解，即所选取的数字，按照输入中的顺序排列。
　　若有多组解，优先输出不包含第n个整数的；若都包含或都不包含，优先输出不包含第n-1个整数的，依次类推。
　　最后一行输出总方案数。
样例输入
5
-7 -3 -2 5 9
0
样例输出
-3 -2 5
-7 -2 9
2
数据规模和约定
　　1<=n<=22
　　T<=maxlongint
　　集合中任意元素的和都不超过long的范围
  
  
/*
  使用A数组来存储集合中的数
  使用B数组来存储生成的排列
  使用回溯的方式进行搜索，但是只通过50%的数据之后就超时了，如何解决呢？
*/
 #include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector> 
using namespace std;
int T;
int vis[30];
int cnt;
map<long long,vector<int> > ma; 
void solve(int cur,int n,int dep,long long *A,long long *B){/*选择数的个数为dep*/ 
	if(cur==dep){
		int s=0;
		for(int i=0;i<cur;i++) s+=B[i];
		if(s==T){//如果和为T 
			cnt++;
			for(int i=0;i<cur;i++){
				cout<<B[i]<<" ";
			}
			cout<<endl;return;
		}
	}else{
		if(cur==0){
			for(int i=n-1;i>=0;i--){
				if(!vis[i]){/*第一次不需要比较优先级*/ 
					vis[i]=1;
					B[cur]=A[i];
					solve(cur+1,n,dep,A,B);
					vis[i]=0;
				}
			}
		}else{
			for(int i=n-1;i>=0;i--){
				if(!vis[i]){
					if(ma[A[i]][0]>ma[B[cur-1]][0]){//如果比上一次的优先级大 
						vis[i]=1;
						B[cur]=A[i];
						solve(cur+1,n,dep,A,B);
						vis[i]=0;
					}
				}
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	long long *A=new long long [n];
	long long *B=new long long [n];
	for(int i=0;i<n;i++){
		scanf("%I64d",(A+i));
		ma[A[i]].push_back(i);/*设定优先级ma[][]中第一个中括号内的内容是key，第二个中括号内的内容*是value（i当做优先级），/
	}
	
	cin>>T;
	for(int i=1;i<=n;i++){
		solve(0,n,i,A,B);
	}
	cout<<cnt;
}
