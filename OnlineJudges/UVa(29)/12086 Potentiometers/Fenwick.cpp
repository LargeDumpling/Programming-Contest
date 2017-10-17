/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,f[200050],num[200050];
inline int low(int x) { return x&-x; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("Fenwick.out","w",stdout);
	char ord[5];
	int a,b,ans;
	for(int T_T=1;scanf("%d",&n)!=-1&&n;T_T++)
	{
		if(T_T>1) putchar('\n');
		printf("Case %d:\n",T_T);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			for(int j=i;j<=n;j+=low(j)) f[j]+=num[i];
		}
		while(true)
		{
			scanf("%s",ord);
			if(ord[0]=='E') break;
			else if(ord[0]=='M')
			{
				scanf("%d%d",&a,&b);
				ans=0;
				for(int i=b;i>0;i-=low(i)) ans+=f[i];
				for(int i=a-1;i>0;i-=low(i)) ans-=f[i];
				printf("%d\n",ans);
			}
			else if(ord[0]=='S')
			{
				scanf("%d%d",&a,&b);
				for(int i=a;i<=n;i+=low(i)) f[i]-=num[a];
				num[a]=b;
				for(int i=a;i<=n;i+=low(i)) f[i]+=num[a];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

