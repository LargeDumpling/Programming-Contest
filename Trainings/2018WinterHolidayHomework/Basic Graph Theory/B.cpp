/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,ST;
map<string,int> f;
double w[35][35],dis[35];
bool exist[35];
bool SPFA()
{
	int u,cnt=0;
	queue<int> q;
	for(int i=0;i<35;i++) dis[i]=-1;
	memset(exist,false,sizeof(exist));
	dis[ST]=10000;
	q.push(ST);
	for(;q.size()&&cnt<=100000;cnt++)
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=1;i<=n;i++)
			if(w[u][i]!=-1&&dis[i]<dis[u]*w[u][i])
		{
			dis[i]=dis[u]*w[u][i];
			if(!exist[i])
			{
				q.push(i);
				exist[i]=true;
			}
		}
	}
	return 10000<dis[ST];
}
int main()
{
	string uu,vv;
	int u,v;
	bool flag;
	double tem;
	for(int T=1;scanf("%d",&n)!=-1&&n;T++)
	{
		f.clear();
		for(int i=0;i<35;i++)
			for(int j=0;j<35;j++)
				w[i][j]=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>uu;
			f[uu]=i;
		}
		scanf("%d",&m);
		while(m--)
		{
			cin>>uu>>tem>>vv;
			u=f[uu]; v=f[vv];
			w[u][v]=max(w[u][v],tem);
		}
		flag=false;
		for(ST=1;ST<=n&&!flag;ST++)
			flag=SPFA();
		printf("Case %d: %s\n",T,flag?"Yes":"No");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

