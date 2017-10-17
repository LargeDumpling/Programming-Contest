/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,last,now;
int main()
{
	scanf("%d",&n);
	last=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&now);
		if(last+15<now)
			break;
		last=now;
	}
	last=min(last+15,90);
	printf("%d",last);
	return 0;
}

