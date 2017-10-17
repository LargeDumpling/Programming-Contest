#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
long long solve()
{
	if(n==1)return 2;
	long long ans=0;
	int en=0,temp;
	m=sqrt(n);
	for(int i=2;i<=m;i++)if(!(n%i))
	{
		en++;temp=1;
		while(!(n%i))n/=i,temp*=i;
		ans+=temp;
	}
	if(n>1)ans+=n;
	if(!en||(en==1&&n==1))ans++;
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
		printf("Case %d: %lld\n",cAse,solve());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

