
标题：地宫取宝

    X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。

    地宫的入口在左上角，出口在右下角。

    小明被带到地宫的入口，国王要求他只能向右或向下行走。

    走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。

    当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。

    请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。

【数据格式】

    输入一行3个整数，用空格分开：n m k (1<=n,m<=50, 1<=k<=12)

    接下来有 n 行数据，每行有 m 个整数 Ci (0<=Ci<=12)代表这个格子上的宝物的价值

    要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。

例如，输入：
2 2 2
1 2
2 1
程序应该输出：
2

再例如，输入：
2 3 2
1 2 3
2 1 5
程序应该输出：
14


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。




/*
  1、有值直接返回，（不需要递归）
  2、达到边界条件（如果满足，就增加cnt）直接返回，不再进行递归
  3、可以先往下递归
  4、可以先往右递归 
  5、最后一步进行返回值 
  6、不到达底部只需要判断条件（只需要按照策略进行递归  
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MOD 1000000007
int N,M,K;
int val[60][60],d[60][60][13][14];
int dfs(int x,int y,int num,int maxvalue){
	if(d[x][y][num][maxvalue+1]!=-1) return d[x][y][num][maxvalue+1];//有值直接返回 
	int t=0; //本次递归的时候成本为0，若是底部，则直接返回，若是没有到达边界，则在已经求得的基础上增加 
	if(x==N&&y==M){/*要注意递归结束条件*/
		if(val[x][y]>maxvalue){
			if(num==K){
				t++;
			}else if(num==K-1){
				t++;
			}
		}else{
			if(num==K) t++;
		}
		return d[x][y][num][maxvalue+1]=t;
	}
	if(x<N){
		if(maxvalue<val[x][y]){
			t+=dfs(x+1,y,num,maxvalue);
			t%=MOD;
			t+=dfs(x+1,y,num+1,val[x][y]);
			t%=MOD;
		}else{
			t+=dfs(x+1,y,num,maxvalue);
			t%=MOD;
		}
	}
	if(y<M){
		if(maxvalue<val[x][y]){
			t+=dfs(x,y+1,num,maxvalue);
			t%=MOD;
			t+=dfs(x,y+1,num+1,val[x][y]);
			t%=MOD;
		}else{
			t+=dfs(x,y+1,num,maxvalue);
			t%=MOD;
		}
	}
	return d[x][y][num][maxvalue+1]=t;
}
int main(){
	memset(d,-1,sizeof(d));
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>val[i][j];
		}
	}
	d[1][1][0][0]=dfs(1,1,0,-1);/*设初始最大value为-1*/ 
	cout<<d[1][1][0][0];
} 
