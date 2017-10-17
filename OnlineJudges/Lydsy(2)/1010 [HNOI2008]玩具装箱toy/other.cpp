#include<map>
#include<set>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,L,l,r;
int c[50005],q[50005];
ll s[50005],f[50005],C;
double slop(int j,int k)
{
	return (f[k]-f[j]+(s[k]+C)*(s[k]+C)-(s[j]+C)*(s[j]+C))/(2.0*(s[k]-s[j]));
}
void dp()
{
	l=1;r=0;q[++r]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&slop(q[l],q[l+1])<=s[i])l++;
		int t=q[l];
		printf("%d %d\n",i,t);
		f[i]=f[t]+(s[i]-s[t]-C)*(s[i]-s[t]-C);
		while(l<r&&slop(q[r],i)<slop(q[r-1],q[r]))r--;
		q[++r]=i;
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	n=read();L=read();C=L+1;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)s[i]=s[i-1]+c[i];
	for(int i=1;i<=n;i++) printf("%d ",s[i]+=i); putchar('\n');
	dp();
	printf("%lld\n",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
