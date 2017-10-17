#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
const int MAXM=100050;
int n,m;
double v[MAXN];
int main()
{
	int a,b;
	double c,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf",&v[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&a,&b,&c);
		v[a]+=c/2.;
		v[b]+=c/2.;
	}
	sort(v+1,v+n+1);
	for(int i=n;i;i--)
	{
		if(i&1) ans-=v[i];
		else ans+=v[i];
	}
	printf("%d",(int)ans);
	return 0;
}

