
标题：带分数

    100 可以表示为带分数的形式：100 = 3 + 69258 / 714

    还可以表示为：100 = 82 + 3546 / 197

    注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

    类似这样的带分数，100 有 11 种表示法。

题目要求：
从标准输入读入一个正整数N (N<1000*1000)
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！


例如：
用户输入：
100
程序输出：
11

再例如：
用户输入：
105
程序输出：
6


资源约定：
峰值内存消耗 < 64M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


/*
  考察全排列，思维转位分组
  1~9这个排列分为三组，
  a,b,c
  满足N=a+b/c的就使cnt++（计数）
*/
#include<cstdio>
#include<iostream>
using namespace std;
int A[12],vis[12],N,cnt; 
void dfs(int cur){
	if(cur==10){
		int a=0,b=0,c=0,la,lb,lc;
		for(la=1;la<=7;la++){/*a末尾可以为从1位到7位*/
			a=0;
			for(int i=1;i<=la;i++){/*a的开头从1开始*/
				a=a*10+A[i];
			}
			for(lb=(la+1+9)/2;lb<=8;lb++){/*b的位数的末尾至少从剩下的一半开始，不然不能被c整除*/
				b=0;
				for(int j=la+1;j<=lb;j++){/*b的开头从a的末尾的下一位开始*/
					b=b*10+A[j];
				}
				c=0;
				for(int k=lb+1;k<=9;k++){/*c的开始从b的末尾的下一位开始，c的末尾为9*/
					c=c*10+A[k];
				}
				if((N-a)*c==b) cnt++;
			}
		}
	}else{
		for(int i=1;i<=9;i++){
			if(!vis[i]){
				vis[i]=1;
				A[cur]=i;
				dfs(cur+1);
				vis[i]=0;
			}
		} 
	} 
}
int main(){
	cin>>N;
	dfs(1);
	cout<<cnt;
} 
