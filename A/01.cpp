#include<iostream>  
#include<algorithm>  
#include<cstdlib>  
#include<cstdio>  
#include<cstring>  
#include<iostream>
using namespace std;  
int k,vis[20],A[20],flag=2,cnt;
void solve(int cur){
	for(int j=2;j<=k;j++){
		cout<<"cur="<<cur<<endl;
		if(cur==j){
			cnt++;
			for(int h=0;h<cur;h++) cout<<A[h]<<" ";
			cout<<endl;
		}
	}
	for(int i=1;i<=k;i++){
		if(!vis[i]){
			if(cur==0){
				vis[i]=1;
				A[cur]=i;
				solve(cur+1);
				vis[i]=0;
			}else if(cur==1){
				vis[i]=1;
				A[cur]=i;
				solve(cur+1);
				vis[i]=0;
			}else{
				if(A[cur-1]>A[cur-2]){//判断是否满足 
					if(i<A[cur-2]){
						vis[i]=1;
						A[cur]=i;
						solve(cur+1);
						vis[i]=0;
					}
				}else if(A[cur-1]<A[cur-2]){
					if(i>A[cur-2]){
						vis[i]=1;
						A[cur]=i;
						solve(cur+1);
						vis[i]=0;
					}
				}
			}	
		}
	}
}
int main()  
{  
   cin>>k;
   solve(0);
   cout<<cnt;
}  
