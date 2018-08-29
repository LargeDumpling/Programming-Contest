/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=20000050;
int pri[MAXN],phi[MAXN];
long long S[MAXN];
bool exist[MAXN];
void Euler()
{
	memset(exist,true,sizeof(exist));
	S[0]=S[1]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i])
		{
			pri[++pri[0]]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0)
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else
				phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
		S[i]=S[i-1]+((i&1)?phi[i]/2:phi[i]);
	}
	return;
}
int gcd(int a,int b)
{
	int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	int T_T,n;
	Euler();
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		printf("%lld\n",S[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

