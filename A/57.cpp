交换瓶子
有N个瓶子，编号 1 ~ N，放在架子上。
比如有5个瓶子：
2 1 3 5 4
要求每次拿起2个瓶子，交换它们的位置。
经过若干次后，使得瓶子的序号为：
1 2 3 4 5
对于这么简单的情况，显然，至少需要交换2次就可以复位。
如果瓶子更多呢？你可以通过编程来解决。
输入格式为两行：
第一行: 一个正整数N（N<10000）, 表示瓶子的数目
第二行：N个正整数，用空格分开，表示瓶子目前的排列情况。
输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。
例如，输入：
5
3 1 2 5 4
程序应该输出：
3
再例如，输入：
5
5 4 3 2 1
程序应该输出：
2



/*
  这里使用了一个非常好的异或运算的小技巧
  如果交换变量a与b但是不依赖任何变量，可以这样：
  a=a^b;
  b=a^b;
  a=a^b;
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
int ar[11000],fl[11000];
using namespace std;
int cnt;
int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>ar[i];
		fl[ar[i]]=i;
	}
	for(int i=1;i<=N;i++){
		//fl[i]找数字i的下标 
		if(i!=ar[i]){
			int x=ar[i];
			ar[i]=ar[i]^ar[fl[i]];/*如果这个位置的数字与应放入的数字不同，那么就进行交换，与它交换的是它应该放入的位置的数字*/
			ar[fl[i]]=ar[i]^ar[fl[i]];
			ar[i]=ar[i]^ar[fl[i]];
			
			fl[x]=fl[x]^fl[i];/*对应的标志也应该改变*/ 
			fl[i]=fl[x]^fl[i];
			fl[x]=fl[x]^fl[i];
			cnt++;
		}
	}
	for(int i=1;i<=N;i++) cout<<ar[i]<<" ";
	cout<<endl;
	for(int i=1;i<=N;i++) cout<<fl[i]<<" ";
	cout<<endl;
	
	cout<<cnt;
} 
