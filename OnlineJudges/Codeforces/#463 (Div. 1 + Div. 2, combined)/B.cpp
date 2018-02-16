/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int s[10][MAXN];
int f(int x)
{
	if(x<10) return x;
	int ans;
	for(ans=1;x;x/=10)
		if(x%10)
			ans*=x%10;
	return f(ans);
}
void pre_calc()
{
	memset(s,0,sizeof(s));
	for(int i=1;i<MAXN;i++)
	{
		for(int j=0;j<10;j++)
			s[j][i]=s[j][i-1];
		s[f(i)][i]++;
	}
	return;
}
int main()
{
	int Q,l,r,k;
	pre_calc();
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",s[k][r]-s[k][l-1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

