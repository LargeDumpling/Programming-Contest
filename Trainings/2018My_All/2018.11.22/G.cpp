/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-11-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
struct Mat
{
	int num[5][5];
	Mat() { memset(num,0,sizeof(num)); }
	Mat operator*(const Mat &M)const;
}ini[1000050],ans;
inline int mul_mod(int a,int b)
{
    int ret;
    __asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mod));
    return ret;
}
Mat Mat::operator*(const Mat &M)const
{
	Mat ans;
	long long x;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			x=0;
			for(int k=0;k<5;k++)
				x=x+(long long)num[i][k]*M.num[k][j];
			ans.num[i][j]=x%mod;
		}
	return ans;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
Mat A[1050];
void pre_calc()
{
	A[1].num[0][0]=3LL;
	A[1].num[0][1]=mod-3LL;
	A[1].num[0][2]=1LL;
	A[1].num[0][3]=1LL;
	A[1].num[0][4]=1LL;
	A[1].num[1][0]=1LL;
	A[1].num[2][1]=1LL;
	A[1].num[3][3]=1LL;
	A[1].num[3][4]=1LL;
	A[1].num[4][4]=1LL;
	for(int i=0;i<5;i++) A[0].num[i][i]=1;
	for(int i=2;i<=1000;i++) A[i]=A[i-1]*A[1];
	ini[0]=Mat();
	ini[0].num[0][0]=15LL;
	ini[0].num[1][0]=5LL;
	ini[0].num[2][0]=1LL;
	ini[0].num[3][0]=3LL;
	ini[0].num[4][0]=1LL;
	ini[1]=A[997]*ini[0];
	for(int i=2;i<=1000000;i++)
		ini[i]=A[1000]*ini[i-1];
	return;
}
int main()
{
	pre_calc();
	int T_T,n;
	pre_calc();
	read1n(T_T);
	while(T_T-->0)
	{
		read1n(n);
		if(n==1) puts("1");
		else if(n==2) puts("5");
		else if(n==3) puts("15");
		else if(n<1000)
		{
			ans=A[n-3]*ini[0];
			printf("%I64d\n",ans.num[0][0]);
		}
		else
		{
			if(n%1000==0) printf("%I64d\n",ini[n/1000].num[0][0]);
			else
			{
				ans=A[n%1000]*ini[n/1000];
				printf("%I64d\n",ans.num[0][0]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

