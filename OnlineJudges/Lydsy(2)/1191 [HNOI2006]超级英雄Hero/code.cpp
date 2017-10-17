#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,fir[2050],end[4060],next[4060],ed=0,lk[2050],ans=0;
bool exist[2050];
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
		if(!exist[end[i]])
		{
			exist[end[i]]=true;
			if(!lk[end[i]]||sef(lk[end[i]]))
			{
				lk[end[i]]=x;
				return true;
			}
		}
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		a++;
		b++;
		addedge(a,i+1000);
		addedge(b,i+1000);
	}
	for(int i=1;i<=m;i++)
	{
		memset(exist,0,sizeof(exist));
		if(sef(i+1000))
			ans++;
		else break;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

