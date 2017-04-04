牌型种数

小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？

请填写该整数，不要填写任何多余的内容或说明文字。


  1、动态规划版本
/*
  若使用动态规划，
  则（不太懂，借鉴网上的http://www.mamicode.com/info-detail-578558.html）  
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int dp[14][14];
int main(){
	dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;
	for(int i=2;i<=13;i++){/*i表示第i次取牌*/ 
		for(int k=0;k<=13;k++){
			if(k-4>=0) dp[i][k]+=dp[i-1][k-4];
			if(k-3>=0) dp[i][k]+=dp[i-1][k-3];
			if(k-2>=0) dp[i][k]+=dp[i-1][k-2];
			if(k-1>=0) dp[i][k]+=dp[i-1][k-1];
			dp[i][k]+=dp[i-1][k];
		} 
	}
	cout<<dp[13][13]<<endl;
	return 0;
} 

  2、dfs版本（要学会优化）
  /*
    优化，比如n从1到13，然后使用数组记录1到13中任意一个数字被访问的次数，但是超时了（等半天没有反应，程序一致在递归调用）
    
    后来借鉴网上的做法，将每张牌的被取的次数作为考虑，共有0~4(代表被取的次数这5中选择，而且所有的选择加在一起要正好等于13（总共取了13次）
    使用cur来控制总共进行13轮，最后计算sum，看是否等于13，等于的话说明取的次数正好为13，满足题意
  */
  #include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int sum,cnt;
void dfs(int cur){
	if(sum>13) return;
	if(cur==14){
		if(sum==13) cnt++;
	}else{
		for(int i=0;i<=4;i++){
			sum+=i;
			dfs(cur+1);
			sum-=i;
		}
	}
}
int main(){
	dfs(1);
	cout<<cnt;
}
