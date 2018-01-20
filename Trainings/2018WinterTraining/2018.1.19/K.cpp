/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=65;
const int MAXM=7500;
int T_T,ch[3050][65],val[3050],sz,wn,n;
int fir[MAXN],end[MAXM],next[MAXM],ed=0;
double len[MAXM],dis[MAXN];
bool exist[MAXN];
struct jp
{
	char name[55];
	long long x,y,z;
}p[65];
void addedge(int u,int v,double lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=lenth;
	return;
}
int idx(char x)
{
	if('A'<=x&&x<='Z')
		return x-'A'; //0-25
	if('a'<=x&&x<='z')
		return x-'a'+26; //26-51
	if('0'<=x&&x<='9')
		return x-'-'+52;
	return -1;
}
int fInd(char *T)
{
	int u;
	for(u=0;*T!='\0';u=ch[u][idx(*T++)])
		if(!ch[u][idx(*T)])
			ch[u][idx(*T)]=++sz;
	if(!val[u]) val[u]=++wn;
	return val[u];
}
void init()
{
	memset(ch,sz=wn=0,sizeof(ch));
	memset(fir,ed=0,sizeof(fir));
	memset(val,0,sizeof(val));
	return;
}
double squ(long long x) { return (double)x*x; }
double calc_dis(int i,int j) { return sqrt(squ(p[i].x-p[j].x)+squ(p[i].y-p[j].y)+squ(p[i].z-p[j].z)); }
double SPFA(int S,int T)
{
	int u,v;
	for(int i=0;i<=n;i++) dis[i]=1e100;
	memset(exist,false,sizeof(exist));
	queue<int> q;
	dis[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])
		{
			v=end[i];
			if(dis[u]+len[i]<dis[v])
			{
				dis[v]=dis[u]+len[i];
				if(!exist[v])
				{
					exist[v]=true;
					q.push(v);
				}
			}
		}
	}
	return dis[T];
}
int main()
{
	int tn;
	char A[55],B[55];
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		printf("Case %d:\n",T);
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s%lld%lld%lld",p[i].name,&p[i].x,&p[i].y,&p[i].z);
			fInd(p[i].name);
		}
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
			{
				addedge(i,j,calc_dis(i,j));
				addedge(j,i,calc_dis(i,j));
			}
		scanf("%d",&tn);
		while(tn--)
		{
			scanf("%s%s",A,B);
			addedge(fInd(A),fInd(B),0);
		}
		scanf("%d",&tn);
		while(tn--)
		{
			scanf("%s%s",A,B);
			printf("The distance from %s to %s is %lld parsecs.\n",A,B,(long long)(SPFA(fInd(A),fInd(B))+0.5));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

