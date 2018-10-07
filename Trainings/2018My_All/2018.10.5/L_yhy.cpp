#include <bits/stdc++.h>
#define low(x) ((x)&(-x))

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 2e5+5;
ll n,k;

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

ll chu(int a,int b){
    return a/b;
}

bool check(ll x){
    if(x==1)return 1;
    ll y = chu(n,x);
  //  cout<<x<<"?"<<endl;
    if(chu(n,x+1)==y||chu(n,x-1)==y)return 0;
   // cout<<x<<'!'<<endl;
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
	{
        scanf("%lld%lld",&n,&k);
        ll l=1,r=n,mid;
        while(l!=r)
		{
            mid=(l+r)>>1;
            mid++;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        printf("%lld ",l+chu(n,l+1));
        if(l>=k) printf("%lld\n",chu(n,k));
        else printf("%lld\n",chu(n,l+1)-k+l+1);
    }
}

