/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int B,M,N;
int f[MAXN],ans[2][MAXN],last[MAXN];
map<int,int> h;
int find(int x)
{
	if(f[x]!=f[f[x]]) f[x]=find(f[x]);
	return f[x];
}
void merge(int a,int b)
{
	a=find(a); b=find(b);
	if(b<a) swap(a,b);
	f[b]=a;
	return;
}
int get_id(int x)
{
	if(!h.count(x))
	{
		int t=h.size();
		h[x]=t;
	}
	return h[x];
}
int main()
{
	int now=0;
	bool flag;
	scanf("%d%d",&B,&M);
	ans[0][0]=0;
	for(int i=0;i<M;i++)
	{
		f[i]=i;
		ans[now][++ans[now][0]]=i;
	}
	now=1;
	do
	{
		flag=false;
		now^=1;
		ans[now^1][0]=0;
		memset(last,-1,sizeof(last));
		for(int i=1;i<=ans[now][0];i++)
		{
			if(last[find(ans[now][i]*B%M)]==-1||last[find(ans[now][i]*B%M)]==0)
			{
				last[find(ans[now][i]*B%M)]=find(ans[now][i]);
				ans[now^1][++ans[now^1][0]]=find(ans[now][i]);
			}
			else
			{
				flag=true;
				merge(last[find(ans[now][i]*B%M)],ans[now][i]);
			}
		}
	}while(flag);
	printf("%d 0\n",ans[now][0]);
	putchar('G');
	for(int i=1;i<ans[now][0];i++)
		printf(" B");
	putchar('\n');
	for(int i=1;i<=ans[now][0];i++)
	{
		for(int j=0;j<B;j++)
			printf("%d%c",get_id(find((ans[now][i]*B+j)%M)),j==B-1?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

