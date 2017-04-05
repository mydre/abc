算法训练 字符串变换  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　相信经过这个学期的编程训练，大家对于字符串的操作已经掌握的相当熟练了。今天，徐老师想测试一下大家对于字符串操作的掌握情况。徐老师自己定义了1,2,3,4,5这5个参数分别指代不同的5种字符串操作，你需要根据传入的参数，按照徐老师的规定，对输入字符串进行格式转化。
　　徐老师指定的操作如下：
　　1 表示全部转化为大写字母输出，如abC 变成 ABC
　　2 表示全部转换为小写字母输出，如abC变成abc
　　3 表示将字符串整个逆序输出，如 abc 变成 cba
　　4 表示将字符串中对应的大写字母转换为小写字母，而将其中的小写字母转化为大写字母输出，如 abC变成ABc
　　5表示将全部转换为小写字母，并将其中所有的连续子串转换为对应的缩写形式输出，比如abcD 转换为a-d，其次，-至少代表1个字母，既如果是ab，则不需要转换为缩写形式。
输入格式
　　一共一行，分别是指代对应操作的数字和字符串，两者以空格分隔，字符串全部由英文字母组成
输出格式
　　输出根据上述规则转换后对应的字符串
样例输入
5 ABcdEE
样例输出
a-ee
数据规模和约定
　　输入字符串长度最长为200。
  
  
  
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int is_lit(char c){
	if(c>='a'&&c<='z') return 1;
	return 0;
}
int is_big(char c){
	if(c>='A'&&c<='Z') return 1;
	return 0;
}
void tolit(char *w,int len){/*将字符串变为由所有的小写字母组成*/
	for(int i=0;i<len;i++){
		if(is_big(w[i])) w[i]+=32;
	}
}
void tobig(char *w,int len){/*变为大写*/
	for(int i=0;i<len;i++){
		if(is_lit(w[i])) w[i]-=32;
	}
}
void nixu(char *w,int len){/*逆序输出*/
	for(int i=len-1;i>=0;i--) cout<<w[i];
}
void inver(char *w,int len){/*大小写反转*/
	for(int i=0;i<len;i++){
		if(is_big(w[i])) w[i]+=32;
		else w[i]-=32;
	}
}
int dele(char *w,int x,int y,int &len){/*删除，假设有dabcdei，则x=1，y=5,删除后变为da-ei */
	if(y-x>1){
		w[x+1]='-';
		for(int i=y;i<=len;i++){
			w[i-y+x+2]=w[i];
		}
		len-=(y-x-2);
		return 1;
	}
	return 0;
}
void surpress(char *w,int &len){
	tolit(w,len);
	for(int i=0;i<len;i++){
		int tot=0;
		for(int j=i;j<len&&w[j]+1==w[j+1];j++){/*这里关键是找边界，尽量只看一步，即把本身当做边界来处理*/
			tot++;
		}
		if(tot>1){
			dele(w,i,i+tot,len);/*只需要删除就行了，i不需要改变，由for循环自己改变*/
		}
	}
}
int main(){
	int n;
	cin>>n;
	char cr[220];
	cin>>cr;
	int len=strlen(cr);
	if(n==1){
		tobig(cr,len);
	}else if(n==2){
		tolit(cr,len);
	}else if(n==3){
		nixu(cr,len);
	}else if(n==4){
		inver(cr,len);
	}else if(n==5){
		surpress(cr,len);
	}
	if(n!=3){
		cout<<cr;
	} 
}
