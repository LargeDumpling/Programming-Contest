/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,k,T,a[10000050],b,c,p,ans,l,r,te[10000000];
bool cnmp(int A,int B){return A>B;}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B_BL.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&k,&T,&a[0],&b,&c,&p);
	for(int i=1;i<=n;i++)a[i]=(a[i-1]*b+c)%p;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			memset(te,0,sizeof(te));
			for(int l=i;l<=j;l++)te[++te[0]]=a[l];
			sort(te+1,te+te[0]+1,cnmp);
			if(te[k]>=T)
			{
				ans++;
				printf("%d %d\n",i,j);
			}
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

