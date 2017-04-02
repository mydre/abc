 算法训练 s01串  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　s01串初始为"0"
　　按以下方式变换
　　0变1，1变01
输入格式
　　1个整数(0~19)
输出格式
　　n次变换后s01串
样例输入
3
样例输出
101
数据规模和约定
　　0~19

/*
  cur=0代表第一次，cur==n为结束条件，这样进行递归调用即可
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[2000000];
int n;
void dfs(int cur,char *cr,int &le){
	if(cur==n){
		for(int i=0;i<le;i++){
			cout<<cr[i];
		}
		return;
	}
	for(int i=0;i<le;i++){
		if(cr[i]=='0'){
			ch[i]='1';
		}else{
			for(int j=le-1;j>=i;j--){//往后移动 
				cr[j+1]=cr[j];
			}
			le++;
			cr[i]='0';
			i++;/*这一步很重要，因为刚使用1产生了01，这是01中的1不需要处理，故让i++，for循环再自动执行一次i++，这样就可以继续往后处理了*/
		}
	}
	dfs(cur+1,cr,le); 
} 
int main(){
	cin>>n;
	ch[0]='0';
	int len=1;
	dfs(0,ch,len);
	
}
