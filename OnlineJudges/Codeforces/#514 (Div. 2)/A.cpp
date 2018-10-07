/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,L,a;
int l[MAXN],t[MAXN];
int main()
{
	int cnt=0;
	scanf("%d%d%d",&n,&L,&a);
	t[0]=l[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&l[i]);
		cnt+=(t[i]-t[i-1]-l[i-1])/a;
	}
	cnt+=(L-t[n]-l[n])/a;
	printf("%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

