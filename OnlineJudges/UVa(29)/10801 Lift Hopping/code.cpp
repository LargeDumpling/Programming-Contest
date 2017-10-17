/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<sstream>
#include<algorithm>
using namespace std;
struct jp
{
	int fir,sec;
	jp(int a=0,int b=0):fir(a),sec(b){}
	bool operator<(const jp &X)const{return fir==X.fir?sec<X.sec:fir<X.fir;}
};
int n,k,T[6],dis[6][105];
bool hav[6][105],exist[6][105];
int Hijkstra()
{
	int un,uk,ans;
	memset(exist,false,sizeof(exist));
	queue<int>q;
	ans=1<<29;
	for(int i=1;i<=n;i++)for(int j=0;j<100;j++)dis[i][j]=1<<29;
	for(int i=1;i<=n;i++)if(hav[i][0])
	{
		dis[i][0]=0;
		exist[i][0]=true;
		q.push(i*1000);
	}
	while(q.size())
	{
		un=q.front();
		q.pop();
		uk=un%1000;
		un/=1000;
		exist[un][uk]=false;
		for(int i=1;i<=n;i++)if(un!=i&&hav[i][uk]&&dis[un][uk]+60<dis[i][uk])
		{
			dis[i][uk]=dis[un][uk]+60;
			if(!exist[i][uk])
			{
				q.push(i*1000+uk);
				exist[i][uk]=true;
			}
		}
		for(int i=0;i<100;i++)if(uk!=i&&hav[un][i]&&dis[un][uk]+T[un]*abs(i-uk)<dis[un][i])
		{
			dis[un][i]=dis[un][uk]+T[un]*abs(i-uk);
			if(!exist[un][i])
			{
				dis[un][i]=dis[un][uk]+T[un]*abs(i-uk);
				if(!exist[un][i])
				{
					q.push(un*1000+i);
					exist[un][i]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)ans=min(ans,dis[i][k]);
	if(ans==1<<29)ans=-1;
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int x;
	string str;
	while(scanf("%d%d",&n,&k)!=-1)
	{
		for(int i=1;i<=n;i++)scanf("%d",&T[i]);
		while(getchar()!='\n');
		for(int i=1;i<=n;i++)
		{
			getline(cin,str);
			stringstream in(str);
			memset(hav[i],false,sizeof(hav[i]));
			while(in>>x)hav[i][x]=true;
		}
		x=Hijkstra();
		if(x==-1)puts("IMPOSSIBLE");
		else printf("%d\n",x);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

