/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
    2016-03-06    File created.
*/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=205;
const int MAXM=1050;
const int INF=2147483647;
int fir[3*MAXN],cur[3*MAXN],lev[3*MAXN],eNd[2*MAXM],nxt[2*MAXM],f[2*MAXM],mono[2*MAXM],pre[2*MAXM],ed,S,T;
int T_T,n,m,K,W,SS[MAXN],TT[MAXN],w[MAXN],op[MAXN];
bool exist[3*MAXN];
void init()
{
    memset(fir,0,sizeof(fir));
    ed=1; S=3*MAXN-2; T=3*MAXN-1;
    return;
}
void addedge(int u,int v,int cap,int val)
{
    eNd[++ed]=v;
    nxt[ed]=fir[u];
    fir[u]=ed;
    f[ed]=cap;
    mono[ed]=val;
    eNd[++ed]=u;
    nxt[ed]=fir[v];
    fir[v]=ed;
    f[ed]=0;
    mono[ed]=-val;
    return;
}
bool BFS()
{
    int u;
    queue<int>q;
    memset(exist,false,sizeof(exist));
    memset(lev,-1,sizeof(lev));
    lev[S]=pre[S]=0;
    q.push(S);
    while(q.size())
    {
        u=q.front(); q.pop();
        exist[u]=false;
        for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[eNd[i]]<lev[u]+mono[i])
        {
            lev[eNd[i]]=lev[u]+mono[i];
            pre[eNd[i]]=i;
            if(!exist[eNd[i]])
            {
                exist[eNd[i]]=true;
                q.push(eNd[i]);
            }
        }
    }
    memcpy(cur,fir,sizeof(fir));
    return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
    if(u==T||!maxf) return maxf;
    if(lev[u]==-1) return 0;
    exist[u]=true;
    int cnt=0;
    for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[u]+mono[i]==lev[eNd[i]])
    {
        if(exist[eNd[i]]) continue;
        tem=DFS(eNd[i],min(f[i],maxf));
        maxf-=tem;
        f[i]-=tem;
        f[i^1]+=tem;
        cnt+=tem;
        if(!maxf) break;
    }
    if(!cnt) lev[u]=-1;
    exist[u]=false;
    return cnt;
}
int Augment()
{
    int delta=INF;
    for(int i=pre[T];i;i=pre[eNd[i^1]])
        if(f[i]<delta)
            delta=f[i];
    for(int i=pre[T];i;i=pre[eNd[i^1]])
    {
        f[i]-=delta;
        f[i^1]+=delta;
    }
    return delta*lev[T];
}
int MCMF()
{
    int ans=0;
    memset(exist,false,sizeof(exist));
    while(BFS())
        ans+=Augment();
    return ans;
}
int main()
{
    int SS,TT,w,op;
    scanf("%d",&T_T);
    while(T_T--)
    {
        init();
        scanf("%d%d%d%d",&n,&m,&K,&W);
        addedge(S,S-1,K,0);
        addedge(S-1,1,K,0);
        addedge(S-1,n+1,K,0);
        for(int i=1;i<n;i++)
        {
            addedge(i,i+1,K,0);
            addedge(n+i,n+i+1,K,0);
        }
        addedge(n,T,K,0);
        addedge(2*n,T,K,0);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&SS,&TT,&w,&op);
            addedge(SS+(op^1)*n,2*n+i,1,W);
			addedge(SS+op*n,2*n+i,1,0);
			addedge(2*n+i,TT+op*n,1,w-W);
        }
        printf("%d\n",MCMF());
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

