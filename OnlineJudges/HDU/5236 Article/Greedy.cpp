/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
double f[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("Greedy.out","w",stdout);
	int T_T,n,w;
	double P,ans;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d%lf%d",&n,&P,&w);
		ans=2147483647;
		f[0]=0;
		for(int i=1;i<=n;i++) f[i]=(f[i-1]+1.)/(1.-P);
		for(int i=1;i<=n;i++)
		{
			int num1,num2,num=n/i;
			num2=n%i;
			num1=i-num2;
			ans=min(ans,1.*i*w+1.*num1*f[num]+1.*num2*f[num+1]);
		}
		printf("Case #%d: %.6f\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

