/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=0x7f7f7f7f;
int need[]={6,2,5,5,4,5,6,3,7,6},p[15][105],f[105][3050],n,m;
void print(int din,int dig,int left)
{
	for(int i=9;i>=0;i--)
	{
		int tar=(dig+m-p[i][din])%m;
		if(f[din-1][tar]+need[i]<=left)
		{
			putchar(i+'0');
			print(din-1,tar,left-need[i]);
			return;
		}
	}
	return;
}
int main()
{
	int din,dig,u;
	bool exist[55][3050];
	for(int cAse=1;scanf("%d%d",&n,&m)==2;cAse++)
	{
		printf("Case %d: ",cAse);
		for(int i=0;i<10;i++)
		{
			p[i][1]=i%m;
			for(int j=2;j<=50;j++)
				p[i][j]=p[i][j-1]*10%m;
		}
		memset(f,127,sizeof(f));
		memset(exist,false,sizeof(exist));
		queue<int>q;
		q.push(0);
		f[0][0]=0;
		while(q.size())
		{
			u=q.front(); q.pop();
			dig=u%10000; din=u/10000;
			for(int i=0;i<10;i++) if(f[din][dig]+need[i]<=n)
			{
				int tar=(dig*10+i)%m;
				if(f[din][dig]+need[i]<f[din+1][tar])
				{
					f[din+1][tar]=f[din][dig]+need[i];
					if(!exist[din+1][tar])
					{
						exist[din+1][tar]=true;
						q.push((din+1)*10000+tar);
						}
				}
			}
		}
		for(int i=50;i;i--)
			if(f[i][0]!=INF)
			{
				print(i,0,n);
				putchar('\n');
				goto end;
			}
		puts("-1");
		end:;
	}
	return 0;
}

