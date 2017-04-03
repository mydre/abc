#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	int tot=0;
	while(n/2){
		tot++;
		n/=2;
	}
	tot++;
	cout<<tot;
}
