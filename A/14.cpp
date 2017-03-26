  算法训练 传纸条  
时间限制：1.0s   内存限制：512.0MB
提交此题   锦囊1   锦囊2
问题描述
　　小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。一次素质拓展活动中，班上同学安排做成一个m行n列的矩阵，而小渊和小轩被安排在矩阵对角线的两端，因此，他们就无法直接交谈了。幸运的是，他们可以通过传纸条来进行交流。纸条要经由许多同学传到对方手里，小渊坐在矩阵的左上角，坐标(1,1)，小轩坐在矩阵的右下角，坐标(m,n)。从小渊传到小轩的纸条只可以向下或者向右传递，从小轩传给小渊的纸条只可以向上或者向左传递。
　　在活动进行中，小渊希望给小轩传递一张纸条，同时希望小轩给他回复。班里每个同学都可以帮他们传递，但只会帮他们一次，也就是说如果此人在小渊递给小轩纸条的时候帮忙，那么在小轩递给小渊的时候就不会再帮忙。反之亦然。
　　还有一件事情需要注意，全班每个同学愿意帮忙的好感度有高有低（注意：小渊和小轩的好心程度没有定义，输入时用0表示），可以用一个0-100的自然数来表示，数越大表示越好心。小渊和小轩希望尽可能找好心程度高的同学来帮忙传纸条，即找到来回两条传递路径，使得这两条路径上同学的好心程度只和最大。现在，请你帮助小渊和小轩找到这样的两条路径。
输入格式
　　输入第一行有2个用空格隔开的整数m和n，表示班里有m行n列（1<=m,n<=50）。
　　接下来的m行是一个m*n的矩阵，矩阵中第i行j列的整数表示坐在第i行j列的学生的好心程度。每行的n个整数之间用空格隔开。
输出格式
　　输出一行，包含一个整数，表示来回两条路上参与传递纸条的学生的好心程度之和的最大值。
样例输入
3 3
0 3 9
2 8 5
5 7 0
样例输出
34
数据规模和约定
　　30%的数据满足：1<=m,n<=10
　　100%的数据满足：1<=m,n<=50
  
  
/*
 和方格取数差不多，都用动态规划，但是来路径上没有重合点，用了四维数组，以空间换区时间
 终点无法到达，因此最大值为dp[m][n-1][m-1][n]
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=55;
int A[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int m,n;
int main(){
	cin>>m>>n;
	int x1,y1,x2,y2;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>A[i][j];
		}
	}
	dp[1][1][1][1]=0;
	for(x1=1;x1<=m;x1++){
		for(y1=1;y1<=n;y1++){
			for(x2=1;x2<=m;x2++){
				for(y2=1;y2<=n;y2++){
					if(x1+y1==x2+y2){//一个人走一步后另一个人走一步 
						if(!(x1==x2)||!(y1==y2)){//如果两人没有走在同一点上 
							int temp=max(dp[x1][y1-1][x2][y2-1],dp[x1-1][y1][x2-1][y2]);//两个都从左方来，两个都从上方来的最大值 
							temp=max(temp,dp[x1][y1-1][x2-1][y2]); //一个从左方，一个上方
							temp=max(temp,dp[x1-1][y1][x2][y2-1]);//一个上方，一个左方 
							dp[x1][y1][x2][y2]=temp+A[x1][y1]+A[x2][y2];
							//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<dp[x1][y1][x2][y2]<<endl;
						}
					}
				}
			}
		} 
	}
	cout<<dp[m][n-1][m-1][n];
}
