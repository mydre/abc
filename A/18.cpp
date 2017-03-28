 算法训练 采油区域  
时间限制：2.0s   内存限制：512.0MB
提交此题    
　　采油区域　　Siruseri政府决定将石油资源丰富的Navalur省的土地拍卖给私人承包商以建立油井。被拍卖的整块土地为一个矩形区域，被划分为M×N个小块。
　　Siruseri地质调查局有关于Navalur土地石油储量的估测数据。这些数据表示为M×N个非负整数，即对每一小块土地石油储量的估计值。
　　为了避免出现垄断，政府规定每一个承包商只能承包一个由K×K块相连的土地构成的正方形区域。
　　AoE石油联合公司由三个承包商组成，他们想选择三块互不相交的K×K的区域使得总的收益最大。
　　例如，假设石油储量的估计值如下：
1	1	1	1	1	1	1	1	1
1	1	1	1	1	1	1	1	1
1	8	8	8	8	8	1	1	1
1	8	8	8	8	8	1	1	1
1	8	8	8	8	8	1	1	1
1	1	1	1	8	8	8	1	1
1	1	1	1	1	1	8	8	8
1	1	1	1	1	1	9	9	9
1	1	1	1	1	1	9	9	9

　　如果K = 2, AoE公司可以承包的区域的石油储量总和为100, 如果K = 3, AoE公司可以承包的区域的石油储量总和为208。
　　AoE公司雇佣你来写一个程序，帮助计算出他们可以承包的区域的石油储量之和的最大值。
输入格式
　　输入第一行包含三个整数M, N, K，其中M和N是矩形区域的行数和列数，K是每一个承包商承包的正方形的大小（边长的块数）。接下来M行，每行有N个非负整数表示这一行每一小块土地的石油储量的估计值。
输出格式
　　输出只包含一个整数，表示AoE公司可以承包的区域的石油储量之和的最大值。
数据规模和约定
　　数据保证K≤M且K≤N并且至少有三个K×K的互不相交的正方形区域。其中30%的输入数据，M, N≤ 12。所有的输入数据, M, N≤ 1500。每一小块土地的石油储量的估计值是非负整数且≤ 500。
样例输入
9 9 3
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 8 8 8 8 8 1 1 1
1 8 8 8 8 8 1 1 1
1 8 8 8 8 8 1 1 1
1 1 1 1 8 8 8 1 1
1 1 1 1 1 1 8 8 8
1 1 1 1 1 1 9 9 9
1 1 1 1 1 1 9 9 9
/*
 s[i][j]代表1..i行1..j列数字之和。
然后处理出以(i,j)为右下角的k*k的矩阵元素之和。
然后分别处理出以(i,j)为左上角，左下角，右上角，右下角的最大矩阵中最大的k*k的值。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,k;
const int maxn=1505;
int G[maxn][maxn];
int s[maxn][maxn];
int ak[maxn][maxn];
int lu[maxn][maxn];
int ld[maxn][maxn];
int ru[maxn][maxn];
int rd[maxn][maxn]; 
int ans;
int main(){
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) cin>>G[i][j]; 
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+G[i][j];
		}
	} 
	for(int i=k;i<=m;i++){
		for(int j=k;j<=n;j++){
			ak[i][j]=s[i][j]+s[i-k][j-k]-s[i-k][j]-s[i][j-k]; 
		}
	}
	for(int i=k;i<=m;i++){//源在左上角(lu)--通过控制i,j完成向右下角进发 
		for(int j=k;j<=n;j++){
			lu[i][j]=ak[i][j];
			lu[i][j]=max(lu[i][j],lu[i-1][j]);
			lu[i][j]=max(lu[i][j],lu[i][j-1]);
		}
	}
	for(int i=m-(k-1);i>=1;i--){//源在左下角(ld)
		for(int j=k;j<=n;j++){
			ld[i][j]=ak[i+(k-1)][j];//调整，[i+(k-1)]非常重要 
			ld[i][j]=max(ld[i][j],ld[i+1][j]);
			ld[i][j]=max(ld[i][j],ld[i][j-1]);
		}
	}
	for(int i=m-(k-1);i>=1;i--){//源在右下角(rd)
		for(int j=n-(k-1);j>=1;j--){
			rd[i][j]=ak[i+(k-1)][j+(k-1)];
			rd[i][j]=max(rd[i][j],rd[i+1][j]);
			rd[i][j]=max(rd[i][j],rd[i][j+1]);
		}
	}
	for(int i=k;i<=m;i++){//源在右上角(ru)
		for(int j=n-(k-1);j>=1;j--){
			ru[i][j]=ak[i][j+(k-1)];
			ru[i][j]=max(ru[i][j],ru[i-1][j]);
			ru[i][j]=max(ru[i][j],ru[i][j+1]);
		}
	}
	ans=0;
	//下面开始更新ans
	for(int j=k;j+(k<<1)<=n;j++){//第一种情况，两边向下，相邻中间是ak 
		for(int i=1;i<=m;i++){
			int t=lu[m][j]+ak[i][j+k]+ru[m][j+k+1];
			ans=max(ans,t);
		}
	} 
	for(int i=k;i+(k<<1)<=m;i++){//第二种情况，两边向右，相邻中间是ak 
		for(int j=1;j<=n;j++){ 
			int t=lu[i][n]+ak[i+k][j]+ld[i+k+1][n];
			ans=max(ans,t);
		}
	} 
	for(int j=k;j+k<=n;j++){//第三种情况，对于每一列进行考虑，共有两列（一向右，二向左） 
		for(int i=k;i+k<=m;i++){
			int t=ru[i][j+1]+rd[i+1][j+1]+lu[m][j];
			ans=max(ans,t);
		}
	}
	for(int j=k;j+k<=n;j++){//第四种情况，对于每一列进行考虑，共有两列 (二向右，一向左)
		for(int i=k;i+k<=m;i++){
			int t=lu[i][j]+ld[i+1][j]+rd[1][j+1];
			ans=max(ans,t);
		}
	}
	for(int i=k;i+k<=m;i++){//第五种情况，
		for(int j=k;j+k<=n;j++){
			int t=ld[i+1][j]+rd[i+1][j+1]+ru[i][1];
			ans=max(ans,t); 
		}
	}
	for(int i=k;i+k<=m;i++){//第六种情况		
     for(int j=k;j+k<=n;j++){
			int t=lu[i][j]+ru[i][j+1]+ld[i+1][n];
			ans=max(ans,t);
		} 
	}
	cout<<ans;
} 
