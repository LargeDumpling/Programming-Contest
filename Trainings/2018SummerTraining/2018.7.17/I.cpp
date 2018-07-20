//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int MAXC=10050;
struct jz
{
	int d,s,id;
	bool operator<(const jz &X)const
	{
		return s-d<=X.s-X.d;
	}
}soft[MAXN];
int n,c,f[MAXN][MAXC],pre[MAXN][MAXC],ans,ansi;
int used[MAXN];
int main()
{
	freopen("I.in","r",stdin);
	freopen("I.out","w",stdout);
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&soft[i].d,&soft[i].s);
		soft[i].id=i; 
	}
	sort(soft+1,soft+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=c;j++)
		{
			if(f[i][j]<f[i-1][j])
			{
				f[i][j]=f[i-1][j];
				pre[i][j]=(i-1)*100000+j;
			}
			if(soft[i].s<=j&&j<=c+soft[i].s-soft[i].d)
			{
				if(f[i][j]<f[i-1][j-soft[i].s]+1)
				{
					f[i][j]=f[i-1][j-soft[i].s]+1;
					pre[i][j]=(i-1)*100000+j-soft[i].s;
				}
			}
		}
	}
	ans=-1;
	for(int i=0;i<=c;i++)
	{
		if(ans<f[n][i])
		{
			ans=f[n][i];
			ansi=n*100000+i;
		}
	}
	printf("%d\n",ans);
	used[0]=0;
	while(ansi!=0)
	{
		int i,j,pj;
		j=ansi%100000; i=ansi/100000;
		ansi=pre[i][j];
		pj=ansi%100000;
		if(pj<j)
			used[++used[0]]=soft[i].id;
	}
	sort(used+1,used+used[0]+1);
	for(int i=1;i<=used[0];i++)
		printf("%d ",used[i]);
	return 0;
}


