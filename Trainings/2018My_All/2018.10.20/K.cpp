/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int mod=1000000007;
int T_T,len,f[MAXN][MAXN],s[MAXN],tim[MAXN][MAXN];
char str[60];
int calc(int l,int r,int T)
{
	if(tim[l][r]==T) return f[l][r];
	tim[l][r]=T;
	f[l][r]=1;
	if(l<r)
	{
		for(int L=l;L<=r;L++)
			for(int R=r;l<=R;R--) if(L<R&&s[L]-s[l-1]==s[r]-s[R-1])
				f[l][r]=(f[l][r]+calc(L+1,R-1,T))%mod;
	}
	return f[l][r];
}
int main()
{
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		scanf("%s",str+1);
		len=strlen(str+1);
		s[0]=0;
		for(int i=1;i<=len;i++)
			s[i]=s[i-1]+str[i]-'0';
		printf("%d\n",calc(1,len,T));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

