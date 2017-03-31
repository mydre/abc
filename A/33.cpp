算法训练 进制转换  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　编写一个程序，输入一个二进制的字符串（长度不超过32），然后计算出相应的十进制整数，并把它打印出来。
　　输入格式：输入为一个字符串，每个字符都是’0’或’1’，字符串的长度不超过32。
　　输出格式：输出一个整数。
　　输入输出样例
样例输入
1101
样例输出
13


#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char ch[33];
int main(){
	cin>>ch;
	int len=strlen(ch);
	long long temp=0;/*使用的是long long型*/
	for(int i=0;i<len;i++){ 
		if(ch[i]=='1'){
			temp+=pow(2,len-1-i);//这里应当注意次数
		}
	}
	cout<<temp;
}
