#include <bits/stdc++.h>
#define foreach(it,v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
using namespace std;
typedef long long ll;
const int maxn = 1120;
bool check[maxn];
int prime[1120];
ll dp[1122][15];
int init(int n)
{
    memset(check,0,sizeof check);
    int tot = 0;
    check[0] = check[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!check[i])prime[tot++] = i;
        for(int j = 0; j < tot; ++j) {
            if((ll)i*prime[j]>n)break;
            check[i*prime[j]] = true;
            if(i%prime[j]==0)break;
        }
    }
    return tot;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int n,k;
    int tot = init(maxn-1);
    while(~scanf("%d%d",&n,&k)&&n) {
       memset(dp,0,sizeof dp);
       dp[0][0] = 1;
       for(int i = 0; prime[i]<=n&&i < tot; i++) {
            int limt = min(i+1,k);
            int w = prime[i];
            for(int V = n; V >= w; V--)
            for(int j = 1; j <= limt; j++)if(dp[V-w][j-1]){
                dp[V][j] += dp[V-w][j-1];
            }
       }
       cout<<dp[n][k]<<endl;
    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}
