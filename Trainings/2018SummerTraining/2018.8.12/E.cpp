/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int q[100][MAXN];
char str[MAXN],tex[MAXN];
int N,L;
long long ans=0;
bool vis[100];
int idx(char x) { return x-=33; }
void print()
{
	long long t=0,x;
	for(int i=0;i<N;i++) if(tex[i]!=32)
	{
		x=q[idx(tex[i])][(ans+i)%L];
		t=max(t,x-(ans+i)%L);
	}
	ans+=t;
	return;
}
int main()
{
	gets(str);
	L=strlen(str);
	ans=-1;
	memset(q,-1,sizeof(q));
	for(int i=0;i<L;i++)
	{
		q[idx(str[i])][i]=i;
		vis[idx(str[i])]=true;
	}
	for(int i=0;i<=93;i++) if(vis[i])
	{
		for(int j=L-2;0<=j;j--) if(q[i][j]==-1)
			q[i][j]=q[i][j+1];
		for(int j=L-1;q[i][j]==-1;j--)
			q[i][j]=q[i][0]+L;
	}
	while(gets(tex))
	{
		ans++;
		N=strlen(tex);
		print();
	}
	if(ans==-1) ans=0;
	printf("%lld",ans+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

