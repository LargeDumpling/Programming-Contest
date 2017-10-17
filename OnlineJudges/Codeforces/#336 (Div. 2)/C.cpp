/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct jp
{
	int fir,sec;
	jp(int a=0,int b=0):fir(a),sec(b){}
	bool operator<(const jp X)const { return fir==X.fir?sec<X.sec:fir<X.fir; }
}JP[100050];
int n,f[100050];
int main()
{
	int a,b,cnt=0,l,r,mid,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		JP[i]=jp(a,b);
	}
	sort(JP+1,JP+n+1);
	f[0]=0;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		if(i==1)
		{
			ans=min(ans,n-f[1]);
			continue;
		}
		l=0,r=i-1;
		cnt=max(JP[i].fir-JP[i].sec,0);
		while(r>l+1)
		{
			mid=(l+r)>>1;
			if(JP[mid].fir<cnt) l=mid;
			else r=mid;
		}
		if(JP[r].fir<cnt)l=r;
		f[i]+=f[l];
		ans=min(ans,n-f[i]);
	}
	cout<<ans;
	return 0;
}
/*#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100000 + 5;
struct D
{
    int u, v;
}d[MAXN], e[MAXN];
bool cmp(D a, D b){return a.u < b.u;}
int dp[MAXN];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        d[0].u = 0;
        for(int i = 1 ; i <= n ; i++)   scanf("%d%d", &d[i].u, &d[i].v);
        sort(d + 1, d + n + 1, cmp);
        dp[0] = 0;
        int ans = n;
        for(int i = 1 ; i <= n ; i++){
            dp[i] = 1;
            if(i == 1)  continue;
            int val = d[i].u - d[i].v;
            val = max(val, 0);
            int le = 0, re = i - 1;
            while(le < re - 1){
                int mid = (le + re) >> 1;
                if(d[mid].u < val) le = mid;
                else re = mid;
            }
            int mark;
            if(d[re].u < val)  mark = re;
            else mark = le;
            dp[i] += dp[mark];
//            printf("ans[%d] = %d, mark = %d\n", i, dp[i], mark);
        }
        for(int i = 1 ; i <= n ; i++)   ans = min(ans, n - dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}
*/
