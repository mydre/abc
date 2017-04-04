移动距离

X星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1,2,3...
当排满一行时，从下一行相邻的楼往反方向排号。
比如：当小区排号宽度为6时，开始情形如下：

1  2  3  4  5  6
12 11 10 9  8  7
13 14 15 .....

我们的问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）

输入为3个整数w m n，空格分开，都在1到10000范围内
w为排号宽度，m,n为待计算的楼号。
要求输出一个整数，表示m n 两楼间最短移动距离。

例如：
用户输入：
6 8 2
则，程序应该输出：
4

再例如：
用户输入：
4 7 20
则，程序应该输出：
5

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
  计算x方向上的偏移量和y方向上的偏移量
  计算x方向上的偏移量直接算绝对值
  计算y方向上的偏移量时，要考虑方向，即点增大的方向，x为偶数时，向右增大，x为奇数时，向左增大（第一行的x为0）
  可以将输入的数减1，便于求模运算（）
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int W,M,N,di;
int dist(int x,int y){
	if(x>y) return x-y;
	return y-x;
}
int main(){
	cin>>W>>M>>N;
	M-=1;N-=1; 
	int xm=M/W;
	int xn=N/W;
	int ym=M%W;
	int yn=N%W;
	if(xm%2==0&&xn%2==0){//都向右增大 
		di=dist(xm,xn)+dist(ym,yn);
	}
	if(xm%2==0&&xn%2==1){//M向右，N向左 
		di=dist(ym,M-yn-1)+dist(xm,xn);
	}
	if(xm%2==1&&xn%2==0){//M向左，N向右 
		di=dist(W-ym-1,yn)+dist(xm,xn);
	}
	if(xm%2==1&&xn%2==1){//都向左增大 
		di=dist(xm,xn)+dist(ym,yn);
	}
	cout<<di;
} 
