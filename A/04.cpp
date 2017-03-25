 算法训练 Car的旅行路线  
时间限制：1.0s   内存限制：256.0MB
提交此题   锦囊1   锦囊2
问题描述
　　又到暑假了，住在城市A的Car想和朋友一起去城市B旅游。她知道每个城市都有四个飞机场，分别位于一个矩形的四个顶点上，同一个城市中两个机场之间有一 条笔直的高速铁路，第I个城市中高速铁路了的单位里程价格为Ti，任意两个不同城市的机场之间均有航线，所有航线单位里程的价格均为t。
　　那么Car应如何安排到城市B的路线才能尽可能的节省花费呢?她发现这并不是一个简单的问题，于是她来向你请教。
　　找出一条从城市A到B的旅游路线，出发和到达城市中的机场可以任意选取，要求总的花费最少。
输入格式
　　的第一行有四个正整数s，t，A，B。
　　S表示城市的个数，t表示飞机单位里程的价格，A，B分别为城市A，B的序号，(1<=A，B<=S)。
　　接下来有S行，其中第I行均有7个正整数xi1，yi1，xi2，yi2，xi3，yi3，Ti，这当中的(xi1，yi1)，(xi2，yi2)，(xi3，yi3)分别是第I个城市中任意三个机场的坐标，T I为第I个城市高速铁路单位里程的价格。
输出格式
　　共有n行，每行一个数据对应测试数据，保留一位小数。
样例输入
1
1 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3
样例输出
47.55
数据规模和约定
　　0<S<=100，
 /*
 使用floyd算法求任意两点之间的最短路，题目不太难理解，但有点繁琐，
 其中利用了数学中关于斜率和向量的知识来求点（已知矩阵的三个点，求另外一个点）
 */
#include<cstdio>
#include<iostream> 
#include<cmath>
using namespace std;
int s,A,B;
float t;
struct city{//对应于城市 (可以暂且把city当成一个类来使用)
	float x[4];
	float y[4];
	float co;
	city(float x1,float y1,float x2,float y2,float x3,float y3,float t){
		x[0]=x1;x[1]=x2;x[2]=x3;
		y[0]=y1;y[1]=y2;y[2]=y3;
		co=t;
	}
}*c[110];
float dp[500][500]; 
void swap(float &a,float &b){
	float temp;temp=a;a=b;b=temp;
}
float min(float a,float b){//注意，min的返回值类型不能是整型了，而是float 
	if(a<b) return a;else return b;
}
float dist(float x1,float y1,float x2,float y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void find_jiao(float x1,float y1,float x2,float y2,float x3,float y3,float &x4,float &y4){//使用取地址是为了把值带回 
	if((y3-y1)*(y2-y1)==(-1)*(x3-x1)*(x2-x1)){//假定(x1,y1)是直角点 
		x4=x2+x3-x1;y4=y2+y3-y1;
	}else if((y1-y2)*(y3-y2)==(-1)*(x1-x2)*(x3-x2)){//假定(x2,y2)是直角点 
		x4=x1+x3-x2;y4=y1+y3-y2;
	}else{//(x3,y3)是直角点 
		x4=x1+x2-x3;y4=y1+y2-y3;
	}
}
void init(int s){//i,j相当于各个点的标号 
	for(int i=0;i<4*s;i++){ 
		for(int j=0;j<4*s;j++){
			if(i/4==j/4){//在同一个城市 ,注意这里是i/4和j/4 
				dp[i][j]=dist(c[i/4]->x[i%4],c[i/4]->y[i%4],c[j/4]->x[j%4],c[j/4]->y[j%4])*c[i/4]->co;
			}else{//在不同的城市 
				dp[i][j]=dist(c[i/4]->x[i%4],c[i/4]->y[i%4],c[j/4]->x[j%4],c[j/4]->y[j%4])*t;
			}
		}
	}
}
void Floyd(int s){//注意，i,j,k都是点的标号，因此对应的最大下标都是4*s-1 
	for(int k=0;k<4*s;k++){
		for(int i=0;i<4*s;i++){
			for(int j=0;j<4*s;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main(){
	cin>>s>>t>>A>>B;
	float x1,x2,x3,x4,y1,y2,y3,y4,t;
	for(int i=0;i<s;i++){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>t; 
		c[i]=new city(x1,y1,x2,y2,x3,y3,t);//使用结构体变量一个一个城市进行实例化 
		find_jiao(x1,y1,x2,y2,x3,y3,c[i]->x[3],c[i]->y[3]);//初始化城市的第四个飞机场 
	}
	//对各点的距离进行初始化 
	init(s);
	//使用使用floyd算法更新任意两点之间的路径
	Floyd(s);
	float ans=1000000.00;//注意，这里的ans一定要是个很大的数,而且要是float类型的 
	for(int i=4*A-4;i<4*A;i++){//A,B是城市编号，不是点在表格里的编号  
		for(int j=4*B-4;j<4*B;j++){
			ans=min(ans,dp[i][j]);
		}
	}
    printf("%.1f",ans);  
} 
