//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXL=50;
struct jz
{
	int s,u;
	jz(const int &S=0,const int &U=0):s(S),u(U) { }
};
int ch[MAXL][2],val[MAXL],last[MAXL],pre[MAXL],sz=0;
double p[4];
char A[25],B[25];
int idx(char ch)
{
	return (int)ch=='H';
}
void insert(char T[],int x)
{
	int u=0;
	for(int i=0;T[i]!='\0';u=ch[u][idx(T[i++])])
		if(!ch[u][idx(T[i])])
			ch[u][idx(T[i])]=++sz;
	val[u]=x;
	return;
}
void getfail()
{
	int u,v,f;
	queue<int> q;
	for(int i=0;i<2;i++)
	{
		if(!ch[0][i])
			continue;
		pre[ch[0][i]]=last[ch[0][i]]=0;
		q.push(ch[0][i]);
	}
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=0;i<2;i++)
		{
			if(!ch[u][i])
			{
				ch[u][i]=ch[pre[u]][i];
				continue;
			}
			v=ch[u][i];
			q.push(v);
			f=pre[u];
			while(f&&!ch[f][i])
				f=pre[f];
			pre[v]=ch[f][i];
			last[v]=val[pre[v]]?pre[v]:last[pre[v]];
		}
	}
	return;
}
void count(int u,double np)
{
	if(last[u]) p[2]+=np;
	else p[val[u]-1]+=np;
	return;
}
bool exist[MAXL][MAXL];
double f[MAXL][MAXL];
void BFS()
{
	int nu,ns;
	memset(f,0,sizeof(f));
	queue<jz> q;
	f[0][0]=1;
	q.push(jz(0,0));
	while(q.size())
	{
		ns=q.front().s;
		nu=q.front().u;
		exist[nu][ns]=false;
		q.pop();
		if(40<ns) continue;
		/*for(int i=0;i<2;i++)
			if(ch[nu][i])
			{
				if(val[ch[nu][i]]) count(ch[nu][i],f[ns][nu]/2.);
				else
				{
					f[ns+1][ch[nu][i]]+=f[ns][nu]/2.;
					if(!exist[ns+1][ch[nu][i]])
					{
						q.push(jz(ns+1,ch[nu][i]));
						exist[ns+1][ch[nu][i]]=true;
					}
				}
			}
		*/
		if(ch[nu][0]!=0&&ch[nu][1]!=0)
		{
			for(int i=0;i<2;i++)
			{
				if(val[ch[nu][i]]) count(ch[nu][i],f[ns][nu]/2.);
				else
				{
					f[ns+1][ch[nu][i]]+=f[ns][nu]/2.;
					if(!exist[ns+1][ch[nu][i]])
					{
						q.push(jz(ns+1,ch[nu][i]));
						exist[ns+1][ch[nu][i]]=true;
					}
				}
			}
		}
		else if(ch[nu][0]!=0)
		{
			double ppp=(f[ns][nu]==1)?1:0.5*f[ns][nu]/(1.-0.5*f[ns][nu]);
			if(val[ch[nu][0]]) count(ch[nu][0],ppp);
			else
			{
				f[ns+1][ch[nu][0]]+=ppp;
				if(!exist[ns+1][ch[nu][0]])
				{
					q.push(jz(ns+1,ch[nu][0]));
					exist[ns+1][ch[nu][0]]=true;
				}
			}
		}
		else if(ch[nu][1]!=0)
		{
			double ppp=(f[ns][nu]==1)?1:0.5*f[ns][nu]/(1.-0.5*f[ns][nu]);
			if(val[ch[nu][1]]) count(ch[nu][1],ppp);
			else
			{
				f[ns+1][ch[nu][1]]+=ppp;
				if(!exist[ns+1][ch[nu][1]])
				{
					q.push(jz(ns+1,ch[nu][1]));
					exist[ns+1][ch[nu][1]]=true;
				}
			}
		}
	}
	return;
}

int main()
{
	scanf("%s%s",A,B);
	insert(A,1);
	insert(B,2);
	getfail();
	/*for(int i=0;i<=sz;i++)
		fprintf(stderr,"(%d,%d)\n",i,last[i]);*/
	BFS();
	printf("%.9lf\n%.9lf\n%.9lf",p[0],p[1],p[2]);
	return 0;
}

