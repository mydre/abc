算法训练 P1102  
时间限制：1.0s   内存限制：256.0MB
提交此题    
　　定义一个学生结构体类型student，包括4个字段，姓名、性别、年龄和成绩。然后在主函数中定义一个结构体数组（长度不超过1000），并输入每个元素的值，程序使用冒泡排序法将学生按照成绩从小到大的顺序排序，然后输出排序的结果。
　　输入格式：第一行是一个整数N（N<1000），表示元素个数；接下来N行每行描述一个元素，姓名、性别都是长度不超过20的字符串，年龄和成绩都是整型。
　　输出格式：按成绩从小到大输出所有元素，若多个学生成绩相同则成绩相同的同学之间保留原来的输入顺序。
输入：
　　3
　　Alice female 18 98
　　Bob male 19 90
　　Miller male 17 92

输出：
　　Bob male 19 90
　　Miller male 17 92
　　Alice female 18 98
  
  
/*
  共需进行n-1趟，每一趟一个最大（小）的数沉底，然后比较第二趟，比较第二趟的时候j也是从下标0开始的。
*/  
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Stu{
	string name;
	string sex;
	int age;
	int score;
	Stu(){}
	Stu(string nn,string ss,int aa,int sc):name(nn),sex(ss),age(aa),score(sc){}
};
int main(){
	int n;
	cin>>n;
	Stu stu[n];
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].sex>>stu[i].age>>stu[i].score;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(stu[j].score>stu[j+1].score){
				Stu st=stu[j];stu[j]=stu[j+1];stu[j+1]=st;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<stu[i].name<<" "<<stu[i].sex<<" "<<stu[i].age<<" "<<stu[i].score<<endl; 
	}
}
