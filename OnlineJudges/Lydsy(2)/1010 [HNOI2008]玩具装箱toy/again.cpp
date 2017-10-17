/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
int n,L,c,R[MAXN],s[MAXN];
long long S[MAXN],f[MAXN];
long long cal(int p1,int p2) { return f[p1]+(S[p2]-S[p1]-c)*(S[p2]-S[p1]-c); }
int decide(int x)
{
	int l=1,r=s[0]+1,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(R[s[mid]]<=x) l=mid;
		else r=mid;
	}
	return s[l];
}
int dec_R(int l,int p1,int p2)
{
	int r=n+1,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(cal(p1,mid)<=cal(p2,mid)) l=mid;
		else r=mid;
	}
	if(cal(p2,l)<cal(p1,l)) r=l;
	return r;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("again.out","w",stdout);
	scanf("%d%d",&n,&L);
	c=L+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&S[i]);
		S[i]+=S[i-1]+1;
	}
	s[1]=0;
	R[0]=s[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=cal(decide(i),i);
		while(s[0]
				&&i<R[s[s[0]]]
				&&(cal(i,R[s[s[0]]])<=cal(s[s[0]],R[s[s[0]]])||R[s[s[0]]]==n+1))
			s[0]--;
		R[i]=dec_R(i+1,s[s[0]],i);
		s[++s[0]]=i;
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

