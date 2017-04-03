算法训练 最短路  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
给定一个n个顶点，m条边的有向图（其中某些边权可能为负，但保证没有负环）。请你计算从1号点到其他点的最短路（顶点从1到n编号）。

输入格式
第一行两个整数n, m。

接下来的m行，每行有三个整数u, v, l，表示u到v有一条长度为l的边。

输出格式
共n-1行，第i行表示1号点到i+1号点的最短路。
样例输入
3 3
1 2 -1
2 3 -1
3 1 2
样例输出
-1
-2
数据规模与约定
对于10%的数据，n = 2，m = 2。

对于30%的数据，n <= 5，m <= 10。

对于100%的数据，1 <= n <= 20000，1 <= m <= 200000，-10000 <= l <= 10000，保证从任意顶点都能到达其他所有顶点。



/*这次我一定要独自把这道题做出来，我可以的！一定可以的！*/
/*最多只能参考答案一次*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define INF 100000
using namespace std;
struct Edges{
	int from;//该边的起点 
	int to;//该边的终点 
	long long dist;//边的长度 
}edges[300000];
int N,M,inq[300000];
long long d[300000];
vector<int>G[300000];
queue<int>Q;
void init(){
	int f,t;
	long long di;
	for(int i=0;i<M;i++){//i表示边的编号 
		cin>>f>>t>>di;
		//G[f].clear();//这一步不要有，是多余的（有了会出错） 
		G[f].push_back(i);
		//cout<<"f="<<f<<" "<<"G[f].size="<<G[f].size()<<endl;
		edges[i].from=f;edges[i].to=t;edges[i].dist=di;
	}
}
void bellford(){
	for(int i=1;i<=N;i++) d[i]=INF;
	inq[1]=1;
	d[1]=0;
	Q.push(1);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		inq[u]=0;/*这一步一定要有，不然只能通过80%*/
		for(int i=0;i<G[u].size();i++){/*这里求的不是所有的边，而是以u为出发点的边*/
			Edges &e=edges[G[u][i]];
			//if(e.dist+d[u]<=d[e.to]){/*边上的松弛操作*/ 
			if(d[u]<INF&&e.dist+d[u]<d[e.to]){
			//if(d[u]&&e.dist+d[u]<d[e.to]){
				d[e.to]=e.dist+d[u];
				//cout<<"d[e.to]="<<d[e.to]<<endl;
				if(!inq[e.to]){
					Q.push(e.to);
					inq[e.to]=1;
					//if(++cnt[e.to]>N) return;/*避免环*/
				}
			}
		}
	} 
}
int main(){
	cin>>N>>M;
	init();
	bellford();
	for(int i=2;i<=N;i++){
		cout<<d[i]<<endl;
	}
}
