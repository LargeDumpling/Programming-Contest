/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
	2015-11-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d,ans=0;
char s[40];
int calc(int x)
{
	int cnt=0,sum=0;
	for(int i=0;i<n;i++)
	{
		if((1<<i)&x)
		{
			cnt++;
			sum=(sum<<1)+(sum<<3)+s[i]-'0';
		}
	}
	if(cnt==n-d)
		return sum;
	return 0;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int t;
	while(scanf("%d%d",&n,&d)&&n)
	{
		ans=0;
		scanf("%s",s);
		for(int i=(1<<n)-1;i;i--)
		{
			t=calc(i);
			if(ans<t)
				ans=t;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

