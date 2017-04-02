算法训练 字符串的展开  
时间限制：1.0s   内存限制：256.0MB
提交此题    
　　在初赛普及组的“阅读程序写结果”的问题中，我们曾给出一个字符串展开的例子：如果在输入的字符串中，含有类似于“d-h”或者“4-8”的字串，我们就把它当作一种简写，输出时，用连续递增的字母获数字串替代其中的减号，即，将上面两个子串分别输出为“defgh”和“45678”。在本题中，我们通过增加一些参数的设置，使字符串的展开更为灵活。具体约定如下：
　　(1) 遇到下面的情况需要做字符串的展开：在输入的字符串中，出现了减号“-”，减号两侧同为小写字母或同为数字，且按照ASCII码的顺序，减号右边的字符严格大于左边的字符。
　　(2) 参数p1：展开方式。p1=1时，对于字母子串，填充小写字母；p1=2时，对于字母子串，填充大写字母。这两种情况下数字子串的填充方式相同。p1=3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充。
　　(3) 参数p2：填充字符的重复个数。p2=k表示同一个字符要连续填充k个。例如，当p2=3时，子串“d-h”应扩展为“deeefffgggh”。减号两边的字符不变。
　　(4) 参数p3：是否改为逆序：p3=1表示维持原来顺序，p3=2表示采用逆序输出，注意这时候仍然不包括减号两端的字符。例如当p1=1、p2=2、p3=2时，子串“d-h”应扩展为“dggffeeh”。
　　(5) 如果减号右边的字符恰好是左边字符的后继，只删除中间的减号，例如：“d-e”应输出为“de”，“3-4”应输出为“34”。如果减号右边的字符按照ASCII码的顺序小于或等于左边字符，输出时，要保留中间的减号，例如：“d-d”应输出为“d-d”，“3-1”应输出为“3-1”。
输入格式
　　输入包括两行：
　　第1行为用空格隔开的3个正整数，一次表示参数p1，p2，p3。
　　第2行为一行字符串，仅由数字、小写字母和减号“-”组成。行首和行末均无空格。
输出格式
　　输出只有一行，为展开后的字符串。
输入输出样例1
输入
1 2 1
abcs-w1234-9s-4zz
输出
abcsttuuvvw1234556677889s-4zz
输入输出样例2
输入
2 3 2
a-d-d
输出
aCCCBBBd-d
输入输出样例3
输入
3 4 2
di-jkstra2-6
输出
dijkstra2************6
数据规模和约定
　　40%的数据满足：字符串长度不超过5
　　100%的数据满足：1<=p1<=3，1<=p2<=8，1<=p3<=2。字符串长度不超过100
  
/*
  考察对字符串的处理 
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int is_num(char c){/*判断是否是数字*/
	if(c>='0'&&c<='9') return 1;
	return 0;
}
int is_char(char c){/*判断是否是字符*/
	if(c>='a'&&c<='z') return 1;
	return 0;
}
int ge(char a,char b){/*返回字符的个数*/
	return b-a-1;
}
void dele(char *w,int k,int &le){/*删除一个字符，当然顺便改变其长度*/
	for(int i=k;i<le;i++){
		w[i]=w[i+1];
	}
	le--;
}
void inver(int k1,int k2,char *w){/*从下标k1开始到下标k2，反转字符串*/
	int k=(k2-k1)/2;
	int len=k2-k1+1;
	int temp;
	for(int i=k1;i<=k1+k;i++){
		temp=w[i];w[i]=w[k2-i+k1];w[k2-i+k1]=temp;/*一定要找到两端之间的关系，利用其增减性*/
	}
}
void tian(char *w,int k,int &le,int p1,int p2,int p3){/*该函数的作用是为了填充需要的字符串*/
	//cout<<"k1="<<k<<endl;
	/*
	  总共有三步，
	  第一步：腾出空间（相应的字符王后移动） 
	  第二步：进行填充 
	  第三步： 根据参数p3判断是否需要进行反转 
	*/
	int p3k=k;
	int x1=w[k-1]+1;
	int x2=w[k+1]-1;
	char cy1=w[k-1];
	char cy2=w[k+1];
	int num=p2*ge(w[k-1],w[k+1]);//计算填多少个星号 
	dele(w,k,le);//删除减号
	for(int i=le;i>=k;i--){//i最大值取到le是为了把'\0'也带上 
		w[i+num]=w[i];//向后移动一些距离，便于等一下填充 
	}
	le=le+num;
	if(p1==1){//如是字母填小写字母， 
		//cout<<"x1="<<x1<<" "<<"x2="<<x2<<endl; 
		int tot=k;
		for(int i=x1;i<=x2;i++){
			int z=p2;
			while(z--){
				w[tot++]=i; 
			}
		}
	}
	if(p1==2){//如是字母，填充大写字母 
		if(is_char(cy1)&&is_char(cy1)){
			x1-=32;x2-=32;
		}
		int tot=k;
		for(int i=x1;i<=x2;i++){
			int z=p2;
			while(z--){
				w[tot++]=i; 
			}
		}
	}
	if(p1==3){//这时只需要填充星号 
		//cout<<"num="<<num<<endl;
		for(int i=k;i<k+num;i++) w[i]='*';
	}
	if(p3==2){//这时候填充的字符串要逆序 
		//cout<<"w="<<w<<endl;
		//cout<<"num="<<num<<endl;
		//cout<<"k="<<k<<endl;
		//cout<<""
		inver(k,k+num-1,w);
		//cout<<"w="<<w<<endl;
	}
}
void change(char *w,int k,int &le,int p1,int p2,int p3){
	/*
	  判断是否需要填充 
	*/
	if(is_num(w[k-1])&&is_num(w[k+1])||is_char(w[k-1])&&is_char(w[k+1])){
		if(w[k-1]+1==w[k+1]){//删除中间的减号
			int i; 
			for(i=k;i<le-1;i++) w[i]=w[i+1]; 
			w[i]='\0';
			le--;
		}
		else if(w[k-1]>=w[k+1]) return;
		else{
			tian(w,k,le,p1,p2,p3);
		}
	}
}
int main(){
//	printf("%d",'A');
//	cout<<endl;
//	printf("%d",'a');


	int p1,p2,p3,len;
	char s[30000];
	cin>>p1>>p2>>p3;
	cin>>s;
	len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='-'){
			change(s,i,len,p1,p2,p3);
		}
	}
	cout<<s;
	
	
	//cout<<endl<<strlen(s);
//	char ch[10];
//	cin>>ch;
//	inver(1,6,ch);
//	cout<<ch; 
}   
