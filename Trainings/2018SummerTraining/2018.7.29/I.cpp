/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=10050;
int n,k;
int num[MAXN],top[MAXN],h[MAXN*10];
char str[5];
int main()
{
	int x;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&top[i]);
		num[i]=k;
	}
	while(true)
	{
		h[0]=0;
		for(int i=1;i<=n;i++) if(top[i]!=0)
		{
			for(int j=1;j<=num[i];j++)
				h[++h[0]]=top[i];
		}
		sort(h+1,h+h[0]+1);
		printf("%d\n",h[h[0]/2+1]);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='E') exit(0);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x!=top[i]) num[i]--;
			top[i]=x;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

