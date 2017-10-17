/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,t;
int fir[100050],du[100050],end[400050],next[400050],num[400050],ed=1;
bool use[400050];
int ans[200050],start;
void addedge(int u,int v,int id1,int id2)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	num[ed]=id1;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	num[ed]=id2;
	return;
}
int cnt=0;
stack<int>s;
void DFS(int u)
{
	s.push(u);
	while(s.size())
	{
		u=s.top();
		int &i=fir[u];
		if(!fir[u])
		{
			s.pop();
			continue;
		}
		while(!use[i]) i=next[i];
		cnt++;
		use[i]=use[i^1]=true;
		s.push(end[i]);
		ans[++ans[0]]=num[i];
	}
	return;
}
void DFS2(int u)
{
	for(int i=fir[u];i;i=next[i])  if(!(i&1)&&!use[i])
	{
		use[i]=use[i^1]=true;
		DFS2(end[i]);
		ans[++ans[0]]=num[i];
	}
	return;
}
bool find_euler_circuit()
{
	memset(use,false,sizeof(use));
	ans[0]=0;
	if(t==1) DFS(start);
	else DFS2(start);
	if(ans[0]==m) return true;
	else return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	bool posi=true;
	scanf("%d%d%d",&t,&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(t==1)
		{
			addedge(a,b,i,-1*i);
			du[a]++;
			du[b]++;
		}
		else
		{
			addedge(a,b,i,i);
			du[a]--;
			du[b]++;
		}
		start=a;
	}
	if(t==1) { for(int i=1;i<=n;i++) if(du[i]&1) posi=false; }
	else { for(int i=1;i<=n;i++) if(du[i]!=0) posi=false; }
	if(posi&&find_euler_circuit())
	{
		puts("YES");
		for(int i=ans[0];i;i--)
			printf("%d ",ans[i]);
	}
	else printf("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

