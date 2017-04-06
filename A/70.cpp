
    在对银行账户等重要权限设置密码的时候，我们常常遇到这样的烦恼：如果为了好记用生日吧，容易被破解，不安全；如果设置不好记的密码，又担心自己也会忘记；
如果写在纸上，担心纸张被别人发现或弄丢了...

    这个程序的任务就是把一串拼音字母转换为6位数字（密码）。我们可以使用任何好记的拼音串(比如名字，王喜明，就写：wangximing)作为输入，程序输出6位数字。

    变换的过程如下：

    第一步. 把字符串6个一组折叠起来，比如wangximing则变为：
    wangxi
    ming 

    第二步. 把所有垂直在同一个位置的字符的ascii码值相加，得出6个数字，如上面的例子，则得出：
    228 202 220 206 120 105

    第三步. 再把每个数字“缩位”处理：就是把每个位的数字相加，得出的数字如果不是一位数字，就再缩位，直到变成一位数字为止。例如: 228 => 2+2+8=12 => 1+2=3

    上面的数字缩位后变为：344836, 这就是程序最终的输出结果！

    要求程序从标准输入接收数据，在标准输出上输出结果。

    输入格式为：第一行是一个整数n（<100），表示下边有多少输入行，接下来是n行字符串，就是等待变换的字符串。
    输出格式为：n行变换后的6位密码。

    例如，输入：
5
zhangfeng
wangximing
jiujingfazi
woaibeijingtiananmen
haohaoxuexi

    则输出：
772243
344836
297332
716652
875843

    注意：

    请仔细调试！您的程序只有能运行出正确结果的时候才有机会得分！
    
    在评卷时使用的输入数据与试卷中给出的实例数据可能是不同的。

    请把所有函数写在同一个文件中，调试好后，存入与【考生文件夹】下对应题号的“解答.txt”中即可。
    
    相关的工程文件不要拷入。
    
    源代码中不能能使用诸如绘图、Win32API、中断调用、硬件操作或与操作系统相关的API。
    
    允许使用STL类库，但不能使用MFC或ATL等非ANSI c++标准的类库。例如，不能使用CString类型（属于MFC类库）。



#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char cr[100];
int N,A[6];
int solve(int n){/*将一个数字的各个位数相加*/
	if(n/10==0){
		return n;
	}
	int tot=0;
	while(n/10){
		tot+=n%10;
		n/=10;
	}
	tot+=n%10;
	return solve(tot);
}
void change(char *ca,int ln){/*将字符处理为数字*/
	int tot;
	for(int i=0;i<ln;i++){
		A[i%6]+=ca[i];
	}
	for(int i=0;i<6;i++){
		A[i]=solve(A[i]);
	}
}
int main(){
	int len;
	cin>>N;
	getchar();/*这个很重要，要加上，不然不能够正确输入后面的字符串*/
	for(int i=0;i<N;i++){/*输入各个字符串*/
		gets(cr);
		len=strlen(cr);
		//cout<<"len="<<len<<endl;
		change(cr,len);
		for(int i=0;i<6;i++){
			cout<<A[i];
		}
		cout<<endl;
		//memset(A,0,sizeof(0));
		for(int i=0;i<6;i++) A[i]=0;
	}
	
}
