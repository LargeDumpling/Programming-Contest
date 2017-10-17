#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m;
int f[11000],c;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int aNs=0;
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)f[i]=-20000000;
		f[0]=0;
		m=min(m,10578);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c);
			for(int j=m-1;j>=c;j--)
				if(f[j]<f[j-c]+1)
					f[j]=f[j-c]+1;
		}
		aNs=0;
		for(int i=m-1;i;i--)
			if(f[i]>f[aNs])
				aNs=i;
		printf("Case %d: %d %d\n",cAse,f[aNs]+1,aNs+678);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

