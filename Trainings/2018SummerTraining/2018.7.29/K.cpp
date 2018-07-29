/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jz
{
	int u,v;
}E[MAXN];
bool vis[MAXN];
int cnt[MAXN],label[MAXN],n,X;
void print()
{
	printf("%d\n",n);
	for(int i=1;i<n;i++)
		printf("%d %d\n",label[E[i].u],label[E[i].v]);
	return;
}
int bigrand()
{
	int tem;
	do
	{
		tem=(rand()<<15)+rand();
	}while(1e9<tem||tem<=n);
	return tem;
}
set<int> s;
bool check(int x) { return s.find(x)==s.end(); }
int main()
{
	//freopen("K.in","r",stdin);
	//freopen("K.out","w",stdout);
	srand(1000000007);
	int x,a=0,b=0;
	scanf("%d",&n);
	X=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		label[i]=i;
		if(x) vis[i]=true;
		else s.insert(i);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&E[i].u,&E[i].v);
		cnt[E[i].u]++; cnt[E[i].v]++;
		if(!vis[E[i].u]) X^=E[i].u;
		if(!vis[E[i].v]) X^=E[i].v;
	}
	for(int i=1;i<=n;i++) if(vis[i])
	{
		if(cnt[i]&1) b++;
		else a++;
	}
	if(b==0)
	{
		if(X==0) print();
		else puts("-1");
	}
	else if(b==1)
	{
		if(X<=n)
		{
			if(X==0||!check(X)) puts("-1");
			else
			{
				if(cnt[X]&1) label[X]=X;
				else
				{
					do
					{
						label[X]=bigrand();
					}while(!check(label[X])||label[X]==X);
					s.insert(label[X]);
					for(int i=1;i<=n;i++)
						if(vis[i]&&(cnt[i]&1))
						{
							label[i]=X;
							s.insert(X);
							break;
						}
				}
				print();
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(vis[i]&&(cnt[i]&1))
				{
					label[i]=X;
					s.insert(X);
					break;
				}
			print();
		}
	}
	else
	{
		if(X==0&&b==2) puts("-1");
		else
		{
			for(int i=1;i<=n;i++) if(vis[i]&&(cnt[i]&1))
			{
				if(b==1)
				{
					label[i]=X;
					s.insert(label[i]);
					break;
				}
				else
				{
					do
					{
						label[i]=bigrand();
					}while(!check(X^label[i])&&!check(label[i]));
					s.insert(label[i]);
					X^=label[i];
					b--;
				}
			}
			print();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

