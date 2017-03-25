算法训练 一元三次方程求解  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
　　有形如：ax3+bx2+cx+d=0 这样的一个一元三次方程。给出该方程中各项的系数(a，b，c，d 均为实数)，并约定该方程存在三个不同实根(根的范围在-100至100之间)，且根与根之差的绝对值>=1。要求三个实根。。
输入格式
　　四个实数：a，b，c，d
输出格式
　　由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后2位
样例输入
1 -5 -4 20
样例输出
-2.00 2.00 5.00
数据规模和约定
　　|a|，|b|，|c|，|d|<=10
  //枚举
 #include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	for(double x=-100.00;x<=100.00;x+=0.01){
		if(abs(a*x*x*x+b*x*x+c*x+d)<=0.00001){
			printf("%.2f ",x);
		}
	}
} 
//分治
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double a,b,c,d;

double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
int main(){
	cin>>a>>b>>c>>d;
	double x1,x2,xx,x;
	for(x=-100;x<=100;x++){
		x1=x;x2=x+1;
		if(f(x)==0) printf("%.2f ",x);
		else if(f(x1)*f(x2)<0){//表示解在这个区间内 
			while(x2-x1>=0.001){
				xx=x1+(x2-x1)/2;
				if(f(x1)*f(xx)<0) x2=xx;
				else x1=xx;
			}
			printf("%.2f ",x1);
		}
	}
}

  
