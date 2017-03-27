/*
 getpri()函数用于求素数
 tot标记下标
 mark[i]==1，则i不是素数，否则是负数
 mark[pri[j]*i]=1;用于产生两个数的倍数，这是标记mark为1表示不是素数，大于1的任意两个正数相乘的结果不是素数
 solve(x)用于
*/

#include<cstdio>
#include<iostream>
using namespace std;
#define N 50000
int ans,tot;
int pri[50005];
bool mark[50005];
int a0,b0,a1,b1;
int n,x;
void getpri(){
	tot=0;
	for(int i=2;i<=N;i++){
		if(!mark[i]) pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=N;j++){
			mark[pri[j]*i]=1;
		}
	}
}
void solve(int x){
	int c0=0,c1=0,c2=0,c3=0;
	while(a0%x==0){a0/=x;c0++;}
	while(a1%x==0){a1/=x;c1++;}
	while(b0%x==0){b0/=x;c2++;}
	while(b1%x==0){b1/=x;c3++;}
	if(c0==c1&&c2==c3){
		if(c1<=c3) ans=ans*(c3-c1+1);
		else ans=0;
	}else if(c0!=c1&&c2!=c3&&c1!=c3) ans=0;
}
int main(){
	    getpri();
    cin>>n;
    while(n--){
		ans=1;
		cin>>a0>>a1>>b0>>b1;
		for(int i=1;i<=tot;i++)//从第一个素数到最后一个素数 
		    solve(pri[i]);//依次解决各个素数 
		if(b1!=1) solve(b1);
		printf("%d\n",ans);
 	}
    return 0;
}
