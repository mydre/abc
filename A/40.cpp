 算法训练 暗恋  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　同在一个高中，他却不敢去找她，虽然在别人看来，那是再简单不过的事。暗恋，是他唯一能做的事。他只能在每天课间操的时候，望望她的位置，看看她倾心的动作，就够了。操场上的彩砖啊，你们的位置，就是他们能够站立的地方，他俩的关系就像砖与砖之间一样固定，无法动摇。还记得当初铺砖的工人，将整个操场按正方形铺砖（整个操场可视为R行C列的矩阵，矩阵的每个元素为一块正方形砖块），正方形砖块有两种，一种为蓝色，另一种为红色。我们定义他和她之间的“爱情指标”为最大纯色正方形的面积，请你写一个程序求出“爱情指标”。
输入格式
　　第一行两个正整数R和C。
　　接下来R行C列描述整个操场，红色砖块用1来表示，蓝色砖块用0来表示。
输出格式
　　一个数，表示他和她之间的“爱情指标”。
样例输入
5 8
0 0 0 1 1 1 0 1
1 1 0 1 1 1 1 1
0 1 1 1 1 1 0 1
1 0 1 1 1 1 1 0
1 1 1 0 1 1 0 1
样例输出
9
数据规模和约定
　　40%的数据R,C<=10;
　　70%的数据R,C<=50;
　　100%的数据R,C<=200;

/*
  从某一点出发，然后看看能够更新长度，每次都是一种试探
  若judge函数返回值为1，则可以试探下一个width，否从该点试探下一个长度
  从其它点试探的时候会默认width，看能够有比width更大的正方形
*/
#include<iostream>
#include <cstdio>  
#define MAX 200 + 10  
using namespace std; 
int M[205][205];
int r,c;
int judge(int x,int y,int length){//从x,y出发，变长为maxwidth+1 
	int color=M[x][y];
	if(x+length>r||y+length>c) return 0;//过界，构建失败
	int f=1; 
	for(int i=x;i<x+length;i++){
		for(int j=y;j<y+length;j++){
			if(M[i][j]!=color) return 0;
		}
	}
	return 1;
}
int main(){
	cin>>r>>c; 
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) cin>>M[i][j];
	}	
	int curmax=1;
	int width=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			while(1){
				if(judge(i,j,curmax)){
					width=curmax;
					curmax++;
				}else{
					break;
				}
			}
		}
	}
	cout<<width*width;
}
