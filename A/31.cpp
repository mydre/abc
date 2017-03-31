算法训练 输出米字形  
时间限制：1.0s   内存限制：512.0MB
提交此题    
　　根据输入的正整数n (1　　米字形由一个(2n-1)*(2n-1)的矩阵组成，矩阵包含从大写A开始的n个字母
　　例如:n=3时，包含A,B,C；n=4时，包含A,B,C,D。
　　矩阵的正中间为n个字母中字典序最大的那个，从这个字母开始，沿着西北、正北、东北、正西、正东、西南、正南、东南八个方向各有一条由大写字母组成的直线。并且直线上的字母按字典序依次减小，直到大写字母A。
　　矩阵的其它位置用英文句号．填充。

　　样例输入一
　　3

　　样例输出一
　　Ａ．Ａ．Ａ
　　．ＢＢＢ．
　　ＡＢＣＢＡ
　　．ＢＢＢ．
　　Ａ．Ａ．Ａ

　　样例输入二
　　4

　　样例输出二
　　Ａ．．Ａ．．Ａ
　　．Ｂ．Ｂ．Ｂ．
　　．．ＣＣＣ．．
　　ＡＢＣＤＣＢＡ
　　．．ＣＣＣ．．
　　．Ｂ．Ｂ．Ｂ．
　　Ａ．．Ａ．．Ａ
  
/*本题关键是找到i和j的递增和递减关系，进而使两者的和或者差与n存在联系*/  
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int main(){
	int n;
	cin>>n;
	int c=n*2-1;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<c;j++){
			if(j==i||j==n-1||j==2*(n-1)-i) printf("%c",'A'+i);
			else cout<<".";
		}
		cout<<endl;
	}
	for(int i=0;i<2*n-1;i++){
		if(i<=n-1) printf("%c",'A'+i);
		else{
			printf("%c",'A'-i+2*(n-1));
		}
	}
	cout<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<c;j++){ 
			if(j==n-1||i+j==n-2||j==n+i) printf("%c",'A'-i+n-2);
			else cout<<".";
		}
		cout<<endl;
	}
}
