算法训练 矩阵乘方  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　给定一个矩阵A,一个非负整数b和一个正整数m，求A的b次方除m的余数。
　　其中一个nxn的矩阵除m的余数得到的仍是一个nxn的矩阵，这个矩阵的每一个元素是原矩阵对应位置上的数除m的余数。
　　要计算这个问题，可以将A连乘b次，每次都对m求余，但这种方法特别慢，当b较大时无法使用。下面给出一种较快的算法(用A^b表示A的b次方)：
　　若b=0，则A^b%m=I%m。其中I表示单位矩阵。
　　若b为偶数，则A^b%m=(A^(b/2)%m)^2%m，即先把A乘b/2次方对m求余，然后再平方后对m求余。
　　若b为奇数，则A^b%m=(A^(b-1)%m)*a%m，即先求A乘b-1次方对m求余，然后再乘A后对m求余。
　　这种方法速度较快，请使用这种方法计算A^b%m，其中A是一个2x2的矩阵，m不大于10000。
输入格式
　　输入第一行包含两个整数b, m，第二行和第三行每行两个整数，为矩阵A。
输出格式
　　输出两行，每行两个整数，表示A^b%m的值。
样例输入
2 2
1 1
0 1
样例输出
1 0
0 1

/*
  一定要注意memset的使用方法，int类型不推荐使用，因为在程序中使用时，打算把整型数组中每个值都置为0，但是
  运算结果却出乎意料，只能通过20%，后来为了把temp数组清零，专门写了一个函数，qingling()，然后就能正常运行了。
*/
#include <iostream>  
#include<cstdio>
#include<cstring>
using namespace std;  
int b,m;
int a[2][2];
int temp[2][2];
int ans[2][2];
int unit[2][2]={1,0,0,1};
void qingling(int a[][2]){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			a[i][j]=0;
		}
	}
}
void pingfang(int a[][2],int b[][2]){/*两个矩阵相乘的函数*/
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				temp[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}
void mod(int arr[][2]){/*矩阵中的每一个值处于m取余*/
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++) arr[i][j]%=m;
	}
}
void cp(int a[][2],int b[][2]){/* 复制b数组中的内容到a数组*/
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++) a[i][j]=b[i][j];
	}
}
void solve(int index,int arr[][2]){
	if(index==0){
		mod(unit);
		cp(ans,unit);
		return;
	}
	if(index%2==0){//b是偶数 
		solve(index/2,arr);//递归调用
    qingling(temp); //使用清零函数
    pingfang(ans,ans);/*当上一次调用结束时，ans中就有值了，这是可以让ans平方*/
		cp(ans,temp);
		mod(ans);
		return;
	}
	if(index%2==1){/*b是奇数*/
		solve(index-1,arr);
		qingling(temp);
		pingfang(ans,arr);/*经过solve的调用，ans中就有值了，这时可以令an*arr            */
		cp(ans,temp);
		mod(ans);
		return;
	}
}
int main(){
	cin>>b>>m;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	solve(b,a); 
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	} 
}
