#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir[100050],end[200050],next[200050],lenth[200050],ed=0;
int dis[100050],n,m;
int dist[200050],p[200050],L[200050],R[200050],top;
struct jp
{
	int first,second;
	jp(int a=0,int b=0):first(a),second(b){}
	bool operator<(const jp X)const
	{
		return first==X.first?second<X.second:first<X.first;
	}
}nod[100050];
void swap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void addedge(int u,int v,int len)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	lenth[ed]=len;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	lenth[ed]=len;
	return;
}
int merge(int A,int B)
{
	if(!A)
		return B;
	else if(!B)
		return A;
	if(nod[B]<nod[A])
		swap(A,B);
	R[A]=merge(R[A],B);
	if(dist[L[A]]<dist[R[A]])
		swap(L[A],R[A]);
	dist[A]=R[A]?dist[R[A]]+1:0;
	return A;
}
void Hijkstra()
{
	bool exist[100050];
	memset(exist,false,sizeof(exist));
	memset(dis,127,sizeof(dis));
	int u;
	exist[0]=true;
	nod[p[++p[0]]]=jp(0,1);
	top=merge(top,p[p[0]]);
	dis[1]=0;
	while(top)
	{
		u=nod[top].second;
		p[p[0]--]=top;
		top=merge(L[top],R[top]);
		if(exist[u])continue;
		exist[u]=true;
		for(int i=fir[u];i;i=next[i])
		{
			if(exist[end[i]]||dis[u]+lenth[i]>=dis[end[i]])
				continue;
			dis[end[i]]=dis[u]+lenth[i];
			nod[p[++p[0]]]=jp(dis[end[i]],end[i]);
			L[p[p[0]]]=R[p[p[0]]]=0;
			top=merge(top,p[p[0]]);
		}
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("Hijkstra.txt","w",stdout);
	for(int i=0;i<100050;i++)p[i]=i;
	int a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	Hijkstra();
	for(int i=1;i<=n;i++)
		printf("%d\n",dis[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

