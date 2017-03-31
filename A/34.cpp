  算法训练 字串统计  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　给定一个长度为n的字符串S，还有一个数字L，统计长度大于等于L的出现次数最多的子串（不同的出现可以相交），如果有多个，输出最长的，如果仍然有多个，输出第一次出现最早的。
输入格式
　　第一行一个数字L。
　　第二行是字符串S。
　　L大于0，且不超过S的长度。
输出格式
　　一行，题目要求的字符串。

　　输入样例1：
　　4
　　bbaabbaaaaa

　　输出样例1：
　　bbaa

　　输入样例2：
　　2
　　bbaabbaaaaa

　　输出样例2：
　　aa

/*
  枚举所有可能的子串，统计出现次数，找出符合条件的那个
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct Node{
	int le;//表示长度 
	int ci;//表示出现的次数
	char s[100]; 
	Node(){}
	Node(int l,int c):le(l),ci(c){}
}node[10000]; 
int main(){
	int L;
	string str;
	cin>>L>>str;
	int len=str.length();
	int tot=0; 
	for(int i=L;i<=len;i++){//i用来设定子串的长度范围 
		for(int j=0;j<len-i+1;j++){ //j用来设定字符串的起始下标，当然，因为子串有长度限制，所以起始下标也是有限的（这就是限制条件） 
			/*j是相当于给一变动的范围，但通过j+i-1<len，可得j<len-i+1*/
			int p=0;
			for(int k=j;k<j+i;k++){//k从字符串的起始位置变动到最终位置 
				node[tot].s[p++]=str[k];
			}
			node[tot].s[p]='\0';
			node[tot].ci=1;
			node[tot].le=p;
			tot++;
		}
	}
	int max=0;int d=1; 
	for(int i=0;i<tot;i++){
		for(int j=i+1;j<tot;j++){//和后面的进行比较 ,只往后计算即可，不需要回头 
			if(strcmp(node[i].s,node[j].s)==0){
				node[i].ci++;//相等，则i的次数加1 
				if(node[i].ci>d||node[i].ci==d&&node[i].le>node[max].le){//次数大于d，或者次数等于d但是长度大于max处的长度 
					max=i;d=node[i].ci;//使用node[i]来进行更新 
				}
			}
		}
	}
	cout<<node[max].s;
} 
