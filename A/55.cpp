算法训练 安慰奶牛  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
Farmer John变得非常懒，他不想再继续维护供奶牛之间供通行的道路。道路被用来连接N个牧场，牧场被连续地编号为1到N。
每一个牧场都是一个奶牛的家。FJ计划除去P条道路中尽可能多的道路，但是还要保持牧场之间 的连通性。你首先要决定那些道路是需要保留的N-1条道路。
第j条双向道路连接了牧场Sj和Ej(1 <= Sj <= N; 1 <= Ej <= N; Sj != Ej)，而且走完它需要Lj的时间。没有两个牧场是被一条以上的道路所连接。
奶牛们非常伤心，因为她们的交通系统被削减了。你需要到每一个奶牛的住处去安慰她们。每次你到达第i个牧场的时候(即使你已经到过)，
你必须花去Ci的时间和奶牛交谈。你每个晚上都会在同一个牧场(这是供你选择的)过夜，直到奶牛们都从悲伤中缓过神来。在早上 起来和晚上回去睡觉的时候，
你都需要和在你睡觉的牧场的奶牛交谈一次。这样你才能完成你的 交谈任务。假设Farmer John采纳了你的建议，请计算出使所有奶牛都被安慰的最少时间。

输入格式
第1行包含两个整数N和P。

接下来N行，每行包含一个整数Ci。

接下来P行，每行包含三个整数Sj, Ej和Lj。

输出格式
输出一个整数, 所需要的总时间(包含和在你所在的牧场的奶牛的两次谈话时间)。
样例输入
5 6
10
10
20
6
30
1 2 5
2 3 5
2 4 12
3 4 17
2 5 15
3 5 6
样例输出
178
数据规模与约定
5 <= N <= 10000，N-1 <= P <= 100000，0 <= Lj <= 1000，1 <= Ci <= 1,000。


/*
  一：find（int x）函数，建表+返回值
  二：并查集
  三：设置边的权值
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge{
	int u;
	int v;
	int w;
}edges[1500000];
int N,M,MIN=1000;
int C[150000],p[150000];
int cmp(Edge e1,Edge e2){
	return e1.w<e2.w;
}
int find(int x){//该函数也非常重要，使用错了的话就会超时 
    if(p[x]!=x)//该函数的作用要有两种，一：找父亲。二：建立表格（x和p[x]之间的联系） 
       p[x]=find(p[x]);
    return p[x];//
}
void init(){
	for(int i=1;i<=N;i++){
		//cin>>C[i];
		scanf("%d",&C[i]);
		if(MIN>C[i]) MIN=C[i];
	}
	for(int i=0;i<M;i++){
		int temp;
		scanf("%d%d%d",&edges[i].u,&edges[i].v,&temp);
		//cin>>edges[i].u>>edges[i].v>>edges[i].w;
		edges[i].w=2*temp+C[edges[i].u]+C[edges[i].v];
	}
} 
int krustal(){
	int ans=0;
	for(int i=1;i<=N;i++) p[i]=i;
	sort(edges,edges+M,cmp);
	for(int i=0;i<M;i++){
		int x=edges[i].u;
		int y=edges[i].v;
		x=find(x);
		y=find(y);
		if(x!=y){//两者的父亲不同，则在两个连同分量重，需要合并 
			//合并连同分量的时候，如果有N各点，则
			p[x]=y;//x的父亲是y
			ans+=edges[i].w; 
		}
	}
	return ans;
}
int main(){
	//freopen("input8 (2).txt","r",stdin);
	//cin>>N>>M;
	scanf("%d%d",&N,&M);
	init();
	int ans=krustal();
	cout<<ans+MIN;
//	for(int i=0;i<M;i++){
//		cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
//	}
}
