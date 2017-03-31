算法训练 字符串编辑  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　从键盘输入一个字符串（长度<=40个字符），并以字符 ’.’ 结束。编辑功能有：
　　1 D：删除一个字符，命令的方式为： D a 其中a为被删除的字符，例如：D s 表示删除字符 ’s’ ，若字符串中有多个 ‘s’，则删除第一次出现的。
　　2 I：插入一个字符，命令的格式为：I a1 a2 其中a1表示插入到指定字符前面，a2表示将要插入的字符。例如：I s d 表示在指定字符 ’s’ 的前面插入字符 ‘d’ ，若原串中有多个 ‘s’ ，则插入在最后一个字符的前面。
　　3 R：替换一个字符，命令格式为：R a1 a2 其中a1为被替换的字符，a2为替换的字符，若在原串中有多个a1则应全部替换。
　　在编辑过程中，若出现被改的字符不存在时，则给出提示信息。
输入格式
　　输入共两行，第一行为原串(以’.’结束)，第二行为命令（输入方式参见“问题描述” 。
输出格式
　　输出共一行，为修改后的字符串或输出指定字符不存在的提示信息。
样例输入
This is a book.
D s
样例输出
Thi is a book.
输入输出样例解释
　　命令为删去s，第一个在字符中出现的s在This中，即得到结果。
  
/*通过相关的命令，来完成对字符串的操作，最关键的是要使用地址传递的方式，而不是值传递的方式，这样才能真正改变相关存储单元中的内容/
#include<cstdio>
#include<iostream>
using namespace std;
int len;
int ji_len(string s){
	int tot=0;
	while(s[tot]!='\0'&&s[tot]!='.'){/*计算数组的长度，最后一个"."也属于字符串的一部分*/
		tot++;
	}
	return tot+1;
}
void display(string stri){/*用于输出字符串*/
	for(int i=0;i<len;i++) cout<<stri[i];
	cout<<endl;
}
void dele(char cb,char *c){/*原来字符指针可以操作字符串，使用字符串的变量名可以把字符串当做字符数组来处理，大大方便了操作*/
	int i=0;
	while(c[i]!=cb&&i<len) i++;
	if(i==len)
	display(c);
	else{
		for(int j=i;j<len;j++) c[j]=c[j+1];
		len--;
		display(c);
	} 
}
void inse(char a1,char a2,char * c){/*插入相关内容*/
	int flag=-1;
	for(int i=0;i<len;i++){
		if(c[i]==a1) flag=i;
	}
	if(flag==-1)
	display(c);
	else{
		for(int i=len;i>flag;i--){
			c[i]=c[i-1];
		}
		c[flag]=a2;
		++len;
		display(c);
	}
}
void reply(char a1,char a2,char *c){/*替换相关内容*/
	int flag=-1;
	for(int i=0;i<len;i++){
		if(c[i]==a1){
			flag=i;
			c[i]=a2;
		}
	}
	if(flag==-1)
	display(c);
	else{
		display(c);
	}
}
int main(){
	char str[50];
	char ca,cb,cc;/*这里很巧妙，定义几个字符，来避免复杂的输入，不同的输入情况对应不同的处理方法*/
	gets(str);/*gets函数用于向字符数组中输入内容，当然，可以包含空格喽，但是输入回车符的时候输入就结束了*/
	len=ji_len(str);
	cin>>ca;
	if(ca=='D'){
		cin>>cb; 
		dele(cb,str);
	}else if(ca=='I'){
		cin>>cb>>cc;
		inse(cb,cc,str);
	}else if(ca=='R'){
		cin>>cb>>cc;
		reply(cb,cc,str); 
	} 
}
