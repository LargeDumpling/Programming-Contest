#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jp
{
	long long a,b;
	bool operator<(const jp &X)const { return a*b<X.a*X.b; }
}p[MAXN];
int n;
long long ans,tem=1LL;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%lld%lld",&p[i].a,&p[i].b);
	sort(p+1,p+n+1);
	tem=p[0].a;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,tem/p[i].b);
		tem*=p[i].a;
	}
	printf("%lld",ans);
	return 0;
}

