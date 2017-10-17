/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int cnt=0,n,t;
	char tex[5];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sprintf(tex,"%d",i);
		for(t=0;tex[t]!='\0';t++);
		if(n<=cnt+t)
		{
			n-=cnt;
			printf("%d",tex[n-1]-'0');
			break;
		}
		cnt+=t;
	}
	return 0;
}

