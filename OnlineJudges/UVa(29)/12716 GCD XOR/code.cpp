/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,cnt[30000050];
void pre()
{
	int a,b;
	for(int c=1;c<=15000000;c++)
	{
		for(a=c<<1;a<=30000000;a+=c)
		{
			b=a-c;
			if((a^b)==c)cnt[a]++;
		}
	}
	cnt[0]=0;
	for(int i=1;i<=30000000;i++)cnt[i]+=cnt[i-1];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pre();
	scanf("%d",&T);
	for(int cAse=1;cAse<=T&&scanf("%d",&n)!=-1;cAse++)
		printf("Case %d: %d\n",cAse,cnt[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

