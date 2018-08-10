/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=20;
int n,f[262144][MAXN];
char str[20];
queue<int> q;
bool exist[262144][MAXN];
int main()
{
	int x,S,u,nS[3];
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	scanf("%s",str);
	x=0;
	for(int i=0;i<n;i++)
		x=(x<<1)|(str[i]=='1');
	f[x][n]=1;
	q.push(x*100+n);
	while(q.size())
	{
		S=q.front(); q.pop();
		u=S%100; S/=100;
		exist[S][u]=false;
		memset(nS,0,sizeof(nS));
		for(int i=u-2;0<=i;i-=2)
		{
			nS[0]=(nS[0]<<1)|((S>>i)&(S>>(i+1)));
			nS[1]=(nS[1]<<1)|((S>>i)|(S>>(i+1)));
			nS[2]=(nS[2]<<1)|((S>>i)^(S>>(i+1)));
		}
		for(int i=0;i<2;i++)
		{
			f[nS[i]][u-1]+=f[S][u];
			if(!exist[nS[i]][u-1])
			{
				exist[nS[i]][u-1]=true;
				q.push(nS[i]*100+u-1);
			}
		}
	}
	printf("%d",f[1][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

