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
#include<stack>
#include<algorithm>
using namespace std;
int fir[100050],end[200050],next[200050],ed=0,n;
int size[100050],deep[100050],fa[100050],cur[100050];
long long ans[100050],deepsum[100050],JP[100050];
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
void DFS1()
{
	stack<int>s;
	s.push(1);
	fa[1]=1;
	int u,v;
	while(s.size())
	{
		u=s.top();
		if(cur[u]==fir[u])
		{
			size[u]=1;
			deepsum[u]=deep[u];
		}
		int &i=cur[u];
		if(end[i]==fa[u]) i=next[i];
		if(i)
		{
			v=end[i];
			deep[v]=deep[u]+1;
			fa[v]=u;
			s.push(v);
			i=next[i];
		}
		else
		{
			for(int i=fir[u];i;i=next[i]) if(end[i]!=fa[u])
			{
				v=end[i];
				deepsum[u]+=deepsum[v];
				size[u]+=size[v];
			}
			s.pop();
		}
	}
	return;
}
void DFS2()
{
	stack<int>s;
	JP[1]=0;
	s.push(1);
	int v,u;
	while(s.size())
	{
		u=s.top();
		if(cur[u]==fir[u])
			ans[u]=JP[u]+deepsum[u]-(long long)deep[u]*size[u];
		int &i=cur[u];
		if(end[i]==fa[u]) i=next[i];
		if(i)
		{
			v=end[i];
			JP[v]=JP[u]+deepsum[u]-deepsum[v]
				-(long long)(size[u]-size[v])*deep[u]+n-size[v];
			s.push(v);
			i=next[i];
		}
		else s.pop();
	}
	return;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	deep[1]=0;
	for(int i=1;i<=n;i++) cur[i]=fir[i];
	DFS1();
	for(int i=1;i<=n;i++) cur[i]=fir[i];
	DFS2();
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

