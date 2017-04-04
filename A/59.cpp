
加法变乘法

我们都知道：1+2+3+ ... + 49 = 1225
现在要求你把其中两个不相邻的加号变成乘号，使得结果为2015

比如：
1+2+3+...+10*11+12+...+27*28+29+...+49 = 2015
就是符合要求的答案。

请你寻找另外一个可能的答案，并把位置靠前的那个乘号左边的数字提交（对于示例，就是提交10）。

注意：需要你提交的是一个整数，不要填写任何多余的内容。


#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int hi(int x,int y){
	int sum=0;
	for(int i=1;i<=x-1;i++){
		sum+=i;
	}
	sum+=x*(x+1);
	for(int i=x+2;i<=y-1;i++){
		sum+=i;
	}
	sum+=y*(y+1);
	for(int i=y+2;i<=49;i++){
		sum+=i;
	}
	return sum;
}
int main(){
	for(int i=1;i<=48;i++){
		for(int j=i+2;j<=48;j++){//这一点非常巧妙，因为前面一个*，后面一个*，有因为不能相邻，所以可以这样设置 
			//if(i==j||i+1==j||j+1==i) continue;
			if(hi(i,j)==2015){
				cout<<"i="<<i<<" "<<"j="<<j<<endl;
			}
		}
	}
}
