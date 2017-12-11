/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-11-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int n,L[MAXN],cnt[MAXN],ans=0;
int main()
{
	int tem=0;
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&L[i]);
		if(L[i]) cnt[max(i-L[i],1)]++;
	}
	for(int i=1;i<=n;i++)
	{
		tem+=cnt[i];
		if(L[i]) tem--;
		if(!tem) ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

