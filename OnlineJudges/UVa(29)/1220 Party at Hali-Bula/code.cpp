/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int pn=0,fir[205],next[205],root,n,d[205][2],f[205][2];
map<string,int>s;
int get_id(const string &temp)
{
	if(s.count(temp)==0)
		s[temp]=++pn;
	return s[temp];
}
int min(const int &A,const int &B){return A<B?A:B;}
int max(const int &A,const int &B){return A<B?B:A;}
void dp(int u)
{
	if(!fir[u])
	{
		d[u][0]=0;
		d[u][1]=f[u][0]=f[u][1]=1;
		return;
	}
	d[u][1]=1;
	f[u][0]=f[u][1]=1;
	int di;
	for(int i=fir[u];i;i=next[i])
	{
		dp(i);
		d[u][1]+=d[i][0];//u要选
		f[u][1]*=f[i][0];
		if(d[i][0]==d[i][1])//u不参加
		{
			d[u][0]+=d[i][0];
			f[u][0]*=(f[i][0]+f[i][1]);
		}
		else
		{
			di=d[i][0]<d[i][1];
			d[u][0]+=d[i][di];
			f[u][0]*=f[i][di];
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int A,B,di;
	string a,b;
	while(scanf("%d",&n)&&n)
	{
		memset(fir,0,sizeof(fir));
		memset(next,pn=0,sizeof(next));
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		s.clear();
		cin>>a;
		root=get_id(a);
		for(int i=1;i<n;i++)
		{
			cin>>a>>b;
			A=get_id(a);
			B=get_id(b);
			next[A]=fir[B];
			fir[B]=A;
		}
		dp(root);
		di=d[root][0]==d[root][1]?-1:d[root][0]<d[root][1];
		if(di==-1)
			printf("%d No\n",d[root][0]);
		else
		{
			printf("%d ",d[root][di]);
			if(f[root][di]==1)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

