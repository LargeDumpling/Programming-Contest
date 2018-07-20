//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=25;
const int INF=2139062143;
int n,ps,limit;
int num[1<<18],f[2][1<<24],d[1<<24];
int main()
{
	int now=0;
	num[0]=0;
	scanf("%d%d",&n,&ps);
	limit=1<<n;
	for(int i=0;i<n;i++)
		scanf("%d",&d[1<<i]);
	for(int S=0;S<limit;S++)
	{
		int exmin=INF;
		bool flag=false;
		for(int i=0;i<n;i++)
			flag|=(S==(1<<i));
		if(flag) continue;
		d[S]=0;
		for(int i=0;i<n;i++)
			if((S&(1<<i)))
			{
				if((long long)d[S]+d[1<<i]>ps)
					d[S]=ps+1;
				else d[S]+=d[1<<i];
			}
			else
				exmin=min(exmin,d[1<<i]);
		if(ps<(long long)exmin+d[S]&&d[S]<=ps)
			num[++num[0]]=S;
	}
	/*cerr<<num[0]<<endl;
	for(int i=1;i<=num[0];i++)
		cerr<<num[i]<<" ";
	cerr<<endl;*/
	memset(f,127,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=num[0];i++)
	{
		memset(f[now^1],127,sizeof(f[now^1]));
		for(int S=0;S<limit;S++) if(f[now][S]!=INF)
		{
			f[now^1][S]=min(f[now^1][S],f[now][S]);
			f[now^1][S|num[i]]=min(f[now^1][S|num[i]],f[now][S]+1);
		}
		now^=1;
	}
	/*for(int i=0;i<n;i++)
	{
		now^=1;
		memset(f[now],127,sizeof(f[now]));
		for(int S=0;S<limit;S++)
		{
			if(f[now^1][S]!=INF) f[now][S]=f[now^1][S];
			for(S&(1<<i))
			{
				int preS=S&(~(1<<i));
				f[now][S]=min(f[now][S],f[now^1][preS]+1);
			}
	}*/
	printf("%d",f[now][limit-1]);
	return 0;
}


