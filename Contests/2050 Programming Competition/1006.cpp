/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long INF=1e15;
int T_T,n,ans;
long long f[1050],a,b,c;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(f,-1,sizeof(f));
		scanf("%d%lld",&n,&c);
		f[0]=c;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			if(a<b)
			{
				for(int j=n-1,k;0<=j;j--) if(a<(k=min(b,f[j])))
				{
					if(f[j+1]<k-a)
						f[j+1]=k-a;
				}
			}
			for(int j=0;j<=n;j++)
			{
				if(f[j]==-1) break;
				f[j]+=c;
			}
		}
		for(ans=n;f[ans]==-1;ans--);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

