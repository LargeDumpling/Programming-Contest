#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long 
#define inf 2000000000
#define mod 1000000007
#define N 300005
using namespace std;
int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,m,top,cnt;
int c[N][2];
int mx[N],fa[N],v[N],tag[N];
int q[N],a[N],b[N],last[N];
bool rev[N];
struct edge{int to,next;}e[N<<1];
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void update(int x)
{
    int l=c[x][0],r=c[x][1];
    mx[x]=max(mx[l],mx[r]);
    mx[x]=max(mx[x],v[x]);
}
void pushdown(int x)
{
    int l=c[x][0],r=c[x][1];
    if(rev[x])
    {
        rev[l]^=1;rev[r]^=1;rev[x]^=1;
        swap(c[x][0],c[x][1]);
    }
    if(tag[x])
    {
        if(l){tag[l]+=tag[x];mx[l]+=tag[x];v[l]+=tag[x];}
        if(r){tag[r]+=tag[x];mx[r]+=tag[x];v[r]+=tag[x];}
        tag[x]=0;
    }
}
bool isroot(int x)
{
    return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}
void rotate(int x)
{
    int y=fa[x],z=fa[y],l,r;
    if(c[y][0]==x)l=0;else l=1;r=l^1;
    if(!isroot(y))
    {
        if(c[z][0]==y)c[z][0]=x;
        else c[z][1]=x;
    }
    fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
    c[y][l]=c[x][r];c[x][r]=y;
    update(y);update(x);
}
void splay(int x)
{
    top=0;q[++top]=x;
    for(int i=x;!isroot(i);i=fa[i])
        q[++top]=fa[i];
    while(top)pushdown(q[top--]);
    while(!isroot(x))
    {
        int y=fa[x],z=fa[y];
        if(!isroot(y))
        {
            if(c[y][0]==x^c[z][0]==y)rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
void access(int x)
{
    for(int t=0;x;t=x,x=fa[x])
        splay(x),c[x][1]=t,update(x);
}
void makeroot(int x)
{
    access(x);splay(x);rev[x]^=1;
}
void link(int x,int y)
{
    makeroot(x);fa[x]=y;
}
void cut(int x,int y)
{
    makeroot(x);access(y);splay(y);
	c[y][0]=fa[c[y][0]]=0;update(y);
}
int find(int x)
{
    access(x);splay(x);
    while(c[x][0])x=c[x][0];
    return x;
}
void add(int x,int y,int val)
{
    makeroot(x);access(y);splay(y);
	tag[y]+=val;mx[y]+=val;v[y]+=val;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++)
            last[i]=tag[i]=rev[i]=fa[i]=c[i][0]=c[i][1]=0;
        mx[0]=-inf;cnt=0;
        for(int i=1;i<n;i++)
        {
            int u=read(),v=read();
            insert(u,v);
        }
        for(int i=1;i<=n;i++)mx[i]=v[i]=read();
        q[++top]=1;
        for(int k=1;k<=top;k++)
        {
            int now=q[k];
            for(int i=last[now];i;i=e[i].next)
                if(e[i].to!=fa[now])
                {
                    fa[e[i].to]=now;
                    q[++top]=e[i].to;
                }
        }
        m=read();
        while(m--)
        {
        	if(m==6)
			m=6;
            int opt=read(),x=read(),y=read(),w;
            switch(opt)
            {
            case 1:
                if(find(x)==find(y)){puts("-1");break;}
                link(x,y);break;
            case 2:
                if(find(x)!=find(y)||x==y){puts("-1");break;}
				cut(x,y);
                break;
            case 3:
				w=x;x=y;y=read();
				if(find(x)!=find(y)){puts("-1");break;}
                add(x,y,w);break;
            case 4:
                if(find(x)!=find(y)){puts("-1");break;}
                makeroot(x);access(y);splay(y);printf("%d\n",mx[y]);break;
            }
        }
		puts("");
    }
    return 0;
}
