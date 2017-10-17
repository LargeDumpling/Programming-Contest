/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pri[50000],en[50000],num[50000];
void calc_pri()
{
	bool exist[50000];
	memset(exist,true,sizeof(exist));
	int t;
	pri[0]=0;
	for(int i=2;i<50000;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&(t=i*pri[j])<50000;j++)
		{
			exist[t]=false;
			if(!(i%pri[j]))break;
		}
	}
	return;
}
int gCd(int m,int n)
{
	int t;
	while(n)
	{
		t=m%n;
		m=n;
		n=t;
	}
	return m;
}
int calc(long long x)
{
	bool flag=false;
	en[0]=0;
	if(x<0)flag=true,x=-x;
	for(int i=1;i<=pri[0]&&x>1;i++)
	{
		if(!(x%pri[i]))
		{
			en[++en[0]]=pri[i];
			num[en[0]]=0;
			while(!(x%pri[i]))
				x/=pri[i],num[en[0]]++;
		}
	}
	if(x>1)
		return 1;
	int nogcd=num[1];
	for(int i=2;i<=en[0];i++)
		nogcd=gCd(nogcd,num[i]);
	if(flag)while(!(nogcd&1))nogcd>>=1;
	return nogcd;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long n;
	calc_pri();
	while(scanf("%lld",&n)!=-1&&n)
		printf("%d\n",calc(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

