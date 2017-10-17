/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
long long f[25][25][25];
bool exist[25][25][25];
void pre()
{
	int un,ul,ur;
	queue<int>q;
	memset(exist,false,sizeof(exist));
	f[1][1][1]=f[2][1][2]=f[2][2][1]=1;
	q.push(20102);q.push(20201);
	exist[2][1][2]=exist[2][2][1]=true;
	while(q.size())
	{
		un=q.front();
		q.pop();
		ur=un%100;un/=100;
		ul=un%100;un/=100;
		if(un>20)continue;
		exist[un][ul][ur]=false;
		f[un+1][ul][ur]+=(un-1)*f[un][ul][ur];
		f[un+1][ul+1][ur]+=f[un][ul][ur];
		f[un+1][ul][ur+1]+=f[un][ul][ur];
		if(!exist[un+1][ul][ur])
		{
			exist[un+1][ul][ur]=true;
			q.push((un+1)*10000+ul*100+ur);
		}
		if(!exist[un+1][ul+1][ur])
		{
			exist[un+1][ul+1][ur]=true;
			q.push((un+1)*10000+(ul+1)*100+ur);
		}
		if(!exist[un+1][ul][ur+1])
		{
			exist[un+1][ul][ur+1]=true;
			q.push((un+1)*10000+ul*100+ur+1);
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,n,l,r;
	scanf("%d",&T);
	memset(f,0,sizeof(f));
	pre();
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		printf("%lld\n",f[n][l][r]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

