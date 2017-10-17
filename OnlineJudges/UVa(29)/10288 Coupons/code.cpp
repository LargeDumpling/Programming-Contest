/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long gCd(long long a,long long b)
{
	long long t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
long long lCm(long long a,long long b)
{
	long long t=gCd(a,b);
	return a*b/t;
}
struct jp
{
	long long fz,fm,z;
	jp(long long A=0,long long B=1,long long C=0)
	{
		long long t=gCd(A,B);
		if(t>1)
		{
			A/=t;
			B/=t;
		}
		fz=A;
		fm=B;
		z=C;
	}
	void maintain()
	{
		long long t=gCd(fz,fm);
		fz/=t;
		fm/=t;
		z+=fz/fm;
		fz%=fm;
		return;
	}
	jp operator+(const jp& A)
	{
		jp C;

		/*long long FM=lCm(A.fm,fm);
		C.fz=fz*(FM/fm)+A.fz*(FM/A.fm);
		C.fm=FM;*/

		C.fz=fz*A.fm+A.fz*fm;//?
		C.fm=fm*A.fm;

		C.z=z+A.z;
		C.maintain();
		return C;
	}
	void print()
	{
		int num=0;
		for(int x=z;x;x/=10,num++);
		if(fz)
		{
			for(int i=0;i<=num;i++)putchar(' ');
			printf("%lld\n",fz);
			num=0;
			for(long long x=fm;x;x/=10,num++);
		}
		printf("%lld",z);
		if(fz)
		{
			putchar(' ');
			for(int i=1;i<=num;i++)putchar('-');
			printf("\n ");
			for(int x=z;x;x/=10)putchar(' ');
			printf("%lld",fm);
		}
		putchar('\n');
		return;
	}
}ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=-1)
	{
		ans=jp(0,1,0);
		for(long long i=1;i<=n;i++)
			ans=ans+jp(n,i,0);
		ans.print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

