/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[20001],d[20001],n,m;
int find(const int &x=0)
{
	while(f[x]!=f[f[x]])
	{
		d[x]^=d[f[x]];
		f[x]=f[f[x]];
	}
	return f[x];
}
void solve()
{
	char in[205];
	int num[20001],k,a,b,c,x,y,i,j,cnt=0;
	for(i=0;i<=20000;i++) f[i]=i,d[i]=0;
	bool flag=true;
	for(i=1;i<=m;i++)
	{
		if(flag) scanf("%s",in);
		else
		{
			gets(in);
			continue;
		}
		if(in[0]=='I')
		{
			cnt++;
			gets(in);
			if(sscanf(in,"%d%d%d",&a,&b,&c)==2) { c=b; b=n; }
			x=find(a); y=find(b);
			if(x==y)
			{
				if(c^d[a]^d[b])
				{
					printf("The first %d facts are conflicting.\n",cnt);
					flag=false;
				}
			}
			else
			{
				if(x>y) swap(x,y),swap(a,b);
				//使得任意集合与虚拟集合合并时，必并向虚拟集合
				f[x]=y;
				d[x]=c^d[a]^d[b];
			}
		}
		else if(in[0]=='Q')
		{
			memset(num,0,sizeof(num));
			scanf("%d",&k);
			y=0;
			while(k--)
			{
				scanf("%d",&a);
				b=find(a);
				y^=d[a];
				if(b!=n) num[b]^=1;
			}
			x=1;
			for(j=0;j<n&&x;j++) if(num[j]) x=0;
			if(x) printf("%d\n",y);
			else puts("I don't know.");
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int T_T=1;scanf("%d%d\n",&n,&m)!=-1&&n&&m;T_T++)
	{
		printf("Case %d:\n",T_T);
		solve();
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

