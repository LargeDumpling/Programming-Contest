/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jz
{
	bool num[20][20];
	jz() { memset(num,0,sizeof(num)); }
	jz operator*(const jz &x)const
	{
		jz ans;
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
				for(int k=0;k<20;k++)
					ans.num[i][j]|=(num[i][k]&x.num[k][j]);
		return ans;
	}
}p[21];
int ans[25],n;
bool exist[25];
bool DFS(int x,int u)
{
	ans[x]=u;
	if(x==n) return p[0].num[u][ans[1]];
	else
		for(int j=0;j<n;j++) if(!exist[j]&&p[0].num[u][j])
		{
			exist[j]=true;
			if(DFS(x+1,j))
			{
				exist[j]=false;
				return true;
			}
			exist[j]=false;
		}
	exist[u]=false;
	return false;
}
int main()
{
	bool flag=true;
	scanf("%d",&n);
	char str[25];
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		for(int j=0;j<n;j++)
			p[0].num[i][j]=str[j]=='W';
	}
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]*p[0];
	for(int i=0;i<n;i++)
		flag&=p[n].num[i][i];
	if(flag)
	{
		exist[0]=true;
		flag=DFS(1,0);
		exist[0]=false;
	}
	if(flag) for(int i=1;i<=n;i++)
	{
		printf("%d",ans[i]+1);
		if(i!=n) putchar(' ');
	}
	else printf("No Solution");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

