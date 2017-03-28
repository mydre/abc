算法训练 蜜蜂飞舞  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　“两只小蜜蜂呀，飞在花丛中呀……”

　　话说这天天上飞舞着两只蜜蜂，它们在跳一种奇怪的舞蹈。用一个空间直角坐标系来描述这个世界，那么这两只蜜蜂初始坐标分别为(x1,y1,z1)，(x2,y2,z2)　　。在接下来它们将进行n次飞行，第i次飞行两只蜜蜂分别按照各自的速度向量飞行ti个单位时间。对于这一现象，玮玮已经观察了很久。他很想知道在蜜蜂飞舞结束时，两只蜜蜂的距离是多少。现在他就求教于你，请你写一个程序来帮他计算这个结果。
输入格式
　　第一行有且仅有一个整数n，表示两只蜜蜂将进行n次飞行。

　　接下来有n行。

　　第i行有7个用空格分隔开的整数ai,bi,ci,di,ei,fi,ti　　，表示第一只蜜蜂单位时间的速度向量为(ai,bi,ci) ，第二只蜜蜂单位时间的速度向量为(di,ei,fi) ，它们飞行的时间为ti 。

　　最后一行有6个用空格分隔开的整数x1,y1,z1,x2,y2,z2，如题所示表示两只蜜蜂的初始坐标。
输出格式
　　输出仅包含一行，表示最后两只蜜蜂之间的距离。保留4位小数位。
样例输入
Sample 1
1
1 1 1 1 -1 1 2
3 0 1 2 0 0
Sample 2
3
1 1 1 1 -1 1 2
2 1 2 0 -1 -1 2
2 0 0 -1 1 1 3
3 0 1 2 0 0

样例输出


Sample 1
4.2426
Sample 2
15.3948

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int dx1,dy1,dz1,dx2,dy2,dz2;
int main(){
	int ai,bi,ci,di,ei,fi,ti;
	int x1,y1,z1,x2,y2,z2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ai>>bi>>ci>>di>>ei>>fi>>ti;//输入速度向量和时间ti 
		dx1+=ai*ti;//这里更新位移 
		dy1+=bi*ti;
		dz1+=ci*ti;
		dx2+=di*ti;
		dy2+=ei*ti;
		dz2+=fi*ti;
	}
	cin>>x1>>y1>>z1>>x2>>y2>>z2;//输入初始坐标 
	x1+=dx1;//更新终点位置坐标 
	y1+=dy1;
	z1+=dz1;
	x2+=dx2;
	y2+=dy2;
	z2+=dz2;
	double s=(double)sqrt(double((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)));//求距离 
	printf("%.4f",s);
}
