/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000000;
int lenth;
char tex[350];
long long f[350][350];
long long F(int l,int r)
{
	if(f[l][r]!=-1) return f[l][r];
	if(l==r) return f[l][r]=1;
	if(tex[l]!=tex[r]||r<l) return f[l][r]=0;
	f[l][r]=0;
	for(int i=l+1;i<=r;i++) if(tex[l]==tex[i])
		f[l][r]=(f[l][r]+F(l+1,i-1)*F(i,r)%mod)%mod;
	return f[l][r];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(true)
	{
		if(scanf("%s",tex)==-1) break;
		lenth=strlen(tex);
		memset(f,-1,sizeof(f));
		printf("%lld\n",F(0,lenth-1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

