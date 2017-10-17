/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int V,K,C,L;
	bool operator<(const jp &X)const
	{
		return V<X.V;
	}
}LED[1050];
int S[1050],f[1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",&LED[i].V,&LED[i].K,&LED[i].C,&LED[i].L);
			//V电压 K电源费用 C灯泡单价 L所需数量
		sort(LED+1,LED+n+1);
		for(int i=1;i<=n;i++)S[i]=S[i-1]+LED[i].L;
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=2147483647;
			for(int j=0;j<i;j++)
				f[i]=min(f[i],f[j]+(S[i]-S[j])*LED[i].C+LED[i].K);
		}
		printf("%d\n",f[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

