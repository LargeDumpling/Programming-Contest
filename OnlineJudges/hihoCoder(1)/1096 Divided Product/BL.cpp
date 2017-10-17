#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,m;
long long ans=0;
void DFS(int sum,int last,long long mul)
{
	if(sum==n&&!(mul%m))
		ans=(ans+1)%mod;
	if(sum+last+1>n)
		return;
	for(int i=last+1;i<=n;i++)
		DFS(sum+i,i,mul*i);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	DFS(0,0,1);
	printf("%lld",ans);
	return 0;
}

