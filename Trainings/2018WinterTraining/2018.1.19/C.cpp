/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,f[205],ans;
struct Dia
{
	double w,c;
	bool operator<(const Dia &X)const
	{
		if(w==X.w) return c>X.c;
		return w<X.w;
	}
}D[205];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(f,ans=0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&D[i].w,&D[i].c);
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
				if(D[j].w<D[i].w&&D[i].c<D[j].c&&f[i]<f[j]+1)
					ans=max(ans,f[i]=f[j]+1);
		printf("%d\n",ans+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

