#include<iostream>
#include<cstdio>
#include<cstldib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=12;
int koloro[MAXN],map[MAXN][MAXN],num[MAXN],n,cnt=0;
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
	memset(koloro,0,sizeof(koloro));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) if(i!=j)
		{
			if(gcd(num[i],num[j])==1) map[i][j]=0;
			else map[i][j]=1;
		}
	}
	koloro[1]=++cnt;
	for(int i=2;i<=n;i++)
	{
		koloro[i]=-1;
		for(int k=1;k<=MAXN;k++)
		{
			for(int j=1;j<=n;j++) if(i!=j)
			{
			}
		}
	}
}

