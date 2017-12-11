/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2000000;
int n,k,cnt[MAXN+50];
int main()
{
	int x,num=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	sort(cnt+1,cnt+MAXN+1);
	for(int i=0;i<k;i++)
		num+=cnt[MAXN-i];
	printf("%d",n-num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

