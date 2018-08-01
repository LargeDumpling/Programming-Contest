/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int T_T,n,V;
int w[MAXN],v[MAXN],f[MAXN],mv,mm;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(f,-1,sizeof(f));
		f[0]=0;
		scanf("%d%d",&n,&V);
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<=n;i++)
			for(int j=V;j>=v[i];j--) if(f[j-v[i]]!=-1)
				f[j]=max(f[j],f[j-v[i]]+w[i]);
		mv=mm=0;
		for(int i=V;i;i--)
			if(f[i]>mm)
			{
				mm=f[i];
				mv=i;
			}
		printf("%d %d\n",mm,mv);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

