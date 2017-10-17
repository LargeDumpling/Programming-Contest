#include <iostream>  
#include <string.h>  
#include <stdio.h>  
  
using namespace std;  
const int N = 20005;  
const int INF = 1<<30;  
  
int head[N];  
int son[N];  
bool vis[N];  
int cnt,n;  
int ans,size;  
  
struct Edge  
{  
    int to;  
    int next;  
};  
  
Edge edge[2*N];  
  
void Init()  
{  
    cnt = 0;  
    size = INF;  
    memset(vis,0,sizeof(vis));  
    memset(head,-1,sizeof(head));  
}  
  
void add(int u,int v)  
{  
    edge[cnt].to = v;  
    edge[cnt].next = head[u];  
    head[u] = cnt++;  
}  
  
void dfs(int cur)  
{  
    vis[cur] = 1;  
    son[cur] = 0;  
    int tmp = 0;  
    for(int i=head[cur];~i;i=edge[i].next)  
    {  
        int u = edge[i].to;  
        if(!vis[u])  
        {  
            dfs(u);  
            son[cur] += son[u] + 1;  
            tmp = max(tmp,son[u] + 1);  
        }  
    }  
    tmp = max(tmp,n-son[cur]-1);  
    if(tmp < size || tmp == size && cur < ans)  
    {  
        ans = cur;  
        size = tmp;  
    }  
}  
  
int main()  
{
	freopen("in.txt","r",stdin);
	freopen("other.txt","w",stdout);
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        Init();  
        scanf("%d",&n);  
        for(int i=1;i<=n-1;i++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            add(u,v);  
            add(v,u);  
        }  
        dfs(1);  
        printf("%d %d\n",ans,size);  
    }  
    fclose(stdin);
    fclose(stdout);
    return 0;  
}
