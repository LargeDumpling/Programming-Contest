#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir[1100050],end[4500050],next[4500050],lk[1100050],ed=0;
int n,a,b,id=0;
int exist[1000050];
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
bool sef(int x)
{
	for(int i=fir[x];i;i=next[i])
	{
		if(id==exist[end[i]])
			continue;
		exist[end[i]]=id;
		if(!lk[end[i]]||sef(lk[end[i]]))
		{
			lk[end[i]]=x;
			return true;
		}
	}
	return false;
}
int work()
{
	int ans=0;
	for(int i=1;i<=10000;i++)
	{
		id=i;
		if(sef(i+1000000))ans++;
		else break;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(i,a+1000000);
		addedge(i,b+1000000);
	}
	printf("%d\n",work());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

