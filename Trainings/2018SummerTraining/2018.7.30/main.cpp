#include <bits/stdc++.h>
#define low(x) ((x)&(-x))

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e7+50;
int n,m,k,p,q,r,MOD,len;
int g[maxn],nex[maxn],fro[maxn];
ll val;
struct node{
    int x,to;
}edg[maxn];

template<typename Ty>
bool read1n(Ty &x)
{
    char ch; bool neg=false;
    for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
        if(ch=='-')
            neg=true;
        else if(ch==-1)return false;
    for(x=0;'0'<=ch&&ch<='9';ch=getchar())
        x=(x<<1)+(x<<3)+ch-'0';
    if(neg) x=-x;
    return true;
}

void add(int a,int b){
    ++len;
    edg[len].x = b;
    edg[len].to = fro[a];
    fro[a]=len;
}

int vec[maxn],fa[maxn];
void change(int x){
    vec[x]=0;
    int i,j;
    for(i=fro[x];i!=-1;i=edg[i].to){
        j = edg[i].x;
        vec[j]++;
        fa[j]=x;
    }
}
int st[maxn];
/*int findf(int x){
    if(fa[x]==x)return x;
    int a = fa[x];
    fa[x]=findf(fa[x]);
    if(a!=fa[x])vec[x]+=vec[a];
    return fa[x];
}*/
int findf(int x)
{
    if(fa[x]==x) return x;
    int pres,u;
    st[st[0]=1]=x;
    while(fa[st[st[0]]]!=st[st[0]])
        st[++st[0]]=fa[st[st[0]]];
    pres=st[st[0]];
    while(st[0])
    {
        u=st[st[0]];
        if(fa[u]!=pres)
        {
            vec[u]+=vec[fa[u]];
            fa[u]=pres;
        }
        st[0]--;
    }
    return fa[x];
}

void solve(){
    val = 0;
    int i,j,a,b;
    a = 1;b = 0;
    for(i=1;i<=n;i++){
        nex[i]=0;
        fro[i]=-1;fa[i]=i;
        while(a<=b&&vec[a]<=i-m)a++;
        while(a<=b&&g[vec[b]]<g[i]){
            nex[vec[b--]]=i;
        }
        vec[++b]=i;
        if(i>=m)val += g[vec[a]]^(i-m+1);
    }
    printf("%lld ",val);

    len = 0;
    for(i=1;i<=n;i++)if(nex[i]){
        add(nex[i],i);
    }
    len = 0;val = 0;
    for(i=1;i<=n;i++){
        change(i);
        if(i>=m){
            findf(i-m+1);
            if(g[i-m+1]==0)val += vec[i-m+1]^(i-m+1);
            else val +=(vec[i-m+1]+1)^(i-m+1);
        }
    }
    printf("%lld\n",val);
}

int main(){
	freopen("A.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&MOD);
        int i,j,a,b;
        for(i=1;i<=k;i++)read1n(g[i]);
        for(;i<=n;i++){
            g[i]= ((ll)p*(ll)g[i-1] + (ll)q*(ll)i + r)%MOD ;
        }
        solve();
    }
}
