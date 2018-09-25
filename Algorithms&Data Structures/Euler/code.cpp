#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int pri[MAXN],phi[MAXN],u[MAXN];
bool vis[MAXN];
void Euler()
{
	memset(vis,true,sizeof(vis));
	pri[0]=0;
	u[1]=1; phi[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(vis[i])
		{
			pri[++pri[0]]=i;
			phi[i]=i-1;
			u[i]=-1;
		}
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			vis[i*pri[j]]=false;
			if(i%pri[j])
			{
				phi[i*pri[j]]=phi[i]*(pri[j]-1);
				u[i*pri[j]]=-u[i];
			}
			else
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
		}
	}
}
int main()
{
	Euler();
	for(int i=1;i<=20;i++)
		printf("%d %d %d\n",i,phi[i],u[i]);
	return 0;
}

