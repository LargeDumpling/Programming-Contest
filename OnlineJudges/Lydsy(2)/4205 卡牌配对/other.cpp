#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#define inf 1000000000
#define ll long long
using namespace std;
ll read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct data{
	int x,y,z;	
}a[30005],b[30005];
struct edge{
	int to,next,v;
}e[4000005];
int n1,n2,ans,tot,cnt=1,ind,T;
int pri[205],id[50][50];
int q[70005],h[70005],last[70005];
vector<int>v[205];
bool mark[205];
void insert(int u,int v,int w)
{
	e[++cnt]=(edge){v,last[u],w};last[u]=cnt;
	e[++cnt]=(edge){u,last[v],0};last[v]=cnt;
}
bool bfs()
{
	int head=0,tail=1;
	memset(h,-1,sizeof(h));
	q[0]=0;h[0]=0;
	while(head!=tail)
	{
	int x=q[head];head++;
	for(int i=last[x];i;i=e[i].next)
	if(h[e[i].to]==-1&&e[i].v)
	{
	h[e[i].to]=h[x]+1;
	q[tail++]=e[i].to;
	}
	}
	return h[T]!=-1;
}
int dfs(int x,int f)
{
	if(x==T)return f;
	int w,used=0;
	for(int i=last[x];i;i=e[i].next)
	if(h[e[i].to]==h[x]+1)
	{
	w=dfs(e[i].to,min(e[i].v,f-used));
	e[i].v-=w;e[i^1].v+=w;used+=w;
	if(used==f)return f;
	}
	if(!used)h[x]=-1;
	return used;
}
void pre()
{
	for(int i=2;i<=200;i++)
	{
	if(!mark[i])pri[++tot]=i;
	for(int j=1;j<=tot&&pri[j]*i<=200;j++)
	{
	mark[pri[j]*i]=1;
	if(i%pri[j]==0)break;
	}
	}
	for(int i=2;i<=200;i++)
	for(int j=1;j<=tot;j++)
	if(i%pri[j]==0)v[i].push_back(j);
}
void build(int t,int f)
{
	int x,y,z;
	if(!f)x=a[t].x,y=a[t].y,z=a[t].z;
	else x=b[t].x,y=b[t].y,z=b[t].z;
	for(int i=0;i<v[x].size();i++)
	for(int j=0;j<v[y].size();j++)
	if(!f)insert(t,n1+n2+id[v[x][i]][v[y][j]],1);
	else insert(n1+n2+id[v[x][i]][v[y][j]],n1+t,1);
	for(int i=0;i<v[x].size();i++)
	for(int j=0;j<v[z].size();j++)
	if(!f)insert(t,n1+n2+id[v[x][i]][v[z][j]]+46*46,1);
	else insert(n1+n2+id[v[x][i]][v[z][j]]+46*46,n1+t,1);
	for(int i=0;i<v[y].size();i++)
	for(int j=0;j<v[z].size();j++)
	if(!f)insert(t,n1+n2+id[v[y][i]][v[z][j]]+46*46*2,1);
	else insert(n1+n2+id[v[y][i]][v[z][j]]+46*46*2,n1+t,1);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	pre();
	n1=read();n2=read();T=n1+n2+46*46*3+1;
	for(int i=1;i<=n1;i++)
	a[i].x=read(),a[i].y=read(),a[i].z=read();
	for(int i=1;i<=n2;i++)
	b[i].x=read(),b[i].y=read(),b[i].z=read();
	for(int i=1;i<=46;i++)
	for(int j=1;j<=46;j++)
	id[i][j]=++ind;
	for(int i=1;i<=n1;i++)
	{
	insert(0,i,1);build(i,0);
	}
	for(int i=1;i<=n2;i++)
	{
	insert(n1+i,T,1);build(i,1);
	}
	while(bfs())ans+=dfs(0,inf);
	printf("%d\n",ans);
	return 0;
}
