
垒骰子

赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。
经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！
我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。
假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。 
atm想计算一下有多少种不同的可能的垒骰子方式。
两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。
由于方案数可能过多，请输出模 10^9 + 7 的结果。

不要小看了 atm 的骰子数量哦～

「输入格式」
第一行两个整数 n m
n表示骰子数目
接下来 m 行，每行两个整数 a b ，表示 a 和 b 数字不能紧贴在一起。

「输出格式」
一行一个数，表示答案模 10^9 + 7 的结果。

「样例输入」
2 1
1 2

「样例输出」
544

「数据范围」
对于 30% 的数据：n <= 5
对于 60% 的数据：n <= 100
对于 100% 的数据：0 < n <= 10^9, m <= 36


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。



/*
  思路：
矩阵快速幂
同理我们只考虑底面的情况，最后乘上4^n即可。
我们设六阶矩阵An，其中An的第a行第b列表示第一层底面数字为a、第n层数字为b的所有排列的情况
记六阶矩阵X中，第a行第b列表示相邻两层的是否能成功连接的情况。a和b能连则为1，a和b不能连则为0
（注意是相邻两层的底面，不是衔接面，所以要转化，比如题给的1 2要改为1 5）
根据上述定义，易得递推式：
An = An-1X，且 A1 = E（六阶单位矩阵）
可得到An的表达式为An = Xn-1
那么ans就是矩阵 Xn-1 的36个元素之和
注意最后侧面的4^n也要二分幂不然会爆炸
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MOD 1000000007/*这个是用于取余的数*/
int N,M; 
struct Matrix{
	long long a[6][6];
	Matrix(int x){
		memset(a,0,sizeof(a));/*该矩阵刚开始都清零*/ 
		for(int i=0;i<6;i++){
			a[i][i]=x;/*在主对角线方向上的初始化为x*/
		}
	}
};
Matrix multri(Matrix matf,Matrix matn){/*矩阵相乘，返回结果*/
	Matrix ret(0);
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				ret.a[i][j]+=matf.a[i][k]*matn.a[k][j];
				ret.a[i][j]%=MOD;
			}
		}
	}
	return ret;
}
Matrix mulTri(Matrix b,int n){/*b就是我们使用输入的对立的两面构造产生的，这里求的是b的n次幂，因为形参为n*/ 
	Matrix ret(1);/*这里ret首先为单位矩阵*/
	while(n>0){
		if(n&1){/*如果n是奇数*/
			ret=multri(ret,b);
		}
		n/=2;
		b=multri(b,b);/*平方，1、2、4、8……等等*/
	}
	return ret;
}
long long mulNum(long long ans,int a,int n){//返回结果为ans乘以a的n次幂 
	while(n>0){
		if(n&1){
			ans*=a;
			ans%=MOD;
		}
		a*=a;
		a%=MOD;//注意，这一步要有 
		n/=2;
	}
	return ans;
}
int main(){
	cin>>N>>M;
	Matrix mat(0);
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			mat.a[i][j]=1;/*初始化所有的元素都为1*/
		}
	}
	int t1,t2;
	for(int i=0;i<M;i++){
		cin>>t1>>t2;/*输入的是哪两个面不能够贴在一次*/
		mat.a[t1-1][(t2-1+3)%6]=0;
		mat.a[t2-1][(t1-1+3)%6]=0;//注意，这个也是条件 
	}
	Matrix ret(0); 
	ret=mulTri(mat,N-1);/*返回矩阵mat的N-1次幂*/
	long long ans=0;/*初始化ans为0*/
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			ans+=ret.a[i][j];
			ans%=MOD;
		}
		//cout<<endl;
	}
	ans=mulNum(ans,4,N);
	cout<<ans<<endl;
}
