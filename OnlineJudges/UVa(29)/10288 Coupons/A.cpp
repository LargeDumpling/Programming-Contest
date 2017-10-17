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
#include<ctime>
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
struct jp1
{
	long long fz,fm,z;
	jp1(long long A=0,long long B=1,long long C=0)
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
	jp1 operator+(const jp1& A)
	{
		jp1 C;

		long long FM=lCm(A.fm,fm);
		C.fz=fz*(FM/fm)+A.fz*(FM/A.fm);
		C.fm=FM;

		/*C.fz=fz*A.fm+A.fz*fm;
		C.fm=fm*A.fm;*/

		C.z=z+A.z;
		return C;
	}
};
struct jp2
{
	long long fz,fm,z;
	jp2(long long A=0,long long B=1,long long C=0)
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
	jp2 operator+(const jp2& A)
	{
		jp2 C;

		/*long long FM=lCm(A.fm,fm);
		C.fz=fz*(FM/fm)+A.fz*(FM/A.fm);
		C.fm=FM;*/

		C.fz=fz*A.fm+A.fz*fm;
		C.fm=fm*A.fm;

		C.z=z+A.z;
		return C;
	}
};
bool check(jp1 A,jp2 B)
{
	return A.fz*B.fm==A.fm*B.fz;
}
int main()
{
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	srand(time(NULL));
	while(true)
	{
		int a=rand()+1,b=rand()+1,c=rand()+1,d=rand()+1;
		if(!check(jp1(a,b,0)+jp1(c,d,0),jp2(a,b,0)+jp2(c,d,0)))
		{
			printf("%d %d %d %d\n",a,b,c,d);
			system("pause");
		}
		printf("Yes\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

