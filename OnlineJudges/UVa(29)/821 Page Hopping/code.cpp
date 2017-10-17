/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int f[105][105];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,sum,n;
	double ave;
	for(int cAse=1;;cAse++)
	{
		scanf("%d%d",&a,&b);
		if(!a&&!b)break;
		set<int>s;
		memset(f,0,sizeof f);
		f[a][b]=1;
		n=max(a,b);
		s.insert(a);
		s.insert(b);
		while(scanf("%d%d",&a,&b)!=-1&&a&&b)f[a][b]=1,n=max(n,max(a,b)),s.insert(a),s.insert(b);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)if(i!=k)
				for(int j=1;j<=n;j++)if(i!=j&&k!=j)
					if((f[i][j]>f[i][k]+f[k][j]||!f[i][j])&&f[i][k]&&f[k][j])
						f[i][j]=f[i][k]+f[k][j];
		sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)if(i!=j)
				sum+=f[i][j];
		n=s.size();
		ave=1.*sum/(n*(n-1));
		printf("Case %d: average length between pages = %.3lf clicks\n",cAse,ave);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

