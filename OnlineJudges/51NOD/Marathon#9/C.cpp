/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*const int D=10000000;
char in[D],*I=in,out[D/10],*O=out;
void read1n(int &x)
{
	for(x=0)
}*/
const int mod=1e9+7;
int n,fir[100050],end[200050],next[200050],ed=0;
long long ans[100050],sum[100050],size[100050],er[100050];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
void DFS(int u,int f)
{
	size[u]=sum[u]=1;
	ans[u]=0;
	for(int i=fir[u];i;i=next[i])if(end[i]!=f)
	{
		DFS(end[i],u);
		ans[u]=(ans[u]*er[size[end[i]]]%mod
			  +ans[end[i]]*er[size[u]]%mod
			  +sum[u]*sum[end[i]]%mod)%mod;
		sum[u]=(sum[u]*er[size[end[i]]]%mod+sum[end[i]]*er[size[u]-1]%mod)%mod;
		size[u]+=size[end[i]];
	}
	return;
}
void DFS()
{
	int s[100050],f[100050],cur[100050],u,v;
	memcpy(cur,fir,sizeof(fir));
	size[1]=sum[1]=f[1]=1;
	ans[1]=s[0]=0;
	s[++s[0]]=1;
	while(s[0])
	{
		u=s[s[0]];
		if(!cur[u])
		{
			for(int i=fir[u];i;i=next[i])if((v=end[i])!=f[u])
			{
				ans[u]=(ans[u]*er[size[v]]+ans[v]*er[size[u]]+sum[u]*sum[v])%mod;
				sum[u]=(sum[u]*er[size[v]]+sum[v]*er[size[u]-1])%mod;
				size[u]+=size[v];
			}
			s[0]--;
			continue;
		}
		for(int &i=cur[u];i;i=next[i])if((v=end[i])!=f[u])
		{
			size[v]=sum[v]=1;
			ans[v]=0;
			f[v]=u;
			s[++s[0]]=v;
			i=next[i];
			break;
		}
	}
}
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	er[0]=1;
	for(int i=1;i<100050;i++)er[i]=(er[i-1]*2)%mod;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	DFS();
	printf("%lld",ans[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

