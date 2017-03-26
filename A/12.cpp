算法训练 纪念品分组  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
　　元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得的纪念品价值 相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品，并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时 间内发完所有纪念品，乐乐希望分组的数目最少。
　　你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。
输入格式
　　输入包含n+2行：
　　第1行包括一个整数w，为每组纪念品价格之和的上限。
　　第2行为一个整数n，表示购来的纪念品的总件数。
　　第3~n+2行每行包含一个正整数pi (5 <= pi <= w)，表示所对应纪念品的价格。
输出格式
　　输出仅一行，包含一个整数，即最少的分组数目。
样例输入
100
9
90
20
20
30
50
60
70
80
90
样例输出
6
数据规模和约定
　　50%的数据满足：1 <= n <= 15
　　100%的数据满足：1 <= n <= 30000, 80 <= w <= 200

/*
 有时候自己写的函数会报错，比如sort的选择排序函数，系统自带的sort函数处理指针比处理数组要快得多，所以当用到排序函数的时候最好定义为指针
 该贪心算法，首先进行排序，然后首尾相加，看是否不大于w
*/
#include <iostream>  
#include <cstdio>  
#include<algorithm>
using namespace std; 
int w,n;
int cnt;
void greed(int w,int *p,int n){
	int i=0,j=n-1;
	while(i<=j){
		if(p[i]+p[j]<=w){
			cnt++;
			i++;j--;
		}else{
			j--;
			cnt++;
		}
	}
}
int main(){
	cin>>w>>n;
	int *p=new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);
	greed(w,p,n);
	cout<<cnt;
}