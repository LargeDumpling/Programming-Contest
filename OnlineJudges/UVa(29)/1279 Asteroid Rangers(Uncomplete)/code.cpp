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
#include<algorithm>
using namespace std;
struct jp
{
	int x,y,z,vx,vy,vz;
	jp(int a=0,int b=0,int c=0,int d=0,int e=0,int f=0)
	{
		x=a;
		y=b;
		z=c;
		vx=d;
		vy=e;
		vz=f;
	}
}p[55];
int dIst(int A,int B){return (p[A].x-p[B].x)*(p[A].x-p[B].x)+(p[A].y-p[B].y)*(p[A].y-p[B].y)+(p[A].z-p[B].z)*(p[A].z-p[B].z);}
int dist[55][55];
struct jP
{
	int a,b,c;
	jP(int A=0,int B=0)
	{
		a=(p[A].vx-p[B].vx)*(p[A].vx-p[B].vx)+(p[A].vy-p[B].vy)*(p[A].vy-p[B].vy)+(p[A].vz-p[B].vz)*(p[A].vz-p[B].vz);
		b=(p[A].vx-p[B].vx)*(p[A].x-p[B].x)+(p[A].vy-p[B].vy)*(p[A].y-p[B].y)+(p[A].vz-p[B].vz)*(p[A].z-p[B].z);
		b*=-2;
		c=(p[A].x-p[B].x)*(p[A].x-p[B].x)+(p[A].y-p[B].y)*(p[A].y-p[B].y)+(p[A].z-p[B].z)*(p[A].z-p[B].z);
	}
	//bool operator<(const jP &x)const{return dist[p1][p2]<=dist[x.p1][x.p2];}
}E[2500];
struct Jp
{
	int E1,E2;
	double t;
}
int n,en;
int f[55],cho[55];
int find(int x){while(f[x]!=f[f[x]])f[x]=f[f[x]];return f[x];}
double t,exc[2500][2500];
void sta()
{
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1,cnt=cho[0]=0,a,b;i<=en&&cnt<n-1;i++)
	{
		a=find(E[i].p1),b=find(E[i].p2);
		if(a!=b)
		{
			cho[++cho[0]]=i;
			f[b]=a;
			cnt++;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;scanf("%d",&n)!=-1;cAse++)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d%d%d",&p[i].x,&p[i].y,&p[i].z,&p[i].vx,&p[i].vy,&p[i].vz);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=dIst(i,j);
		en=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				E[++en]=jP(i,j);
		sta();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

