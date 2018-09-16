/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline int mul_mod(int a,int b)
{
	int ret;
	__asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mod));
	return ret;
}
struct Mat
{
	int num[9][9];
	Mat() { memset(num,0,sizeof(num)); }
	Mat operator*(const Mat &X)const
	{
		Mat ans;
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				for(int k=0;k<9;k++)
				{
					ans.num[i][j]+=mul_mod(num[i][k],X.num[k][j]);
					if(mod<=ans.num[i][j]) ans.num[i][j]-=mod;
				}
		return ans;
	}
}Coe;
Mat pow(Mat X,long long n)
{
	Mat ans;
	for(int i=0;i<9;i++) ans.num[i][i]=1;
	while(n)
	{
		if(n&1) ans=ans*X;
		X=X*X;
		n>>=1;
	}
	return ans;
}
int T_T;
int main()
{
	int ans;
	long long n;
	scanf("%d",&T_T);
	for(int i=0;i<9;i++)
	{
		int t=i%3;
		for(int j=0;j<3;j++)
			Coe.num[t*3+j][i]=1;
	}
	Coe.num[0][0]=0;
	Coe.num[4][4]=0;
	Coe.num[8][8]=0;
	Coe.num[5][1]=0;
	Coe.num[3][7]=0;
	Coe.num[1][3]=0;
	Coe.num[7][5]=0;
	while(T_T--)
	{
		scanf("%lld",&n);
		if(n<3)
		{
			switch(n)
			{
				case 1:
					puts("3");
					break;
				case 2:
					puts("9");
					break;
				default:
					break;
			}
			continue;
		}
		n-=2;
		Mat X=pow(Coe,n);
		ans=0;
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			{
				ans+=X.num[i][j];
				if(mod<=ans) ans-=mod;
			}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

