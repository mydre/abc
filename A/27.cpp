#include <iostream>  
#include<cstdio>
using namespace std;  
void quicksort(int *a,int n){
	int flag1=0,flag2=n-1;
	int temp=*(a);
	if(n>1){
		while(flag1<flag2){
			for(1;flag2>flag1;flag2--){
			//1、通过flag2找到了比temp小的，赋值给flag1，这时lag2中渴望得到新的值 
			//2、通过flag2出发，没有找到比temp小的，则flag2走到了flag1，
			//因为此时a[flag1]==temp,所以此时令a[falg1]=temp，并没有改变原数据的大小 
				if(*(a+flag2)<temp){
					*(a+flag1)=*(a+flag2);
					break;
				}
			}
			for(1;flag1<flag2;flag1++){
			//1、从flag1出发，找到了比temp大的，则将其赋值给a[flag2]，a[flag2]得到了满足，但是
			//a[flag1]渴望得到新的值，此时在最后一步令a[flag1]=temp即可 
			//2、从flag1出发，没有找到比temp大的，则此时flag1==flag2，则只需满足a[flag2]的需要即可，
			//即令a[flag1]=temp和a[flag2]=temp等价 
				if(*(a+flag1)>temp){
					*(a+flag2)=*(a+flag1);
					break;
				}
			}
			*(a+flag1)=temp;
		}
		quicksort(a,flag1);//有时加1或减1可能导致越界，因此不推荐 
		quicksort(a+flag1+1,n-flag1-1);
	}
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>*(a+i);
	}
	quicksort(a,n);
	for(int i=0;i<n;i++){
		cout<<*(a+i)<<endl;
	}
}
