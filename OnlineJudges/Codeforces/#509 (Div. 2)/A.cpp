#include<bits/stdc++.h>
#define lc(x) (2*x)
#define rc(x) (2*x+1)
#define fi first
#define se second
#define low(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e3+5;
const ll mod = 1e9+7;
int g[maxn];
int f[maxn];

int main(){
    int n;
    int i,j,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&g[i]);
    sort(g+1,g+1+n);
    for(i=1;i<=n;i++){
        if(g[i]-g[1]>n)break;
        f[g[i]-g[1]]=1;
    }
    int ans = 0;
    for(i=0;i<n;i++)if(!f[i])ans++;
    printf("%d",ans);
}

