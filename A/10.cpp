算法训练 JAM计数法  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
　　Jam是个喜欢标新立异的科学怪人。他不使用阿拉伯数字计数，而是使用小写英文字母计数，他觉得这样做，会使世界更加丰富多彩。在他的计数法中，每个数字的位数都是相同的（使用相同个数的字母），英文字母按原先的顺序，排在前面的字母小于排在它后面的字母。我们把这样的“数字”称为Jam数字。在Jam数字中，每个字母互不相同，而且从左到右是严格递增的。每次，Jam还指定使用字母的范围，例如，从2到10，表示只能使用{b,c,d,e,f,g,h,i,j}这些字母。如果再规定位数为5，那么，紧接在Jam数字“bdfij”之后的数字应该是“bdghi”。（如果我们用U、V依次表示Jam数字“bdfij”与“bdghi”，则U<V< span>，且不存在Jam数字P，使U<P<V< span>）。你的任务是：对于从文件读入的一个Jam数字，按顺序输出紧接在后面的5个Jam数字，如果后面没有那么多Jam数字，那么有几个就输出几个。
输入格式
　　有2行，第1行为3个正整数，用一个空格隔开：
　　s t w
　　（其中s为所使用的最小的字母的序号，t为所使用的最大的字母的序号。w为数字的位数，这3个数满足：1≤s<T≤26, 2≤w≤t-s ）
　　第2行为具有w个小写字母的字符串，为一个符合要求的Jam数字。
　　所给的数据都是正确的，不必验证。
输出格式
　　最多为5行，为紧接在输入的Jam数字后面的5个Jam数字，如果后面没有那么多Jam数字，那么有几个就输出几个。每行只输出一个Jam数字，是由w个小写字母组成的字符串，不要有多余的空格。
样例输入
2 10 5
bdfij
样例输出
bdghi
bdghj
bdgij
bdhij
befgh


/*思路
一开始走了弯路，后来发现在回溯的过程中添加限制条件，相当于进行剪枝，而不是在将要输出结果的时候进行判断（这时已经做了大量的无用功），
这样可以大大提高程序向指定目标的运行效率。
*/
#include<cstdio>
#include<iostream>
using namespace std;
int A[27]; 
int vis[27];
int s,t,w;
string begin;
int flag;//表示是否已进入可输出状态  
int cou;//记录已经输出了后面的几个序列 
int equal(string a,int *b,int w){
	int i;
	for(i=0;i<w;i++){
		if(a[i]==b[i]-1+'a') continue;
		else break;
	}
	if(i==w) return 1;
	return 0;
}
//int biger(int *a,int w){
//	int i;
//	for(i=0;i<w-1;i++){
//		if(a[i]<=a[i+1]) continue;
//		else break;
//	}
//	if(i==w-1) return 1;
//	return 0;
//}
void solve(int cur){
	if(cur==w){
		if(flag){
			//if(biger(A,w)){
			cou++;
			if(cou<=5){
				for(int i=0;i<cur;i++){
					printf("%c",A[i]-1+'a');
				}
				cout<<endl;
			}
			//}	
		}
		if(equal(begin,A,w))flag=1;
		return;
	}else{
		for(int i=s;i<=t;i++){
			if(cur==0){
				A[cur]=i;
				vis[i]=1;
				solve(cur+1);
				vis[i]=0;
			}else{
				if(!vis[i]){
					if(i>=A[cur-1]){
						vis[i]=1;
						A[cur]=i;
						solve(cur+1);
						vis[i]=0;
					}	
				} 
			}
		}
	}
}
int main(){
	cin>>s>>t>>w;
	cin>>begin;
	solve(0);
}
