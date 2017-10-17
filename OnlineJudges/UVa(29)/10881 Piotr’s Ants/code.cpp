/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Ant
{
	int pos,id,dir;
	bool operator<(const Ant &x)const
	{ return pos<x.pos; }
}ant[10050],fin[10050];
int L,T,N;
int rank[10050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,x;
	char tex[5];
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		printf("Case #%d:\n",cAse);
		scanf("%d%d%d",&L,&T,&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d %c",&ant[i].pos,&tex[0]);
			//if(tex[0]=='R') ant[i].dir=1;
			//else ant[i].dir=-1;
			ant[i].dir=tex[0]=='R'?1:-1;
			ant[i].id=i;
			fin[i].pos=ant[i].pos+ant[i].dir*T;
			fin[i].dir=ant[i].dir;
			fin[i].id=0;
		}
		sort(ant+1,ant+N+1);
		for(int i=1;i<=N;i++)
			rank[ant[i].id]=i;
		sort(fin+1,fin+N+1);
		for(int i=1;i<=N-1;i++)
			if(fin[i].pos==fin[i+1].pos)
				fin[i].id=fin[i+1].id=1;
		for(int i=1;i<=N;i++)
		{
			x=rank[i];
			if(fin[x].pos<0||fin[x].pos>L)
			{
				//puts("Fell off");
				printf("Fell off\n");
				continue;
			}
			printf("%d ",fin[x].pos);
			if(fin[x].id) printf("Turning\n");
			else if(fin[x].dir>0) printf("R\n");
			else printf("L\n");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

