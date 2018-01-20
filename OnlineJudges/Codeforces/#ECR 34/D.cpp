/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
const int M=262144;
int n,a[MAXN],h[MAXN],b[MAXN],pRe[MAXN],nExt[MAXN],cnt[MAXN];
long long ans;
int main()
{
	memset(pRe,-1,sizeof(pRe));
	memset(nExt,-1,sizeof(nExt));
	long long sum=0;
	h[0]=ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		h[++h[0]]=a[i];
		ans+=((long long)i*a[i]-sum);
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		b[i]=lower_bound(h+1,h+h[0]+1,a[i])-h;
		cnt[b[i]]++;
		if(1<b[i]&&h[b[i]-1]==a[i]-1)
			pRe[i]=b[i]-1;
		if(b[i]<h[0]&&h[b[i]+1]==a[i]+1)
			nExt[i]=b[i]+1;
		if(pRe[i]) ans-=cnt[pRe[i]];
		if(nExt[i]) ans+=cnt[nExt[i]];
	}
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

