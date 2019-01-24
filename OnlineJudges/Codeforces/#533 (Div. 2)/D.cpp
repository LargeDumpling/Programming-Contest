/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct jz
{
	int x,y,step;
	jz(const int &X=0,const int &Y=0,const int &S=0):x(X),y(Y),step(S) { }
};
int n,m,p;
int s[10],con[10],mOve[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char map[1050][1050];
queue<int> q[10];
queue<jz> Q;
int now_nam;
void expand()
{
	int xx,yy,x,y,step;
	while(Q.size())
	{
		x=Q.front().x;
		y=Q.front().y;
		step=Q.front().step;
		Q.pop();
		if(!step) continue;
		for(int i=0;i<4;i++)
		{
			xx=x+mOve[i][0];
			yy=y+mOve[i][1];
			if(xx<0||n<=xx) continue;
			if(yy<0||m<=yy) continue;
			if(map[xx][yy]!='.') continue;
			q[now_nam].push(xx*10000+yy);
			map[xx][yy]=now_nam+'0';
			Q.push(jz(xx,yy,step-1));
		}
	}
	return;
}
int main()
{
	bool flag=true;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;i++)
	{
		scanf("%d",&s[i]);
		s[i]=min(s[i],n*m);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
		for(int j=0;j<m;j++)
			if(map[i][j]!='.'&&map[i][j]!='#')
				q[map[i][j]-'0'].push(i*10000+j);
	}
	while(flag)
	{
		flag=false;
		for(int i=1;i<=p;i++) if(!q[i].empty())
		{
			flag=true;
			now_nam=i;
			while(!q[i].empty())
			{
				Q.push(jz(q[i].front()/10000,q[i].front()%10000,s[i]));
				q[i].pop();
				con[i]++;
			}
			expand();
		}
	}
	for(int i=1;i<=p;i++)
		printf("%d ",con[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

