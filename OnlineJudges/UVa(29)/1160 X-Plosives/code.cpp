/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[100050],f[100050];
int find(int x){while(f[x]!=f[f[x]])f[x]=f[f[x]];return f[x];}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,ans;
	for(int i=0;i<100050;i++)num[i]=i;
	while(scanf("%d",&a)!=-1)
	{
		memcpy(f,num,sizeof num);
		scanf("%d",&b);
		f[b]=a;
		ans=0;
		while(scanf("%d",&a)!=-1&&a!=-1)
		{
			scanf("%d",&b);
			a=find(a);b=find(b);
			if(a!=b) f[b]=a;
			else ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

