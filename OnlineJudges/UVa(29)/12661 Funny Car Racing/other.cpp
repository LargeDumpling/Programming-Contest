#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1e5+100;
const int inf=1<<29;
int e,n,m,s,t,head[maxn],nxt[maxn],cost[maxn],a[maxn],b[maxn],pnt[maxn],dist[maxn];
bool vis[maxn];
queue<int> q;
void AddEdge(int u,int v,int c,int sa,int sb)
{
    pnt[e]=v;nxt[e]=head[u];cost[e]=c;a[e]=sa;b[e]=sb;head[u]=e++;
}
int Spfa(int st,int des)
{
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    dist[st]=0;
    memset(vis,0,sizeof(vis));
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i])
        {
            int v=pnt[i];
            int val=dist[u],s=dist[u];
            val=val%(a[i]+b[i]);
            if(val>a[i])
                s+=b[i]-(val-a[i]);
            else if(a[i]-val<cost[i])
                s+=b[i]+a[i]-val;
            if(s+cost[i]<dist[v])
            {
                dist[v]=s+cost[i];
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return dist[des];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int cas=1;
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            int u,v,a,b,t;
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
            if(a>=t)
                AddEdge(u,v,t,a,b);
        }
        printf("Case %d: %d\n",cas++,Spfa(s,t));
    }    
    return 0;
}

