/*
  使用深度优先遍历，从区域中选择3个块，但是有的相邻，但是有的不相邻，dfs是为了产生这样的序列的
  下面实用广度优先遍历，来对使用dfs产生的所有情况进行检查（即从dfs中的node[0]开始搜索相邻的区域，如果不相邻，则返回的cn不大于3）
  如果相邻的话，就把这个点加入到队列Q中，但是加入过之后的点应当避免再次加入，因此加入之后立即零map[nx][ny]=0.
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
	int x;
	int y;
	Node(){}
	Node(int xx,int yy):x(xx),y(yy){}
};
Node node[10];
int vis[10][10];
int map[10][10];
int m,n;
int cnt1,cnt2;
int len=0;
int cn;
int dir[4][2]={-1,0,1,0,0,1,0,-1};//四个方向 
int isout(int x,int y){
	if(x<1||x>3||y<1||y>4) return 1;
	else return 0;
}
//假设有三行四列
int bfs(){
	int cn,nx,ny;
	memcpy(map,vis,sizeof(map));
	queue<Node> Q;
	Q.push(node[0]);//第一个原始结点如队列
	map[node[0].x][node[0].y]=0;//为0则不能再入队 
	cn=1; 
	while(!Q.empty()){
		Node tx=Q.front();Q.pop();
		for(int i=0;i<4;i++){
			nx=dir[i][0]+tx.x;
			ny=dir[i][1]+tx.y;
			if((!isout(nx,ny))&&map[nx][ny]){//这里有两个限制条件，已经入队的元素不能够再次入队！ 
				Q.push(Node(nx,ny));//入队之后应该改变状态 
				map[nx][ny]=0;
				cn++;
			}
		} 	
	}
	return cn;	
}
void dfs(int x,int y,int dep){
	if(dep==3){
		if(bfs()==3){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=4;j++){
					cout<<vis[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<"------------------"<<endl;
		}
		return;
	}else{
		if(x>3) return;//判断x是否过界
		for(int i=y;i<=5;i++){//向后看一步 
			
			if(i<=4){//这个是成功的
				node[len]=Node(x,i);//使用i变量代表y，这是要注意是Node(x,i)而不是Node(x,y) 
				vis[x][i]=1;
				len++; 
				dfs(x,i+1,dep+1);
				len--;
				vis[x][i]=0;
			}else{//这个是不成功的 
				dfs(x+1,1,dep);
			}
		} 
	}
}
int main(){
	dfs(1,1,0);
}
