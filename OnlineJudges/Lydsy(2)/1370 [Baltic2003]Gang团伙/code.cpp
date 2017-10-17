/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int n,m,f[2050];
int find(int x)
{
	while(f[x]!=f[f[x]]) f[x]=f[f[x]];
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[5];
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=(n<<1);i;i--) f[i]=i;
	while(m--)
	{
		scanf("%s%d%d",tex,&a,&b);
		if(tex[0]=='E')
		{
			f[find(a)]=find(b+n);
			f[find(b)]=find(a+n);
		}
		else
			f[find(a)]=find(b);
	}
	set<int>s;
	for(int i=1;i<=n;i++) s.insert(find(i));
	printf("%d",(int)s.size());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

