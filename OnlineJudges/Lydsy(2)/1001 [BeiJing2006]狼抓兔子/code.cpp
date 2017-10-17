#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int fir[2050050],end[6050050],next[6050050],len[6050050],ed=0,s,t,n,m;
int dis[2050050];
bool exist[2050050];
queue<int>q;
void addedge(int u,int v,int L)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=L;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=L;
	return;
}
int SPFA()
{
	int u;
	memset(dis,127,sizeof(dis));
	memset(exist,false,sizeof(exist));
	q.push(s);
	dis[s]=0;
	while(q.size())
	{
		u=q.front();
		q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])
		{
			if(dis[end[i]]<=dis[u]+len[i])
				continue;
			dis[end[i]]=dis[u]+len[i];
			if(!exist[end[i]])
			{
				q.push(end[i]);
				exist[end[i]]=true;
			}
		}
	}
	return dis[t];
}
int read1n()
{
	int x=0;char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int temp,a,b,i,j;
	//scanf("%d%d",&n,&m);
	n=read1n();
	m=read1n();
	if(n!=1&&m!=1)
	{
		s=2*n*m+5;
		t=s+1;
		n--;
		m--;
		for(i=1;i<=n+1;i++)
			for(j=1;j<=m;j++)
			{
				//scanf("%d",&temp);
				temp=read1n();
				a=(i==n+1)?2*(i-2)*m+2*j-1:2*(i-1)*m+2*j;
				b=(i==1||i==n+1)?(i==1?t:s):2*(i-2)*m+2*j-1;
				addedge(a,b,temp);
			}
		for(i=1;i<=n;i++)
			for(j=1;j<=m+1;j++)
			{
				//scanf("%d",&temp);
				temp=read1n();
				a=(j==1)?s:2*(i-1)*m+2*(j-1);
				b=(j==m+1)?t:2*(i-1)*m+2*j-1;
				addedge(a,b,temp);
			}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				//scanf("%d",&temp);
				temp=read1n();
				a=2*(i-1)*m+2*j-1;
				b=a+1;
				addedge(a,b,temp);
			}
		printf("%d",SPFA());
	}
	else
	{
		if(n<m)
		{
			n^=m;
			m=n^m;
			n^=m;
		}
		m=2147483647;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			if(temp<m)
				m=temp;
		}
		printf("%d",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

