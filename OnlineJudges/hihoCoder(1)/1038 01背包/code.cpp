#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,ned,val,f[100050];
int main()
{
	int i,j,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&ned,&val);
		for(j=m;j>=ned;j--)
			f[j]=max(f[j],f[j-ned]+val);
	}
	for(i=0;i<=m;i++)
		ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}

