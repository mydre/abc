算法训练 结点选择  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？

输入格式
第一行包含一个整数 n 。

接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。

接下来一共 n-1 行，每行描述树上的一条边。

输出格式
输出一个整数，代表选出的点的权值和的最大值。
样例输入
5
1 2 3 4 5
1 2
1 3
2 4
2 5
样例输出
12
样例说明
选择3、4、5号点，权值和为 3+4+5 = 12 。
数据规模与约定
对于20%的数据， n <= 20。

对于50%的数据， n <= 1000。

对于100%的数据， n <= 100000。

权值均为不超过1000的正整数。


/*
  有时候还是把数组开的大一点比较好，因为提示运行超时可能是由于开的内存不足造成的。
  还有时会造成运行错误
*/
#include<iostream>
#include<cstring>
using namespace std;
struct Edge{
	int e;//该边连接的子结点 
	int next;//指向下一条边 
}edges[300000];
int head[150000];/*head[s]表示以s为父结点的边*/ 
int val[150000];
int vis[150000];
int dp[150000][2];/*针对的是点，不是边*/ 
int M,N=0;
void adde(int u,int v){/*从u出发到v有一条边*/ 
	edges[++M].e=v;/*第一步：产生边并和子结点建立联系*/ 
	edges[M].next=head[u];/*第二步：和下一条邻边建立联系*/
	head[u]=M;/*第三步：火炬（head[s]传递给新加进来的边）*/
}

void dfs(int s){/*s是出发点*/ 
	dp[s][0]=val[s];/*选我则权值为1*/
	dp[s][1]=0;/*不选我当然权值为0*/ 
	for(int i=head[s];i!=-1;i=edges[i].next){
		//if(!vis[i]){
		int u=edges[i].e;
		if(!vis[u]){ 
			vis[u]=1;
			dfs(u);/*第一步：进行递归深度遍历，因为在递归的过程中才能够得到需要处理的值*/ 
			dp[s][0]+=dp[u][1];/*第二步：然后出栈得到值*/
			dp[s][1]+=max(dp[u][0],dp[u][1]);
			//dfs(edges[s].next);
			vis[u]=0;
		}
	}
}
int main(){
	cin>>N;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=N;i++) cin>>val[i];/*注意，这里的下标和前面程序的处理时息息相关的
	因为下标是从1开始的，即结点的编号从1到n*/
	int a,b;
	for(int i=0;i<N-1;i++){
		cin>>a>>b;
		adde(a,b);
		adde(b,a);
	}
	memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
	vis[1]=1;
	dfs(1);
	vis[1]=0; 
	int ans=0;
	ans=max(dp[1][0],dp[1][1]);
	cout<<ans;
	return 0;
} 
