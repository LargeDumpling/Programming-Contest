/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
typedef long double ld;
struct jp
{
	ld P,C;
	bool operator<(const jp &X)const { return C*X.P<=X.C*P; }
}R[MAXN];
int n,k[MAXN],p[MAXN][MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&p[i][j]);
		sort(p[i]+1,p[i]+k[i]+1);
		R[i].C=0;
		R[i].P=1;
		for(int j=k[i];j;j--)
		{
			R[i].C=R[i].C*((ld)p[i][j]/1000)+1;
			R[i].P=R[i].P*(ld)p[i][j]/1000.;
		}
	}
	sort(R+1,R+n+1);
	ld ans=0;
	for(int i=n;i;i--)
		ans=ans*((ld)1-R[i].P)+R[i].C;
	printf("%.9lf",(double)ans);
	//cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

