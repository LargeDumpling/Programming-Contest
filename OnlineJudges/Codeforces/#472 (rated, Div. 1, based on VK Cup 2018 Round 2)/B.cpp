/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,U,E[MAXN];
double ans=-1;
int main()
{
	int r=1;
	scanf("%d%d",&n,&U);
	for(int i=1;i<=n;i++)
		scanf("%d",&E[i]);
	for(int i=1;i<=n;i++)
	{
		while(r<n&&E[r+1]-E[i]<=U) r++;
		if(E[r]-E[i]<=U&&i+1<r)
			ans=max(ans,(double)(E[r]-E[i+1])/(E[r]-E[i]));
	}
	if(ans==-1) printf("-1");
	else printf("%.10lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

