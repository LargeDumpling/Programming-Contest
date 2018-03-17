/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,cnt[605];
int main()
{
	int x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	x=0;
	for(int i=1;i<=600;i++) if(cnt[i]) x++;
	printf("%d",x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

