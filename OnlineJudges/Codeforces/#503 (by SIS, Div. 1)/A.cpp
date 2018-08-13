/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=3050;
const long long INF=1e14;
int n,m,p[MAXN];
long long c[MAXN],f[2][MAXN][MAXN],ans;
vector<long long> q[MAXN];
bool exist[MAXN][MAXN];
struct jz
{
	int u,limit,tim;
	jz(const int &U=0,const int &L=0,const int &T=0):u(U),limit(L),tim(T) { }
};
queue<jz> qu;
int main()
{
	int u,limit,nu,nl,now=0,tem;
	long long sum;
	scanf("%d%d",&n,&m);
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			f[0][i][j]=f[1][i][j]=INF;
	memset(exist,false,sizeof(exist));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%lld",&p[i],&c[i]);
		q[p[i]].push_back(c[i]);
	}
	for(int i=0;i<=(int)q[1].size();i++)
	{
		f[now][i][0]=0;
		qu.push(jz(i,0,1));
	}
	for(int i=2;i<=m;i++)
	{
		//printf("%d\n",i);
		now^=1;
		for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) f[now][j][k]=INF;
		sort(q[i].begin(),q[i].end());
		sum=0;
		for(int j=0;j<(int)q[i].size();j++)
			sum+=q[i][j];
		tem=sum;
		while(qu.size()&&qu.front().tim<i)
		{
			u=qu.front().u;
			limit=qu.front().limit;
			exist[u][limit]=false;
			qu.pop();
			sum=tem;
			for(int j=0;j<=(int)q[i].size();j++)
			{
				nl=max(limit,j);
				nu=u+q[i].size()-j;
				if(f[now^1][u][limit]+sum<f[now][nu][nl])
				{
					f[now][nu][nl]=f[now^1][u][limit]+sum;
					if(!exist[nu][nl])
					{
						exist[nu][nl]=true;
						qu.push(jz(nu,nl,i));
						//printf("(%d,%d)=%lld %d\n",nu,nl,f[now][nu][nl],i);
					}
				}
				if(sum) sum-=q[i][q[i].size()-1-j];
			}
		}
		/*putchar('\n');
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				if(f[now][j][k]!=INF)
					printf("(%d,%d)=%lld\n",j,k,f[now][j][k]);*/
	}
	ans=INF;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) if(i>j&&f[now][i][j]<ans)
			ans=f[now][i][j];
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

