#include<bits/stdc++.h>
#define fi first
#define se second
#define mid ((l+r)>>1)
#define lc(x) (2*x)
#define rc(x) (2*x+1)
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e4 + 5;
int n,k;
struct node{
    int l,r,len;
    int lazy,now;
}tre[4*maxn];
vector<pair<int,int> >v[maxn];

void build(int x,int l,int r){
    tre[x].l=l;
    tre[x].r=r;
    tre[x].len=(r-l+1);
    tre[x].now=0;
    tre[x].lazy=0;
    if(l==r)return;
    build(lc(x),l,mid);
    build(rc(x),mid+1,r);
}

void lazy(int x){
    if(tre[x].len==1||tre[x].lazy==0)return;
    tre[x].lazy=0;
    tre[lc(x)].now = tre[lc(x)].len-tre[lc(x)].now;
    tre[rc(x)].now = tre[rc(x)].len-tre[rc(x)].now;
    tre[lc(x)].lazy ^= 1;
    tre[rc(x)].lazy ^= 1;
}

void ins(int x,int l,int r){
    if(tre[x].r<l||tre[x].l>r)return;
    lazy(x);
    if(tre[x].l>=l&&tre[x].r<=r){
        tre[x].lazy ^= 1;
        tre[x].now = tre[x].len-tre[x].now;
        return;
    }
    ins(lc(x),l,r);
    ins(rc(x),l,r);
    tre[x].now=tre[lc(x)].now+tre[rc(x)].now;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int i,j,a,b,c,d;
        for(i=1;i<=k;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            v[a].push_back(make_pair(c,d));
            v[b+1].push_back(make_pair(c,d));
        }
        build(1,1,n);
        ll ans=0;
        for(i=1;i<=n;i++){
            for(j=0;j<v[i].size();j++){
                ins(1,v[i][j].fi,v[i][j].se);
            }
            ans+=tre[1].now;
        }
        printf("%lld\n",ans);
        for(i=1;i<=n;i++){
            v[i].clear();
        }
    }
}

